#include <iostream>
#include <bits/stdc++.h>

/*
 *  give by M which is the sum of each row
 *  1+2+3 = M
 *  4+5+6 = M
 *  7+8+9 = M
 *  3M = 45  so each row must sum to 45 and also the  column
 * M = 15 (magic constant)
        | 1 | 2 | 3 |
        | 4 | 5 | 6 |  there are only 2 diagonal , 1 center,4 corners(even), edges(odd)
        | 7 | 8 | 9 |
  *
  * pick the element row by row to sum up to 15
  * 1 + 2+ 12 =15 but 12 is greater than s[i][j] <= 9 so it won't work
  * 1 + 5+9 =15, ->diagonal 
  * 1+ 6+8=15,
  * 2+4+9=15,
  * 2+5+8=15,
  * 2+6+7 =15,
  * 3+4+8=15,
  * 3+5+7=15,
  * 4+5+6=15,
  * 
  * the center square is involved in 4 combinations
  * corner is involved in 3 combinations
  * edges  is involved in 2 combinations
*/

bool is_magic_Square(std::vector<int> v)
{
        int a[3][3];
        // convert to a 3*3 matrix
        for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                        a[i][j] = v[3 * i + j]; // when i=0 j=0,1,2 v[0,1,2]
                                                // when i=1 j=0,1,2 v[3,4,5]
                                                // when i=2 j=0,1,2  v[6,7,8]

        int s = 0;
        for (int j = 0; j < 3; ++j)
                s += a[0][j]; // a[0][j ... 2] first row

        // check if the sum of 1-2 rows are all same proofing 3M
        for (int i = 0; i <= 2; ++i)
        {
                int temp = 0;
                for (int j = 0; j < 3; ++j)
                        temp += a[i][j];
                if (temp != s)
                        return false; // quit
        }
        // check if the sum of 0-2 columns are all same proofing 3M
        for (int j = 0; j < 3; ++j)
        {
                int temp = 0;
                for (int i = 0; i < 3; ++i)
                        temp += a[i][j]; // a[0][0] ,a[0][1] ,a[0][2]
                if (temp != s)
                        return false; // quit
        }

        int temp = 0; // diagonal[1] sum
        for (int i = 0; i < 3; ++i)
                temp += a[i][i]; // a[0][0],a[1][1],a[2][2]
        if (temp != s)
                return false;

        temp = 0; // diagonal[2] sum
        for (int i = 0; i < 3; ++i)
                // temp += a[i][2 - i];  a[2][0],a[1][1],a[0][2]
                temp += a[2 - i][i];
        if (temp != s)
                return false;

        return true;
}

void find_magic_squares(std::vector<std::vector<int>> &magic_squares)
{
        std::vector<int> v(9);
        for (int i = 0; i < 9; i++)
                //      | 1 | 2 | 3 |
                //      | 4 | 5 | 6 |
                //     | 7 | 8 | 9 |
                v[i] = i + 1; // forms the square above
        //peform all permutation of the square
        do
        {
                if (is_magic_Square(v))
                {
                        magic_squares.push_back(v);
                }
        } while (next_permutation(v.begin(), v.end()));
}

//return sum of difference between each element of the two vector
int diff(std::vector<int> a, std::vector<int> b)
{
        int res = 0;
        for (int i = 0; i < 9; i++)
                res += std::abs(a[i] - b[i]);
        return res;
}

int wrapper(std::vector<int> v)
{

        int res = INT_MAX;
        std::vector<std::vector<int>> magic_squares;
        // generate all magic square
        find_magic_squares(magic_squares);
        for (int i = 0; i < magic_squares.size(); ++i)
                // finding the difference with each magic square and assigning the minimum value
                res = std::min(res, diff(v, magic_squares[i]));
        return res;
}

std::vector<int> convert(std::vector<std::vector<int>> &v)
{
        std::vector<int> a(9);
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        a.push_back(v[i][j]);
                }
        }

        return a;
};

int main(int argc, char const *argv[])
{
        // taking the matrix in the vector rowwise to make calculation easy
        std::vector<int> v;
        v.push_back(5);
        v.push_back(3);
        v.push_back(4);
        v.push_back(1);
        v.push_back(5);
        v.push_back(8);
        v.push_back(6);
        v.push_back(4);
        v.push_back(2);
        std::cout << "minimum cost : " << wrapper(convert(v)) << std::endl;
        return 0;
}
