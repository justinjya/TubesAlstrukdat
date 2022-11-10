#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    while (currentChar == ' ')
    {
        ADV();
    }
}

void STARTWORD(char *directory, int type)
{
    if (type == 0)
    {
        START(directory);
        IgnoreBlanks();
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
        START(directory);
        IgnoreBlanks();
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
        IgnoreBlanks();
        if (currentChar == '\n')
        {
            EndWord = true;
        }
        else
        {
            CopyWord(type);
            IgnoreBlanks();
        }
    }
    else
    {
        ADV();
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
    else
    {
        int i = 0;
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
}

boolean isEndWord()
{
    return EndWord;
}
