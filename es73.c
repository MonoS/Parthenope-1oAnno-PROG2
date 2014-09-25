#include <stdio.h>

void HeapSort(int vet[], int n);
void Heapify(int vet[], int n);
void CreaHeap(int vet[], int i, int n);
void Scambia(int* a, int* b);

int main()
{
    int vet[16] = {0,98,34,45,13,62,1,56,81,31,21,97,20,12,5,73};
    int n = 16;
    int i;

    printf("Array non ordinato: ");
    for(i = 1; i < n; i++)
        printf("%2d ", vet[i]);
    printf("\n");

    HeapSort(vet, n);

    printf("Array non ordinato: ");
    for(i = 1; i < n; i++)
        printf("%2d ", vet[i]);
    printf("\n");

    return 0;
}

void HeapSort(int vet[], int n)
{
    int i;

    for(i = n - 1; i > 0; i--)
    {
        Heapify(vet, i);

        Scambia(&vet[1], &vet[i]);
    }

    return;
}

void Heapify(int vet[], int n)
{
    int i;

    for(i = n; i > 1; i--)
        CreaHeap(vet, i, n);

    return;
}

void CreaHeap(int vet[], int i, int n)
{
    if(vet[i] > vet[i/2])
    {
        Scambia(&vet[i], &vet[i/2]);

        if((i * 2) + 1 < n)
            CreaHeap(vet, (i * 2) + 1, n);

        if((i * 2) < n)
            CreaHeap(vet, (i * 2), n);
    }

    return;
}

void Scambia(int* a, int* b)
{
    int temp;

    temp = (*a);
    (*a) = (*b);
    (*b) = temp;

    return;
}
