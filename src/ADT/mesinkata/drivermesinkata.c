#include <stdio.h>
#include "../mesinkarakterv2/mesinkarakterv2.h"
#include "mesinkata.h"

int main()
{
    char ch;
    int i;
    i = 0;
    system("cls||clear");
    printf("Ketik enter untuk melanjutkan program.\n");
    while (i < 2)
    {
        scanf("%c", &ch);
        system("cls||clear");
        if (i == 0)
        {
            printf("Menerima input dari user untuk dijadikan pita.\n"); 
            printf("Menggunakan STARWORD(NULL, 0) & ADVWORD(0))\n");
            printf("Kata dipisah setiap spasi. Pita dibaca hingga newline\n");
            printf("\nInput kata: ");
            STARTWORD(NULL, 0);
            int count = 1;
            while (currentChar != '\n')
            {
                printf("Kata ke - %d\n", count);
                for (int i = 0; i < currentWord.Length; i++)
                {
                    printf("%c", currentWord.TabWord[i]);
                }
                printf("\n");
                count++;
                ADVWORD(0);
            }
            printf("Kata ke - %d\n", count);
            for (int i = 0; i < currentWord.Length; i++)
            {
                printf("%c", currentWord.TabWord[i]);
            }
            printf("\n\n");
        }
        else if (i == 1)
        {
            printf("Membaca file untuk dijadikan pita.\n"); 
            printf("Menggunakan STARWORD(directory, 1) & ADVWORD(1))\n");
            printf("Kata dipisah setiap newline. Pita dibaca hingga MARK '.'\n(Dapat disebut kalimat)\n");
            printf("\n");
            STARTWORD("test.txt", 1);
            int count = 1;
            while (currentChar != MARK)
            {
                printf("Kalimat ke - %d\n", count);
                for (int i = 0; i < currentWord.Length; i++)
                {
                    printf("%c", currentWord.TabWord[i]);
                }
                printf("\n\n");
                count++;
                ADVWORD(1);
            }
        }
        i++;
    }
}
