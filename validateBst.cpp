#include <bits/stdc++.h>
using namespace std;
class BST
{
public:
        int value;
        BST *left;
        BST *right;

        BST(int val);
        BST &insert(int val);
};

bool validateBst(BST *tree, bool isValid = false)
{
        BST *current = tree;
        if (current->left == NULL && current->right == NULL)
                return isValid;
        if (
            current->left == NULL && current->right->value >= current->value)
                validateBst(current->right, true);
        if (
            current->right == NULL && current->left->value < current->value)
                validateBst(current->left, true);
        if (current->left->value < current->value && current->right->value >= current->value)
        {
                validateBst(current->right, true);
                validateBst(current->left, true);
        }

        return false;
}
