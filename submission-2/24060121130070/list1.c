/********************************************************/
/* Program   : list1.c                                  */
/* Deskripsi : file BODY modul list                     */
/* NIM/Nama  : 24060121130070/Daffa Aulia Rizky Karunia */
/* Tanggal   : 30 Oktober 2022                          */
/********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "list1.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean ListEmpty(List L)
{
    //Kamus Lokal

    //Algoritma
    return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *L)
{
    //Kamus Lokal

    //Algoritma
    First(*L) == Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi(infotype X)
{
    //Kamus Lokal
    address P;

    //Algoritma
    P = (address)malloc(sizeof(ElmtList));
    if (P != Nil)
    {
        info(P) = X;
        next(P) = Nil;
    }
    return P;
}

void Dealokasi(address *P)
{
    //Kamus Lokal

    //Algoritma
    info(*P) = 0;
    next(*P) = Nil;
    (*P) = Nil;
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search(List L, infotype X)
{
    //Kamus Lokal
    address P;

    //Algoritma
    P = First(L);
    while (P != Nil)
    {
        if(X == info(P))
        {
            return P;
        }
        else
        {
            P = next(P);
        }
    }
    return Nil;
}

boolean FSearch(List L, address P)
{
    //Kamus Lokal
    address Q;

    //Algoritma
    Q = First(L);
    while (Q != Nil)
    {
        if (Q == P)
        {
            return true;
        }
        else
        {
            Q = next(Q);
        }
    }
    return false;
}

address SearchPrec(List L, infotype X, address *Prec)
{
    //Kamus Lokal
    address P;

    //Algoritma
    P = First(L);
    while (next(P) != Nil)
    {
        if(info(next(P)) == X)
        {
            return P;
        }
        else
        {
            P = next(P);
        }
    }
    return Nil;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst(List *L, infotype X)
{
    //Kamus Lokal
    address P;

    //Algoritma
    P = Alokasi(X);
    if (P != Nil)
    {
        InsertFirst(L, P);
    }
}

void InsVLast(List *L, infotype X)
{
    //Kamus Lokal
    address P;

    //Algoritma
    P = Alokasi(X);
    if (P != Nil)
    {
        InsertLast(L, P);
    }
}

void InsVAfter1(List *L, address Prec, address X)
{
    //Kamus Lokal

    //Algoritma
    next(X) = next(Prec);
    next(Prec) = X;
}

void InsVAfter2(List *L, infotype Prec, infotype X)
{
    //Kamus Lokal
    address P;
    address Q;

    //Algoritma
    P = Alokasi(X);
    Q = First(*L);
    if (ListEmpty(*L))
    {
        InsVFirst(&(*L), X);
    }
    else
    {
        while (info(Q) != Prec)
        {
            Q = next(Q);
        }
        next(P) = next(Q);
        next(Q) = P;
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(List *L, infotype *X)
{
    //Kamus Lokal
    address P;

    //Algoritma
    P = First(*L);
    (*X) = info(P);
    First(*L) = next(P);
    next(P) = Nil;
    Dealokasi(&P);
}

void DelVLast(List *L, infotype *X)
{
    //Kamus Lokal
    address P;

    //Algoritma
    DelLast(L, P);
    (*X) = info(P);
    Dealokasi(&P);
}

void DelVAfter1(List *L, infotype *X, infotype Y)
{
    //Kamus Lokal
    address P;
    address Q;

    //Algoritma
    P = First(*L);
    if (info(First(*L)) == Y)
    {
        Q = next(P);
        (*X) = info(Q);
        next(P) = next(Q);
        next(Q) = Nil;
        Dealokasi(&Q);
    }
    else
    {
        while (info(P) != Y)
        {
            P = next(P);
        }
        Q = next(P);
        (*X) = info(next(P));
        next(P) = next(Q);
        next(Q) = Nil;
        Dealokasi(&Q);
    }
}

void DelVAfter2(List *L, address *X, address Y)
{
    //Kamus Lokal
    address P;

    //Algoritma
    (*X) = next(Y);
    next(Y) = next(next(Y));
    Dealokasi(&(*X));
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst(List *L, address P)
{
    //Kamus Lokal

    //Algoritma
    next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter(List *L, address P, address Prec)
{
    //Kamus Lokal

    //Algoritma
    next(P) = next(Prec);
    next(Prec) = P;
}

void InsertLast(List *L, address P)
{
    //Kamus Lokal
    address Last;

    //Algoritma
    if (First(*L) == Nil)
    {
        InsertFirst(&(*L), P);
    }
    else
    {
        Last = First(*L);
        while (next(Last) != Nil)
        {
            Last = next(Last);
        }
        InsertAfter(&(*L), P, Last);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst(List *L, address *P)
{
    //Kamus Lokal

    //Algoritma
    if (!ListEmpty(*L))
    {
        (*P) = First(*L);
        First(*L) = next(First(*L));
    }
    else
    {
        printf("List Kosong");
    }
}

void DelP(List *L, infotype X)
{
    //Kamus Lokal
    address P;
    address Prec;

    //Algoritma
    if (!ListEmpty(*L))
        {
            if (info(First(*L)) == X)
            {
                DelFirst(&(*L), &P);
            }
            else
            {
                Prec = First(*L);
                while (info(next(Prec)) != X)
                {
                    Prec = next(Prec);
                }
                DelAfter(&(*L), &P, Prec);
            }
        }
}

void DelLast(List *L, address *P)
{
    //Kamus Lokal
    address Last;
    address PrecLast;

    //Algoritma
    Last = First(*L);
    PrecLast = Nil;
    while (next(Last) != Nil)
    {
        PrecLast = Last;
        Last = next(Last);
    }
    (*P) = Last;
    if (PrecLast == Nil)
    {
        First(*L) = Nil;
    }
    else
    {
        next(PrecLast) = Nil;
    }
}

void DelAfter(List *L, address *Pdel, address Prec)
{
    //Kamus Lokal

    //Algoritma
    (*Pdel) = next(Prec);
    next(Prec) = next(next(Prec));
    next(*Pdel) = Nil;

    Dealokasi(&(*Pdel));
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void Printinfo(List L)
{
    //Kamus Lokal
    address P;

    //Algoritma
    P = First(L);
    if (P == Nil)
    {
        printf("List Kosong\n");
    }
    else
    {
        while (next(P) != Nil)
        {
            printf("%d, ", info(P));
            P = next(P);
        }
        printf("%d\n", info(P));
    }
}

int NbElmt(List L)
{
    //Kamus Lokal
    int counter;
    address P;

    //Algoritma
    counter = 0;
    if (!ListEmpty(L))
    {
        P = First(L);
        while (P != Nil)
        {
            counter++;
            P = next(P);
        }
    }
    return counter;
}
