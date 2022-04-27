#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int main()
{
    int mat1[20][20];
    int i,j,n;

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
    printf("-----------------Uppertriangular matrix-----------------------------\n\n");
    uppertriangular(mat1,n);
    printf("-----------------Lowertriangular matrix-----------------------------\n\n");
    lowertriangular(mat1,n);
}

int uppertriangular(int mat1[20][20],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i<=j){
                    printf("%d\t",mat1[i][j]);
            }
            else{
                printf("0\t");
            }
        }
        printf("\n");
    }
}

int lowertriangular(int mat1[20][20],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i>=j){
                    printf("%d\t",mat1[i][j]);
            }
            else{
                printf("0\t");
            }
        }
        printf("\n");
    }
}
