#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

const int DIM_BUFFER = 20;

///FILE DI INPUT: casa56789012345678casa34567890casa5678casa345678
///FINE BUFFER  : -------------------!-------------------!-------!
///OUTPUT       : 4
int RicercaViaBuffer(FILE* input, char* substr);

int main(int argc, char** argv)
{
    FILE* input;
    char* substr = "casa";

    input = fopen(argv[1], "r");

    printf("%d\n",RicercaViaBuffer(input, substr));

    system("PAUSE");

    return 0;
}

int RicercaViaBuffer(FILE* input, char* substr)
{
    char buffer[DIM_BUFFER + 1];
    int charRead;
    int subLen;

    char* next;
    int ris;
    bool trovato;

    int j;

    subLen = strlen(substr);
    ris = 0;
    trovato = false;

    charRead = fread(buffer, sizeof(char), DIM_BUFFER, input); buffer[charRead] = '\0'; //Riempiamo per a prima volta il buffer
    while(charRead > 0)
    {
        //Questa parte controlla se ci sta parte della sottostringa all'interno del uffer successivo
        //AL primo passaggio non viene mai eseguita
        if(trovato)
        {
            if(strncmp(buffer, substr + j, subLen - j) == 0)
                ris++;

            trovato = false;
        }

        //Cerchiamo le occorrenze semplici [che non stanno tra un bbuffer e il successivo]
        next = buffer;
        do{
            next = strstr(next, substr);

            if(next != NULL)
            {
                ris++;
                next += subLen;
            }

        }while(next != NULL);

        //Cerchiamo se c'è parte dell'occorrenza alla fine del buffer attuale
        j = subLen - 1;
        while((j > 0) && (!trovato))
        {
            if(strncmp(buffer+charRead-j, substr, j) == 0)
                trovato = true;
            else
                j--;
        }

        //Abbiamo finito di analizzare l buffer, riempiamo quello successivo
        charRead = fread(buffer, sizeof(char), DIM_BUFFER, input); buffer[charRead] = '\0';
    }

    return ris;
}
