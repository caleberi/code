#include <vector>
#include <iostream>
using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST
{
public:
	int value;
	BST *left;
	BST *right;

	BST(int val)
	{
		value = val;
		left = NULL;
		right = NULL;
	}
	BST &insert_iter(int val)
	{
		BST *current = this;
		while (true)
		{
			if (val < current->value)
			{
				if (current->left == NULL)
				{
					BST *n_tree{new BST{val}};
					current->left = n_tree;
					break;
				}
				else
				{
					current = current->left;
				}
			}
			else
			{
				if (current->right == NULL)
				{
					BST *n_tree{new BST{val}};
					current->right = n_tree;
					break;
				}
				else
				{
					current = current->right;
				}
			}
		}

		return *this;
	};

	bool contains_iter(int val)
	{
		BST *current = this;
		while (current != NULL)
		{
			if (val < current->value)
			{
				current = current->left;
			}
			else if (val > current->value)
			{
				current = current->right;
			}
			else
			{
				return true;
			}
		}
		return false;
	}

	BST &remove_iter(int val, BST *parent = NULL)
	{
		BST *current = this;
		while (current != NULL)
		{
			if (val < current->value)
			{
				parent = current;
				current = current->left;
			}
			else if (val > current->value)
			{
				parent = current;
				current = current->right;
			}
			else
			{
				// case1 : with two node
				// case2 :with one node
				if (current->left != NULL and current->right != NULL)
				{
					current->value = current->right->getMinValue();
					current->right->remove(current->value, current);
				}
				else if (parent == NULL)
				{
					if (current->left != NULL)
					{
						current->value = current->left->value;
						current->right = current->left->right;
						current->left = current->left->left;
					}
					else if (current->right != NULL)
					{
						current->value = current->left->value;
						current->left = current->right->left;
						current->right = current->right->left;
					}
					else
					{
					}
				}
				else if (parent->left == current)
				{
					parent->left = left != NULL ? left : right;
				}
				else if (parent->right == current)
				{
					parent->right = left != NULL ? left : right;
				}
			}
		}
	}

	BST &insert(int val)
	{
		// Write your code here.
		// Do not edit the return statement of this method.
		//
		if (val < value)
		{
			if (left == NULL)
			{
				BST *n_tree{new BST(val)};
				left = n_tree;
			}
			else
			{
				left->insert(val);
			}
		}
		else
		{
			if (right == NULL)
			{
				BST *n_tree{new BST(val)};
				right = n_tree;
			}
			else
			{
				right->insert(val);
			}
		}
		return *this;
	}

	bool contains(int val)
	{
		if (val > value)
		{
			if (right == NULL)
				return false;
			else
				return right->contains(val);
		}
		else if (val < value)
		{
			if (left == NULL)
				return false;
			else
				return left->contains(val);
		}
		else
		{
			return true;
		}
	}

	BST &remove(int val, BST *parent = NULL)
	{
		// Write your code here.
		// Do not edit the return statement of this method.
		if (val < value)
		{
			if (left != NULL)
			{
				left->remove(val, this);
			}
		}
		else if (val > value)
		{
			if (right != NULL)
			{
				right->remove(val, this);
			}
		}
		else
		{
			if (left != NULL && right != NULL)
			{
				value = right->getMinValue();
				right->remove(value, this);
			}
			else if (parent == NULL)
			{
				if (left != NULL)
				{
					value = left->value;
					right = left->right;
					left = left->left;
				}
				else if (right != NULL)
				{
					value = right->value;
					right = right->right;
					left = right->left;
				}
				else
				{
					// sngle node do nothiing
				}
			}
			else if (parent->left == this)
			{
				parent->left = left != NULL ? left : right;
			}
			else if (parent->right == this)
			{
				parent->right = left != NULL ? left : right;
			}
		}
		return *this;
	}

	int getMinValue()
	{
		if (left == NULL)
		{
			return value;
		}
		else
		{
			return left->getMinValue();
		}
	}
};

// bool validateBst(BST *tree, BST *l = NULL, BST *r = NULL)
// {
// 	if (tree == NULL)
// 		return true;
// 	if (l != NULL && tree->value < l->value)
// 		return false;
// 	if (r != NULL && tree->value >= r->value)
// 		return false;
// 	return validateBst(tree->left, l, tree) && validateBst(tree->right, tree, r);
// }

int main(int argc, char const *argv[])
{
	BST Tree(10);
	Tree.insert(15).insert(22).insert(5).insert(5).insert(11).insert(2).insert(1);
	// Tree.contains_iter(12);
	// Tree.remove(5);

	return 0;
}
