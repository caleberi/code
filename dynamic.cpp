#include <bits/stdc++.h>

using namespace std;
#define INF 999999
int stairWaysToHeaven(int n)
{
        vector<int> ways(n + 1);
        ways[0] = 1;
        ways[1] = 1;
        for (int i = 2; i < n + 1; i++)
        {
                ways[i] = ways[i - 1] + ways[i - 2];
        }

        return ways[n + 1];
}

int onTheWayHome(int m, int n)
{
        int ways[m][n];
        for (int i = 0; i <= m - 1; i++)
                ways[i][n - 1] = 1;
        for (int j = 0; j <= n - 1; j++)
                ways[m - 1][j] = 1;

        for (int i = m - 2; i >= 0; i--)
                for (int j = n - 2; j >= 0; j--)
                        ways[i][j] = ways[i][j + 1] + ways[i + 1][j];

        return ways[0][0];
}

int RodCutter(vector<int> cost, int n)
{
        vector<int> rod(n + 1);
        rod[0] = 0;
        for (int i = 1; i <= n; i++)
        {
                int max_val = -INF;
                for (int j = 1; j <= i; j++)
                        max_val = max(max_val, cost[j] + rod[i - j]);
                rod[i] = max_val;
        }
        return rod[n];
}

int maxStockProfit(vector<int> price)
{
        int sz = price.size();
        int maxProfit = -9999999;
        for (int buy = 1; buy < sz + 1; buy++)
                for (int sell = 1; sell < sz + 1; sell++)
                {
                        if (sell - 1 < buy - 1 || price[buy - 1] > price[sell - 1])
                                continue;
                        int profit{price[sell - 1] - price[buy - 1]};
                        maxProfit = max(maxProfit, profit);
                }
        return maxProfit;
}

int maxStockProfitV2(vector<int> price, int n)
{
        int sz = price.size();
        vector<int> min_util(n), max_profit(n);
        int highestProfit = -9999999;
        min_util[0] = price[0];
        for (int i = 1; i < n - 1; i++)
                min_util[i] = min(min_util[i - 1], price[i]);
        for (int i = 0; i < n - 1; i++)
        {
                max_profit[i] = price[i] - min_util[i];
                if (highestProfit < max_profit[i])
                        highestProfit = max_profit[i];
        }
        return highestProfit;
}

int sumOfRange(vector<int> arr, int start, int end)
{
        int n = end - start;
        vector<int> sum(n + 1);
        sum[0] = 0;
        for (int i = 1; i < end + 1; i++)
                sum[i] = sum[i - 1] + arr[i];

        return start == 0 ? sum[end] : sum[end] - sum[start - 1];
}
int main(int argc, char const *argv[])
{
        cout << sumOfRange({1, -2, 3, 10, -8, 0}, 1, 4) << endl;
        return 0;
}
