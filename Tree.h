//
// Created by elena
//

#ifndef LINEAR_CONGRUENTIAL_GENERATOR_TREE_H
#define LINEAR_CONGRUENTIAL_GENERATOR_TREE_H

#include <stack>
#include <queue>
#include "Generator.h"


struct Node {
    Id id;
    Node* left, * right;
    explicit Node(Id id) : id(id), left(nullptr), right(nullptr) {}
};


class BinarySearchTree final {
private:
    Node* root{};
public:
    BinarySearchTree() = default;
    void create_tree(std::vector<Id> numbers)noexcept;
    void inorder()const noexcept;

    [[nodiscard]] Node* get_root()const noexcept;
private:
    void add(const Id& id)noexcept;
};
#endif
