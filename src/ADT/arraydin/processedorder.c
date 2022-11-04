#include <stdio.h>
#include <stdlib.h>
#include "processedorder.h"

masakan MakeMasakan(char* makanan, int sisa_durasi_or_ketahanan_masakan){
    masakan m;
    m.makanan = makanan;
    m.sisa_durasi_or_ketahanan_masakan = sisa_durasi_or_ketahanan_masakan;
    return m;
}

processedorder MakeProcessedOrder(int size)
{
    processedorder processedorder;
    processedorder.A = (masakan *) malloc (size * sizeof(processedorder));
    processedorder.Capacity = size;
    processedorder.Neff = 0;
    return processedorder;
}

boolean IsProcessedOrderEmpty(processedorder processedorder)
{
    return processedorder.Neff == 0;
}

int LengthOfProcessedOrder(processedorder processedorder)
{
    return processedorder.Neff;
}

masakan GetProcessedOrder(processedorder processedorder, IdxType i)
{
    return processedorder.A[i];
}

int GetProcessedOrderCapacity(processedorder processedorder)
{
    return processedorder.Capacity;
}

void InsertProcessedOrderAt(processedorder *processedorder, masakan masakkan, IdxType i)
{
    if (processedorder->Neff == processedorder->Capacity)
    {
        processedorder->Capacity *= 2;
        processedorder->A = (masakan *) realloc (processedorder->A, processedorder->Capacity * sizeof(masakan));
    }
    IdxType temp = processedorder->Neff;
    while (temp > i)
    {
        processedorder->A[temp] = processedorder->A[temp - 1];
        temp--;
    }
    processedorder->A[i].makanan = masakkan.makanan;
    processedorder->A[i].sisa_durasi_or_ketahanan_masakan = masakkan.sisa_durasi_or_ketahanan_masakan;
    processedorder->Neff++;
}

void InsertProcessedOrderLast(processedorder *processedorder, masakan masakkan)
{
    InsertProcessedOrderAt(processedorder, masakkan, processedorder->Neff);
}

void InsertProcessedOrderFirst(processedorder *processedorder, masakan masakkan)
{
    InsertProcessedOrderAt(processedorder, masakkan, 0);
}

void DeleteProcessedOrderAt(processedorder *processedorder, IdxType i)
{
    IdxType temp = i;
    while (temp < processedorder->Neff - 1)
    {
        processedorder->A[temp] = processedorder->A[temp + 1];
        temp++;
    }

    if (processedorder->Neff > 1)
    {
        processedorder->Neff--;
    }
    else
    {
        processedorder->Neff = 0;
    }
}

void DeleteProcessedOrderLast(processedorder *processedorder)
{
    DeleteProcessedOrderAt(processedorder, processedorder->Neff - 1);
}

void DeleteProcessedOrderFirst(processedorder *processedorder)
{
    DeleteProcessedOrderAt(processedorder, 0);
}

IdxType SearchMasakan(processedorder processedorder, masakan masakkan)
{
    IdxType i;
    for (i = 0; i < processedorder.Neff; i++)
    {
        if (processedorder.A[i].makanan == masakkan.makanan && processedorder.A[i].sisa_durasi_or_ketahanan_masakan == masakkan.sisa_durasi_or_ketahanan_masakan)
        {
            return i;
        }
    }
    return -1;
}