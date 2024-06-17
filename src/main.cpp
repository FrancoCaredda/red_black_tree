#include "red_black_tree.h"

#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
    RedBlackTree<int> tree;

    std::vector<int> arr = { 10, 9, 8, 7, 6, 5, 4, 3 };

    for (const int val : arr)
    {
        tree.Insert(val);
        RedBlackTreeHelper::PrintTree(tree);

        std::cout << "\n";
    }

    tree.Bypass([](int value) {
        std::cout << value << " ";
    });

    return 0;
}