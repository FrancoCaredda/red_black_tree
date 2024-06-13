#include "red_black_tree.h"

#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
    RedBlackTree<int> tree;

    std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

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