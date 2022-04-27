#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int mat1[20][20],mat2[20][20];
    int i,j,n;
    int sumrow,sumcol;
    printf("Enter order of Matix : ");
    scanf("%d",&n);
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

    printf("-------------Serialized Execution-------------------------\n");
    for(i=0;i<n;i++)
    {
        sumrow=0;
        for(j=0;j<n;j++)
        {
            sumrow = sumrow + mat1[i][j];
        }
        printf("Sum of row[%d] = %d \n",i,sumrow);
    }
    for(i=0;i<n;i++)
    {
        sumcol=0;
        for(j=0;j<n;j++)
        {
            sumcol = sumcol + mat1[j][i];
        }
        printf("Sum of column[%d] = %d \n",i,sumcol);
    }

    printf("------------Parallelized Execution-------------------------\n");
    #pragma omp parallel for
    for(i=0;i<n;i++)
    {
        sumrow=0;
        for(j=0;j<n;j++)
        {
            sumrow = sumrow + mat1[i][j];
        }
        printf("Sum of row[%d] = %d \n",i,sumrow);
    }
    #pragma omp parallel for
    for(i=0;i<n;i++)
    {
        sumcol=0;
        for(j=0;j<n;j++)
        {
            sumcol = sumcol + mat1[j][i];
        }
        printf("Sum of column[%d] = %d \n",i,sumcol);
    }
}
