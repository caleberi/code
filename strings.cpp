#include <bits/stdc++.h>
using namespace std;
string twoStrings(string s1, string s2)
{
    vector<int> check(26, 0);
    for (auto c : s1)
    {
        if (check[c - 'a'] == 0)
            check[c - 'a'] = 1;
    }

    for (auto c : s2)
    {
        if (check[c - 'a'] == 1)
            return "YES";
    }

    return "NO";
}

vector<int> matchingStrings(vector<string> strings, vector<string> queries)
{
    int n = queries.size();
    vector<int> mk(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < strings.size(); j++)
        {
            if (queries[i] == strings[j])
            {
                mk[i]++;
                continue;
            }
        }
    }
    return mk;
}

bool validateSubsequence(vector<int> array, vector<int> sequence)
{
    int seqIdx = 0;
    int arrIdx = 0;
    while (arrIdx < array.size() && seqIdx < sequence.size())
    {
        if (array[arrIdx] == sequence[seqIdx])
            seqIdx += 1;
        arrIdx += 1;
    }
    return seqIdx == sequence.size();
}