#include <stdio.h>
#include <stdlib.h>
int compare(const void *l, const void *r)
{
        int a = *(const int *)l;
        int b = *(const int *)r;
        if (a < b)
        {
                return -1;
        }
        else if (a > b)
        {
                return 1;
        }

        return 0;
}

void twoSum(int *arr, int sum, int size)
{
        // create a result variable

        int *result;
        qsort(arr, size, sizeof(int), compare); // nlogm
        int i;
        for (i = 0; i < size; i++) // n
        {
                // subtract it from the sum to find the difference
                int diff = sum - *(arr+i);
                // loop and find each diff in the array
                result = (int *)bsearch(&diff, arr, size, sizeof(int), compare);
                //to subarray
                if (result)
                {
                        int a[2] = {arr[i], diff};
                        printf("[%d , %d]\n", a[0],a[1]);
                }
                else
                {
                        continue;
                }
        }
}

int main()
{
        int arr[9] = {1, 2, 4, 3, 6, 5, 7, 0, 10};
        twoSum(arr, 11, 9);
        return 0;
}
