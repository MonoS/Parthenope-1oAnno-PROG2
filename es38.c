#include <stdio.h>

typedef struct{
    char nome[64];
    int next;
} tNome;

void ScorriLista(int start, tNome lista[]);

int main()
{
    tNome lista[4] = {{"d", -1},{"a", 3},{"c", 0},{"b", 2}};
    int start = 1;
    int i;

    for(i = 0; i < 4; i++)
        printf("%s\n", lista[i].nome);

    printf("\n");

    ScorriLista(start, lista);

    return 0;
}

void ScorriLista(int start, tNome lista[])
{
    do{
        printf("%s\n",lista[start].nome);

        start = lista[start].next;
    }while(start != -1);

    return;
}
