#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
        if (b == 0)
                return a;
        return gcd(b, a % b);
}

int lcm(int a, int b)
{
        return a * (b / gcd(a, b));
}

int lcm_vector(vector<int> v)
{
        int res = v[0];
        for (int i = 1; i < v.size(); i++)
        {
                res = lcm(res, v[i]);
        }
        return res;
}

int gcd_vector(vector<int> v)
{
        int res = v[0];
        for (int i = 1; i < v.size(); i++)
        {
                res = gcd(res, v[i]);
        }
        return res;
}

int getTotalX(vector<int> a, vector<int> b)
{
        int count = 0;
        int f = lcm_vector(a);
        int l = gcd_vector(b);
        for (int i = f, j = 2; i <= l; i = f * j, j++)
        {
                if (l % i == 0)
                        count++;
        }
        return count;
}

int main(int argc, char const *argv[])
{
        vector<int> a = {2, 4};
        vector<int> b = {24, 36};
        cout << getTotalX(a, b) << endl;
        return 0;
}
