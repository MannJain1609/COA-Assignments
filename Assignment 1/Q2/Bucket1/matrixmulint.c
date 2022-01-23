#include <stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d", &n);
    struct timespec clk1_start,clk1_end;
    clock_gettime(CLOCK_MONOTONIC, &clk1_start);
    int a[n][n];
    int b[n][n];
    int c[n][n];
    int i,j,k;
    srand(time(0));
    for(i=1; i<=n; i++)
    {
     for(j=1; j<=n; j++)
     {
         a[j][j]=rand()%100;
         b[i][j]=rand()%100;
     }
    }
    
    struct timespec start,end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            c[i][j]=0;
            for(k=1; k<=n; k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }

    printf("\nThe result of A*B matrix is: \n");
    for(i=1; i<=n; i++)
    {
     for(j=1; j<=n; j++)
     {
         printf("%d ", c[i][j]);
     }
     printf("\n");
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    clock_gettime(CLOCK_MONOTONIC, &clk1_end);
    double time_taken=end.tv_sec-start.tv_sec;
    time_taken+=(end.tv_nsec-start.tv_nsec)*0.000000001;
    printf("Time taken by the meat program is %f seconds\n", time_taken);
    double total_time=clk1_end.tv_sec-clk1_start.tv_sec;
    total_time+=(clk1_end.tv_nsec-clk1_start.tv_nsec)*0.000000001;
    printf("Total time taken by the program is %f seconds\n", total_time);
    return 0;
}
