#include <bits/stdc++.h>

using namespace std;
long max(vector<int> v)
{
        long maximum = INT32_MIN;
        for (int i = 0; i < v.size(); i++)
        {
                if (static_cast<long>(v[i]) > maximum)
                        maximum = v[i];
        }
        return maximum;
}

long arrayManipulation(int n, vector<vector<int>> queries)
{
        // create your own vector filled with 0 of n
        vector<int> res(n + 1, 0);
        int a, b, k;
        for (int j = 0; j < queries.size(); j++)
        {
                k = queries[j][2];
                b = queries[j][1];
                a = queries[j][0];

                res[a - 1] += k;
                if (b < n)
                        res[b] -= k;
        }

        long max = 0;
        long temp = 0;

        for (int i = 0; i < n; i++)
        {
                temp += res[i];
                if (temp > max)
                        max = temp;
        }

        return max;
}

int main(int argc, char const *argv[])
{

        return 0;
}
