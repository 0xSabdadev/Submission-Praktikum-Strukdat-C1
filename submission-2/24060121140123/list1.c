/*********************************************/
/* Program   : list1.c                       */
/* Deskripsi : file REALISASI modul list        */
/* NIM/Nama  : 24060121140123/Akbar Ario Satrio Utomo*/
/* Tanggal   : 26 Oktober 2022              */
/*********************************************/
 
#include "list1.h"
#include <stdio.h>
#include <stdlib.h>

boolean ListEmpty(List L)
{
    return First(L) == Nil;
}

void CreateList(List *L)
{
    First((*L)) = Nil;
}

address Alokasi(infotype X)
{
    /*Kamus Lokal*/
    address P;

    /*Algortima*/
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
    /*Kamus Lokal*/
    
    /*Algortima*/
    info((*P)) = 0;
    next((*P)) = Nil;
    (*P) = Nil;
}

address Search(List L, infotype X)
{
    /*Kamus Lokal*/
    address P;
    boolean found;

    /*Algortima*/
    P = First(L);
    found = false;
    while((P != Nil)&&(!found)){
        if(info(P)==X){
            found = true;
        }
        else{
            P = next(P);
        }
    }
    return P;
}

boolean FSearch(List L, address P)
{
    /*Kamus Lokal*/
    boolean found;
    address PSearch;

    /*Algortima*/
    PSearch = First(L);
    found = false;
    while((PSearch != Nil)&&(!found)){
        if(PSearch = P){
            found = true;
        }
        else{
            PSearch = next(PSearch);
        }
    }
    return found;
}

address SearchPrec(List L, infotype X, address *Prec)
{
    /*Kamus Lokal*/
    address P;
    boolean found;
    /*Algortima*/
    (*Prec) = Nil;
    P = First(L);
    while((P != Nil)&&(!found)){
        if(info(P) == X){
            found = true;
        }
        else{
            (*Prec) = P;
            P = next(P);
        }
    }
    if(found){
        return (*Prec);
    }
    else{
        Prec = Nil;
        return (*Prec);
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst(List *L, infotype X)
{
    /*Kamus Lokal*/
    address P;
    /*Algoritma*/
    P = Alokasi(X);
    if(P != Nil){
        InsertFirst(L, P);
    }
}

void InsVLast(List *L, infotype X)
{
    /*Kamus Lokal*/
    address P;
    /*Algoritma*/
    P = Alokasi(X);
    if(P != Nil){
        InsertLast(L, P);
    }
}

void InsVAfter2(List *L, infotype Prec, infotype X)
{
    /*Kamus Lokal*/
    address P;
    address Q;
    /*Alogritma*/
    P = Alokasi(X);
    Q = First(*L);
    if(ListEmpty((*L))){
        InsVFirst(&(*L), X);
    }
    else{
        while(info(Q) != Prec){
            Q = next(Q);
        }
        next(P) = next(Q);
        next(Q) = P;
    }
}

void InsVAfter1(List *L, address Prec, address X)
{
    /*Kamus Lokal*/

    /*Algoritma*/
    next(X) = next(Prec);
    next(Prec) = X;
}



/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(List *L, infotype *X)
{
    /*Kamus Lokal*/
    address P;
    /*Algortima*/
    P = First(*L);
    (*X) = info(P);
    First(*L) = next(P);
    next(P) = Nil;
    Dealokasi(&P);
}

void DelVLast(List *L, infotype *X)
{
    /*Kamus Lokal*/
    address P;
    /*Algoritma*/
    DelLast(L, &P);
    (*X) = info(P);
    Dealokasi(&P);
}

void DelVAfter2(List *L, address *X, address Y)
{
    /*Kamus Lokal*/
    address P;
    /*Algortima*/
    (*X) = next(Y);
    next(Y) = next(next(Y));
    Dealokasi(&(*X));
}

void DelVAfter1(List *L, infotype *X, infotype Y)
{
    /*Kamus Lokal*/
    address P;
    address Q;
    /*Algoritma*/
    P = First(*L);
    if(info(First(*L)) == Y){
        Q = next(P);
        (*X) = info(Q);
        next(P) = next(Q);
        next(Q) = Nil;
        Dealokasi(&Q);
    }
    else{
        while(info(P) != Y){
            P = next(P);
        }
        Q = next(P);
        (*X) = info(next(P));
        next(P) = next(Q);
        next(Q) = Nil;
        Dealokasi(&Q);
    }
}


/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst(List *L, address P)
{
    /*Kamus Lokal*/

    /*Algoritma*/
    next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter(List *L, address P, address Prec)
{
/*Kamus Lokal*/

/*Algoritma*/
    next(P) = next(Prec);
    next(Prec) = P;
}

void InsertLast(List *L, address P)
{
    /*Kamus Lokal*/
    address Last;
    /*Algoritma*/
    if (First(*L) == Nil){
        InsertFirst (&(*L), P);
    }
    else{
        Last = First((*L));
        while((next(Last)) != Nil){
            Last = next(Last);
        }
        InsertAfter(&(*L), P, Last);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst(List *L, address *P)
{
    /*Kamus Lokal*/

    /*Algoritma*/
    if(!ListEmpty((*L))){
        (*P) = First(*L);
        First(*L) = next(First(*L));
    }
    else{
        printf("List Kosong");
    }
}

void DelP(List *L, infotype X)
{
    /*Kamus Lokal*/
    address P;
    address Prec;
    /*Algoritma*/
    if(!ListEmpty(*L)){
        if(info(First(*L)) == X){
            DelFirst(&(*L), &P);
        }
        else{
            Prec = First(*L);
            while(info(next(Prec)) != X){
                Prec = next(Prec);
            }
            DelAfter(&(*L), &P, Prec);
        }
    }
}

void DelLast(List *L, address *P)
{
    /*kamus Lokal*/
    address Last;
    address PrecLast;
    /*Algoritma*/
    Last = First(*L);
    PrecLast = Nil;

    while(next(Last) != Nil){
        PrecLast = Last;
        Last = next(Last);
    }
    (*P) = Last;
    if(PrecLast == Nil){
        First(*L) = Nil;
    }
    else{
        next(PrecLast) = Nil;
    }
}

void DelAfter(List *L, address *Pdel, address Prec)
{
    /*Kamus Lokal*/

    /*Algoritma*/
    (*Pdel) = next(Prec);
    next(Prec) = next(next(Prec));
    next(*Pdel) = Nil;
    Dealokasi(&(*Pdel));
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void Printinfo(List L)
{
    /*Kamus Lokal*/
    address P;
    /*Algoritma*/
    P = First(L);
    if(P == Nil){
        printf("list Kosong\n");
    }
    else{
        while(next(P) != Nil){
            printf("%d,", info(P));
            P = next(P);
        }
        printf("%d\n", info(P));
    }
}

int NbElmt(List L)
{
    /*Kamus Lokal*/
    int counter;
    address P;
    /*Algoritma*/
    counter = 0;
    if(!ListEmpty(L)){
        P = First(L);
        while(P != Nil){
            counter++;
            P = next(P);
        }
    }
    return counter;
}