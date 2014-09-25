#include <stdio.h>

int main()
{
    int i, j, k;
    char* test = "1234567890";
    char* test1= "123456789!";
    char* test2= "123456789?";

    for(k = 0; k < 2; k++)
    {
        for(j = 0; j < 24; j++)
        {
            for(i = 0; i < 3; i++)
                printf("%s", test);
            printf("%s", test1);
        }

        for(i = 0; i < 3; i++)
            printf("%s", test);
        printf("%s", test2);
    }

    return 0;
}
