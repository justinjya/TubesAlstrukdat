#include <stdio.h>
#include <stdlib.h>
#include "arraydin_sb.h"

ArrayDin_SB MakeArrayDin_SB(int Neff)
{
    ArrayDin_SB Arr;
    Arr.A = (ElType_SB *) malloc (InitialSize * sizeof(ElType_SB));
    Arr.Capacity = InitialSize;
    Arr.Neff = Neff;
    for (IdxType i = 0; i < Neff; i++)
    {
        CreateEmpty_M(&Arr.A[i]);
    }
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

void AddNeff_SB(ArrayDin_SB *array)
{
    if (array->Neff == array->Capacity)
    {
        array->Capacity *= 2;
        array->A = (ElType_SB *) realloc (array->A, array->Capacity * sizeof(ElType_SB));
    }
    CreateEmpty_M(&array->A[array->Neff]);
    array->Neff++;
}

void SubNeff_SB(ArrayDin_SB *array)
{
    array->Neff--;
}
