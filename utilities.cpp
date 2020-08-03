#include <iostream>
#include <bits/stdc++.h>

using std::vector;
namespace Sort
{
        template <typename _Tc>
        void swap(_Tc &u, _Tc &v)
        {
                _Tc t;
                t = u;
                u = v;
                v = t;
        }
        // Selection Sort
        template <typename _Tc>
        void selection_sort(vector<_Tc> &arr)
        {
                int n = arr.size();
                for (int i = 0; i < n - 1; i++)
                {
                        int smallest = i;
                        for (int j = i + 1; j < n - 2; j++)
                        {
                                if (arr[j] < arr[smallest])
                                        smallest = j;
                        }
                        swap(arr[i], arr[smallest]);
                }
        };
        // Bubble Sort
        template <typename _Tc>
        void bubble_sort(vector<_Tc> &arr)
        {
                int n = arr.size();
                bool flag = false;
                for (int i = 0; i < n; i++)
                {
                        for (int j = i + 1; j < n - 1; j++)
                        {
                                if (arr[i] > arr[j])
                                {
                                        swap(arr[i], arr[j]);
                                        flag = true;
                                }
                        }
                        if (flag == false)
                                break;
                }
        }
        template <typename _Tc>
        void inbuilt_sort(vector<_Tc> &arr)
        {
                std::sort(arr.begin(), arr.end());
        }

        template <typename _Tc>
        vector<_Tc> counting_sort(vector<_Tc> items)
        {
                int x = items.size();
                int n;
                if (items.size() % 2 == 1)
                {
                        n = (items.size() + 1) / 2;
                }
                else
                {
                        n = items.size() / 2;
                }
                vector<_Tc> res(x, 0);
                for (int i = 0; i < n; i++)
                {
                        if (items[i] + n == i)
                                res[i] = items[items[i] + n];
                }
                return res;
        }
}; // namespace Sort

namespace Search
{
        template <typename _Tc>
        bool linear_search(vector<_Tc> &haystack, _Tc needle)
        {
                int n = haystack.size();

                for (int i = 0; i < n - 1; i++)
                {
                        if (haystack[i] == needle)
                                return true;
                }
                return false;
        }

        template <typename _Tc>
        bool binary_search(vector<_Tc> &haystack, _Tc needle)
        {
                int first = 0;
                int last = haystack.size() - 1;
                while (first != last)
                {
                        int middle = first + (last - first) / 2;
                        if (haystack[middle] == needle)
                                return true;
                        if (haystack[middle] < needle)
                                first = middle + 1;
                        if (haystack[middle] > needle)
                                last = middle;
                }

                return false;
        };

} // namespace Search

int main(int argc, char const *argv[])
{
        vector<int> v = {-10, -9, -7, -4};
        for (auto &a : Sort::counting_sort(v))
        {
                std::cout << a << std::endl;
        }
        return 0;
}
