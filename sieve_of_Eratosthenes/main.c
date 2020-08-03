#include <stdio.h>
#include <math.h>
#define  N 50

int main() {

        int i,j,primes[N+1];
        for (i=0;i<=N;i++) primes[i]=1; // turns every number to prime by setting it to 1 except index 1 since 0 is not prime
        primes[0]=0; // not prime
        primes[1]=0; // not prime

        for( i=2;i<=sqrt(N);i++){ // anything less than sqrt(N) is it factor so this reduces factor finding time
                if(primes[i]==1){
                         for(j=2;i*j<=N;j++)// settimg muiltples of i to zero
                        primes[i*j]=0;
                }
        }
               
        for (i=1;i<=N;i++)
                if(primes[i]) printf("%4d",i);
        printf("\n");
    return 0;
}