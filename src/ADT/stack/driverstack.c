#include <stdio.h>
#include "stack.h"

void PrintStack(Stack S)
{
    printf("[");
    for (int i = Top(S); i >= 0; i--)
    {
        if (i > 0)
        {
            printf("%s, ", S.T[i]);
        }
        else
        {
            printf("%s", S.T[i]);
        }
    }
    printf("]");
}

int main()
{
    int i;
    char ch;
    Stack S;
    infotypeStack val;
    i = 0;
    system("cls||clear");
    printf("Ketik enter untuk melanjutkan program.\n");
    while (i < 6)
    {
        scanf("%c", &ch);
        system("cls||clear");
        if (i == 0)
        {
            printf("Membentuk stack kosong.\n");
            CreateEmptyStack(&S);
            PrintStack(S); printf("\n");
            printf("IsEmptyStack = %d\n", IsEmptyStack(S));
            printf("IsFullStack = %d\n", IsFullStack(S));
            printf("Top(S) = %d\n", Top(S));
            printf("InfoTop(S) = %s\n", InfoTop(S));
        }
        else if (i == 1)
        {
            printf("Push satu elemen ke dalam stack.\n");
            Push(&S, "TestElemen");
            PrintStack(S); printf("\n");
            printf("IsEmptyStack = %d\n", IsEmptyStack(S));
            printf("IsFullStack = %d\n", IsFullStack(S));
            printf("Top(S) = %d\n", Top(S));
            printf("InfoTop(S) = %s\n", InfoTop(S));
        }
        else if (i == 2)
        {
            printf("Push dua elemen ke dalam stack.\n");
            Push(&S, "TestElemen2");
            Push(&S, "TestElemen3");
            PrintStack(S); printf("\n");
            printf("IsEmptyStack = %d\n", IsEmptyStack(S));
            printf("IsFullStack = %d\n", IsFullStack(S));
            printf("Top(S) = %d\n", Top(S));
            printf("InfoTop(S) = %s\n", InfoTop(S));  
        }
        else if (i == 3)
        {
            printf("Pop dua elemen dari stack.\n");
            Pop(&S, &val);
            printf("Pop pertama\n");
            PrintStack(S); printf("\n");  
            printf("Val = %s\n\n", val);
            Pop(&S, &val);
            printf("Pop kedua\n");
            PrintStack(S); printf("\n");
            printf("Val = %s\n\n", val);
            printf("IsEmptyStack = %d\n", IsEmptyStack(S));
            printf("IsFullStack = %d\n", IsFullStack(S));
            printf("Top(S) = %d\n", Top(S));
            printf("InfoTop(S) = %s\n", InfoTop(S));
        }
        else if (i == 4)
        {
            printf("Pop satu elemen dari stack. (Stack menjadi kosong)\n");
            Pop(&S, &val);
            PrintStack(S); printf("\n");
            printf("Val = %s\n", val);
            printf("IsEmptyStack = %d\n", IsEmptyStack(S));
            printf("IsFullStack = %d\n", IsFullStack(S));
            printf("Top(S) = %d\n", Top(S));
            printf("InfoTop(S) = %s\n", InfoTop(S));
        }
        else if (i == 5)
        {
            printf("Push elemen ke dalam stack hingga penuh.\n");
            for (int j = 0; j < 99; j++)
            {
                Push(&S, "TestElemen");
            }
            Push(&S, "TestElemen100");
            PrintStack(S); printf("\n");
            printf("IsEmptyStack = %d\n", IsEmptyStack(S));
            printf("IsFullStack = %d\n", IsFullStack(S));
            printf("Top(S) = %d\n", Top(S));
            printf("InfoTop(S) = %s\n", InfoTop(S)); 
        }
        i++;
    }
}