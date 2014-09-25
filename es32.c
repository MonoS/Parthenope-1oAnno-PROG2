#include <stdio.h>

#define BUFFER 200
#define RIGHE 25
#define COLONNE 40

void ReadBuffer(FILE* file);

int main(int argc, char** argv)
{
    FILE* file;

    file = fopen(argv[1], "r");

    ReadBuffer(file);

    return 0;
}

void ReadBuffer(FILE* file)
{

    char buffer[BUFFER];
    int caratteriLetti;
    int r, c;
    int i; //Rappresenta il numero totale di righe scritte

    caratteriLetti = 0;

    i = 0;
    do
    {
        for(r = 0; r < RIGHE; r++, i++)
        {
            if (i % (BUFFER/COLONNE) == 0) //nel caso il buffer si svuotase dobbiamo riempirlo
                caratteriLetti = fread((void*)buffer, sizeof(char), BUFFER, file);

            if(caratteriLetti > 0)
            {
                for(c = 0; c < COLONNE; c++)
                {
                    //Controlliamo se possiamo ancora leggere altri carattei
                    if((((r % (BUFFER/COLONNE)) * COLONNE) + c) < caratteriLetti)
                        putchar(buffer[(((r % (BUFFER/COLONNE)) * COLONNE) + c)]);
                    else
                        c = COLONNE;
                }

                putchar('\n');
            }
            else
                r = RIGHE;
        }

        printf("Premi un tasto per continuare\n");
        getchar();
    }while (caratteriLetti > 0);

    return;
}
