#include "Generator.h"
#include "Tree.h"
#include "Util.h"
#include "Heap.h"


int main() {
    int n;
    std::string path;
    std::cout << "n = ";
    std::cin >> n;
    LinearCongruentialGenerator generator(n);
    std::cout << "Please enter the name of the config file [format name.txt]  ";
    std::cin >> path;
    generator.start_generator(path);
    std::cout << "The output of random numbers: ";
    generator.print();
    std::cout << std::endl;

    BinarySearchTree tree;
    tree.create_tree(generator.get_randomNumbers());
    std::cout << "The output of the tree : \n";
    Node* p = tree.get_root();
    Util::printTree(p);
    std::cout << std::endl;
    std::cout << "The output of the tree(inorder): \n";
    tree.inorder();
    std::cout << std::endl;

    Heap heap(generator.get_randomNumbers());
    std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
    heap.heapsort();
    return 0;
}