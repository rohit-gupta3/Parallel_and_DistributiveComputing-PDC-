#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include <omp.h>

int main()
{
    int mat1[20][20],mat2[20][20];
    int i,j,n,x,mul;
    printf("Enter order of Matix : ");
    scanf("%d",&n);
    double start_time = omp_get_wtime();

    printf("-------------------------The Generated matrix------------------------\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            mat1[i][j] = ((rand() % 50 + rand() % 40) % 20);
            printf("%d\t",mat1[i][j]);
            if(j==n-1)
                printf("\n");
        }
    }
    printf("\n------------------------Transposed matrix-------------------------------\n");
    #pragma omp parallel for
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            mat2[i][j] = mat1[j][i];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d\t",(mat2[i][j]));

        }
        printf("\n");
    }
    double end_time = omp_get_wtime();
    double time_used = end_time - start_time;
    printf("Parallel Execution time: %f s\n", time_used);

}
