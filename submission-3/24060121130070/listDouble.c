/********************************************************/
/* Program   : listDouble.c                             */
/* Deskripsi : file BODY modul list double pointer      */
/* NIM/Nama  : 24060121130070/Daffa Aulia Rizky Karunia */
/* Tanggal   : 27 November 2022                         */
/********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "listDouble.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
bool ListEmpty(List L)
{
    //Kamus Lokal

    //Algoritma
    return First(L) == Nil && Last(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *L)
{
    //Kamus Lokal

    //Algoritma
    First(*L) = Nil;
    Last(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi(infotype X)
{
    //Kamus Lokal
    address P;

    //Algoritma
    P = (address)malloc(sizeof(ElmtList));
    if(P!=Nil)
    {
        info(P) = X;
        next(P) = Nil;
        prev(P) = Nil;
    }
    return P;
}
void Dealokasi(address *P)
{
    //Kamus Lokal

    //Algoritma
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search(List L, infotype X)
{
    //Kamus Lokal
    address P;

    //Algoritma
    P = First(L);
    while(P!=Nil){
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
bool FSearch(List L, address P)
{
    //Kamus Lokal
    address Q;

    //Algoritma
    Q = First(L);
    while(Q!=Nil)
    {
        if(Q == P)
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
    while(next(P)!=Nil)
    {
        if(info(next(P))==X)
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
    InsertFirst(&(*L),P);
}
void InsVLast(List *L, infotype X)
{
    //Kamus Lokal
    address P;

    //Algoritma
    P = Alokasi(X);
    InsertLast(&(*L),P);
}

/*** PENGHAPUSAN ELEMEN ***/
void InsVAfter(List *L, infotype Prec, infotype X)
{
    //Kamus Lokal
    address P, Q;

    //Algoritma
    P = Alokasi(X);
    Q = First((*L));
    if(ListEmpty((*L)))
    {
        InsVFirst(&(*L),X);
    }
    else
    {
        while(info(Q)!=Prec){
            Q = next(Q);
        }
        next(P) = next(Q);
        next(Q) = P;
    }
}
void DelVFirst(List *L, infotype *X)
{
    //Kamus Lokal
    address P;

    //Algoritma
    DelFirst(&(*L),&P);
    (*X) = info(P);
    Dealokasi(&P);
}
void DelVLast(List *L, infotype *X)
{
    //Kamus Lokal
    address P;

    //Algoritma
    DelLast(&(*L),&P);
    (*X) = info(P);
    Dealokasi(&P);
}
void DelVAfter(List *L, infotype *X, infotype Y)
{
    //Kamus Lokal
    address P, Q;

    //Algoritma
    P = First(*L);
    if(info(First(*L))==Y)
    {
        Q = next(P);
        (*X) = info(P);
    }
    else
    {
        while(info(P)!=Y)
        {
            P = next(P);
        }
        Q = next(P);
        (*X) = info(next(P));
    }
    next(P) = next(Q);
    next(Q) = Nil;
    //prev(next(Q)) = P;
    Dealokasi(&Q);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst(List *L, address P)
{
    //Kamus Lokal

    //Algoritma
    if(!ListEmpty(*L))
    {
        next(P) = First(*L);
        prev(First(*L)) = P;
    }
    else
    {
        Last(*L) = P;
    }
    First(*L) = P;
}
void InsertAfter(List *L, address P, address Prec)
{
    //Kamus Lokal

    //Algoritma
    next(P) = next(Prec);
    prev(P) = Prec;
    prev(next(Prec)) = P;
    next(Prec) = P;
}
void InsertLast(List *L, address P)
{
    //Kamus Lokal

    //Algoritma
    if(!ListEmpty(*L))
    {
        prev(P) = Last(*L);
        next(Last(*L)) = P;
    }else
    {
        First(*L) = P;
    }
    Last(*L) = P;
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst(List *L, address *P)
{
    //Kamus Lokal

    //Algoritma
    (*P) = First(*L);
    First(*L) = next(First(*L));
    prev(First(*L)) =Nil;
}
void DelLast(List *L, address *P)
{
    //Kamus Lokal

    //Algoritma
    (*P) = Last(*L);
    Last(*L) = prev(*P);
    if(Last(*L) != Nil)
    {
        next(Last(*L)) = Nil;
    }
    else
    {
        First(*L) = Nil;
    }
    prev(*P) = Nil;
}
void DelAfter(List *L, address *Pdel, address Prec)
{
    //Kamus Lokal
    address P;

    //Algoritma
    P = next(Prec);
    (*Pdel) = P;
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    Dealokasi(&P);
}
void DelP(List *L, infotype X)
{
    //Kamus Lokal
    address P, Q;

    //Algoritma
    P = First(*L);
    if(info(P) == X && next(P) == Nil)
    {
        DelFirst(&(*L),&P);
    }
    else
    {
        while(info(next(P)) != X)
        {
            P = next(P);
        }
        DelAfter(&(*L),&Q,P);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void Printinfo(List L)
{
    //Kamus Lokal
    address P;

    //Algoritma
    P = First(L);
    if (!ListEmpty(L))
    {
        while (next(P) != Nil)
        {
            printf("%d,", info(P));
            P = next(P);
        }
        printf("%d\n", info(P));
    }
}
int NbElmt(List L)
{
    //Kamus Lokal
    address P;

    //Algoritma
    int counter = 0;
    P = First(L);
    while(P!=Nil)
    {
        counter++;
        P=next(P);
    }
    return counter;
}

/****************** PROSES TERHADAP LIST ******************/
void AdrLast(List *L, address *Prec, address *Last)
{
    //Kamus Lokal

    //Algoritma

}
void DelAll(List *L)
{
    //Kamus Lokal
    address P;

    //Algoritma
    while (!ListEmpty(*L))
    {
        DelFirst(&(*L), &P);
        Dealokasi(&P);
    }
}
void InversList(List *L)
{
    //Kamus Lokal
    address P, Temp;

    //Algoritma
    P = First(*L);
    if (!ListEmpty(*L))
    {
        Temp = First(*L);
        First(*L) = Last(*L);
        Last(*L) = Temp;
    }
    while (P != Nil)
    {
        Temp = next(P);
        next(P) = prev(P);
        prev(P) = Temp;
        P = Temp;
    }
}
List FInversList(List L)
{
    //Kamus Lokal
    address P, Temp;
    List L1;
    bool fail;

    //Algoritma
    fail = false;
    P = First(L);
    CreateList(&L1);
    while ((P != Nil) && (!fail))
    {
        Temp = Alokasi(info(P));
        if (Temp != Nil)
        {
            InsertFirst(&L1, Temp);
            P = next(P);
        }
        else
        {
            DelAll(&L1);
            fail = true;
        }
    }
    return L1;
}
void CopyList(List *L1, List *L2)
{
    //Kamus Lokal

    //Algoritma
    First(*L2) = First(*L1);
}
List FCopyList(List L)
{
    //Kamus Lokal
    address P;
    List L1;

    //Algoritma
    CreateList(&L1);
    P = First(L);
    while (P != Nil)
    {
        InsVLast(&L1, info(P));
        P = next(P);
    }
    return L1;
}
void CpAlokList(List Lin, List *Lout)
{
    //Kamus Lokal
    address P;

    //Algoritma
    CreateList(&(*Lout));
    while (P != Nil)
    {
        InsVLast(&(*Lout), info(P));
        P = next(P);
    }
}
void Konkat(List L1, List L2, List *L3)
{
    //Kamus Lokal
    address P;

    //Algoritma
    CreateList(&(*L3));
    P = First(L1);
    while (P != Nil)
    {
        InsVLast(&(*L3), info(P));
        P = next(P);
    }
    P = First(L2);
    while (P != Nil)
    {
        InsVLast(&(*L3), info(P));
        P = next(P);
    }
}
void Konkat1(List *L1, List *L2, List *L3)
{
    //Kamus Lokal
    address P;

    //Algoritma
    P = First(*L1);
    CreateList(L3);
    First(*L3) = First(*L1);
    if (P != Nil)
    {
        while (next(P) != Nil)
        {
            P = next(P);
        }
    }
    next(P) = First(*L2);
    CreateList(L1);
    CreateList(L2);
}
void PecahList(List *L1, List *L2, List L)
{
    //Kamus Lokal
    address P;
    int i;

    //Algoritma
    CreateList(&(*L1));
    CreateList(&(*L2));
    P = First(L);
    i = 1;
    while (P != Nil)
    {
        if (i%2 == 1)
        {
            InsVLast(&(*L1), info(P));
        }
        else
        {
            InsVLast(&(*L1), info(P));
        }
        P = next(P);
        i++;
    }
}
