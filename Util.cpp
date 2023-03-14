//
// Created by elena
//
#include "Util.h"

void Util::printTree(const std::string& string, const Node* root, bool isLeft) {
    if (root != nullptr) {
        std::cout << string;
        std::cout << (isLeft ? "|___>" : "|--->");
        std::cout << root->id << std::endl;
        printTree(string + (isLeft ? "|    " : "    "), root->right, true);
        printTree(string + (isLeft ? "|    " : "    "), root->left, false);
    }
}

void Util::printTree(const Node* node) {
    printTree("", node, false);
}

void Util::delete_tree(Node* root) {
    if (root) {
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
    }
}
