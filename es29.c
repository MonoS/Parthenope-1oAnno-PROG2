#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

inline int* AllocaMalloc(int m, int n);
inline void GeneraRandom(int m, int n, int* matrice);
inline int* AllocaCalloc(int m, int n);
inline void ProdMalloc(int* a, int* b, int* c, int m1, int n1, int n2);
inline void ProdCalloc(int* a, int* b, int* c, int m1, int n1, int n2);

typedef int* intP;

int main()
{
    double allocaMalloc, allocaCalloc, generaMalloc, generaCalloc, prodMalloc, prodCalloc;
    intP aM, aC, bM, bC, cM, cC;
    LARGE_INTEGER ticksPerSecond, TICKS1, TICKS2;
    int m1, n1, m2, n2;

    srand(time(NULL));

    m1 = 512; n1 = 512; m2 = 512, n2 = 512;

    QueryPerformanceFrequency(&ticksPerSecond); // processor clock frequency


    QueryPerformanceCounter(&TICKS1);

    aM = AllocaMalloc(m1, n1);
    bM = AllocaMalloc(m2, n2);
    cM = AllocaMalloc(m1, n2);

    QueryPerformanceCounter(&TICKS2);
    allocaMalloc = (double)(TICKS2.QuadPart - TICKS1.QuadPart)/(double)ticksPerSecond.QuadPart;

    /**************************************************************************/

    QueryPerformanceCounter(&TICKS1);

    aC = AllocaCalloc(m1, n1);
    bC = AllocaCalloc(m2, n2);
    cC = AllocaCalloc(m1, n2);

    QueryPerformanceCounter(&TICKS2);
    allocaCalloc = (double)(TICKS2.QuadPart - TICKS1.QuadPart)/(double)ticksPerSecond.QuadPart;

    /**************************************************************************/

    QueryPerformanceCounter(&TICKS1);

    GeneraRandom(m1, n1, aM);
    GeneraRandom(m2, n2, bM);

    QueryPerformanceCounter(&TICKS2);
    generaMalloc = (double)(TICKS2.QuadPart - TICKS1.QuadPart)/(double)ticksPerSecond.QuadPart;

    /**************************************************************************/

    QueryPerformanceCounter(&TICKS1);

    GeneraRandom(m1, n1, aC);
    GeneraRandom(m2, n2, bC);

    QueryPerformanceCounter(&TICKS2);
    generaCalloc = (double)(TICKS2.QuadPart - TICKS1.QuadPart)/(double)ticksPerSecond.QuadPart;

    /**************************************************************************/

    QueryPerformanceCounter(&TICKS1);

    ProdMalloc(aM, bM, cM, m1, n1, n2);

    QueryPerformanceCounter(&TICKS2);
    prodMalloc = (double)(TICKS2.QuadPart - TICKS1.QuadPart)/(double)ticksPerSecond.QuadPart;

    /**************************************************************************/

    QueryPerformanceCounter(&TICKS1);

    ProdCalloc(aC, bC, cC, m1, n1, n2);

    QueryPerformanceCounter(&TICKS2);
    prodCalloc = (double)(TICKS2.QuadPart - TICKS1.QuadPart)/(double)ticksPerSecond.QuadPart;

    printf("             Malloc              Calloc\n");
    printf("Allocazione: %10.3e          %10.3e\n", allocaMalloc, allocaCalloc);
    printf("Generazione: %10.3e          %10.3e\n", generaMalloc, generaCalloc);
    printf("Prodotto:    %10.3e          %10.3e\n", prodMalloc, prodCalloc);
    printf("Totale:      %10.3e          %10.3e\n", allocaMalloc+generaMalloc+prodMalloc, allocaCalloc+generaCalloc+prodCalloc);

    return 0;
}

inline int* AllocaMalloc(int m, int n)
{
    return malloc(sizeof(int)*m*n);
}

inline int* AllocaCalloc(int m, int n)
{
    return calloc(m*n, sizeof(int));
}

inline void ProdMalloc(int* a, int* b, int* c, int m1, int n1, int n2)
{
    int i, j, k;
    int somma;

    for(i = 0; i < m1; i++)
        for(j = 0; j < n2; j++)
        {
            for(k = 0, somma = 0; k < n1; k++)
                somma += *(a + (i*m1) + k) + *(b + (j*n2) + k);

            *(c + (i*n2) + j) = somma;
        }
}

inline void ProdCalloc(int* a, int* b, int* c, int m1, int n1, int n2)
{
    //avendo usato calloc invece che malloc siamo sicuri che tutte le celle delle
    //matrici sono settate a 0 e quindi non abbiamo bisogno dell'accumulatore
    int i, j, k;

    for(i = 0; i < m1; i++)
        for(j = 0; j < n2; j++)
            for(k = 0; k < n1; k++)
                *(c + (i*n2) + j) += *(a + (i*m1) + k) + *(b + (j*n2) + k);

    return;
}

inline void GeneraRandom(int m, int n, int* matrice)
{
    int i, j;

    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            *(matrice + (i*m) + j) = rand();

    return;
}
