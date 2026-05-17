#include <stdio.h>
int main()
{
    int n, i, isPrime = 1;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n <= 1)
        isPrime = 0;
    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0) {
            isPrime = 0;
            break;
        }
    }
    if (isPrime)
        printf("%d is a Prime number\n", n);
    else
        printf("%d is NOT a Prime number\n", n);
    return 0;
}
