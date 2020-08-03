#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
        int value;
        Node *left;
        Node *right;
        Node(int value)
        {
                this->value = value;
        }
};
class Tree
{
        Node *root;

public:
        enum class SearchType
        {
                depthFirst,
                breathFirst,
        };

        void insert(int value);
        void in_order_tranversal();
        void pre_order_tranversal();
        void post_order_transversal();
        Tree &max_heapify();
        Tree &min_heapify();
        Node *search(SearchType st, int value);
        Node *search(int value);
        Node *bfs(int value);
        Node *dfs(int value);
        void print(Node *node);
};
void insert_recursive(Node *next, Node *node)
{

        if (next->value >= node->value) // move left
        {
                if (next->left == nullptr)
                        next->left = node;
                insert_recursive(next->left, node);
        }
        else
        {
                if (next->right == nullptr)
                        next->right = node;
                insert_recursive(next->right, node);
        }
}
void Tree::insert(int value)
{
        Node *node{new Node(value)};
        if (root == nullptr)
                root = node;
        else if (root->value >= value) // move left
                insert_recursive(root->left, node);
        else
                insert_recursive(root->right, node);
}

Node *Tree::search(SearchType st, int value)
{
        switch (st)
        {
        case SearchType::breathFirst:
                return this->bfs(value);

        case SearchType::depthFirst:
                return this->dfs(value);

        default:
                return this->search(value);
        }
};

void print(Node *node)
{
        cout << node->value << endl;
};

void in_order_transversal_recursive(Node *node)
{
        if (node != nullptr)
        {
                in_order_transversal_recursive(node->left);
                print(node);
                in_order_transversal_recursive(node->right);
        }
};

void Tree::in_order_tranversal()
{
        in_order_transversal_recursive(this->root);
}

void post_order_transversal_recursive(Node *node)
{
        if (node != nullptr)
        {
                post_order_transversal_recursive(node->left);
                post_order_transversal_recursive(node->right);
                print(node);
        }
};

void Tree::post_order_transversal()
{
        post_order_transversal_recursive(this->root);
};

void pre_order_transversal_recursive(Node *node)
{
        if (node != nullptr)
        {
                print(node);
                pre_order_transversal_recursive(node->left);
                pre_order_transversal_recursive(node->right);
        }
};

void Tree::pre_order_tranversal()
{
        pre_order_transversal_recursive(this->root);
};

void min_heap(Node *node)
{
        if (node->left == nullptr && node->right == nullptr)
        {
                return;
        }
        if (node->left->value < node->value)
        {
                swap(node->left, node);
                min_heap(node->left);
        }
        else
        {
                swap(node->right, node);
                min_heap(node->right);
        }
}

void max_heap(Node *node)
{
        if (node->left == nullptr && node->right == nullptr)
        {
                return;
        }
        if (node->left->value > node->value)
        {
                swap(node->left, node);
                max_heap(node->left);
        }
        else
        {
                swap(node->right, node);
                max_heap(node->right);
        }
}

Tree &Tree::min_heapify()
{
        min_heap(this->root);
        return *this;
};

Tree &Tree::max_heapify()
{
        max_heap(this->root);
        return *this;
};

Node *bfs_recursive(Node *node, int value)
{
        if (node->value == value)
        {
                return node;
        }

        if (node->left)
                return bfs_recursive(node->left, value);
        if (node->right)
                return bfs_recursive(node->right, value);

        return nullptr;
}
Node *bfs_recursive(Node *node, int value)
{
        if (node->value == value)
        {
                return node;
        }

        if (node->left)
                return bfs_recursive(node->left, value);
        if (node->right)
                return bfs_recursive(node->right, value);

        return nullptr;
}
Node *Tree::bfs(int value)
{
        return bfs_recursive(root, value);
};

int main(int argc, char const *argv[])
{

        return 0;
}
