#include "red_black_tree.h"

#include <iostream>

int main(int argc, char** argv)
{
    RedBlackTree<int> tree;

    tree.Insert(4);
    tree.Insert(2);
    tree.Insert(1);
    tree.Insert(3);
    tree.Insert(6);
    tree.Insert(5);
    tree.Insert(8);
    tree.Insert(7);
    tree.Insert(9);

    tree.Bypass([](int value) {
        std::cout << value << " ";
    });

    return 0;
}