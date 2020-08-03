#include <stdio.h>
#include <string.h>

void swap(char *x, char *y)
{
        char temp;
        temp = *x;
        *x = *y;
        *y = temp;
}
void permutateString(char *str, int fidx, int lidx)
{
        int i;
        if (fidx == lidx) // check if the index of first equal to the last element
        {
                printf("%s\n", str);
        }
        else
        {
                for (i = fidx; i <= lidx; i++) // move forward selecting the character index
                {
                        swap(str + fidx, str + i);
                        permutateString(str, fidx + 1, lidx); // move the current selected character forward by 1
                        swap( str + fidx,str+i);
                }
        }
}

int main(int argc, char const *argv[])
{
        char a[]="abc";
        int n=strlen(a);
        permutateString(a, 0,n-1 );
        return 0;
}
