#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OCCORRENZE 16
#define MAX_STR 32
#define OCCORRENZE 16

int TrovaOccorrenze_Stat(char* str, char* substr, char* occorrenze[]);
int SostituisciOccorrenze_Stat(char* str, char* substr, char* sosstr);

int TrovaOccorrenze_Dina(char* str, char* substr, char** occorrenze[]);
int SostituisciOccorrenze_Dina(char* str, char* substr, char* sosstr);

int main()
{
    char strStat[MAX_STR] = "1230045600789";
    char* strDina;
    char* strSub = "00";
    char* strSos = "0";

    strDina = malloc(sizeof(char)*14);
    strcpy(strDina, "1230045600789");

    printf("Orig: %s\n", strStat);
    printf("Sub : %s\n", strSub);
    printf("Sos : %s\n", strSos);
    SostituisciOccorrenze_Stat(strStat, strSub, strSos);
    printf("Stat: %s\n", strStat);
    SostituisciOccorrenze_Dina(strDina, strSub, strSos);
    printf("Dina: %s\n", strStat);

    return 0;
}

int TrovaOccorrenze_Stat(char* str, char* substr, char* occorrenze[])
{
    int i;
    char* temp;
    int lenSub;

    lenSub = strlen(substr);
    i = 0; temp = strstr(str,substr); //cerchiamo la prima occorrenza
    while(temp != NULL)
    {
        if(i < MAX_OCCORRENZE) //Controlliamo se non abbiamo riempito l'array delle occorrenze
        {
            occorrenze[i] = temp; //segnamoci l'indirizzo dell'occorrenzza
            i++;
            temp = strstr(temp+lenSub, substr); //cerchiamo la prossima
        }
        else
        {
            temp = NULL;
            i = -1;
        }
    }

    return i;
}

int SostituisciOccorrenze_Stat(char* str, char* substr, char* sosstr)
{
    int len, lenSub, lenSos, lenNew;
    char* occorrenze[MAX_OCCORRENZE+1]; //Ci serve un'occorrenza in più per segnarci la fine della stringa
    int occ;
    int i, j;
    int peso; //quanti caratteri sono stati spostati

    lenSub = strlen(substr);
    lenSos = strlen(sosstr);
    len = strlen(str);

    occ = TrovaOccorrenze_Stat(str, substr, occorrenze); //Cerchiamo tutte le occorrenze

    if (occ >= 0) //Controlliamo che non ci siano stati errori
    {
        if (lenSos < lenSub) //Controlliamo se la stringa da sostituire sia maggiore o minori di quella per la sostituzione
        {
            occorrenze[occ] = str + len; //Settiamo il termine della stringa nell'array delle occorrenze

            for(i = 0, peso = 0; i < occ; i++) //per ciascuna occorrenza
            {
                /*  Dobbiamo spostare un preciso numero di caratteri
                    (occorrenze[i+1] - occorrenze[i] -> Controlliamo quanti caratteri ci sono l'occorrenza attuale e quella successiva.
                    - lenSub -> togliamoci la lunghezza della sottostringa da sostituire.

                    In questo modo otteniamo quanti caratteri dobbiamo traslare tra le due occorrenze lasciando comunque spazio
                    per la stringa di sostituzione.
                */
                for(j = 0; j < (occorrenze[i+1] - occorrenze[i] - lenSub); j++, peso++)
                    /*  Dobbiamo copiare i caratteri prima dell'occorrenza successiva nella loro nuova posizione.
                        L'indirizzo di destinazione sarà dato da:
                        occorrenze[i] -> partendo dall'inizio dell'occorrenza
                        + ((lenSos)*(i+1)) -> aggungiamo i+1 volte la lunghezza della stringa da sostituire in modo da lasciare spazio per
                        la sostituzione
                        + j ->Aggiungiamo quanti caratteri abbiamo già traslato
                        - (lenSub*i) -> togliamo la lunghezza della sottostringa da sostituire

                        L'indirizzo di partenza invece sarà dato da:
                        occorrenze[i] -> L'inizio dell'occorrenza corrente
                        + lenSub -> la lunghezza della stringa di sostituzione
                        + j -> Il numero di caratteri già traslati
                    */
                    *(occorrenze[i] + ((lenSos)*(i+1)) + j - (lenSub*i)) = *(occorrenze[i] + lenSub + j);

                //Ora dobbiamo copiare la stringa sistitutiva
                for(j = 0; j < lenSos; j++, peso++)
                    /*  L'indirizzo di destinazione è dato da:
                        occorrenze[i] -> l'indirizzo dell'occorrenza attuale
                        ((lenSub - lenSos)*i) -> il totale dei caratteri che abbiamo risparmiato fin'ora
                        + j -> il numero di caratteri che abbiamo già spostato
                    */
                    *(occorrenze[i] - ((lenSub - lenSos)*i) + j) = sosstr[j];
            }

            str[(len - ((lenSub - lenSos)*occ))]  = '\0';
        }
        else if (lenSos > lenSub)
        {
            occorrenze[occ] = str + len;

            lenNew = (len + ((lenSos - lenSub)*occ));

            if (lenNew < MAX_STR) //Controlliamo che ci sia abbastanza spazio nella stringa
            {
                str[lenNew+1]  = '\0';

                for(i = occ - 1, peso = 0; i >= 0; i--) //Per ciascuna occorrenza, partendo dall'ultima
                {
                    /*  Dobbiamo spostare un preciso numero di caratteri
                        (occorrenze[i+1] - occorrenze[i] -> Controlliamo quanti caratteri ci sono l'occorrenza attuale e quella successiva.
                        - lenSub -> togliamoci la lunghezza della sottostringa da sostituire.

                        In questo modo otteniamo quanti caratteri dobbiamo traslare tra le due occorrenze.
                    */
                    for(j = (occorrenze[i+1] - occorrenze[i] - lenSub); j >= 0; j--, peso++)
                        /*  Dobbiamo copiare i caratteri tra le occorrenze in modo da fare spazio per la nuova stringa
                            L'indirizzo di destinazione sarà dato da:
                            occorrenze[i] -> dall'inizzio dell'occorrenza
                            + lenSub -> aggiungiamo la grandezza della stringa da sostituire
                            + ((lenSos - lenSub)*(i + 1)) -> Aggiungiamo i caratteri per fare spazio alla strinda di sostituzione
                            + j -> Il numero di caratteri già traslati
                        */
                        *(occorrenze[i] + lenSub + ((lenSos - lenSub)*(i + 1)) + j) = *(occorrenze[i] + lenSub + j);

                    for(j = 0; j < lenSos; j++, peso++)
                        /*  Ora dobbiamo copiare i caratteri della stringa di sostituzione
                            L'indirizzo di destinazione sarà dato da:
                            occorrenze[i] -> partendo dall'inizio dell'occorrenza
                            + ((lenSos - lenSub)*i) -> Aggiungiamo il numero di caratteri di correzione per fare spazio alle stringhe
                            che verranno aggiunte
                            + j -> il numero di caratteri già copiati
                        */
                        *(occorrenze[i] + ((lenSos - lenSub)*i) + j) = sosstr[j];

                }
            }
            else
                peso = -1;
        }
        else //nel caso le due stringhe siano uguali l'algoritmo procede con una semplice copia
        {
            for(i = 0, peso = 0; i < occ; i++)
            {
                for(j = 0; j < lenSos; j++, peso++)
                    *(occorrenze[i] + j) = sosstr[j];
            }
        }
    }

    return peso;
}

