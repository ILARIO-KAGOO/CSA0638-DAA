#include<stdio.h>

// Utility function to find minimum of two integers
int min(int a, int b)
{
    return (a < b)? a: b;
}

// Function to find the binomial coefficient using dynamic programming
int binomialCoeff(int n, int k)
{
    int C[n+1][k+1];
    int i, j;

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    return C[n][k];
}


int main()
{
    int n, k;
    printf("Enter the value of n and k (n choose k): ");
    scanf("%d %d", &n, &k);
    printf("Binomial Coefficient C(%d, %d) is %d", n, k, binomialCoeff(n, k));
    return 0;
}

