#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char* argv[])
{

    int pid, np;
    // np -> no. of processes
    // pid -> process id
    int n = 4455;

    // Creation of parallel processes
    MPI_Init(&argc, &argv);

    // find out process ID,
    // and how many processes were started
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    MPI_Comm_size(MPI_COMM_WORLD, &np);

    if(pid == 0)
    {
        int a, sum, b;
        a=n;
        sum=0;
        while(a>0)
        {
            b = a % 10 ;
            sum = sum + b ;
            a= a/10;
        }
        printf("From Process ID %d --> The sum of digits of %d is = %d\n ",pid,n,sum);
    }

    if(pid == 1)
    {
        int x,y;
        x=n;
        int even_sum =0, odd_sum=0, odd_count=0, even_count=0;
        while(x>0)
        {
            y = x % 10;
            if(y % 2 == 0)
            {
                even_sum  = even_sum + y;
                even_count = even_count + 1;
            }
            else if(y % 2 != 0)
            {
                odd_sum = odd_sum + y;
                odd_count = odd_count + 1;
            }
            x = x / 10 ;
        }
        printf("\n\nFrom Process ID %d -->\n ",pid);
        printf("The even count is %d and even sum is %d\n",even_count,even_sum);
        printf("The odd count is %d and odd sum is %d\n\n\n",odd_count,odd_sum);
    }

    if(pid == 2)
    {
        int count=0;
        if (n <= 1)
            count = 1;
        // Check from 2 to square root of n
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                count= 1;
        if (count == 0)
        {
            printf("From Process ID %d --> %d is prime number\n",pid,n);
        }
        else
            printf("From Process ID %d --> %d is not a prime number \n",pid,n);
    }

    if(pid ==3 )
    {
        int t,m,res;
        m=n;
        while(m>0)
        {
            t = m % 10;
            res = res + t;
            m = m / 10 ;
        }
        if ( n == m)
        {
            printf("\nFrom Process ID %d --> %d is a palindrome\n",pid,n);
        }
        else
        {
            printf("\nFrom Process ID %d --> %d is not a palindrome\n",pid,n);
        }
    }
    MPI_Finalize();

    return 0;
}
