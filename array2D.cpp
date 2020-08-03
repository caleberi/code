#include <bits/stdc++.h>

using namespace std;
int max(vector<int> v)
{
        int maximum = INT32_MIN;
        for (int i = 0; i < v.size(); i++)
        {
                if (static_cast<int>(v[i]) > maximum)
                        maximum = v[i];
        }
        return maximum;
}
int hourglassSum(vector<vector<int>> arr)
{
        vector<int> res;
        int n = arr.size();
        int tl, tm, tr, ctr, bl, bm, br;

        for (int i = 0; i < n - 2; i++)
        {
                for (int j = 0; j < n - 2; j++)
                {
                        tl = arr[j][i];
                        tm = arr[j][i + 1];
                        tr = arr[j][i + 2];
                        ctr = arr[j + 1][i + 1];
                        bl = arr[j + 2][i];
                        bm = arr[j + 2][i + 1];
                        br = arr[j + 2][i + 2];
                        cout << tl << " " << tm << " " << tr << " "
                             << "\n";
                        cout << " "
                             << " " << ctr << " "
                             << " "
                             << "\n";
                        cout << bl << " " << bm << " " << br << " "
                             << "\n";
                        cout << endl;
                        int sum = tm + tr + tl + ctr + bl + bm + br;
                        res.push_back(sum);
                }
        }

        return max(res);
}

int main(int argc, const char **argv)
{
        return 0;
}