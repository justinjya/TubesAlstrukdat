#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void MakeEmpty(TabInt *T)
{
    T->Neff = 0;
}   

int NbElmt(TabInt T)
{
    return T.Neff;
}

int MaxNbEl(TabInt T)
{
    return IdxMax;
}

IdxType GetFirstIdx(TabInt T)
{
    return IdxMin;
}

IdxType GetLastIdx(TabInt T)
{
    return T.Neff;
}

ElType GetElmt(TabInt T, IdxType i)
{
    return T.TI[i];
}

void SetTab(TabInt Tin, TabInt *Tout)
{
    int i;
    for (i = IdxMin; i < IdxMax; i++)
    {
        Tout->TI[i] = Tin.TI[i];
    }
    Tout->Neff = Tin.Neff;
}

void SetEl(TabInt *T, IdxType i, ElType v)
{
    T->TI[i] = v;
    if (i == T->Neff + 1)
    {
        T->Neff += 1;
    }
}

void SetNeff(TabInt *T, IdxType N)
{
    T->Neff = N;
}

boolean IsIdxValid(TabInt T, IdxType i)
{
    return (i >= IdxMin && i <= IdxMax);
}

boolean IsIdxEff(TabInt T, IdxType i)
{
    return T.TI[i] != IdxUndef;
}

boolean IsEmpty(TabInt T)
{
    return T.Neff = 0;
}

boolean IsFull(TabInt T)
{
    return T.Neff = IdxMax;
}

void TulisIsi(TabInt T)
{
    if (T.Neff == 0)
    {
        printf("Tabel kosong\n");
    }
    else
    {
        int i;
        for (i = IdxMin; i <= T.Neff; i++)
        {
            printf("%d:%d\n", i, T.TI[i]);
        }
    }
}

TabInt PlusTab(TabInt T1, TabInt T2)
{
    TabInt hasil;
    MakeEmpty(&hasil);
    int i;
    for (i = IdxMin; i <= T1.Neff; i++)
    {
        hasil.TI[i] = T1.TI[i] + T2.TI[i]; 
    }
    hasil.Neff = T1.Neff;
    return hasil;
}

TabInt MinusTab(TabInt T1, TabInt T2)
{
    TabInt hasil;
    MakeEmpty(&hasil);
    int i;
    for (i = IdxMin; i <= T1.Neff; i++)
    {
        hasil.TI[i] = T1.TI[i] - T2.TI[i];
    }
    hasil.Neff = T1.Neff;
    return hasil;
}

ElType ValMax(TabInt T)
{
    ElType i, max;
    max = T.TI[IdxMin];
    for (i = IdxMin; i <= T.Neff; i++)
    {
        if (T.TI[i] > max)
        {
            max = T.TI[i];
        }
    }
    return max;
}

ElType ValMin(TabInt T)
{
    ElType i, min;
    min = T.TI[IdxMin];
    for (i = IdxMin; i <= T.Neff; i++)
    {
        if (T.TI[i] < min)
        {
            min = T.TI[i];
        }
    }
    return min;
}

IdxType IdxMaxTab(TabInt T)
{
    IdxType i;
    for (i = IdxMin; i <= T.Neff; i++)
    {
        if (T.TI[i] == ValMax(T))
        {
            return i;
        }
    }
}

IdxType IdxMinTab(TabInt T)
{
    IdxType i;
    for (i = IdxMin; i <= T.Neff; i++)
    {
        if (T.TI[i] == ValMin(T))
        {
            return i;
        }
    }
}