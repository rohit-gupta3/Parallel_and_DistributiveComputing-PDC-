#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main()
{
    int n;
    printf("Enter the order for the matrix: ");
    scanf("%d",&n);
    mataddserial(n);
    mataddparallel(n);
    return 0;
}

int mataddserial(int n)
{
    int mat1[50][50],mat2[50][50];
    int i,j;
    double start_time = omp_get_wtime();
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            mat1[i][j] = ((rand() % 50 + rand() % 40) % 20);
           // printf("Generated Number for mat[%d][%d] = %d\n",i,j,mat1[i][j]);
        }
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            mat2[i][j] = ((rand() % 50 + rand() % 40) % 20);
           // printf("Generated Number for mat[%d][%d] = %d\n",i,j,mat2[i][j]);
        }
    printf("------------------------------------------------------");
    printf("\nSum of the matrix is : \n");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            printf("%d\t",(mat1[i][j]+mat2[i][j]));
            if(j==n-1)
                printf("\n");
        }
    double end_time = omp_get_wtime();
    double time_used = end_time - start_time;
    printf("Serial Execution time: %f s\n", time_used);
}

int mataddparallel(int n)
{
    int mat1[50][50],mat2[50][50];
    int i,j;
    double start_time = omp_get_wtime();
    #pragma omp parallel
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            mat1[i][j] = ((rand() % 50 + rand() % 40) % 20);
          //  printf("Generated Number for mat[%d][%d] = %d\n",i,j,mat1[i][j]);
        }
    }
    #pragma omp parallel
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            mat2[i][j] = ((rand() % 50 + rand() % 40) % 20);
           // printf("Generated Number for mat[%d][%d] = %d\n",i,j,mat2[i][j]);
        }
    printf("------------------------------------------------------");
    printf("\nSum of the matrix is : \n");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            printf("%d\t",(mat1[i][j]+mat2[i][j]));
            if(j==n-1)
                printf("\n");
        }
    double end_time = omp_get_wtime();
    double time_used = end_time - start_time;
    printf("Parallel Execution time: %f s\n", time_used);
}
