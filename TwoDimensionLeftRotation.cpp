#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

void swap(int &u, int &v)
{
        int t;
        t = u;
        u = v;
        v = t;
}
void TwoDLeftRotation(std::vector<int> &arr, int d)
{
        int len = arr.size();
        for (int i = 0; i < len; i++)
        {
                for (int j = 0; j < len - 1; j++)
                        swap(arr[j], arr[j + 1]);
                if (i == d - 1)
                        break;
        }
        for (auto &r : arr)
        {
                std::cout << r << " ";
        }
        std::cout << std::endl;
}

void TwoDLeftRotationV2(std::vector<int> &arr, int d)
{
        int x;
        std::deque<int> dq(arr.size());
        std::copy(arr.begin(), arr.end(), dq.begin());
        for (int i = 0; i < d ; i++)
        {
                x= dq.front();
                dq.pop_front();
                dq.push_back(x);
        }
        std::copy(dq.begin(), dq.end(), arr.begin());
        for (auto &r : arr)
        {
                std::cout << r << " ";
        }
        std::cout << std::endl;
}

int main(int argc, const char **argv)
{
        int n, d;
        int c;

        int i = 0;
        std::cin >> n;
        std::cin >> d;
        std::vector<int> v(n, 0);
        while (i < n)
        {
                std::cin >> c;
                v[i] = c;
                i++;
        }
        TwoDLeftRotationV2(v, d);
        return 0;
}