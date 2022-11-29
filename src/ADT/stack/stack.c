#include <stdio.h>
#include "stack.h"

void CreateEmptyStack(Stack *S)
{
    Top(*S) = Nil;
}

boolean IsEmptyStack(Stack S)
{
    return Top(S) == Nil;
}

boolean IsFullStack(Stack S)
{
    return Top(S) == CAPACITY - 1;
}

void Push(Stack *S, infotypeStack X)
{
    if (IsEmptyStack(*S))
    {
        Top(*S) = 0;
        InfoTop(*S) = X;
    }
    else
    {
        if (!IsFullStack(*S))
        {
            Top(*S)++;
            InfoTop(*S) = X;
        }
    }
}

void Pop(Stack *S, infotypeStack *X)
{
    *X = InfoTop(*S);
    if (Top(*S) == 0)
    {
        Top(*S) = Nil;
    }
    else
    {
        Top(*S)--;
    }
}