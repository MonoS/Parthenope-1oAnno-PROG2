#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* StrCat_Stat(char* str1, char* str2);
char* StrCat_Dina(char* str1, char* str2);

int main()
{
    char str1Stat[18] = "Stringa1"; //Dobbiamo prevedere la memoria anche per la seconda stringa
    char* str1Dina = "Stringa1";;
    char str1Stds[18] = "Stringa1";
    char* str2 = "1agnirtS";


    StrCat_Stat(str1Stat, str2);
    str1Dina = StrCat_Dina(str1Dina, str2);
    strcat(str1Stds, str2);

    printf("Statica: %s\n", str1Stat);
    printf("Dinamica:%s\n", str1Dina);
    printf("strcat   %s\n", str1Stds);

    return 0;
}

char* StrCat_Stat(char* str1, char* str2)
{
    int len1;
    int i;

    len1 = strlen(str1);

    for(i = 0; str2[i] != '\0'; i++)
        str1[i+len1] = str2[i];

    str1[i+len1] = '\0';

    return str1;
}

char* StrCat_Dina(char* str1, char* str2)
{
    int len1;
    int i;
    char* strNew;

    len1 = strlen(str1);
    strNew = malloc(sizeof(char)*(len1 + strlen(str2) + 1));

    if(strNew != NULL)
    {
        for(i = 0; str1[i] != '\0'; i++)
            strNew[i] = str1[i];

        for(i = 0; str2[i] != '\0'; i++)
            strNew[i+len1] = str2[i];
    }
    else
        abort();

    strNew[i+len1] = '\0';

    return strNew;
}
