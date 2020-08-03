#include <bits/stdc++.h>

using namespace std;

void decending(int n)
{
        if (n <= 0)
        {
                return;
        }
        cout << n << endl;
        decending(n - 1);
}

int exponent(int base, int pow)
{
        if (pow == 0)
                return 1;
        if (pow == 1)
                return base;

        return base * exponent(base, pow - 1);
}

bool perm(string &s, int i, int f)
{
        if (i < f)
        {
                if (s[i] == s[f])
                        return perm(s, i + 1, f - 1);
                else
                        return false;
        }
        else
        {
                return true;
        }
}

int fibonacci(int n)
{
        vector<int> cache(n + 1);
        if (n <= 2)
                return 1;
        if (cache[n] <= 0)
                cache[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return cache[n];
}

bool search(int arr[], int sz, int n)
{
        for (int i = 0; i < sz; i++)
        {
                if (arr[i] == n)
                        return true;
        }
        return false;
}

bool searchRecursive(string str, int i, int f, char c)
{
        if (i < f)
                return false;
        if (str[i] == c)
                return true;
        return searchRecursive(str, i + 1, f - 1, c);
}

void reverse(string &s, int left, int right)
{
        if (left >= right)
                return;
        swap(s[left], s[right]);
        reverse(s, left + 1, right - 1);
}

void Hanoi(int disks, char source, char destination, char aux)
{
        if (disks < 1)
        {
                return;
        }
        else
        {
                Hanoi(disks - 1, source, aux, destination);
                cout << "Move disk " << disks << " from " << source << " to " << destination << endl;
                Hanoi(disks - 1, aux, destination, source);
        }
}

// int superDigit(string n, int k) {

// }

// int summation(int n)
// {
//         if (n < 10)
//                 return n;
//         if (n >= 10)
//                 n = (n % 10) + summation(n / 10);
//         summation(n);
// }

int summation(unsigned long long int n)
{
        if (n < 10)
                return n;
        n = (n % 10) + summation(n / 10);
        return summation(n);
}

// Complete the superDigit function below.
int superDigit(string n, int k)
{
        string str = "";
        for (int i = 0; i < k; i++)
        {
                str += n;
        }
        cout << str << endl;
        stringstream s(str);
        unsigned long long int x;
        s >> x;
        cout << x << endl;
        return summation(x);
}

bool isPalindrome(string s, int first, int last)
{
        if (first == last)
                return true;
        if (s[first] != s[last])
                return false;

        isPalindrome(s, first + 1, last - 1);
}

int stepPerms(int n)
{
        map<int, int> cache;
        if (n < 0)
                return 0;
        if (n == 0)
                return 1;
        if (n == 2)
                return 2;
        if (n == 3)
                return 4;

        if (!cache[n])
        {
                cache[n] = (stepPerms(n - 1) +
                            stepPerms(n - 2) +
                            stepPerms(n - 3)) %
                           10000000007;
        }
        return cache[n];
}

/*
*  This program counts the size of "blobs" in a 2-D array.  The
 * program uses a recursive function blockCheck, which takes as
 * parameter a grid cell and computes and returns how many cell are
 * filled around it. The program calls this function for each cell in
 * the grid.
*/

enum class State
{
        Empty = 0,
        Filled,
        Marked
};

// blobber represent our first test case
vector<vector<State>> blobber = {
    {State::Filled, State::Empty, State::Filled},
    {State::Filled, State::Filled, State::Empty},
    {State::Empty, State::Filled, State::Empty},
};

bool outsideGrid(vector<vector<State>> grid, int row, int column)
{
        return ((row > grid[0].size() - 1 && row < 0) || (column > grid[0].size() - 1 && column < 0));
}
/* 
      *Returns the size of the blob containing the grid cell specified 
     * by the paramaters.  The function is called recursively because 
     * each square that is filled must look at each square around it 
     * to see if it is filled.  The base cases are: unfilled square, a 
     * square with something other than the filled value, or location 
     * out of bounds. 
*/
int blobCheck(vector<vector<State>> grid, int row, int column)
{
        // base case
        if (outsideGrid(grid, row, column))
                return 0;
        if (grid[row][column] != State::Filled)
                return 0;
        // the current grid[row][column] is filled so marked

        grid[row][column] = State::Marked;
        int count = 1;
        for (int i = -1; i <= 1; i++)
                for (int j = -1; j <= 1; j++)
                {
                        if (i == 0 && j == 0)
                                continue;
                        count += blobCheck(grid, row + i, column + j);
                }
}

int power_using_divide_conquer(int base, int exp)
{
        if (exp == 0)
                return 1;
        if (exp % 2 == 0)
                return power_using_divide_conquer(base, exp / 2) * power_using_divide_conquer(base, exp / 2);
        return power_using_divide_conquer(base, exp / 2) * power_using_divide_conquer(base, exp / 2) * base;
}

int maxSubsetSum(vector<int> arr, int first, int last)
{
        int mid = (first + last) / 2;
        int left_sum = 0;
        int right_sum = 0;
        if (first == last)
                return arr[first];
        left_sum += maxSubsetSum(arr, first, mid);
        right_sum += maxSubsetSum(arr, mid + 1, last);
        return left_sum + right_sum;
}

int maxValue(vector<int> &arr, int start, int stop)
{
        int left, right;

        if (start == stop)
                return arr[start];
        left = maxValue(arr, start, (start + stop) / 2);
        right = maxValue(arr, (start + stop) / 2 + 1, stop);
        return max(left, right);
}

int maxArraySum(vector<int> arr, int step)
{
        int max_sum = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
                maxArraySum(arr,step);
        }
        
}
int main(int argc, char const *argv[])
{
        vector<int> v = {-2, 1, 3, 4, 5};
        cout << maxArraySum(v) << endl;
        return 0;
}
