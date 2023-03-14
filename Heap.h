//
// Created by elena
//

#ifndef LINEAR_CONGRUENTIAL_GENERATOR_HEAP_H
#define LINEAR_CONGRUENTIAL_GENERATOR_HEAP_H

#include "Generator.h"
#include "Tree.h"
#include "Util.h"

class Heap final {
private:
    std::vector<Id> heap;
    Node* root{};
public:
    Heap(std::vector<Id> vec);
    void print()noexcept;
    void create_heap()noexcept;
    void create_tree()noexcept;
    Node* get_root()noexcept;
    void delete_tree()noexcept;
    void heapsort()noexcept;
private:
    void heapify(std::size_t i)noexcept;
    Node* create_tree_recursive(Node* node, std::size_t index)noexcept;
};

#endif
