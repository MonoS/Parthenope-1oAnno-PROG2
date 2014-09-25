#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const char* FILE_ORIG = "studenti1.dat";
const char* FILE_DEST = "studenti2.dat";
const char* FILE_UPDT = "update.dat";

typedef struct{
    char nomeCognome[31];
    char matricola[10];
    short esamiSup;
    float mediaEsami;
    short crediti;
} tStudente;

typedef struct{
    char matricola[10];
    short voto;
    short crediti;
} tUpdate;

int AggiornaStudenti(char* fileUpdate);
int LeggiRecord(FILE* file, tStudente* studente);
int ScriviRecord(FILE* file, tStudente studente);
int LeggiUpdate(FILE* file, tUpdate* update);
tStudente UpdateRecord(tStudente studente, tUpdate update);

int main()
{
    return AggiornaStudenti(FILE_UPDT);
}

int AggiornaStudenti(char* fileUpdate)
{
    int ris;

    FILE* orig;
    FILE* dest;
    FILE* update;

    tStudente cor;
    tUpdate upd;

    bool trovato;

    orig = fopen(FILE_ORIG, "r");
    dest = fopen(FILE_DEST, "w");
    update = fopen(fileUpdate, "r"); //Si suppone che il file di update sia anch'esso ordinato

    ris = 0;
    if(orig != NULL)
    {
        if(dest != NULL)
        {
            if (update != NULL)
            {
                //Leggiamo ogni record nel file di aggioramento
                while((LeggiUpdate(update, &upd) > 0) && (ris >= 0))
                {
                    trovato = false;
                    do{
                        //Leggiamo il record nel file di origine
                        if(LeggiRecord(orig, &cor) > 0)
                        {
                            //Controlliamo se abbiamo trovato la matircola da aggiornare
                            if (strcmp(cor.matricola, upd.matricola) == 0)
                            {
                                ScriviRecord(dest, UpdateRecord(cor, upd));
                                trovato = true;
                                ris++;
                            }
                            else
                                ScriviRecord(dest, cor);
                        }
                        else
                            ris = -4; //Errore: Il file di origine è terminato ma ci sono ancora record nel file di aggiornamento

                    }while((!trovato) && (ris >= 0));
                }

                //Finiamo di scrivere i record restanti dal file di origine
                while(LeggiRecord(orig, &cor) > 0)
                    ScriviRecord(dest, cor);
            }
            else
                ris = -3; //Errore: impossibile aprire il file di aggiornamento
        }
        else
            ris = -2; //Errore: impossibile aprire il file di destinazione
    }
    else
        ris = -1; //Errore: impossibile aprire il file di origine

    return ris;
}

int LeggiRecord(FILE* file, tStudente* studente)
{
    return fscanf(file, "%30c%9c%hd%f%hd", (*studente).nomeCognome, (*studente).matricola, &(*studente).esamiSup, &(*studente).mediaEsami, &(*studente).crediti);
}

int ScriviRecord(FILE* file, tStudente studente)
{
    return fprintf(file, "%30s%9s%hd%f%hd", studente.nomeCognome, studente.matricola, studente.esamiSup, studente.mediaEsami, studente.crediti);
}

int LeggiUpdate(FILE* file, tUpdate* update)
{
    return fscanf(file, "%9c%hd%hd", (*update).matricola, &(*update).voto, &(*update).crediti);
}

tStudente UpdateRecord(tStudente studente, tUpdate update)
{
    tStudente aggiornato;

    strcpy(aggiornato.matricola, studente.matricola);
    strcpy(aggiornato.nomeCognome, studente.nomeCognome);
    aggiornato.esamiSup = studente.esamiSup + 1;
    aggiornato.crediti = studente.crediti + update.crediti;
    aggiornato.mediaEsami = (((studente.mediaEsami*studente.crediti) + update.voto) / aggiornato.crediti);

    return aggiornato;
}
