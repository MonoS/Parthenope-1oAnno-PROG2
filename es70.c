#include <stdio.h>

void MergeSortRico(int inizio, int fine, int vet[], int temp[]);
void MergeSortIter(int n, int vet[], int temp[]);
void Merge(int inizio, int fine, int vet[], int temp[]);

int main()
{
    int mergeRico[8] = {5,3,7,2,1,6,4,8};
    int mergeIter[8] = {5,3,7,2,1,6,4,8};
    int temp[8];
    int n = 8;
    int i;


    printf("Originale\n");
    for(i = 0; i < n; i++)
        printf("%d ", mergeRico[i]);

    printf("\nRicorsivo\n");
    MergeSortRico(0, n, mergeRico, temp);
    for(i = 0; i < n; i++)
        printf("%d ", mergeRico[i]);

    printf("\nIterativo\n");
    MergeSortIter(n, mergeIter, temp);
    for(i = 0; i < n; i++)
        printf("%d ", mergeIter[i]);
    return 0;
}

void MergeSortRico(int inizio, int fine, int vet[], int temp[])
{
    if(fine - inizio >= 2)
    {
        MergeSortRico(inizio, (fine + inizio) / 2, vet, temp); //sinistra
        MergeSortRico((fine + inizio) / 2, fine, vet, temp); //destra
        Merge(inizio, fine, vet, temp);

        return;
    }
    else
        return;

}

void MergeSortIter(int n, int vet[], int temp[])
{
    int i, j;

    for (i = 1; (1 << i) <= n; i++) //setta la dimensione delle partizioni
    {
        for(j = 0; j < n; j = j + (1 << i)) //seleziona le varie partizioni
        {
            Merge(j, (j + (1 << i)), vet, temp);
        }
    }

    return;
}

void Merge(int inizio, int fine, int vet[], int temp[])
{
    int meta = (fine + inizio) / 2;
    int i, j, k;

    i = inizio; j = meta; k = inizio;
    while((i < meta) && (j < fine))
    {
        if(vet[i] < vet[j])
        {
            temp[k] = vet[i];
            i++; k++;
        }
        else
        {
            temp[k] = vet[j];
            j++; k++;
        }
    }

    while(i < meta)
    {
        temp[k] = vet[i];
        i++; k++;
    }

    while (j < fine)
    {
        temp[k] = vet[j];
        j++; k++;
    }

    for(k = inizio; k < fine; k++)
        vet[k] = temp[k];
}
