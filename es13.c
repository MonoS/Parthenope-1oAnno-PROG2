#include <stdio.h>
#include <stdbool.h>
#include <math.h>

float MyAtof2(char* flt);
bool ControlloSegno(char** flt);

//Queste definizioni sono inutili, ma non ce la faccio a cancellarle
float myAtof(char* flt);
float BuildFloat(bool segno, char esp, int mantissa);
long long ConvertiInt(char* flt);
long long ConvertiDec(char* flt);
int ContaPos(int a);
char* CercaPunto(char* flt);
const int POS_ESP = 8;
const int POS_MAN = 23;
const int BIAS = 127;

int main()
{
    char cifre[128];
    float ris;

    printf("Inseire il numero float da convertire: ");
    scanf("%127s", cifre);

    ris = MyAtof2(cifre);

    printf("%f", ris);

    return 0;
}

float MyAtof2(char* flt)
{
    bool segno;
    float n;
    bool punto;

    int i, k;

    segno = ControlloSegno(&flt); //Controlliamo il segno del numero

    for(n = 0, i = 0, punto = false, k = 1; flt[i] != '\0'; i++)
    {
        if ((flt[i] == '.') || (flt[i] == ',')) //Controlliamo ad ogni passo se abbiamo raggiunto il punto
            punto = true;
        else
        {
            if (!punto)
            {   //Se non abbiamo raggiunto il punto stiamo su una cifra intera
                n = n*10; //Dobbiamo moltiplicare il numero per fare spazio alla nuova cifra
                n += (flt[i] - 48);
            }
            else
            {   //Altrimenti abbiamo superato il punto, siamo su una cifra decimale
                n += ((flt[i] - 48)/(pow(10,k))); //Dobbiamo dividere la cifra per ottenre il giusto valore decimale
                k++;
            }
        }
    }

    if (segno) //Se il segno era negativo, ci serve l'opposto
        n = -n;

    return n;
}

bool ControlloSegno(char** flt)
{
    bool segno;

    //Se il primo carattere è il segno, dobbiamo segnarlo e andare avanti
    if(*flt[0] == '+')
    {
        segno = false;
        (*flt)++;
    }
    else if(*flt[0] == '-')
    {
        segno = true;
        (*flt)++;
    }
    else //Se non c'è alcun segno assumiamo un numero positivo
        segno = false;

    return segno;
}


//Tutto ciò che c'è qui sotto dovrebbe essere cancellato, ma non ce la faccio, sono pur sempre umano
//Non sapendo se deve essere fatta in questo modo risparmio ulteriore mal di testa
float myAtof(char* flt)
{
    char esp;
    int mantissa;
    bool segno;

    char* punto;

    long long parteInt;
    long long parteDec;

    int cifreInt;
    int cifreDec;

    long long temp;

    float ris;

    if(strcmp(flt,"NaN")) //Controlliamo se è NaN
    {
        esp = 255;
        if(mantissa == 0)
            mantissa++;
    }
    else
    {
        segno = ControlloSegno(&flt); //Controlliamo il segno

        if (strcmp(flt, "inf")) //Controlliamo se è infinito
        {
            esp = 255;
            mantissa = 0;
        }
        else
        {
            punto = CercaPunto(flt); //Cerchiamo il punto

            if (punto != NULL) //Se abbiamo un punto prendiamo le cifre decimali
            {
                *punto = '\0';
                punto++;
            }

            //prendiamoci la parte intera
            parteInt = ConvertiInt(flt);
            cifreInt = ContaCifre(parteInt);

            //Controlliamo la parte decimale solo se ci sta spazio nella mantissa
            if(cifreInt < POS_MAN)
            {
                if(punto != NULL)
                {
                    parteDec = ConvertiDec(punto);
                    cifreDec = ContaCifre(parteDec) - 1; //togliamo 1 per tener segno del bit fittizio
                }
                else //Se non c'è punto non abbiamo alcuna parte decimale
                {
                    parteDec = 0;
                    cifreDec = 0;
                }
            }

            /**if(ZOMETHING)
            {

            }

            }**/

            temp = parteInt << cifreDec;
            temp = temp|parteDec;

            if(cifreDec+cifreInt > POS_MAN)
                temp >> (cifreDec+cifreInt-POS_MAN);
        }
    }

    //Costruiamo il numero colle informazioni che abbiamo ottenuto
    ris = BuildFloat(segno, esp, mantissa);

    return ris;
}

float BuildFloat(bool segno, char esp, int mantissa)
{
    long ris;

    ris = 0; //resettiamo la variabile

    if(segno)
        ris = 1<<POS_ESP; //Aggiungiamo il segno e shiftiamo per far spazio all'esponente

    ris = ris|esp; //Aggiungiamo l'esponente

    ris = ris<<POS_MAN; //Shiftiamo per far spazio alla mantissa

    ris = ris|mantissa; //Aggiungiamo la mantissa

    return (float)ris;
}

long long ConvertiInt(char* flt)
{
    return atoi(flt);
}

long long ConvertiDec(char* flt)
{
    double dec;
    int i;
    long long ris;

    dec = atoi(flt)/(pow(10,strlen(flt))); //Otteniamo il nostro numero decimale

    ris = 2; // Aggiungiamo una cifra decimale aggiuntiva per tener conto delle cifre significative
    i = 0;
    while((i < POS_MAN) && (dec > 0)) //Applichiamo l'algoritmo di moltiplicazione per la base
    {
        dec *= 2;
        if(dec >= 1)
        {
            ris += 1;
            ris = ris << 1;

            dec -= 1;
        }
        else
            ris = ris << 1;

        i++;
    }

    return ris;
}

int ContaPos(int a)
{
    int i;

    while (a > 0)
    {
        i++;
        a = a>>1;
    }

    return i;
}

char* CercaPunto(char* flt)
{
    char* punto;

    punto = strstr(flt, ",");

    if (punto == NULL)
        punto = strstr(flt, ".");

    return punto;
}

int ContaCifre(char* flt)
{
    return 0;
}
