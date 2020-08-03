#include <bits/stdc++.h>

using namespace std;

void rotate(vector<vector<int>> a)
{
        int n = a.size();
        vector<vector<int>> res;
        int rotation = 0;
        while (rotation < n - 1)
        {
                vector<vector<int>> rotation_matrix(n, vector<int>());
                for (int i = 0; i < a.size(); i++)
                {
                        for (int j = 0; j < a.size(); j++)
                        {
                                rotation_matrix[j].push_back(a[i][a.size() - j - 1]);
                        }
                }
                for (int i = 0; i < rotation_matrix.size(); i++)
                {
                        for (int j = 0; j < rotation_matrix.size(); j++)
                        {
                                a[i][j] = rotation_matrix[i][j];
                        }
                }
                for (auto h : a)
                {
                        for (auto u : h)
                        {
                                cout << u << " ";
                        }
                        cout << endl;
                }
                cout << "================================" << endl;
                rotation++;
        }
        for (auto h : a)
        {
                for (auto u : h)
                {
                        cout << u << " ";
                }
                cout << endl;
        }
        cout << "================================" << endl;
}

int main(int argc, char const *argv[])
{
        vector<vector<int>> g = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
            };
        rotate(g);
        return 0;
}
