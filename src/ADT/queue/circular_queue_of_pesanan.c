#include <stdio.h>
#include <stdlib.h>
#include "circular_queue_of_pesanan.h"

boolean IsQueueOfPesananEmpty(QueueOfPesanan Q)
{
    return Q.HEAD == NIL && Q.TAIL == NIL;
}

boolean IsQueueOfPesananFull(QueueOfPesanan Q)
{
    return LengthQueueOfPesanan(Q) == Q.MaxEl;
}

int LengthQueueOfPesanan(QueueOfPesanan Q)
{
    if (IsQueueOfPesananEmpty(Q))
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

int MaxLengthQPesanan(QueueOfPesanan Q)
{
    return Q.MaxEl;
}

pesanan CreatePesanan (char* makanan, int durasimasak, int ketahanan, int harga){
    pesanan pesanan;
    pesanan.makanan = makanan;
    pesanan.durasimasak = durasimasak;
    pesanan.ketahanan = ketahanan;
    pesanan.harga = harga;
    return pesanan;
}

QueueOfPesanan CreateQueueOfPesanan(int Max)
{
    QueueOfPesanan Q;
    Q.Tab = (pesanan *) malloc (Max * sizeof(pesanan));
    Q.MaxEl = Max;
    Q.HEAD = NIL;
    Q.TAIL = NIL;
    return Q;
}

void DeleteQueueOfPesanan(QueueOfPesanan *Q)
{
    free(Q->Tab);
    Q->MaxEl = 0;
}

void PushPesanan(QueueOfPesanan *Q, pesanan X)
{
    if (IsQueueOfPesananEmpty(*Q))
    {
        Q->HEAD = 0;
        Q->TAIL = 0;
        Q->Tab[Q->HEAD] = X;
    }
    else
    {   
        if(IsQueueOfPesananFull(*Q)){
            Q->MaxEl *= 2;
            Q->Tab = (pesanan *) realloc (Q->Tab, Q->MaxEl * sizeof(pesanan));
            if (Q->Tab != NULL){
                if(Q->HEAD > Q->TAIL){
                    int i;
                    for (i=0;i<=Q->TAIL;i++){
                        Q->Tab[i+LengthQueueOfPesanan(*Q)] = Q->Tab[i];
                    }
                    Q->TAIL = Q->HEAD + LengthQueueOfPesanan(*Q) - 1;
                }
                Q->TAIL = (Q->TAIL + 1)%Q->MaxEl;
                Q->Tab[Q->TAIL] = X;
            }
            else{
                printf("Maaf, alokasi gagal.\n");
            }
            // alokasi gagal
        }
        else{
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
}

pesanan PopPesanan(QueueOfPesanan *Q)
{
    if (!IsQueueOfPesananEmpty(*Q)){
        pesanan val;
        val = Q->Tab[Q->HEAD];
        if (LengthQueueOfPesanan(*Q) == 1)
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
}

pesanan FrontPesanan(QueueOfPesanan Q)
{
    return Q.Tab[Q.HEAD];
}