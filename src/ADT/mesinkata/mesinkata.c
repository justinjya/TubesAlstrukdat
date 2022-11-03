#include <stdio.h>
#include "mesinkata.h"
#include "C:\Users\Legion\OneDrive - Institut Teknologi Bandung\vscode\C\tubes\src\ADT\mesinkarakterv2\mesinkarakterv2.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks(int type)
{
    while (currentChar == ' ')
    {
        ADV(type);
    }
}

void STARTWORD(char *directory, int type)
{
    if (type == 0)
    {
        START(directory, type);
        IgnoreBlanks(type);
        if (currentChar == '\n')
        {
            EndWord = true;
        }
        else
        {
            EndWord = false;
            CopyWord(type);
        }
    }
    else
    {
        START(directory, type);
        IgnoreBlanks(type);
        if (currentChar == '\n' || currentChar == MARK)
        {
            EndWord = true;
        }
        else
        {
            EndWord = false;
            CopyWord(type);
        }
    }
}

void ADVWORD(int type)
{
    if (type == 0)
    {
        IgnoreBlanks(type);
        if (currentChar == '\n')
        {
            EndWord = true;
        }
        else
        {
            CopyWord(type);
            IgnoreBlanks(type);
        }
    }
    else
    {
        ADV(type);
        if (currentChar == '\n' || currentChar == MARK)
        {
            EndWord = true;
        }
        else
        {
            CopyWord(type);
        }
    }
}

void CopyWord(int type)
{
    if (type == 0)
    {
        int i = 0;
        while ((currentChar != '\n') && (currentChar != BLANK))
        {
            currentWord.TabWord[i] = currentChar;
            ADV(type);
            i++;
        }
        currentWord.TabWord[i] = '\0';

        if (i > NMax)
        {
            currentWord.Length = NMax;
        }
        else
        {
            currentWord.Length = i;
        }
    }
    else
    {
        int i = 0;
        while (currentChar != MARK && currentChar != '\n')
        {
            currentWord.TabWord[i] = currentChar;
            ADV(type);
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
}

boolean isEndWord()
{
    return EndWord;
}
