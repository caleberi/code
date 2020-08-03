#include <iostream>

void swap(int &u, int &v)
{
        int t;
        t = u;
        u = v;
        v = t;
}

int gcd(int u, int v)
{

        while (u != 0)
        {
                if (u < v)
                        swap(u, v);
                u -= v;
        }
        return v;
};

int main(int argc, char const *argv[])
{
        std::cout<<gcd(6,9)<<std::endl;
        return 0;
}
