#include <bits/stdc++.h>
using namespace std;
ifstream in("data.in");
ofstream out("data.out");
vector<int> arr;
vector<int> appearance(vector<int> items)
{
        int n = items.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++)
        {
                if (items[i] == i)
                        res[i]+=1;
        }
        return res;
}

int main(int argc, char **argv)
{
        int n;
        in >> n;
        for (int i = 0; i < n; i++)
        {
                int x;
                in >> x;
                arr.push_back(x);
        }

        vector<int> res = appearance(arr);
        for (auto &a : res)
        {
                cout << a << endl;
        }
}