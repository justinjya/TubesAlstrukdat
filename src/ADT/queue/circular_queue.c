#include <stdio.h>
#include <stdlib.h>
#include "circular_queue.h"

boolean IsEmpty(Queue Q)
{
    return Q.HEAD == NIL && Q.TAIL == NIL;
}

boolean IsFull(Queue Q)
{
    return Length(Q) == Q.MaxEl;
}

int Length(Queue Q)
{
    if (IsEmpty(Q))
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

int MaxLength(Queue Q)
{
    return Q.MaxEl;
}

Queue CreateQueue(int Max)
{
    Queue Q;
    Q.Tab = (ElType *) malloc (Max * sizeof(ElType));
    Q.MaxEl = Max;
    Q.HEAD = NIL;
    Q.TAIL = NIL;
    return Q;
}

void DeleteQueue(Queue *Q)
{
    free(Q->Tab);
    Q->MaxEl = 0;
}

void Push(Queue *Q, ElType X)
{
    if (IsEmpty(*Q))
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

ElType Pop(Queue *Q)
{
    ElType val;
    val = Q->Tab[Q->HEAD];
    if (Length(*Q) == 1)
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

ElType Front(Queue Q)
{
    return Q.Tab[Q.HEAD];
}