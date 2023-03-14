//
// Created by elena
//
#include "Heap.h"

#include <utility>

Heap::Heap(std::vector<Id> vec) : heap(std::move(vec)) {}

Node* Heap::get_root()noexcept { return root; }

void Heap::print()noexcept {
    for (std::size_t i = 0; i < heap.size(); ++i)
        std::cout << heap[i] << " ";
}

void Heap::heapify(std::size_t i)noexcept {
    std::size_t parent = i;
    std::size_t left = 2 * i + 1;
    std::size_t right = 2 * i + 2;
    if (left < heap.size() && heap[left] > heap[parent])
        parent = left;
    if (right < heap.size() && heap[right] > heap[parent])
        parent = right;
    if (i != parent) {
        auto tmp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = tmp;
        heapify(parent);
    }
}

void Heap::create_heap()noexcept {
    for (int i = (heap.size() / 2) - 1; i >= 0; --i)
        heapify(i);
}

Node* Heap::create_tree_recursive(Node *node, std::size_t index)noexcept {
    if (index < heap.size()) {
        node = new Node(heap[index]);
        node->left = create_tree_recursive(node->left, 2 * index + 1);
        node->right = create_tree_recursive(node->right, 2 * index + 2);
    }
    return node;
}

void Heap::create_tree()noexcept {
    Node* p = root;
    root = create_tree_recursive(p, 0);
}

void Heap::delete_tree()noexcept {
    Util::delete_tree(root);
}

void Heap::heapsort()noexcept {
    create_heap();
    std::vector<Id> sorted_heap;
    while (!heap.empty()) {
        sorted_heap.push_back(heap[0]);
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        std::cout << std::endl;
        std::cout << "Unsorted part: ";
        print();
        if (!heap.empty()) {
            std::cout << std::endl;
            create_tree();
            Util::printTree(root);
            Util::delete_tree(root);
        }
        std::cout << "\nSorted part: ";
        for (int i = sorted_heap.size() - 1; i >= 0; --i)
            std::cout << sorted_heap[i] << " ";
        std::cout << std::endl;
        std::cout << "--------------------------------------------------------------------------------------------\n";
        create_heap();
    }
}
