#include "includes.h"

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
    while (i >= 0)
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

void inputString(int type, char* value)
{
    STARTWORD(NULL, type);
    wordToString(currentWord, value);
}

void inputInteger(int *value)
{
    STARTWORD(NULL, 1);
    *value = wordToInteger(currentWord); 
}

int randomNumber(int lowerlimit, int upperlimit)
{
    srand(time(NULL));
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

void INPUTNAMASCOREBOARD(int Skor)
{
    char *nama;
    nama = (char *) malloc (25 * sizeof(char));
    printf("Nama: ");
    inputString(0, nama);
}