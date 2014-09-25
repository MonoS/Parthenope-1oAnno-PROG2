#include <stdio.h>
#include <stdlib.h>

const int DIM_STR = 20;

char* Read_Stat(int n, char* dest);
char* Read_Dina(int n);

int main()
{
    char stat[DIM_STR+1];
    char* dina;
    char scan[DIM_STR+1];
    int n;

    printf("Inserire il numero di caratteri da leggere da tastiera: ");
    scanf("%d", &n);

    printf("inserisci 3 volte la stessa parola premendo ogni volta invio\n");

    fflush(stdin);
    Read_Stat(n, stat);
    fflush(stdin);
    dina = Read_Dina(n);
    fflush(stdin);
    scanf("%s", scan);

    printf("Statica: %s\n", stat);
    printf("Dinamica:%s\n", dina);
    printf("scanf:   %s\n", scan);

    return 0;
}

char* Read_Stat(int n, char* dest)
{
    int i;

    if (n >= DIM_STR) //Controlliamo che non ecceda il massimo numero di caratteri
    {
        dest[0] = '\0';
        return NULL;
    }
    else
    {
        for(i = 0; i < n; i++)
            dest[i] = getchar(); //Prendiamo da tastiera gli n caratteri uno alla volta

        dest[i] = '\0'; //Settiamo il terminatore
    }

    return dest;
}

char* Read_Dina(int n)
{
    char* dest;
    int i;

    dest = malloc(sizeof(char)*(n+1)); //Prendiamoci la memoria che ci serve

    if (dest != NULL) //Controlliamo che l'OS ce l'abbia fornita
    {
        for(i = 0; i < n; i++)
            dest[i] = getchar(); //Prendiamo da tastiera gli n caratteri uno alla volta

        dest[i] = '\0'; //Settiamo il terminatore
    }
    return dest;
}
