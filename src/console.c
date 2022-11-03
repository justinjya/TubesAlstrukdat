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

int wordToInteger(Word currentWord)
{
    int value = 0;
    int satuan = 1;
    int i = currentWord.Length - 1;
    while (i >= 0)
    {
        value += (currentWord.TabWord[i] - 48) * satuan;
        satuan *= 10;
        i--;
    }
    return value;
}

void inputString(int type, char* value)
{
    STARTWORD(NULL, type);
    wordToString(currentWord, value);
}

void STARTBNMO(ArrayDin *Games)
{
    LOADFILE(Games, "config");
}

void LOADFILE(ArrayDin *Games, char *inputfile)
{
    char placeholder[] = ".\\data\\";
    char directory[50];
    char txt[] = ".txt";
    char filename[25];

    concat(inputfile, txt, filename);
    concat(placeholder, filename, directory);

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
        STARTWORD(directory, 1);
        wordToString(currentWord, string);
        amount = atoi(string);
        ADVWORD(1);
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
            ADVWORD(1);
        }
        if (directory == "config.txt")
        {
            printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
        }
        else
        {
            printf("File %s berhasil dibaca. BNMO berhasil dijalankan.\n", inputfile);
        }   
    }
}

void SAVE(ArrayDin *Games, char *inputfile)
{
    char placeholder[] = ".\\data\\";
    char directory[50];
    char txt[] = ".txt";
    char filename[25];

    concat(inputfile, txt, filename);
    concat(placeholder, filename, directory);

    FILE *open;
    open = fopen(directory, "w");

    fprintf(open, "%d\n", Games->Neff);
    for (int i = 0; i < Games->Neff; i++)
    {
        fprintf(open, "%s\n", Games->A[i]);
    }

    fprintf(open, ".");
    fclose(open);
    printf("Save file berhasil disimpan.\n");
}

void CREATEGAME (ArrayDin *arrayGames){
    char *gamesname;
    int i = 0;
    boolean found = false;

    /* Input game yang ingin ditambah */
    printf("Masukkan nama game yang akan ditambahkan: "); scanf("%[^\n]", &gamesname);
    
    /* Proses pencarian nama games yang diinput apakah sudah terdaftar sebelumnya */
    for (i; i < (*arrayGames).Neff; i++){
        if ((*arrayGames).A[i] == gamesname){
            found = true;
        }
    }
    if (found) /* Kondisi ketika game belum terdaftar */{
        InsertLast(arrayGames, gamesname);
        printf("Game berhasil ditambahkan");
    } else /* Kondisi ketika game seudah terdaftar */{
        printf("Game sudah terdaftar");
    }
}

#include <stdio.h>
#include "arraydin.c"

void LISTGAME (ArrayDin arrayGames){
    int i = 0;
    printf("Berikut adalah daftar game yang tersedia");
    
    for (i; i < arrayGames.Neff; i++){
        printf("%d. %s\n", i + 1, arrayGames.A[i]);
    }
}

