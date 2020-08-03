#include <bits/stdc++.h>

int roundup(int score)
{
        int nxt = ((score / 5) * 5) + 5; // next multiple of 5
        std::cout << nxt << std::endl;
        int diff = nxt - score; // difference between score and next multiple of 5
        if (score < 38)
                return score;
        if (diff < 3 && nxt <= 100)
                return nxt;

        return score;
}

int main(int argc, char const *argv[])
{
        std::cout << roundup(73) << std::endl;
        return 0;
}
