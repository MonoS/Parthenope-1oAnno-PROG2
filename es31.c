#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void GenTabellaKMP(char* str, int tabellaKMP[]);
char* RicercaKMP(char* str, char* substr, int tabellaKMP[]);
int CercaOccorrenze(char* str, char* substr);

int main()
{
    char* str = "000123412312340000000001234";
    char* substr = "1234";

    printf("Orig: %s\n", str);
    printf("Sub : %s\n", substr);
    printf("N Occorrenze: %d\n", CercaOccorrenze(str, substr));

    return 0;
}

void GenTabellaKMP(char* str, int tabellaKMP[])
{
    int i, j;

    i = 1;
    while(str[i] != '\0')
    {
        /*  Dobbiamo cercare dove la striga si sovrappone con se stessa
            Per trovare questi overlap usiamo i due indici in modo da poterli muovere indipendentemente
        */
        for(j = 0; ((str[j] == str[i+j]) && (str[i+j] != '\0')); j++)
            tabellaKMP[i + j] = j + 1;

        if(j > 0) //Se abbiamo trovato una sovrapposizione allora posiamo saltare dei caratteri
            i += j;
        else
            i++;
    }
}

char* RicercaKMP(char* str, char* substr, int tabellaKMP[])
{
    int i, j;


    i = 0; //Si muove solo sulla stringa
    j = 0; //Si muove prevalentemente sulla sottostringa
    while((substr[j] != '\0') && (str[i+j] != '\0'))
    {
        if (str[i+j] == substr[j]) //Se abbiamo trovato il pattern
            j++; //continuiamo a vedere se è proprio quello
        else //Se non l'abbiamo trovato
        {
            if(j == 0) //Controlliamo di aver trovato almeno un carattere
                i++;
            else
            {
                i += j; //abbiamo troato dei caratteri, quindi possiamo saltare quelli intermedi
                j = tabellaKMP[j - 1]; //Ci pensa la tabella a sapere a che punto siamo nella sottostringa
            }
        }

    }

    if (substr[j] == '\0') //Se l'abbiamo trovato
        return &str[i];
    else
        return NULL;
}

int CercaOccorrenze(char* str, char* substr)
{
    int sublen;
    int* tabellaKMP;
    int i;

    sublen = strlen(substr);

    tabellaKMP = calloc(sizeof(int), sublen);
    GenTabellaKMP(substr, tabellaKMP);

    i = 0;
    str = RicercaKMP(str, substr, tabellaKMP); //Cerchiamo la prima occorrenza
    while (str != NULL) //Per ogni occorrenza trovata
    {
        i++;

        str = RicercaKMP(str + sublen, substr, tabellaKMP); //cerchiamo la prossima
    }

    free(tabellaKMP); //liberiamo la memoria occupata dalla tabella

    return i;
}
