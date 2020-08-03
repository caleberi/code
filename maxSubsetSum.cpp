#include <bits/stdc++.h>
using namespace std;

// // int maxSubsetSum(vector<int> h,)
// // {
// //         int max = INT16_MIN;
// //         int a = h[0];
// //         if(h.size()<2)
// //                 return 0;
// //         else return

// // }

// int main(int argc, char const *argv[])
// {

//         return 0;
// }
#include <bits/stdc++.h>

using namespace std;
int maxSubarraySum(vector<int> array) //{1,2,3,4,5}
{
        int max_sum = array[0];
        int temp_sum = array[0];
        for (int i = 0; i < array.size(); i++)
        {
                temp_sum = max(array[i], temp_sum + array[i]);
                if (temp_sum > max_sum)
                        max_sum = temp_sum;
        }
        return max_sum;
}
int maxSubsetSum(vector<int> array)
{
        if (array.size() == 0)
                return 0;
        array[0] = max(0, array[0]);
        if (array.size() == 1)
                return array[0];
        array[1] = max(array[0], array[1]);
        for (int i = 2; i < array.size(); i++)
        {
                array[i] = max(array[i - 2] + array[i], array[i - 1]);
        }
        return array[array.size() - 1];
}

string abbreviate(string, string);
int main(int argc, char const *argv[])
{
        string input = "beFgH";
        string match = "EFG";
        cout << abbreviate(input, match);
        return 0;
}
void abbreviate_helper(string input, string match, vector<int> &contains, vector<int> &found)
{
        for (int i = 0; i < input.size(); i++)
        {
                for (int j = 0; j < match.size(); j++)
                {
                        if (input[i] == 1)
                                break;

                        if (input[i] == match[j])
                                contains[i] = found[j] = 1;
                }
        }
}

bool count_helper(vector<int> &contains, vector<int> &found,int match_size)
{
        int contains_count =0;
        int found_count = 0;
        for (int i = 0; i < found.size(); i++)
        {
                if (found[i] == 1)
                        found_count++;
        }
        return match_size == found_count ? true : false;
}
string abbreviate(string input, string match)
{
        int n = input.size();
        int m = match.size();
        vector<int> contains(n, 0);
        vector<int> found(m, 0);
        for (auto &letter : input)
        {
                if (islower(letter))
                        letter = toupper(letter);
        }
        abbreviate_helper(input, match, contains, found);
        return count_helper(contains, found,match.size()) ? "YES" : "NO";
}

string longestSubsequence(string a,string b){
        
}