int TrovaOccorrenze_Dina(char* str, char* substr, char** occorrenze[])
{
    int i, k;
    char* temp;
	int lenSub;

    lenSub = strlen(substr);

    i = 0; temp = strstr(str,substr); k = 1; (*occorrenze) = malloc(sizeof(char*)*(OCCORRENZE));
    while(temp != NULL)
    {
        if(i > ((OCCORRENZE * k) - 1))
        {
            k++;
			(*occorrenze) = realloc(occorrenze, sizeof(char*) * (OCCORRENZE * k));
        }

		(*occorrenze)[i] = temp;
		i++;
		temp = strstr(temp+lenSub, substr);
    }

    return i;
}

int SostituisciOccorrenze_Dina(char* str, char* substr, char* sosstr)
{
    int len, lenSub, lenSos, lenNew;
    char** occorrenze;
    int occ;
    int i, j;
    int peso;

    lenSub = strlen(substr);
    lenSos = strlen(sosstr);
    len = strlen(str);

    occ = TrovaOccorrenze_Dina(str, substr, &occorrenze);

    if (occ >= 0)
    {
        if (lenSos < lenSub)
        {
            occorrenze[occ] = str + len;

            for(i = 0, peso = 0; i < occ; i++)
            {
                for(j = 0; j < (occorrenze[i+1] - occorrenze[i] - lenSub); j++, peso++)
                    *(occorrenze[i] + ((lenSos)*(i+1)) + j - (lenSub*i)) = *(occorrenze[i] + lenSub + j);

                for(j = 0; j < lenSos; j++, peso++)
                    *(occorrenze[i] - ((lenSub - lenSos)*i) + j) = sosstr[j];
            }

            lenNew = (len - ((lenSub - lenSos)*occ));
            str = realloc(str, lenNew);
            str[lenNew]  = '\0';
        }
        else if (lenSos > lenSub)
        {
            occorrenze[occ] = str + len;

            lenNew = (len + ((lenSos - lenSub)*occ));
            str = realloc(str, lenNew+1);

            str[lenNew+1]  = '\0';

            for(i = occ-1, peso = 0; i >= 0; i--)
            {
                for(j = (occorrenze[i+1] - occorrenze[i] - lenSub); j >= 0 ; j--, peso++)
                    *(occorrenze[i] + lenSub + ((lenSos - lenSub)*(i + 1)) + j) = *(occorrenze[i] + lenSub + j);

                for(j = 0; j < lenSos; j++, peso++)
                    *(occorrenze[i] + ((lenSos - lenSub)*i) + j) = sosstr[j];

            }
        }
        else
        {
            for(i = 0, peso = 0; i < occ; i++)
            {
                for(j = 0; j < lenSos; j++, peso++)
                    *(occorrenze[i] + j) = sosstr[j];
            }
        }
    }

    return peso;
}
