#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
        int birdsNum; // number  of birds
        cin >> birdsNum;
        int arr[birdsNum];
        for (int i = 0; i < birdsNum; ++i)
                cin >> arr[i]; // fill the array with value
        map<int, int> store;   // birds store

        for (int i = 1; i < 6; ++i)
        {
                store[i] = 0;
        }

        for (int i = 0; i < birdsNum; ++i)
        {
                if (!store[arr[i]])
                {
                        store[arr[i]] = 1;
                        continue;
                }
                else
                {
                        store[arr[i]]++;
                }
        }

        for (auto &a : store)
        {
                cout << "{" << a.first << ":"
                     << a.second << "}" << endl;
        }

        cout << "===================" << endl;

        pair<int, int> maxcount{0, 0};
        for (auto it = store.begin(); it != store.end(); ++it)
        {

                if (it->second == maxcount.second && it->first > maxcount.first)
                {
                        continue;
                }
                if (it->second > maxcount.second)
                {
                        maxcount = *it;
                }
        }
        cout << maxcount.first << "==" << maxcount.second << endl;
        return 0;
}
