/* Program   : listDouble.c */
/* Deskripsi : file BODY modul list dengan pointer ganda */
/* NIM/Nama  : 24060121130090 - Dorino Baharson*/
/* Tanggal   : 27 - 11 - 2022*/
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "listDouble.h"

/*Prototype*/
/* ----- Test List Kosong ----- */
bool ListEmpty(List L)
/* Mengirim true jika list kosong */
{
    // Kamus Lokal

    // Algoritma
    if (First(L) == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* ----- Pembuatan List Kosong ----- */
void CreateList(List *L)
/* I.S.		: sembarang
   F.S.		: Terbentuk list kosong */
{
    // Kamus Lokal

    // Algoritma
    First(*L) = Nil;
}

/* ----- Manajemen Memori ----- */
address Alokasi(infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil,
   dan misalnya menghasilkan P, maka
   Info(P) = X, next(P) = Nil
   Jika alokasi gagal, mengirimkan Nil */
{
    // Kamus Lokal
    address P;

    // Algooritma
    P = (address)malloc(sizeof(ElmtList));
    if (P != Nil)
    {
        info(P) = X;
        next(P) = Nil;
        return P;
    }
    else
    {
        return Nil;
    }
}

void Dealokasi(address *P)
/* I.S.		: P terdefinisi
   F.S.		: P dikembalikan ke sistem
   Melakukan dealokasi/pengembalian address P */
{
    // Kamus Lokal

    // Algoritma
    free(*P);
}

void AdrLast(List *L, address *Prec, address *Last)
/*mencari alamat elemen terakhir dan sebelumnya*/
{
    // Kamus Lokal

    // Algoritma
    if (!ListEmpty(*L))
    {
        (*Last) = First(*L);
        (*Prec) = Nil;
        while (next(*Last) != Nil)
        {
            (*Prec) = (*Last);
            (*Last) = next(*Last);
        }
    }
    else
    {
        (*Last) = Nil;
        (*Prec) = Nil;
    }
}

/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
void InsertFirst(List *L, address P)
/* I.S. 	: Sembarang, P sudah dialokasi
   F.S.		: Menambahkan elemen ber-address P sebagai elemen pertama */
{
    // Kamus Lokal

    // Algoritma
    if (First(*L) == Nil)
    {
        First(*L) = P;
        next(P) = Nil;
        prev(P) = Nil;
    }
    else
    {
        next(P) = First(*L);
        prev(First(*L)) = P;
        First(*L) = P;
        prev(P) = Nil;
    }
}

void InsertAfter(List *L, address P, address Prec)
/* I.S.		: Prec pastilah elemen list dan bukan elemen terakhir,
              P sudah dialokasi
   F.S. 	: Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    // Kamus Lokal

    // Algoritma
    if (First(*L) == Nil)
    {
        InsertFirst(&(*L), P);
    }
    else
    {
        next(P) = next(Prec);
        next(Prec) = P;
        prev(P) = Prec;
        prev(next(Prec)) = P;
    }
}

void InsertLast(List *L, address P)
/* I.S.		: Sembarang, P sudah dialokasi
   F.S.		: P ditambahkan sebagai elemen terakhir yang baru */
{
    // Kamus Lokal
    address Last;

    // Algoritma
    if (ListEmpty(*L))
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

/* Penghapusan Sebuah Elemen */
void DelFirst(List *L, address *P)
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen pertama list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              First element yang baru adalah suksesor elemen pertama yang
              lama */
{
    // Kamus Lokal

    // Algoritma
    (*P) = First(*L);
    First(*L) = next(First(*L));
    prev(First(*L)) = Nil;
}

void DelLast(List *L, address *P)
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen terakhir list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              Last element baru adalah predesesor elemen pertama yang
              lama, jika ada */
{
    // Kamus Lokal
    address Last, Prec;

    // Algoritma
    Prec = First(*L);
    Last = Prec;
    if (next(Prec) == Nil)
    {
        First(*L) = Nil;
    }
    else
    {
        while (next(Last) != Nil)
        {
            Prec = Last;
            Last = next(Last);
        }
        next(Prec) = Nil;
    }
    (*P) = Last;
}

void DelAfter(List *L, address *Pdel, address Prec)
/* I.S.     : List tidak kosong. Prec adalah anggota list L.
   F.S.     : Menghapus next(Prec) :
              Pdel adalah alamat elemen list yang dihapus*/
{
    // Kamus Lokal
    address P;

    // Algoritma
    (*Pdel) = next(Prec);
    next(Prec) = next(*Pdel);
    if (next(*Pdel) != Nil)
    {
        prev(next(*Pdel)) = Prec;
    }
    next(*Pdel) = Nil;
    prev(*Pdel) = Nil;
}

/* ----- Primitif Berdasarkan Nilai ----- */
/* Penambahan Elemen */
void InsVFirst(List *L, infotype X)
/* I.S.		: L mungkin kosong
   F.S. 	: X ditambahkan sebagai elemen pertama L
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen
              pertama dengan nilai X jika alokasi berhasil.
              Jika alokasi gagal, maka I.S.= F.S. */
{
    // Kamus Lokal
    address P;

    // Algoritma
    P = Alokasi(X);
    InsertFirst(&(*L), P);
}

void InsVLast(List *L, infotype X)
/* I.S. 	: L mungkin kosong
   F.S.		: X ditambahkan sebagai elemen terakhir L
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
              di akhir yaitu
              jika alokasi berhasil, elemen terakhir yang baru bernilai X
              Jika alokasi gagal, maka I.S.= F.S. */
{
    // Kamus Lokal
    address P;

    // Algoritma
    P = Alokasi(X);
    InsertLast(&(*L), P);
}

void InsVAfter(List *L, infotype Xprec, infotype X)
/* I.S. 	: L mungkin kosong
   F.S.		: X ditambahkan sebagai elemen setelah Prec
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
              setelah Prec yaitu
              jika alokasi berhasil, elemen setelah Prec yang baru bernilai X
              Jika alokasi gagal, maka I.S.= F.S. */
{
    // Kamus Lokal
    address P, Q;

    // Algoritma
    P = Alokasi(X);
    Q = First(*L);
    if (ListEmpty(*L))
    {
        InsVFirst(&(*L), X);
    }
    else
    {
        while (info(Q) != Xprec)
        {
            Q = next(Q);
        }
        next(P) = next(Q);
        next(Q) = P;
    }
}

/* Penghapusan ELemen */
void DelVFirst(List *L, infotype *X)
/* I.S.		: List L tidak kosong
   F.S.		: Elemen pertama list dihapus den nilai info disimpan pada X
             dan alamat elemen pertama di-dealokasi */
{
    // Kamus Lokal
    address P;

    // Algoritma
    P = First(*L);
    (*X) = info(P);
    DelFirst(&(*L), &P);
    Dealokasi(&P);
}

void DelVLast(List *L, infotype *X)
/* I.S.		: List L tidak kosong
   F.S.		: Elemen terakhir list dihapus : nilai info disimpan pada X
              dan alamat elemen terakhir di-dealokasi */
{
    // Kamus Lokal
    address Last, Prec;

    // Algoritma
    AdrLast(&(*L), &Prec, &Last);
    (*X) = info(Last);
    if (Prec == Nil)
    {
        First(*L) = Nil;
    }
    else
    {
        next(Prec) = Nil;
    }
    Dealokasi(&Last);
}

void DelVAfter(List *L, infotype *X, infotype Y)
/* I.S.		: List L tidak kosong
   F.S.		: Elemen list setelah Prec dihapus : nilai info disimpan pada X
              dan alamat elemen setelah Prec di-dealokasi */
{
    // Kamus Lokal
    address P, Q;

    // Algoritma
    P = First(*L);
    if (info(First(*L)) == Y)
    {
        Q = next(P);
        (*X) = info(Q);
        next(P) = next(Q);
        next(Q) = Nil;
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
    }
}

/* ----- Proses Semua Elemen List ----- */
void PrintInfo(List L)
/* I.S.     : List mungkin kosong
   F.S.     : Jika list tidak kosong, semua info yg disimpan pada elemen
              list diprint
              Jika list kosong, hanya menuliskan "list kosong" */
{
    // Kamus Lokal
    address P;

    // Algoritma
    P = First(L);
    if (ListEmpty(L))
    {
        printf("List kosong");
    }
    else
    {
        while (P != Nil)
        {
            printf("%d ", info(P));
            P = next(P);
        }
        printf("\n");
    }
}

int NbElmt(List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    // Kamus Lokal
    int i;
    address P;

    // Algoritma
    i = 0;
    P = First(L);
    if (!ListEmpty(L))
    {
        while (P != Nil)
        {
            i++;
            P = next(P);
        }
    }
    return i;
}

/*----------------------------------------------------------*/
/*Tugas Prak 9*/
/*----------------------------------------------------------*/
void DelAll(List *L)
{
    // Kamus Lokal
    address P;

    // Algoritma
    while (!ListEmpty(*L))
    {
        DelFirst(&(*L), &P);
        Dealokasi(&P);
    }
}

void InversList(List *L)
{
    // Kamus Lokal
    address P, Temp;

    // Algoritma
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

List FInversList(List L){
    // Kamus Lokal
    address P, Temp;
    List L1;
    bool fail;

    // Algoritma
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

void CopyList(List *L1, List *L2){
    /*Kamus Lokal*/

    /*Algoritma*/
    First(*L2) = First(*L1);
    
}

List FCopyList(List L){
    /*Kamus Lokal*/
    address P;
    /*Algoritma*/
    List L1;
    CreateList(&L1);
    P = First(L);
    while(P!=Nil){
        InsVLast(&L1,info(P));
        P = next(P);
    }
    return L1;
}

void CpAlokList(List Lin, List *Lout){
    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    CreateList(&(*Lout));
    P = First(Lin);
    while(P!=Nil){
        InsVLast(&(*Lout),info(P));
        P = next(P);
    }
}


void Konkat(List L1, List L2, List *L3){
    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    CreateList(&(*L3));
    P = First(L1);
    while(P!=Nil){
        InsVLast(&(*L3),info(P));
        P = next(P);
    }
    P = First(L2);
    while(P!=Nil){
        InsVLast(&(*L3),info(P));
        P = next(P);
    }
}

void Konkat1(List *L1, List *L2, List *L3){
    /* Kamus Lokal */
    address P;

    /* Algoritma */
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

void PecahList(List *L1, List *L2, List L){
    /*Kamus Lokal*/
    address P;
    int i;
    /*Algoritma*/
    CreateList(&(*L1));
    CreateList(&(*L2));
    P = First(L);
    i = 1;
    while(P!=Nil){
        if(i%2==1){
            InsVLast(&(*L1),info(P));
        }else{
            InsVLast(&(*L2),info(P));
        }
        P = next(P);
        i++;
    }
}
