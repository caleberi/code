#include <iostream>
#include <cmath>

int sieveOfErathoenes(int size)
{
        bool arr[size];
        int i, j;
        arr[0] = false;
        arr[1] = false;
        for (i = 2; i < size; i++)
        {
                arr[i] = true;
        }

        for (i = 2; i <= std::sqrt(size); i++)
        {
                if (arr[i] == true)
                {
                        for (j = 0; i*j <=size; j++)
                        {
                                arr[i * j] = false;
                        }
                }
        }
        int count = 0;
        for (i = 0; i < size; i++)
        {
                if (arr[i])
                {
                        count++;
                }
        }
        return count;
}

int main(int argc, const char **argv)
{

        std::cout << sieveOfErathoenes(200) << std::endl;
        return 0;
}