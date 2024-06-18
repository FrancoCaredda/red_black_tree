#include "red_black_tree.h"


#include <vector>

int main(int argc, char** argv)
{
    RedBlackTree<int> tree;

    std::vector<int> arr = { 4, 2, 3, 0, 6, 1, 5, 13, 10, 100, 7 };

    for (const int val : arr)
    {
        tree.Insert(val);
    }

    RedBlackTreeHelper::PrintTreeAsList(tree);

    tree.Bypass([](int value) {
        std::cout << value << " ";
    });

    std::cout << "\n" << std::boolalpha
        << "Does the tree contain the number 5: " << tree.Contains(5) << "\n"
        << "Does the tree contain the number 10: " << tree.Contains(10) << std::endl;

    return 0;
}