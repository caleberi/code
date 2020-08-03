#include <bits/stdc++.h>

using namespace std;

int fibonacci_memorization(int n)
{
        vector<int> cache(n + 1);
        if (n < 2)
                return n;
        if (cache[n] != 0)
                return cache[n];
        cache[n] = fibonacci_memorization(n - 1) + fibonacci_memorization(n - 2);
        return cache[n];
}

int fibonacci_tabulation(int n)
{
        if (n == 0)
                return 0;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
                dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
}

bool canPartitionRecursive(const vector<int> &num, int sum, int idx)
{
        if (sum == 0)
        {
                return true;
        }
        if (num.empty() || idx >= num.size())
                return false;
        if (num[idx] <= sum)
        {
                if (canPartitionRecursive(num, sum - num[idx], idx + 1))
                        return true;
        }
        return canPartitionRecursive(num, sum, idx + 1);
}

bool canPartition(const vector<int> &arr)
{
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
                sum += arr[i];
        }
        if (sum % 2 != 0)
                return false;
        return canPartitionRecursive(arr, sum / 2, 0);
}

int KnapSackRecursive(const vector<int> &profits, const vector<int> &weight, int capacity, int idx)
{
        if (capacity <= 0 || idx >= profits.size())
                return 0;
        int profit_sum = 0;
        if (weight[idx] <= capacity)
        {
                profit_sum = profits[idx] + KnapSackRecursive(profits, weight, capacity - weight[idx], idx + 1);
        }
        int profit_sum_two = KnapSackRecursive(profits, weight, capacity, idx + 1);
        return max(profit_sum, profit_sum_two);
}

int KnapSack(const vector<int> &profits, const vector<int> &weight, int capacity)
{
        return KnapSackRecursive(profits, weight, capacity, 0);
}

int maxSubsetSumRecursive(const vector<int> &arr, int fidx, int sum)
{ //{1,2,3,4,5}=>135

        if (fidx <= arr.size())
        {
                return arr[fidx];
        }
};

int maxSubsetSum(const vector<int> &arr)
{
        if (arr.empty())
                return 0;
        if (arr.size() == 1 || arr.size() == 2)
        {
                return arr[0];
        }
        int sum = 0;
        return maxSubsetSumRecursive(arr, 0, sum);
}

struct Point
{
        int row;
        int col;
        Point(int row, int col) : row{row}, col{col} {};
};

bool is_valid(vector<vector<int>> map, Point &pos)
{
        if (pos.row < 0 || pos.row >= map.size())
                return false;
        if (pos.col < 0 || pos.col >= map.size())
                return false;
        if (map[pos.col][pos.row] != 0)
                return false;
        return true;
}

bool arrived(Point &pos, Point target)
{
        return pos.row == target.row && pos.col == target.col;
}
bool path_finder(vector<vector<int>> map, Point &pos, Point &target, vector<Point> &path)
{
        if (arrived(pos, target))
                return true;
        Point down = {pos.row + 1, pos.col};
        Point right = {pos.row, pos.col + 1};
        if (is_valid(map, down))
        { // check right if next cell is open
                bool found = path_finder(map, down, target, path);
                if (found)
                {
                        path.push_back(down);
                        return true;
                }
        }
        if (is_valid(map, right))
        { // check right if next cell is open
                bool found = path_finder(map, right, target, path);
                if (found)
                {
                        path.push_back(right);
                        return true;
                }
        }

        return false;
}

void test_pathFinder()
{
        vector<vector<int>> map = {
            {0, 0, 1, 0, 0},
            {1, 0, 0, 1, 0},
            {0, 1, 0, 0, 1},
            {0, 1, 0, 1, 0},
            {0, 0, 0, 0, 0},
        };
        Point str(0, 0);
        Point target(4, 4);
        vector<Point> path;
        bool found = path_finder(map, str, target, path);
        if (found)
        {
                for (int i = path.size() - 1; i >= 0; i--)
                {
                        cout << "[" << path[i].row << "][" << path[i].col << "]  -> ";
                }
                cout << endl;
        }
        else
        {
                cout << "no available path" << endl;
        }
}

int magic_index_recursive(vector<int> arr, int idx)
{
        if (idx == arr.size())
                return -1;
        if (arr[idx] == idx)
                return idx;
        return magic_index_recursive(arr, idx + 1);
}
int magic_index(vector<int> arr)
{
        if (arr.size() == 0)
                return -1;
        if (arr[0] == 0)
                return 0;
        return magic_index_recursive(arr, 0);
}

int multiply_recursively(int x, int y, int sum, int count)
{
        if (count == y)
                return sum;
        sum += x;
        return multiply_recursively(x, y, sum, count + 1);
}

int multipy(int x, int y)
{
        return multiply_recursively(x, y, 0, 0);
}

void not_unique_permutations_recursive(string str, int fidx, int lidx, vector<string> &store)
{
        int i;
        if (fidx == lidx)
        {
                store.push_back(str);
                return;
        }
        else
        {
                for (i = fidx; i <= lidx; i++)
                {
                        swap(str[fidx], str[i]);
                        not_unique_permutations_recursive(str, fidx + 1, lidx, store);
                        swap(str[fidx], str[i]);
                }
        }
}
void not_unique_permutations_recursive(vector<int> str, int fidx, int lidx, vector<vector<int>> &store)
{
        int i;
        if (fidx == lidx)
        {
                store.push_back(str);
                return;
        }
        else
        {
                for (i = fidx; i <= lidx; i++)
                {
                        swap(str[fidx], str[i]);
                        not_unique_permutations_recursive(str, fidx + 1, lidx, store);
                        swap(str[fidx], str[i]);
                }
        }
}
vector<vector<int>> not_unique_permutations(vector<int> str, int fidx, int lidx)
{
        vector<vector<int>> store;
        not_unique_permutations_recursive(str, fidx, lidx, store);
        return store;
}

int main(int argc, char const *argv[])
{
        vector<vector<int>> list = not_unique_permutations({1, 2, 3, 4, 5}, 0, 4);
        for (auto &itr : list)
        {
                cout << "{" ;
                for (auto it : itr)
                {
                        cout << it << ",";
                }
                cout << "} " << endl;
        }
        cout << endl;
        return 0;
}
