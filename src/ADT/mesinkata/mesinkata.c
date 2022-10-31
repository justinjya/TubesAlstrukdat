#include <stdio.h>
#include "mesinkata.h"
#include "C:\Users\Legion\OneDrive - Institut Teknologi Bandung\vscode\C\tubes\src\ADT\mesinkarakterv2\mesinkarakterv2.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    while (currentChar == ' ')
    {
        ADV();
    }
}

void STARTWORD(char *directory)
{
    START(directory);
    IgnoreBlanks();
    if (currentChar == '\n' || currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD()
{
    // IgnoreBlanks();
    ADV();
    if (currentChar == '\n' || currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        // IgnoreBlanks();
    }
}

void CopyWord()
{
    int i = 0;
    // while ((currentChar != '.') && (currentChar != BLANK))
    while (currentChar != MARK && currentChar != '\n')
    {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.TabWord[i] = '\n';

    if (i > NMax)
    {
        currentWord.Length = NMax;
    }
    else
    {
        currentWord.Length = i;
    }
}

boolean isEndWord()
{
    return EndWord;
}