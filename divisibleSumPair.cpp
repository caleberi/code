#include <iostream>
#include <vector>
#include <algorithm>

// int divisibleSumPairs(int n, int k, std::vector<int> ar)
// {
//         int i;
//         std::vector<int> m(k,0);
//         for (i=0;i<n;i++){
//                 m[ar[i]%k]++; // fill the array with the mod
//         }
//         int sum=0;
//         sum+=(m[0]+m[0]-1)/2;
//         for ( i = 0; i <=k/2 && i!=k-i; i++)
//         {
//                 sum+=m[i]*m[k-i];
//         }
//         if (k%2==0)
//         {
//                 sum+=(m[k/2]+m[k/2]-1)/2;
//         }

//         return sum;
// };

int divisibleSumPairs(int n, int k, std::vector<int> ar)
{
        int count = 0;
        int i, j;
        for (i = 0; i < n; i++)
        {
                for (j = i + 1; j < n; j++)
                {
                        if (((ar[i] + ar[j]) % k) == 0)
                        {
                                std::cout << "[" << ar[i] << "," << ar[j] << "]" << std::endl;
                                count++;
                        }
                }
        }
        return count;
};

int divisibleSumPairsv2(int n, int k, std::vector<int> ar)
{
        int count = 0;
        int i;
        std::sort(ar.begin(), ar.end());
        for (i = 0; i < n; i++)
        {
                int diff = k - ar[i];
                if (std::binary_search(ar.begin(), ar.end(), diff))
                {
                        std::cout << "[" << ar[i] << "," << diff <<"]" << std::endl;
                        count++;
                        continue;
                }
                else
                {
                        continue;
                }
        }
        return count;
};

int main(int argc, char const *argv[])
{
        std::vector<int> v = {1, 3, 2, 6, 4, 5, 9};
        int n = v.size();
        std::cout << divisibleSumPairs(n, 3, v) << std::endl;
        return 0;
}
