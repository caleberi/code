#include <bits/stdc++.h>
using namespace std;

int diagonalDifference(vector<vector<int>> arr)
{
        int d1 = 0;
        int d2 = 0;
        int n = arr[0].size();
        cout << n << endl;
        for (int i = 0; i < arr.size(); i++)
        {

                d1 += arr[i][i];
        }
        for (int i = 0; i < arr.size(); i++)
        {

                d2 += arr[n - i - 1][i];
        }
        cout << d2 << endl;

        return abs(d1 - d2);
}

int main(int argc, char const *argv[])
{

        return 0;
}
