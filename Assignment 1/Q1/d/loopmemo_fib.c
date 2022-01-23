#include <stdio.h>
#include <time.h>

int main(void)
{
    struct timespec start,end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    unsigned long long prev_prev=0;
    unsigned long long prev=1;
    unsigned long long present=1;
    printf("1st term: 1\n");
    int i;
    for(i=2; i<=100; i++)
    {
        present=prev+prev_prev;
        printf("%dth term: %llu\n", i,present);
        prev_prev=prev;
        prev=present;
        
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken=end.tv_sec-start.tv_sec;
    time_taken+=(end.tv_nsec-start.tv_nsec)*0.000000001;
    printf("Total time taken by program is %f seconds", time_taken);
    return 0;
}

