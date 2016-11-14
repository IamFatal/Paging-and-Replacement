#include <stdio.h>
 
int main()
{
    int i, j, n, isPrime, sum=0;
	n = 100000;
    for(i=2; i<=n; i++)
    {
        isPrime = 1;
        for(j=2; j<=i/2 ;j++)
        {
            if(i % j == 0)
            {
                isPrime = 0;
                break;
            }
        }
        if(isPrime==1)
        {
            sum += i;
        }
    }
 
    printf("Sum of all prime numbers between 1 to %d = %d", n, sum);
 
    return 0;
}