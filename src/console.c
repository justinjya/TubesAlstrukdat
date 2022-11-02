#include "console.h"

boolean compareString(char *string1, char *string2)
{
    while (*string1 != '\0' && *string2 != '\0')
    {
        if (*string1 != *string2)
        {
            return false;
        }
        string1++;
        string2++;
    }
    return true;
}

void concat(char *string1, char *string2, char *string3)
{
    int i = 0;
    int j = 0;

    while (string1[i] != '\0') {
        string3[j] = string1[i];
        i++;
        j++;
    }

    i = 0;
    while (string2[i] != '\0') {
        string3[j] = string2[i];
        i++;
        j++;
    }
    string3[j] = '\0';
}

void wordToString(Word currentWord, char *string)
{
    int i = 0;
    while (i < currentWord.Length)
    {
        string[i] = currentWord.TabWord[i];
        i++;
    }
    string[i] = '\0';
}

void STARTBNMO(ArrayDin *Games)
{
    char placeholder[] = ".\\data\\";
    char directory[50];

    concat(placeholder, "config.txt", directory);

    char string[50];
    char *temp;
    int i;
    int amount;

    STARTWORD(directory);
    wordToString(currentWord, string);
    amount = atoi(string);
    ADVWORD();
    for (int j = 0; j < amount; j++)
    {
        wordToString(currentWord, string);
        temp = (char *) malloc (currentWord.Length * sizeof(char));
        i = 0;
        while (i <= currentWord.Length)
        {
            temp[i] = string[i];
            i++;
        }
        InsertLast(Games, temp);
        ADVWORD();
    }
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}

void LOADFILE(ArrayDin *Games, ArrayDin *History, char *inputfile)
{
    char placeholder[] = ".\\data\\";
    char directory[50];
    
    concat(placeholder, inputfile, directory);

    char string[50];
    char *temp;
    int i;
    int amount;
    int arrayNumber = 0;

    START(directory);
    if (pita == NULL)
    {
        printf("File tidak dapat dibuka. Silahkan masukkan nama file lain.\n");
    }
    else
    {
        fclose(pita);
        STARTWORD(directory);
        while (arrayNumber < 2)
        {
            wordToString(currentWord, string);
            amount = atoi(string);
            ADVWORD();
            for (int j = 0; j < amount; j++)
            {
                wordToString(currentWord, string);
                temp = (char *) malloc (currentWord.Length * sizeof(char));
                i = 0;
                while (i <= currentWord.Length)
                {
                    temp[i] = string[i];
                    i++;
                }
                if (arrayNumber == 0)
                {
                    InsertLast(Games, temp);
                }
                else
                {
                    InsertLast(History, temp);
                }
                ADVWORD();
            }
            arrayNumber++;
        }
        printf("File %s berhasil dibaca. BNMO berhasil dijalankan.\n", inputfile);
    }
}

void SAVE(ArrayDin *Games, ArrayDin *History, char *inputfile)
{
    char placeholder[] = ".\\data\\";
    char directory[50];

    concat(placeholder, inputfile, directory);

    FILE *open;
    open = fopen(directory, "w");

    fprintf(open, "%d\n", Games->Neff);
    for (int i = 0; i < Games->Neff; i++)
    {
        fprintf(open, "%s\n", Games->A[i]);
    }

    fprintf(open, "%d\n", History->Neff);
    for (int i = 0; i < History->Neff; i++)
    {
        fprintf(open, "%s\n", History->A[i]);
    }
    printf("Save file berhasil disimpan.\n");
    fclose(open);
}
