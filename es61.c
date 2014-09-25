#include <stdio.h>

int PotIter(int x, int n);
int PotRicLin(int x, int n);
int PotRicBin(int x, int n);

int main()
{
    printf("5^4 = 625\n");
    printf("Iterativa: %d\n", PotIter(5,4));
    printf("Ric. lin.: %d\n", PotRicLin(5,4));
    printf("Ric. bin.: %d\n", PotRicLin(5,4));

    return 0;
}

int PotIter(int x, int n)
{
    int pot;
    int i;

    for(i = 0, pot = 1; i < n; i++)
        pot *= x;

    return pot;
}

int PotRicLin(int x, int n)
{
    if(n <= 1)
        return x;
    else
        return x * PotRicLin(x, n-1);
}

int PotRicBin(int x, int n)
{
    if (n <= 1)
        return x;
    else
        return PotRicBin(x, n/2) * PotRicBin(x, n - (n/2));
}
