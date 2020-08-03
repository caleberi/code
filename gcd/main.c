#include <stdio.h>

int gcd(int u,int v){
        int t;
        while (u>0)
        {
                if(u<v){
                        t=u;u=v;v=t;
                }
                u=u-v;
        }
        return v;
        

}

int gcdModulus(int u,int v){
        int t;
        while (u>0)
        {
                if(u<v){
                        t=u;u=v;v=t;
                }
                u=u%v;
        }
        return v;
        

}

typedef struct Fraction
{
        int numerator;
        int denominator;
} ft;

int gcdstruct(ft f){
        int t;
        while (f.numerator>0)
        {
                if(f.numerator<f.denominator){
                        t=f.numerator;f.numerator=f.denominator;f.denominator=t;
                }
                f.numerator=f.numerator-f.denominator;
        }
        return f.denominator;
        

}

int main(int argc, char const *argv[])
{
        int x,y;
        while (scanf("%d %d",&x,&y)!=EOF)
        {
                ft fration={x,y};
               if(x>0&&y>0){
                       printf("%d %d = gcd -> %d \n",x,y,gcdstruct(fration));
               }

        }
        
        return 0;
}
