#include "includes.h"

int power(int number, int power)
{
    int result = number;
    for (int i = 1; i < power; i++)
    {
        result *= number;
    }
    return result;
}

boolean compareString(char *string1, char *string2)
{
    while (*string1 != '\0' || *string2 != '\0')
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

char* int_to_string(int num){
    if(num == 0){
        char* result = "0";
        return result;
    }
    else{
        int temp;
        char* result;
        int idx_max = -1;
        temp = num;
        while (temp != 0){
            idx_max++;
            temp /= 10;
        }
        result = malloc ((idx_max+2)*sizeof(char));
        result[idx_max+1]='\0';
        while (num!=0)
        {
            temp = num%10;
            num/=10;
            result[idx_max] = temp+'0';
            idx_max--;
        }
        return result;
    }
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

int stringLen(char *string)
{
    int i = 0;
    int count = 0;
    while (string[i]!='\0') {
        count++;
        i++;
    }
    return count;
}

char* upper(char *string)
{
    char *uppered;
    uppered = (char *) malloc (50 * sizeof(char));
    for (int i = 0; i < stringLen(string); i++)
    {
        if (string[i] >= 97 && string[i] <= 122)
        {
            uppered[i] = string[i] - 32;
        }
        else
        {
            uppered[i] = string[i];
        }
    }
    uppered[stringLen(string)] = '\0';
    return uppered;
}

char* lower(char *string)
{
    char *lowered;
    lowered = (char *) malloc (50 * sizeof(char));
    for (int i = 0; i < stringLen(string); i++)
    {
        if (string[i] >= 65 && string[i] <= 90)
        {
            lowered[i] = string[i] + 32;
        }
        else
        {
            lowered[i] = string[i];
        }
    }
    lowered[stringLen(string)] = '\0';
    return lowered;
}

void addspace(char *string, int space) {
    int i;
    int length = stringLen(string);
    int temp = length;
    while (length < temp + space)
    {
        string[length] = ' ';
        length+=1;
    }
    string[length] = '\0';
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
        if (currentWord.TabWord[i] < 48 || currentWord.TabWord[i] > 57)
        {
            return -9999;
        }
        else
        {
        value += (currentWord.TabWord[i] - 48) * satuan;
        satuan *= 10;
        i--;
        }
    }
    return value;
}

int stringToInteger(char *string)
{
    int value = 0;
    int satuan = 1;
    int i = stringLen(string) - 1;
    while (i > 0)
    {
        if (string[i] < 48 || string[i] > 57)
        {
            return -9999;
        }
        else
        {
        value += (string[i] - 48) * satuan;
        satuan *= 10;
        i--;
        }
    }
    return value;
}

char* splitStringInt(char *string, int *number)
{
    int i = 0;
    char *temp;
    temp = (char *) malloc (stringLen(string) * sizeof(char));
    while (*string != BLANK)
    {
        temp[i] = *string;
        i++;
        string++;
    }
    temp[i] = '\0';
    i = 0;

    char *num;
    num = (char *) malloc (3 * sizeof(char));
    while (*string != '\0')
    {
        num[i] = *string;
        i++;
        string++;
    }
    num[i] = '\0';
    *number = stringToInteger(num);
    free(num);
    return temp;
}

void inputString(int type, char* value)
{
    STARTWORD(NULL, type);
    wordToString(currentWord, value);
}

void inputInteger(int *value)
{
    STARTWORD(NULL, 0);
    *value = wordToInteger(currentWord); 
}

int randomNumber(int lowerlimit, int upperlimit)
{
    int number;
    number = (rand() % (upperlimit - lowerlimit + 1)) + lowerlimit;
    return number; 
}

char* getCurrentWord(Word string){
    char* string1 = malloc ((string.Length)*sizeof(char));
    int i;
    for(i=0;i<string.Length;i++){
        string1[i]=string.TabWord[i];
    }
    string1[i] = '\0';
    return string1;
}

void inputNamaScoreboard(ArrayDin *Games, Queue *GamesQueue, ArrayDin_SB *Scoreboard, int Skor)
{
    char *nama;
    nama = (char *) malloc (50 * sizeof(char));
    printf("Nama (Max. 11 karakter): ");
    inputString(0, nama);
    while (stringLen(nama) > 11)
    {
        printf("\nNama melebihi batas maximum.\n");
        printf("Nama (Max. 11 karakter): ");
        inputString(0, nama);
    }
    if (stringLen(nama) > 11)
    {
        nama[11] = '\0';
    }
    if (!IsMember_M(Scoreboard->A[SearchArrayDin(*Games, HEAD(*GamesQueue))], nama))
    {
        Insert_M(&Scoreboard->A[SearchArrayDin(*Games, HEAD(*GamesQueue))], nama, Skor);
    }
    else
    {
        printf("\nNama sudah dipakai. Silahkan input nama lain.\n");
        inputNamaScoreboard(Games, GamesQueue, Scoreboard, Skor);
    }
    SortValueMap(&Scoreboard->A[SearchArrayDin(*Games, HEAD(*GamesQueue))], false);
}
