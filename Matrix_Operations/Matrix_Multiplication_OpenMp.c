#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int main()
{
    int mat1[20][20],mat2[20][20];
    int i,j,n,x,mul;
    printf("Enter order of Matix : ");
    scanf("%d",&n);
    printf("-------------------------The 1st Generated matrix------------------------\n");
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
    printf("-------------------------The 2nd Generated matrix------------------------\n");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            mat2[i][j] = ((rand() % 50 + rand() % 40) % 20);
            // printf("Generated Number for mat[%d][%d] = %d\n",i,j,mat2[i][j]);
            printf("%d\t",mat2[i][j]);
            if(j==n-1)
                printf("\n");
        }
    //Multiplication by parallelizing the loop
    printf("\n\n------------------------------------------------------");
    printf("\nMultiplication of the matrix is : \n");
    double start_time = omp_get_wtime();
    for(i=0; i<n; i++)
    {
        x=0;
        while(x<n)
        {
            mul = 0;
            #pragma omp parallel for
            for(j=0; j<n; j++)
            {
                mul = mul + mat1[i][j]*mat2[j][x];

            }
            x=x+1;
            printf("%d\t",mul);

        }
        printf("\n");
    }
    double end_time = omp_get_wtime();
    double time_used = end_time - start_time;
    printf("parallel Execution time: %f s\n", time_used);
    //Multipication by serial method
    start_time = omp_get_wtime();
    for(i=0; i<n; i++)
    {
        x=0;
        while(x<n)
        {
            mul = 0;
            for(j=0; j<n; j++)
            {
                mul = mul + mat1[i][j]*mat2[j][x];
            }
            x=x+1;
            printf("%d\t",mul);
        }
        printf("\n");
    }
    end_time = omp_get_wtime();
    time_used = end_time - start_time;
    printf("Serial Execution time: %f s\n", time_used);
}
