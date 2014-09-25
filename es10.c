#include <stdio.h>

int ComplementoA2(int a);
int ComplementoBiasK(int a, int k);
void StampaBinario(void const * const ptr, size_t const size);

int main()
{
    int n, a2, biasK, k;

    printf("Inserire il numero da trattare: ");
    scanf("%d", &n);

    printf("Inserire il valore della k del bias: ");
    scanf("%d", &k);

    a2 = ComplementoA2(n);
    biasK = ComplementoBiasK(n, k);

    StampaBinario(&n, sizeof(n));
    StampaBinario(&a2, sizeof(a2));
    StampaBinario(&biasK, sizeof(biasK));

    return 0;
}

int ComplementoA2(int a)
{
    return ((~a) + 1);
}

int ComplementoBiasK(int a, int k)
{
    return a+k;
}

void StampaBinario(void const * const ptr, size_t const size)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = b[i] & (1<<j);
            byte >>= j;
            printf("%u", byte);
        }
    }
    puts("");
}
