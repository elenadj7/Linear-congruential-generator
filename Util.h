//
// Created by elena
//

#ifndef LINEAR_CONGRUENTIAL_GENERATOR_UTIL_H
#define LINEAR_CONGRUENTIAL_GENERATOR_UTIL_H

#include <string>
#include <iostream>
#include "Tree.h"

namespace Util {
    void printTree(const std::string& string, const Node* root, bool isLeft);

    void printTree(const Node* node);

    void delete_tree(Node* root);
}

#endif
