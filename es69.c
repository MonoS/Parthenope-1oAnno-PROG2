#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[32];
    char cognome[32];
} tNomeCognome;

void OrdinaNominativi(tNomeCognome nominativi[], int n);
int ConfrontaNominativi(tNomeCognome a, tNomeCognome b);

int main()
{
    tNomeCognome nominativi[5] = {{"bbb","aaa"},{"ccc","bbb"},{"ccc","ccc"},{"ddd","ddd"}, {"ccc","aaa"}};
    int n = 5;
    int i;
    printf("Non ordinata\n");
    for(i = 0; i < n; i++)
        printf("%s %s\n", nominativi[i].cognome, nominativi[i].nome);

    OrdinaNominativi(nominativi, n);

    printf("\nOrdinata\n");
    for(i = 0; i < n; i++)
        printf("%s %s\n", nominativi[i].cognome, nominativi[i].nome);

    return 0;
}
void OrdinaNominativi(tNomeCognome nominativi[], int n)
{
    tNomeCognome temp;
    int i, j;

    for(i = 1; i < n; i++)
    {
        temp = nominativi[i];
        j = i - 1;

        while((j >= 0) && (ConfrontaNominativi(nominativi[j], temp) > 0))
        {
            nominativi[j + 1] = nominativi[j];
            j--;
        }

        nominativi[j + 1] = temp;
    }

    return;
}

int ConfrontaNominativi(tNomeCognome a, tNomeCognome b)
{
    int ris;

    //Confrontiamo il cognome di a con quello di b
    ris = strcmp(a.cognome, b.cognome);
    //Se i due cognomi sono uguali confrontiamo per nome
    if(ris == 0)
        return strcmp(a.nome, b.nome);
    else
        return ris;
}
