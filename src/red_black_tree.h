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

    void FixViolations()
    {

    }
private:
    Node<T>* m_Root = nullptr;
};

#endif