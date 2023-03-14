//
// Created by elena
//
#include "Tree.h"

void BinarySearchTree::add(const Id& id)noexcept {
    Node* p = root;
    Node* q = nullptr;
    Node* new_node = new Node(id);
    while (p != nullptr) {
        q = p;
        if (new_node->id == p->id)
            std::cout << "Element already exists" << std::endl;
        else if (new_node->id < p->id)
            p = p->left;
        else p = p->right;
    }
    if (q == nullptr)
        root = new_node;
    else {
        if (new_node->id < q->id)
            q->left = new_node;
        else
            q->right = new_node;
    }
}

void BinarySearchTree::create_tree(std::vector<Id> numbers)noexcept {
    for (auto it : numbers) {
        add(it);
    }
}

void BinarySearchTree::inorder()const noexcept {
    std::stack<Node*> stack;
    stack.push(root);
    Node* next = root->left;
    while (!stack.empty() || next) {
        while (next != nullptr) {
            stack.push(next);
            next = next->left;
        }
        if (!stack.empty()) {
            next = stack.top();
            std::cout << next->id << " ";
            stack.pop();
            next = next->right;
        }
    }
}

Node* BinarySearchTree::get_root()const noexcept { return root; }
