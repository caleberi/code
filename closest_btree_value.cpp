#include <bits/stdc++.h>

using namespace std;
class Tree
{
public:
        int value;
        Tree *left;
        Tree *right;
};

int FindClosestValueInBstHelper(Tree *t, int target, int closest)
{
        if (t == nullptr)
                return closest;
        if (abs(target - closest) > abs(target - t->value))
                closest = t->value;
        if (target < t->value)
                return FindClosestValueInBstHelper(t->left, target, closest);
        else if (target > t->value)
                return FindClosestValueInBstHelper(t->right, target, closest);
        else
                return closest;
};

int FindClosestValueInBst(Tree *t, int target)
{
        return FindClosestValueInBstHelper(t, target, INT_MIN);
};

int sherlockAndAnagrams(string s)
{
        int lstr = s.length() - 1;
        int fstr = 0;
        int count = 0;
        while (fstr <= lstr)
        {
                string left = s.substr(fstr);
                string right = s.substr(lstr);
                if (left == right)
                        count++;
                lstr--;
                fstr++;
        }
        return count;
}

int main(int argc, char const *argv[])
{
        string s = "mom";
        cout << sherlockAndAnagrams(s) << endl;
        return 0;
}
