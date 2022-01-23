#include <stdio.h>
#include <time.h>

long long fib(int );

int main(void)
{
    struct timespec start,end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    int i;
    for(i=1; i<=50; i++)
    {
        printf("%dth term: %lld\n", i,fib(i));
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken=end.tv_sec-start.tv_sec;
    time_taken+=(end.tv_nsec-start.tv_nsec)*0.000000001;
    printf("Total time taken by program is %f seconds", time_taken);
    return 0;
}

long long fib(int n)
{
    if(n==1 || n==2)
        return 1;
    return fib(n-1)+fib(n-2);
}
