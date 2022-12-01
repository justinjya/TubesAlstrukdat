#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

ArrayDin MakeArrayDin()
{
    ArrayDin Arr;
    Arr.A = (ElType *) malloc (InitialSize * sizeof(ElType));
    Arr.Capacity = InitialSize;
    Arr.Neff = 0;
    return Arr;
}

void DeallocateArrayDin(ArrayDin *array)
{
    free(array->A);
    array->Neff = 0;
}

boolean IsEmpty(ArrayDin array)
{
    return array.Neff == 0;
}

int Length(ArrayDin array)
{
    return array.Neff;
}

ElType Get(ArrayDin array, IdxType i)
{
    return array.A[i];
}

int GetCapacity(ArrayDin array)
{
    return array.Capacity;
}

void InsertAt(ArrayDin *array, ElType el, IdxType i)
{
    if (array->Neff == array->Capacity)
    {
        array->Capacity *= 2;
        array->A = (ElType *) realloc (array->A, array->Capacity * sizeof(ElType));
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

void InsertLast(ArrayDin *array, ElType el)
{
    InsertAt(array, el, array->Neff);
}

void InsertFirst(ArrayDin *array, ElType el)
{
    InsertAt(array, el, 0);
}

void DeleteAt(ArrayDin *array, IdxType i)
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

void DeleteLast(ArrayDin *array)
{
    DeleteAt(array, array->Neff - 1);
}

void DeleteFirst(ArrayDin *array)
{
    DeleteAt(array, 0);
}

void PrintArrayDin(ArrayDin array)
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

boolean compareStringArrayDin(char *string1, char *string2)
{
    while (*string1 != '\0' || *string2 != '\0')
    {
        if (*string1 != *string2)
        {
            return false;
        }
        string1++;
        string2++;
    }
    return true;
}

IdxType SearchArrayDin(ArrayDin array, ElType el)
{
    IdxType i;
    for (i = 0; i < array.Neff; i++)
    {
        if (compareStringArrayDin(array.A[i], el))
        {
            return i;
        }
    }
    return -1;
}
