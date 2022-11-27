#include <stdio.h>
#include <stdlib.h>
#include "arraydin_sb.h"

ArrayDin_SB MakeArrayDin_SB()
{
    ArrayDin_SB Arr;
    Arr.A = (ElType_SB *) malloc (InitialSize * sizeof(ElType_SB));
    Arr.Capacity = InitialSize;
    Arr.Neff = 0;
    return Arr;
}

void DeallocateArrayDin_SB(ArrayDin_SB *array)
{
    free(array->A);
    array->Neff = 0;
}

boolean IsEmpty_SB(ArrayDin_SB array)
{
    return array.Neff == 0;
}

int Length_SB(ArrayDin_SB array)
{
    return array.Neff;
}

ElType_SB Get_SB(ArrayDin_SB array, IdxType i)
{
    return array.A[i];
}

int GetCapacity_SB(ArrayDin_SB array)
{
    return array.Capacity;
}

void InsertAt_SB(ArrayDin_SB *array, ElType_SB el, IdxType i)
{
    if (array->Neff == array->Capacity)
    {
        array->Capacity *= 2;
        array->A = (ElType_SB *) realloc (array->A, array->Capacity * sizeof(ElType_SB));
    }
    IdxType temp = array->Neff;
    while (temp > i)
    {
        array->A[temp] = array->A[temp - 1];
        temp--;
    }
    array->A[i] = el;
    array->Neff++;
}

void InsertLast_SB(ArrayDin_SB *array, ElType_SB el)
{
    InsertAt_SB(array, el, array->Neff);
}

void InsertFirst_SB(ArrayDin_SB *array, ElType_SB el)
{
    InsertAt_SB(array, el, 0);
}

void DeleteAt_SB(ArrayDin_SB *array, IdxType i)
{
    IdxType temp = i;
    while (temp < array->Neff - 1)
    {
        array->A[temp] = array->A[temp + 1];
        temp++;
    }

    if (array->Neff > 1)
    {
        array->Neff--;
    }
    else
    {
        array->Neff = 0;
    }
}

void DeleteLast_SB(ArrayDin_SB *array)
{
    DeleteAt_SB(array, array->Neff - 1);
}

void DeleteFirst_SB(ArrayDin_SB *array)
{
    DeleteAt_SB(array, 0);
}

void PrintArrayDin_SB(ArrayDin_SB array)
{
    if (array.Neff == 0)
    {
        printf("[]\n");
    }
    else
    {
        IdxType i;
        printf("[");
        for (i = 0; i < array.Neff - 1; i++)
        {
            printf("%s, ", array.A[i]);
        }
        printf("%s]\n", array.A[array.Neff - 1]);
    }
}

void ReverseArrayDin_SB(ArrayDin_SB *array)
{
    IdxType i = array->Neff - 1;
    IdxType count = 0;
    ElType_SB temp;
    while (count < i)
    {
        temp = array->A[count];
        array->A[count] = array->A[i];  
        array->A[i] = temp;
        count++;
        i--;
    }
}

ArrayDin_SB CopyArrayDin_SB(ArrayDin_SB array)
{
    ArrayDin_SB ArrCopy;
    ArrCopy = MakeArrayDin_SB();
    IdxType i;
    for (i = 0; i < array.Neff; i++)
    {
        InsertLast_SB(&ArrCopy, array.A[i]);
    }
    return ArrCopy;
}

IdxType SearchArrayDin_SB(ArrayDin_SB array, ElType_SB el)
{
    IdxType i;
    for (i = 0; i < array.Neff; i++)
    {
        if (array.A[i].Elements == el.Elements && array.A[i].Count == el.Count)
        {
            return i;
        }
    }
    return -1;
}