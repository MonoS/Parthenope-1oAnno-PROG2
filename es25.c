#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int OCCORRENZE = 3;

int TrovaOccorrenze(char* str, char* substr, char** occorrenze[]);

int main()
{
    char** occorrenze;
    char* str = "123000456000789";
    char* substr = "0";
    int nOccorrenze;
    int i;

    nOccorrenze = TrovaOccorrenze(str, substr, &occorrenze);
    if(nOccorrenze >= 0)
    {
        printf("%d occorrenze\n", nOccorrenze);
        for(i = 0; i < nOccorrenze; i++)
            printf("%s\n", occorrenze[i]);
    }
    return 0;
}
int TrovaOccorrenze(char* str, char* substr, char** occorrenze[])
{
    int i, k;
    char* temp;
    int subLen;

    i = 0; temp = strstr(str,substr); subLen = strlen(substr); k = 1; (*occorrenze) = malloc(sizeof(char*)*OCCORRENZE);
    while(temp != NULL)
    {
        if((k * OCCORRENZE) > i) //Controlliamo che abbiamo altro spazio nel vettore delle occorrenze
        {
            (*occorrenze)[i] = temp; //Salviamoci la posizione dell'occorrenza
            i++;
            temp = strstr(temp + subLen, substr); //Cerchiamo la prossima
        }
        else //in caso non abbiamo spazio
        {
            k++;
            (*occorrenze) = realloc((*occorrenze), sizeof(char*)*(OCCORRENZE*k)); //riallochiamo il vettore
            if((*occorrenze) == NULL) //Controlliamo che il riallocamento sia andato a buon fine
            {
                temp = NULL;
                i = -1;
            }
        }
    }
    return i;
}
