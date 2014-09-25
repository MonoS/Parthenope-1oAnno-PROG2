#include <stdio.h>
#include <stdbool.h>

//const int DIM_STACK = 10;
#define DIM_STACK 10

typedef struct{
    int elem[DIM_STACK];
    int testa;
} tStack;

void InizializzaStack(tStack* stack);
bool StackVuoto(tStack stack);
bool StackPieno(tStack stack);
bool Push(tStack* stack, int elem);
bool Pop(tStack* stack, int* elem);
void Menu();

int main()
{
    Menu();

    return 0;
}

//Resettiamo la testa dello stack
void InizializzaStack(tStack* stack)
{
    (*stack).testa = -1;

    return;
}

bool StackVuoto(tStack stack)
{
    if (stack.testa == -1)
        return true;
    else
        return false;
}

bool StackPieno(tStack stack)
{
    if(stack.testa == (DIM_STACK - 1))
        return true;
    else
        return false;
}

bool Push(tStack* stack, int elem)
{
    if(!StackPieno(*stack))
    {
        (*stack).testa++;
        (*stack).elem[(*stack).testa] = elem;
        return true;
    }
    else
        return false;
}

bool Pop(tStack* stack, int* elem)
{
    if(!StackVuoto(*stack))
    {
        (*elem) = (*stack).elem[(*stack).testa];
        (*stack).testa--;
        return true;
    }
    else
        return false;
}

void Menu()
{
    int operazione;
    int elem;
    tStack stack;

    InizializzaStack(&stack);

    do{
        printf("1 - Pop\n");
        printf("2 - Push\n");
        printf("0 - Esci\n");

        scanf("%d", &operazione);

        switch(operazione)
        {
        case 1:
            if(Pop(&stack, &elem))
                printf("Valore estratto: %d\n", elem);
            else
                printf("Stack vuoto\n");

            break;

        case 2:
            printf("Inserisci il valore da inserire: ");
            scanf("%d", &elem);

            if(Push(&stack, elem))
                printf("Valore inserito\n");
            else
                printf("Stack pieno\n");

            break;

        case 0:
            printf("Uscita\n");

            break;

        default:
            printf("Operazione errata");

            break;
        }
    }while(operazione != 0);

    return;
}
