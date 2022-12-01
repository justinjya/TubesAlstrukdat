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

    address P;
    P = (address) malloc (sizeof(ElmtList));
    if (P != NULL)
    {
        ABSIS(Info(P)) = ABSIS(X);
        ORDINAT(Info(P)) = ORDINAT(X);
        Next(P) = NULL;
    }
    return P;
}
void Dealokasi_LL(address *P)
{

    free(*P);
}

address Search_LL(List L, point X)
{

    if (IsEmpty_LL(L))
    {
        return NULL;
    }
    else
    {
        address P;
        P = First(L);
        while (P != NULL)
        {
            if (ABSIS(Info(P)) == ABSIS(X) && ORDINAT(Info(P)) == ORDINAT(X))
            {
                return P;
            }
            P = Next(P);
        }
        return NULL;
    }
}

void InsVFirst_LL(List *L, point X)
{

    address First;
    First = Alokasi_LL(X);
    if(First != NULL){
        InsertFirst_LL(L, First);
    }
}

void InsVLast_LL(List *L, point X)
{

    address Last;
    Last = Alokasi_LL(X);
    if(Last != NULL){
        InsertLast_LL(L, Last);
    }
}

void DelVFirst_LL(List *L, point *X)
{

    address Del;
    DelFirst_LL(L, &Del);
    (*X).x = Info(Del).x;
    (*X).y = Info(Del).y;
    Dealokasi_LL(&Del);
}
void DelVLast_LL(List *L, point *X)
{

    address hasil;
    DelLast_LL(L, &hasil);
    (*X).x = Info(hasil).x;
    (*X).y = Info(hasil).y;
    Dealokasi_LL(&hasil);
}

void InsertFirst_LL(List *L, address P)
{

    Next(P) = First(*L);
    First(*L) = P;
    if(Next(First(*L)) == NULL){
        Last(*L) = P;
    }
}

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

    if (!IsEmpty_LL(*L))
    {
        address addressX, P, temp;
        addressX = Search_LL(*L, X);
        if (addressX != NULL)
        {
            if (addressX != First(*L))
            {
                P = First(*L);
                while (Next(P) != addressX)
                {
                    P = Next(P);
                }
                DelAfter_LL(L, &temp, P);
            }
            else
            {
                DelFirst_LL(L, &temp);
            }
        }
        Dealokasi_LL(&addressX);
    }
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

    address P;
    int N = 0;
    P = First(L);
    while (P != NULL)
    {
        N++;
        P = Next(P);
    }
    return N;
}
