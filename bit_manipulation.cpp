#include <bits/stdc++.h>
using namespace std;

bool set_bit(int num, int i)
{
        return (num & (1 << i)) != 0;
}
int count_setbit(int num)
{
        int cnt = 0;
        while (num > 0)
        {
                if ((num & 1 )> 0)
                        cnt++;
                num = num >> 1;
        }
        return cnt;
}

int main(int argc, char const *argv[])
{
        cout << count_setbit(12) << endl;
        return 0;
}
