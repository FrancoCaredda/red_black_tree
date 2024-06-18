# Red-black Tree
This repository was created for the learning purposes.  
A custom implementation of the Red-Black Tree data structure.

## About
This library was created for the learning purposes by following a tutorial on [GeeksForGeeks about the Red-Black Tree](https://www.geeksforgeeks.org/introduction-to-red-black-tree/).  
The Red-Black Tree is a type of BST that is auto-balanced.

## Algorithms
The red-black tree ensures that all the main operations such as: insertion, deletion and searching are perfomed with 
O(log n) complexity.  
To make this possible, after each insertion or deletion the tree has to be checked on violations and in case they are present, the tree has to be rebalanced. The red-black tree is a superset of the AVL-tree which means that the balancing is performed by the rotation operations. The red-black tree also provides a new operation called recoloring. Each node is either red or black and there are some related properties.

Properties of the red-black tree:  
1. Each node is either black or red;
2. The root node is always black;
3. Red nodes can only have black nodes;
4. All leaves are black and called NIL's;
5. The amount of black nodes from the root node to any NIL node is the same.

If a tree satisfies all the properties, than this tree is a red-black tree.

Read more about the implementation of the basic operations:  
* [Insertion](https://www.geeksforgeeks.org/insertion-in-red-black-tree/);
* [Deletion](https://www.geeksforgeeks.org/insertion-in-red-black-tree/);
* [Searching](https://www.geeksforgeeks.org/introduction-to-red-black-tree/#3-searching).

## How to use
> WARNING: This code shouldn't be used in production.  
> The data structure is not optimised because for each call of the Insert/Delete methods, new/delete operators are called.
> Instead use the STL's std::map container

```C++
void RedBlackTree<T>::Insert(T value); // Inserts a value into the tree
void RedBlackTree<T>::Delete(T value); // Deletes the value from the tree
bool RedBlackTree<T>::Contains(T value); // Checks if the value exists in the container
void RedBlackTree<T>::Bypass(const std::function<void(T)>& callback); // Travels around the tree using the inner-bypassing algorithm. The callback function is called on each node of the tree 
```