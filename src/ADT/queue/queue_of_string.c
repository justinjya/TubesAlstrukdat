#include <stdio.h>
#include <stdlib.h>
#include "queue_of_string.h"

boolean IsQueueOfStringEmpty(QueueOfString Q)
{
    return Q.HEAD == NIL && Q.TAIL == NIL;
}

boolean IsQueueOfStringFull(QueueOfString Q)
{
    return LengthQueueOfString(Q) == Q.MaxEl;
}

int LengthQueueOfString(QueueOfString Q)
{
    if (IsQueueOfStringEmpty(Q))
    {
        return 0;
    }
    else
    {
        int length = 0;
        if (Q.HEAD <= Q.TAIL)
        {
            for (IdxType i = Q.HEAD; i <= Q.TAIL; i++)
            {
                length++;
            }
        }
        else
        {
            for (IdxType i = Q.HEAD; i < Q.MaxEl; i++)
            {
                length++;
            }
            for (IdxType i = 0; i <= Q.TAIL; i++)
            {
                length++;
            }
        }
        return length;
    }
}

int MaxLengthQString(QueueOfString Q)
{
    return Q.MaxEl;
}

QueueOfString CreateQueueOfString(int Max)
{
    QueueOfString Q;
    Q.Tab = (ElType *) malloc (Max * sizeof(ElType));
    Q.MaxEl = Max;
    Q.HEAD = NIL;
    Q.TAIL = NIL;
    return Q;
}

void DeleteQueueOfString(QueueOfString *Q)
{
    free(Q->Tab);
    Q->MaxEl = 0;
}

void PushString(QueueOfString *Q, ElType X)
{
    if (IsQueueOfStringEmpty(*Q))
    {
        Q->HEAD = 0;
        Q->TAIL = 0;
        Q->Tab[Q->HEAD] = X;
    }
    else
    {
        if (Q->TAIL == Q->MaxEl - 1)
        {
            Q->TAIL = 0;
            Q->Tab[Q->TAIL] = X;
        }
        else
        {
            Q->TAIL++;
            Q->Tab[Q->TAIL] = X;
        }
    }
}

ElType PopString(QueueOfString *Q)
{
    ElType val;
    val = Q->Tab[Q->HEAD];
    if (LengthQueueOfString(*Q) == 1)
    {
        Q->HEAD = NIL;
        Q->TAIL = NIL;
    }
    else
    {
        Q->HEAD = (Q->HEAD + 1) % Q->MaxEl;
    }
    return val;
}

ElType FrontString(QueueOfString Q)
{
    return Q.Tab[Q.HEAD];
}