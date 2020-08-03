#include <bits/stdc++.h>
using namespace std;
void swap(int &u, int &v)
{
        int t;
        t = u;
        u = v;
        v = t;
}
int minimum_swap(vector<int> &arr)
{
        int swap_count = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
                while (arr[i] != i + 1)  // 1-2,
                {
                        int temp = arr[i];
                        arr[i] = arr[temp - 1];
                        arr[temp - 1] = temp;
                        swap_count++;
                }
        }
        return swap_count;
}

int main(int argc, char const *argv[])
{
        vector<int> m{1, 3, 5, 2, 4, 6, 7};
        cout << minimum_swap(m) << endl;
        for (auto &a : m)
        {
                cout << a << endl;
        }
        return 0;
}
