/********************************************************/
/* Program   : list1.c                                  */
/* Deskripsi : file c modul list                        */
/* NIM/Nama  : 24060121110042 / Naufal Arya Ramadhan    */
/* Tanggal   : 30 Oktober 2022                          */
/********************************************************/

#ifndef LIST1_C
#define LIST1_C

#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

/****************** TEST LIST KOSONG ******************/
boolean ListEmpty(List L){
    /* Mengirim true jika list kosong */
    return (First(L) = Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *L){
    /* I.S. sembarang */
    /* F.S. Terbentuk list kosong */
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi(infotype X){
    /* Mengirimkan address hasil alokasi sebuah elemen */
    /* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
    /* menghasilkan P, maka info(P)=X, Next(P)=Nil */
    /* Jika alokasi gagal, mengirimkan Nil */

    //kamus lokal
    address P;

    //algoritma
    P = (address)malloc(sizeof(ElmtList));
    if (P != Nil)
    {
        info(P) = X;
        next(P) = Nil;
    }
    return P;
}

void Dealokasi(address *P){
    /* I.S. P terdefinisi */
    /* F.S. P dikembalikan ke sistem */
    /* Melakukan dealokasi/pengembalian address P */

    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search(List L, infotype X){
    /* Mencari apakah ada elemen list dengan info(P)= X */
    /* Jika ada, mengirimkan address elemen tersebut. */
    /* Jika tidak ada, mengirimkan Nil */

    //kamus lokal
    address P;

    //algoritma
    P = First(L);
    while (P != Nil && info(P) != X)
    {
        P = next(P);
    }
    return P;
}

boolean FSearch(List L, address P){
    /* Mencari apakah ada elemen list yang beralamat P */
    /* Mengirimkan true jika ada, false jika tidak ada */

    //kamus lokal
    address Q;

    //algoritma
    Q = First(L);
    while (Q != Nil && Q != P)
    {
        Q = next(Q);
    }
    return Q;
}

address Searchprec(List L, infotype X, address *prec){
    /* Mengirimkan address elemen sebelum elemen yang nilainya=X */
    /* Mencari apakah ada elemen list dengan info(P)= X */
    /* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P */
    /* dan Info(P)=X. */
    /* Jika tidak ada, mengirimkan Nil */
    /* Jika P adalah elemen pertama, maka Prec=Nil */
    /* Search dengan spesifikasi seperti ini menghindari */
    /* traversal ulang jika setelah Search akan dilakukan operasi lain*/

    //kamus lokal
    address P;

    //algoritma
    P = First(L);
    *prec = Nil;
    while (P != Nil && info(P) != X)
    {
        *prec = P;
        P = next(P);
    }
    return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst(List *L, infotype X){
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

    //kamus lokal
    address P;

    //algoritma
    P = Alokasi(X);
    if (P != Nil)
    {
        next(P) = First(*L);
        First(*L) = P;
    }
}

void InsVLast(List *L, infotype X){
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen list di akhir: elemen terakhir yang baru */
    /* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

    //kamus lokal
    address P;
    address Q;

    //algoritma
    P = Alokasi(X);
    if (P != Nil)
    {
        if (ListEmpty(*L))
        {
            First(*L) = P;
        }
        else
        {
            Q = First(*L);
            while (next(Q) != Nil)
            {
                Q = next(Q);
            }
            next(Q) = P;
        }
    }
}

void InsVAfter2(List *L, infotype prec, infotype X){
    /* procedure InsVAfter2 (input/output L: List, input Prec: infotype, input X: infotype)
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen bernilai X setelah elemen bernilai Prec */
    /* Jika alokasi gagal: I.S.= F.S. */

    //kamus lokal
    address P;
    address Q;

    //algoritma
    P = Alokasi(X);
    if (P != Nil)
    {
        Q = First(*L);
        while (Q != Nil && info(Q) != prec)
        {
            Q = next(Q);
        }
        if (Q != Nil)
        {
            next(P) = next(Q);
            next(Q) = P;
        }
    }
}

void InsVAfter1(List *L, address prec, address X){
    /* procedure InsVAfter1 (input/output L: List, input Prec: address, input X: address)*/
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen bernilai X setelah elemen bernilai Prec */
    /* Jika alokasi gagal: I.S.= F.S. */

    //algoritma
    if (prec != Nil)
    {
        next(X) = next(prec);
        next(prec) = X;
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(List *L, infotype *X){
    /* I.S. List L tidak kosong */
    /* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
    /* dan alamat elemen pertama di-dealokasi */

    //kamus lokal
    address P;

    //algoritmas
    if (!ListEmpty(*L))
    {
        P = First(*L);
        First(*L) = next(P);
        *X = info(P);
        Dealokasi(&P);
    }
}

void DelVLast(List *L, infotype *X){
    /* I.S. list tidak kosong */
    /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
    /* dan alamat elemen terakhir di-dealokasi */

    //kamus lokal
    address P;
    address Q;

    //algoritma
    if (!ListEmpty(*L))
    {
        P = First(*L);
        if (next(P) = Nil)
        {
            First(*L) = Nil;
        }
        else
        {
            Q = next(P);
            while (next(Q) != Nil)
            {
                P = Q;
                Q = next(Q);
            }
            next(P) = Nil;
        }
        *X = info(Q);
        Dealokasi(&Q);
    }
}

void DelVAfter2(List *L, address *X, address Y){
    /* procedure DelVAfter2 (input/output L: List, input/output X: infotype, input Y: infotype)
    /* I.S. list tidak kosong */
    /* F.S. Elemen terakhir setelah elemen dengan nilai address Y: nilai address disimpan pada X */
    /*      dan alamat elemen X tersebut di-dealokasi */

    //algoritma
    if (Y != Nil)
    {
        *X = next(Y);
        next(Y) = next(*X);
        next(*X) = Nil;
    }
}

void DelVAfter1(List *L, infotype *X, infotype Y){
    /* procedure DelVAfter1 (input/output L: List, input/output X: infotype, input Y: infotype)
    /* I.S. list tidak kosong */
    /* F.S. Elemen terakhir setelah elemen dengan nilai info Y: nilai info disimpan pada X */
    /*      dan alamat elemen nilsi info Y tersebut di-dealokasi */

    //kamus lokal
    address P;
    address Q;

    //algoritma
    P = First(*L);
    while (P != Nil && info(P) != Y)
    {
        P = next(P);
    }
    if (P != Nil)
    {
        Q = next(P);
        next(P) = next(Q);
        next(Q) = Nil;
        *X = info(Q);
        Dealokasi(&Q);
    }
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst(List *L, address P){
    /* I.S. Sembarang, P sudah dialokasi */
    /* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */

    //algoritma
    if (P != Nil)
    {
        next(P) = First(*L);
        First(*L) = P;
    }
}

void InsertAfter(List *L, address P, address prec){
    /* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
    /* P sudah dialokasi */
    /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

    //algoritma
    if (P != Nil && prec != Nil)
    {
        next(P) = next(prec);
        next(prec) = P;
    }
}

void InsertLast(List *L, address P){
    /* I.S. Sembarang, P sudah dialokasi */
    /* F.S. P ditambahkan sebagai elemen terakhir yang baru */

    //kamus lokal
    address Last;
    address Q;

    //algoritma
    if (P != Nil)
    {
        if (ListEmpty(*L))
        {
            First(*L) = P;
        }
        else
        {
            Q = First(*L);
            while (next(Q) != Nil)
            {
                Q = next(Q);
            }
            next(Q) = P;
        }
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst(List *L, address *P){
    /* I.S. List tidak kosong */
    /* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
    /* Elemen list berkurang satu (mungkin menjadi kosong) */
    /* First element yg baru adalah suksesor elemen pertama yang lama */

    //algoritma
    if (!ListEmpty(*L))
    {
        *P = First(*L);
        First(*L) = next(*P);
        next(*P) = Nil;
    }
}

void DelP(List *L, infotype X){
    /* I.S. Sembarang */
    /* F.S. Jika ada elemen list beraddress P, dengan info(P)=X */
    /* Maka P dihapus dari list dan di-dealokasi */
    /* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
    /* List mungkin menjadi kosong karena penghapusan */

    //kamus lokal
    address P;
    address prec;

    //algoritma
    P = First(*L);
    prec = Nil;
    while (P != Nil && info(P) != X)
    {
        prec = P;
        P = next(P);
    }
    if (P != Nil)
    {
        if (prec == Nil)
        {
            First(*L) = next(P);
        }
        else
        {
            next(prec) = next(P);
        }
        next(P) = Nil;
        Dealokasi(&P);
    }
}

void DelLast(List *L, address *P){
    /* I.S. List tidak kosong */
    /* F.S. P adalah alamat elemen terakhir list sebelum penghapusan */
    /* Elemen list berkurang satu (mungkin menjadi kosong) */
    /* Last element baru adalah predesesor elemen pertama yg lama, */
    /* jika ada */

    //kamus lokal
    address Q;

    //algoritma
    if (!ListEmpty(*L))
    {
        *P = First(*L);
        if (next(*P) == Nil)
        {
            First(*L) = Nil;
        }
        else
        {
            Q = next(*P);
            while (next(Q) != Nil)
            {
                *P = Q;
                Q = next(Q);
            }
            next(*P) = Nil;
        }
        Dealokasi(&Q);
    }
}

void DelAfter(List *L, address *Pdel, address prec){
    /* I.S. List tidak kosong. Prec adalah anggota list */
    /* F.S. Menghapus Next(Prec): */
    /* Pdel adalah alamat elemen list yang dihapus */

    //algoritma
    if (prec != Nil)
    {
        *Pdel = next(prec);
        next(prec) = next(*Pdel);
        next(*Pdel) = Nil;
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void Printinfo(List L){
    /* I.S. List mungkin kosong */
    /* F.S. Jika list tidak kosong, */
    /* Semua info yg disimpan pada elemen list diprint */
    /* Jika list kosong, hanya menuliskan "list kosong" */

    //kamus lokal
    address P;

    //algoritma
    P = First(L);
    while (P != Nil)
    {
        printf("%d ", info(P));
        P = next(P);
    }
    printf("\n");
}

int NbElmt(List L){
    /* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

    //kamus lokal
    address P;

    //algoritma
    int count = 0;
    P = First(L);
    while (P != Nil)
    {
        count++;
        P = next(P);
    }
    return count;
}

#endif
