#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

boolean IsEmpty_LL(List L)
{

    return First(L) == Nil && Last(L) == Nil;
}

void CreateEmpty_LL(List *L)
{

    First(*L) = Nil;
    Last(*L) = Nil;
}


address Alokasi_LL(point X)
{

    ElmtList *P = (ElmtList *)malloc(sizeof(ElmtList));
    if (P != Nil)
    {
        ABSIS(Info(P)) = ABSIS(X);
        ORDINAT(Info(P)) = ORDINAT(X);
        Next(P) = Nil;
        return P;
    }
    else
    {
        return Nil;
    }
}
void Dealokasi_LL(address *P)
{

    free(*P);
}

address Search_LL(List L, point X)
{

    address hasil = Nil;
    if (!IsEmpty_LL(L))
    {
        address P = First(L);
        boolean found = false;
        while (P != Nil && !found)
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
    if (tambah != Nil)
    {
        InsertFirst_LL(L, tambah);
    }
}
*/
void InsVLast_LL(List *L, point X)
{

    address tambah = Alokasi_LL(X);
    if (tambah != Nil)
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
    if(Next(First(*L)) == Nil){
        Last(*L) = P;
    }
}
*/
void InsertAfter_LL(List *L, address P, address Prec)
{

    Next(P) = Next(Prec);
    Next(Prec) = P;
    if(Next(P) == Nil){
        Last(*L) = P;
    }
}
void InsertLast_LL(List *L, address P)
{

    if (IsEmpty_LL(*L))
    {
        Next(P) = First(*L);
        First(*L) = P;
        if(Next(First(*L)) == Nil){
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
        First(*L) = Nil;
        Last(*L) = Nil;
    }
    else
    {
        First(*L) = Next(First(*L));
    }
}
void DelP_LL(List *L, point X)
{

    address P = Search_LL(*L, X);
    if (P != Nil)
    {
        address Acari = First(*L);
        address prec = Nil;
        address x;
        boolean found = (Info(Acari).x == X.x && Info(Acari).y == X.y);
        if (found)
        {
            DelFirst_LL(L, &P);
        }
        else
        {
            while (Acari != Nil && !found)
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
        First(*L) = Nil;
        Last(*L) = Nil;
    }
    else
    {
        address y = First(*L);
        while (Next(Next(y)) != Nil)
        {
            y = Next(y);
        }
        DelAfter_LL(L, P, y);
    }
}
void DelAfter_LL(List *L, address *Pdel, address Prec)
{

    *Pdel = Next(Prec);
    if(*Pdel != Nil){
        if (Next(*Pdel) == Nil)
        {
            Next(Prec) = Nil;
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
        while (P != Nil)
        {
            if (Next(P) != Nil)
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
        while (P != Nil)
        {
            count += 1;
            P = Next(P);
        }
    }
    return count;
}