#include <stdio.h>

void QuickSort(int inizio, int fine, int vet[]);
int Partiziona(int inizio, int part, int fine, int vet[]);
void Scambia(int* a, int* b);

int main()
{
    int vet[8] = {5,3,7,2,1,6,4,8};
    int n = 8;
    int i;


    printf("Originale\n");
    for(i = 0; i < n; i++)
        printf("%d ", vet[i]);

    printf("\nOrdinato\n");
    QuickSort(0, n, vet);
    for(i = 0; i < n; i++)
        printf("%d ", vet[i]);

    return 0;
}

void QuickSort(int inizio, int fine, int vet[])
{
    int part;
    if(inizio < fine)
    {
        part = (inizio + fine) / 2;
        part = Partiziona(inizio, part, fine, vet);

        QuickSort(inizio, part - 1, vet);
        QuickSort(part + 1, fine, vet);
    }


    return;
}

int Partiziona(int inizio, int part, int fine, int vet[])
{
    int partVal;
    int i;

    partVal = vet[part];

    Scambia(&vet[part], &vet[fine]);
    part = inizio;

    for(i = inizio; i < fine; i++)
    {
        if(vet[i] < partVal)
        {
            Scambia(&vet[part], &vet[i]);
            part++;
        }
    }

    Scambia(&vet[part], &vet[fine]);

    return part;
}

void Scambia(int* a, int* b)
{
    int t;

    t = (*a);
    (*a) = (*b);
    (*b) = t;

    return;
}
