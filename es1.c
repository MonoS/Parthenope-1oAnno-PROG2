#include <stdio.h>

char LowUpp(char c);

int main()
{
    char c;

    printf("Inserisci un carattere: ");
    scanf("%c", &c);

    c = LowUpp(c);

    printf("%c\n", c);

    return 0;
}

char LowUpp(char c)
{
    if((c >= 'a') && (c <= 'z')) //Controlliamo che il carattere sia minuscolo
    {
        c = c-'a'+'A'; //Convertiamolo in maiuscolo
    }
    else if((c >= 'A') && (c <= 'Z')) //Controlliamo che il carattere sia maiuscolo
    {
        c = c-'A'+'a'; //Convertiamo in minuscolo
    }

    return c;
}
