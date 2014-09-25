#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char* StrStr(char* str, char* substr);

int main()
{
    char* str = "SonoFattiMiei";
    char* substr = "Fatti";
    char* resMio;
    char* resStd;

    resMio = StrStr(str, substr);
    resStd = strstr(str, substr);

    printf("Mia strstr: %s\n", resMio);
    printf("Std strstr: %s\n", resStd);

    return 0;
}

char* StrStr(char* str, char* substr)
{
    int i, j;
    bool continua; //Se abbiamo trovato la sottostringa non dobbiamo continuare

    i = 0; continua = true;
    while((str[i] != '\0') && (continua))
    {
        if(str[i] == substr[0]) //Se troviamo nella stringa il primo carattere della sottostringa dobbiamo andare a cercare il resto
        {
            j = 1;

            while((str[i+j] == substr[j]) && (str[i+j] != '\0'))
                j++;

            if(substr[j] == '\0') //Se raggiungiamo la fine della sottostringa vuol dire l'abbiamo trovata, dobbiamo fermarci
                continua = false;
        }
        else
            i++;
    }

    if(str[i] == '\0')
        return NULL;
    else
        return &str[i];
}
