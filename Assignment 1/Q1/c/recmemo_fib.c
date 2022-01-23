#include <stdio.h>
#include <time.h>

long long fib(int );

int main(void)
{
    struct timespec start,end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    int i;
    for(i=1; i<=100; i++)
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
    static int array[101]={0};
    array[1]=1;
    array[2]=1;
    if(array[n]==0)
    array[n]=fib(n-1)+fib(n-2);
    return array[n];
}
