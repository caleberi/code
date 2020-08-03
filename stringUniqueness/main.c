#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isUnique(const char* str){
        //  get the string length
        int len = strlen(str);
        //  check if length is greater than charset
        if (len>128)
        {
               return false;
        }
        bool char_set[128]={false};
        for (int i = 0; i < len ; i++)
        {
                int val = str[i];
                if (char_set[val])
                        return false;
                char_set[val]=true;
                
        }
        return true;
}

int main(int argc, char const *argv[])
{
     
        
        

        return 0;
}
