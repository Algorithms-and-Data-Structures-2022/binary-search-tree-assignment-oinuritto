#include "assignment/binary_search_tree.hpp"

namespace assignment {

  BinarySearchTree::~BinarySearchTree() {
    BinarySearchTree::Clear();
  }

  void BinarySearchTree::Insert(int key, int value) {
    // Write your code here...
    insert(key,value,root_);

  }

  bool BinarySearchTree::Remove(int key) {
    // Write your code here...
    return remove(key,root_);
  }

  void BinarySearchTree::Clear() {
    // Write your code here...
    clear(root_);
    root_ = nullptr;
  }

  std::optional<int> BinarySearchTree::Find(int key) const {
    // Write your code here...
    Node* node = find(key, root_);
    if (node != nullptr) {
      return node->value;
    }
    return std::nullopt;
  }

  bool BinarySearchTree::Contains(int key) const {
    // Write your code here...
    return find(key, root_) != nullptr;
  }

  bool BinarySearchTree::IsEmpty() const {
    return root_ == nullptr;
  }

  std::optional<int> BinarySearchTree::FindMin() const {
    // Write your code here...
    Node* node = find_min(root_);
    if (node != nullptr) {
      return node->value;
    }
    return std::nullopt;
  }

  std::optional<int> BinarySearchTree::FindMax() const {
    // Write your code here...
    Node* node = find_max(root_);
    if (node != nullptr) {
      return node->value;
    }
    return std::nullopt;
  }

  Node* BinarySearchTree::root() const {
    return root_;
  }

  // вспомогательные методы

  void BinarySearchTree::insert(int key, int value, Node*& node) {
    // Write your code here ...
    if (node == nullptr) {
      node = new Node(key,value);
      return;
    } else if (key < node->key) {
      insert(key,value,node->left);
      return;
    } else if (key > node->key) {
      insert(key, value, node->right);
      return;
    } else if (node->key == key) {
      node->value = value;
    }

  }

  bool BinarySearchTree::remove(int key, Node*& node) {
    // Write your code here...
    if (node == nullptr) {
      return false;
    }
    if (key < node->key) {
      remove(key, node->left);
    } else if (key > node->key) {
      remove(key, node->right);
    } else if (key == node->key) {
      if (node->left == nullptr && node->right == nullptr) {
        delete node;
        node = nullptr;
        return true;
      } else if (node->left != nullptr && node->right != nullptr) {
        Node* n = find_min(node->right);
        node->key = n->key;
        node->value = n->value;
        remove(n->key, node->right);
      } else if (node->left != nullptr) {
        node = node->left;
        return true;
      } else if (node->right != nullptr) {
        node = node->right;
        return true;
      }
    }
  }

  void BinarySearchTree::clear(Node* node) {
    // Write your code here...
    if (node == nullptr) {
      return;
    }
    clear(node->left);
    clear(node->right);
    delete node;
  }

  Node* BinarySearchTree::find(int key, Node* node) const {
    // Write your code here...
    if (node == nullptr) {
      return nullptr;
    } else if (key < node->key) {
      return find(key, node->left);
    } else if (key > node->key) {
      return find(key, node->right);
    } else {
      return node;
    }
  }

  Node* BinarySearchTree::find_min(Node* node) const {
    // Write your code here...
    if (node == nullptr) {
      return nullptr;
    }

    while (node->left != nullptr){
      node = node->left;
    }
    return node;

  }

  Node* BinarySearchTree::find_max(Node* node) const {
    // Write your code here...
    if (node == nullptr) {
      return nullptr;
    }
    while (node->right != nullptr) {
      node = node->right;
    }
    return node;
  }

}  // namespace assignment