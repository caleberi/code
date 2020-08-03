#include <bits/stdc++.h>
using namespace std;

long coinTriplets(vector<long> arr, long ratio)
{
        map<long, long> rightMap;
        map<long, long> leftMap;
        for (auto item : arr)
        {
                if (rightMap.find(item) != rightMap.end())
                        rightMap[item]++;
                rightMap.insert(pair<long, long>{item, 1}); //Map{a1->1,....}
        }

        for (auto item : arr)
        {
                leftMap.insert(pair<long, long>{item, 0});
        }

        long count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
                long mid = arr[i];
                long c1 = 0;
                long c3 = 0;
                rightMap[mid] = rightMap.at(mid) - 1;
                if (leftMap.find(mid / ratio) != rightMap.end() && mid % ratio == 0)
                        c1 = leftMap.at(mid / ratio);
                if (rightMap.find(mid * ratio) != rightMap.end())
                        c3 = rightMap.at(mid * ratio);
                count += c1 * c3;
                leftMap[mid] = leftMap.at(mid) + 1;
        }
        return count;
}

vector<int> freqQuery(vector<vector<int>> queries)
{
        vector<int> store;
        map<int, int> count;
        for (auto query : queries)
        {
                int op = query[0];
                int num = query[1];
                if (op == 1)
                {
                        if (count.find(num) != count.end())
                                count[num]++;
                        count.insert(pair<int, int>{num, 1});
                }
                else if (op== 2)
                {
                       if(count.find(num)!=count.end()&&count[num]>1){
                               count[num]--;
                       }else if(count.find(num)!=count.end()&&count[num]==1){
                               count.erase(num);
                       }
                       else continue;
                }
                if (op== 3)
                {
                        if(num>=queries.size()) store.push_back(0);
                        if (count.find(num) != count.end())
                                store.push_back(1);
                        else
                                store.push_back(0);
                }
        }
        return store;
}

int main(int argc, char const *argv[])
{
        vector<long> s = {1, 3, 3, 9, 9, 9, 27, 81};
        cout << coinTriplets(s, 3) << endl;
        return 0;
}


