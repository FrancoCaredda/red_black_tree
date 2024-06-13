#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE

#include <cinttypes>
#include <functional>

enum class NodeColor : uint8_t
{
    RED = 0,
    BLACK = 1
};

template<typename T>
struct Node
{
    Node(T _data, NodeColor _color = NodeColor::BLACK)
        : data(_data), color(_color) {}

    T data;
    NodeColor color;
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;
    Node<T>* parent = nullptr;
};

template<typename T>
class RedBlackTree
{
public:
    RedBlackTree() = default;

    void Insert(T value)
    {
        if (!m_Root)
        {
            m_Root = new Node<T>(value);
            return;
        }

        InsertInternal(value, m_Root);
    }

    bool Search(T value) const
    {
        return false;
    }

    void Delete(T value)
    {}

    void Bypass(const std::function<void(T)>& callback)
    {
        BypassInternal(callback, m_Root);
    }

    ~RedBlackTree()
    {
        CleanUp(m_Root);
    }

    friend class RedBlackTreeHelper;
private:
    void InsertInternal(T value, Node<T>* root)
    {
        if (value >= root->data)
        {
            if (!root->right)
            {
                root->right = new Node<T>(value, NodeColor::RED);
                root->right->parent = root;

                return;
            }
            
            InsertInternal(value, root->right);
            return;
        }

        if (!root->left)
        {
            root->left = new Node<T>(value, NodeColor::RED);
            root->left->parent = root;

            return;
        }

        InsertInternal(value, root->left);
    }

    void BypassInternal(const std::function<void(T)>& callback, Node<T>* root)
    {
        if (!root)
            return;

        BypassInternal(callback, root->left);
        callback(root->data);
        BypassInternal(callback, root->right);
    }

    void CleanUp(Node<T>* root)
    {
        if (!root)
            return;

        Node<T>* left = root->left;
        Node<T>* right = root->right;

        CleanUp(left);
        delete root;
        CleanUp(right);
    }

    void LeftRotate(Node<T>* node)
    {
        Node<T>* y = node->right;

        if (y == nullptr)
            return;
        
        node->right = y->left;

        if (y->left != nullptr)
            y->left->parent = node;

        y->parent = node->parent;
        if (node->parent == nullptr)
            m_Root = y;
        else if (IsLeftChild(node))
            node->parent->left = y;
        else
            node->parent->right = y;

        y->left = node;
        node->parent = y;
    }

    void RightRotate(Node<T>* node)
    {
        Node<T>* y = node->left;

        if (y == nullptr)
            return;

        node->left = y->right;

        if (y->right != nullptr)
            y->right->parent = node;

        y->parent = node->parent;
        if (node->parent == nullptr)
            m_Root = y;
        else if (IsLeftChild(node))
            node->parent->left = y;
        else
            node->parent->right = y;

        y->right = node;
        node->parent = y;
    }

    inline bool IsRed(const Node<T>* const node) const noexcept 
    { return node != nullptr && node->color == NodeColor::RED; }

    inline bool IsRightChild(const Node<T>* const node) const noexcept
    { return node->parent->right == node; }

    inline bool IsLeftChild(const Node<T>* const node) const noexcept
    { return node->parent->left == node; }

    Node<T>* GetUncle(Node<T>* node) const noexcept
    {
        if (node->parent == nullptr || 
            node->parent->parent == nullptr)
            return nullptr;

        Node<T>* parent = node->parent;
        Node<T>* grandParent = parent->parent;

        if (grandParent->left == parent)
            return grandParent->right;

        return grandParent->left;
    }
private:
    Node<T>* m_Root = nullptr;
};


class RedBlackTreeHelper final
{
public:
    template<typename T>
    static void PrintTree(const RedBlackTree<T>& tree)
    {
        Node<T>* currentNode = tree.m_Root;

        std::cout << "[" << currentNode->data << ", " << (int)currentNode->color << "]\n";
        PrintSubtree(currentNode->left, 1, 'l');
        PrintSubtree(currentNode->right, 1, 'r');
    }
private:
    template<typename T>
    static void PrintSubtree(Node<T>* node, int level, char side)
    {
        if (node == nullptr)
            return;

        for (int i = 0; i < level - 1; i++)
            std::cout << "     ";

        std::cout << "|--> [" << node->data << ", " << (int)node->color << ", " << side << "]\n";

        PrintSubtree(node->left, level + 1, 'l');
        PrintSubtree(node->right, level + 1, 'r');
    }
};
    
#endif