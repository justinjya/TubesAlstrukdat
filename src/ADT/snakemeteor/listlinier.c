#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

boolean IsEmpty_LL(List L)
{

    return First(L) == NULL && Last(L) == NULL;
}

void CreateEmpty_LL(List *L)
{

    First(*L) = NULL;
    Last(*L) = NULL;
}


address Alokasi_LL(point X)
{

    ElmtList *P = (ElmtList *)malloc(sizeof(ElmtList));
    if (P != NULL)
    {
        ABSIS(Info(P)) = ABSIS(X);
        ORDINAT(Info(P)) = ORDINAT(X);
        Next(P) = NULL;
        return P;
    }
    else
    {
        return NULL;
    }
}
void Dealokasi_LL(address *P)
{

    free(*P);
}

address Search_LL(List L, point X)
{

    address hasil = NULL;
    if (!IsEmpty_LL(L))
    {
        address P = First(L);
        boolean found = false;
        while (P != NULL && !found)
        {
            if (ABSIS(Info(P)) == ABSIS(X) && ORDINAT(Info(P)) == ORDINAT(X))
            {
                found = true;
                hasil = P;
            }
            else
            {
                P = Next(P);
            }
        }
    }
    return hasil;
}
/*
void InsVFirst_LL(List *L, point X)
{

    address tambah = Alokasi_LL(X);
    if (tambah != NULL)
    {
        InsertFirst_LL(L, tambah);
    }
}
*/
void InsVLast_LL(List *L, point X)
{

    address tambah = Alokasi_LL(X);
    if (tambah != NULL)
    {
        InsertLast_LL(L, tambah);
    }
}

void DelVFirst_LL(List *L, point *X)
{

    address hasil;
    DelFirst_LL(L, &hasil);
    X->x = Info(hasil).x;
    X->y = Info(hasil).y;
    Dealokasi_LL(&hasil);
}
void DelVLast_LL(List *L, point *X)
{

    address hasil;
    DelLast_LL(L, &hasil);
    X->x = Info(hasil).x;
    X->y = Info(hasil).y;
    Dealokasi_LL(&hasil);
}
/*
void InsertFirst__LL(List *L, address P)
{

    Next(P) = First(*L);
    First(*L) = P;
    if(Next(First(*L)) == NULL){
        Last(*L) = P;
    }
}
*/
void InsertAfter_LL(List *L, address P, address Prec)
{

    Next(P) = Next(Prec);
    Next(Prec) = P;
    if(Next(P) == NULL){
        Last(*L) = P;
    }
}
void InsertLast_LL(List *L, address P)
{

    if (IsEmpty_LL(*L))
    {
        Next(P) = First(*L);
        First(*L) = P;
        if(Next(First(*L)) == NULL){
            Last(*L) = P;
        }
    }
    else
    {
        InsertAfter_LL(L, P, Last(*L));
    }
}

void DelFirst_LL(List *L, address *P)
{

    *P = First(*L);
    if (First(*L) == Last(*L))
    {
        First(*L) = NULL;
        Last(*L) = NULL;
    }
    else
    {
        First(*L) = Next(First(*L));
    }
}
void DelP_LL(List *L, point X)
{

    address P = Search_LL(*L, X);
    if (P != NULL)
    {
        address Acari = First(*L);
        address prec = NULL;
        address x;
        boolean found = (Info(Acari).x == X.x && Info(Acari).y == X.y);
        if (found)
        {
            DelFirst_LL(L, &P);
        }
        else
        {
            while (Acari != NULL && !found)
            {
                if (Info(Acari).x == X.x && Info(Acari).y == X.y)
                {
                    found = true;
                    DelAfter_LL(L, &x, prec);
                }
                else
                {
                    prec = Acari;
                    Acari = Next(Acari);
                }
            }
        }
    }
    Dealokasi_LL(&P);
}
void DelLast_LL(List *L, address *P)
{
    
    if (First(*L) == Last(*L))
    {
        *P = Last(*L);
        First(*L) = NULL;
        Last(*L) = NULL;
    }
    else
    {
        address y = First(*L);
        while (Next(Next(y)) != NULL)
        {
            y = Next(y);
        }
        DelAfter_LL(L, P, y);
    }
}
void DelAfter_LL(List *L, address *Pdel, address Prec)
{

    *Pdel = Next(Prec);
    if(*Pdel != NULL){
        if (Next(*Pdel) == NULL)
        {
            Next(Prec) = NULL;
            Last(*L) = Prec;
        }
        else
        {
            Next(Prec) = Next(*Pdel);
        }
    }
}

void PrintInfo_LL(List L)
{

    if (!IsEmpty_LL(L))
    {
        address P = First(L);
        printf("[");
        while (P != NULL)
        {
            if (Next(P) != NULL)
            {
                printf("<%d,%d>,", Info(P).x, Info(P).y);
            }
            else
            {
                printf("<%d,%d>", Info(P).x, Info(P).y);
            }
            P = Next(P);
        }
        printf("]");
    }
    else
    {
        printf("[]");
    }
}
int NbElmt_LL(List L)
{

    int count = 0;
    if (!IsEmpty_LL(L))
    {
        address P = First(L);
        while (P != NULL)
        {
            count += 1;
            P = Next(P);
        }
    }
    return count;
}
