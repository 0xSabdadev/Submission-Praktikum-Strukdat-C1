#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "listDouble.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
bool ListEmpty(List L)
/* Mengirim true jika list kosong */
{
    return First(L) == Nil && Last(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *L)
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
{
    First((*L)) = Nil;
    Last((*L)) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi(infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address P = (address)malloc(sizeof(ElmtList));
    if(P!=Nil){
        info(P) = X;
        next(P) = Nil;
        prev(P) = Nil;
    }
    return P;
}

void Dealokasi(address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search(List L, infotype X)
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    address P = First(L);
    while(P!=Nil){
        if(X == info(P)){
            return P;
        }
        else{
            P = next(P);
        }
    }
    return Nil;
}

bool FSearch(List L, address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
    address Q = First(L);
    while(Q!=Nil){
        if(Q==P){
            return true;
        }
        else{
            Q = next(Q);
        }
    }
    return false;
}

address SearchPrec(List L, infotype X, address *Prec)
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P */
/* dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain*/
{
    address P = First(L);
    while(next(P)!=Nil){
        if(info(next(P))==X){
            return P;
        }
        else{
            P = next(P);
        }
    }
    return Nil;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst(List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address P = Alokasi(X);
    InsertFirst(&(*L),P);
}

void InsVLast(List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P = Alokasi(X);
    InsertLast(&(*L),P);
}

/*** PENGHAPUSAN ELEMEN ***/
void InsVAfter(List *L, infotype Prec, infotype X)
/* procedure InsVAfter2 (input/output L: List, input Prec: infotype, input X: infotype)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen bernilai X setelah elemen bernilai Prec */
/* Jika alokasi gagal: I.S.= F.S. */
{
    address P = Alokasi(X);
    address Q = First((*L));
    if(ListEmpty((*L))){
        InsVFirst(&(*L),X);
    }
    else{
        while(info(Q)!=Prec){
            Q = next(Q);
        }
        next(P) = next(Q);
        next(Q) = P;
    }
}

void DelVFirst(List *L, infotype *X)
/* I.S. List L tidak kosong */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/* dan alamat elemen pertama di-dealokasi */
{
    address P;
    DelFirst(&(*L),&P);
    (*X) = info(P);
    Dealokasi(&P);
}

void DelVLast(List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/* dan alamat elemen terakhir di-dealokasi */
{
    address P;
    DelLast(&(*L),&P);
    (*X) = info(P);
    Dealokasi(&P);
}

void DelVAfter(List *L, infotype *X, infotype Y)
/* procedure DelVAfter1 (input/output L: List, input/output X: infotype, input Y: infotype)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir setelah elemen dengan nilai info Y: nilai info disimpan pada X */
/*      dan alamat elemen nilsi info Y tersebut di-dealokasi */
{
    address P = First(*L);
    address Q;
    if(info(First(*L))==Y){
        Q = next(P);
        (*X) = info(P);
        
    }
    else{
        while(info(P)!=Y){
            P = next(P);
        }
        Q = next(P);
        (*X) = info(next(P));
    }
    next(P) = next(Q);
    next(Q) = Nil;
    Dealokasi(&Q);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst(List *L, address P)
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    if(!ListEmpty(*L)){
        next(P) = First(*L);
        prev(First(*L)) = P;
    }
    else{
        Last(*L) = P;
    }
    First(*L) = P;
}

void InsertAfter(List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    next(P) = next(Prec);
    prev(P) = Prec;
    prev(next(Prec)) = P;
    next(Prec) = P;
}

void InsertLast(List *L, address P)
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if(!ListEmpty(*L)){
        prev(P) = Last(*L);
        next(Last(*L)) = P;
    }
    else{
        First(*L) = P;
    }
    Last(*L) = P;
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst(List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    (*P) = First(*L);
    First(*L) = next(First(*L));
    prev(First(*L)) =Nil;
}

void DelLast(List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
    *P = Last(*L);
    Last(*L) = prev(*P);
    if(Last(*L)!=Nil){
        next(Last(*L)) = Nil;
    }
    else{
        First(*L) = Nil;
    }
    prev(*P) = Nil;
}

void DelAfter(List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list */
/* F.S. Menghapus Next(Prec): */
/* Pdel adalah alamat elemen list yang dihapus */
{
    address P = next(Prec);
    (*Pdel) = P;
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    Dealokasi(&P);
}

void DelP(List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address P = First(*L);
    address Q;
    if(info(P)==X && next(P) == Nil){
        DelFirst(&(*L),&P);
    }
    else{
        while(info(next(P))!=X){
            P = next(P);
        }
        DelAfter(&(*L),&Q,P);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void Printinfo(List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */
{
    address P=First(L);
    if (!ListEmpty(L)){
        while(next(P)!=Nil){
            printf("%d,", info(P));
            P = next(P);
        }
        printf("%d\n", info(P));
    }
}

int NbElmt(List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
{
    int counter = 0;
    address P = First(L);
    while(P!=Nil){
        counter++;
        P=next(P);
    }
    return counter;
}

void DelAll(List *L)
{
    // kamus lokal
    address P,Pdel;

    // algoritma
    if(First(*L)==Nil){
        printf("List Kosong\n");
    } 
    else{
        P = First(*L);
        while(P!=Nil){
            Pdel = P;
            P = next(P);
            Dealokasi(Pdel);
        }
    Dealokasi(P);
    printf("Dealokasi sukses\n");
    }
}

void InversList(List *L)
{
    // kamus lokal
    address P[100];
    int x=1;

    // algoritma
    if (First(*L)==Nil){
        printf("List Kosong\n");
    }
    else{
        P[x] = First(*L);
        while(P[x]!=Nil){
            P[x+1] = next(P[x]);
            x++;
        }
        x--;
        First(*L) = P[x];
        while(x!=1){
            next(P[x]) = P[x-1];
            x--;
        }
        next(P[x]) = Nil;
    }
}

List FInversList(List L)
{
    // kamus lokal
    address P,P1;
    List L1;
    int z=0;

    // algoritma
    if(First(L)==Nil){
        First(L1)=Nil;
    } 
    else{
        P = First(L);
        First(L1) = Nil;
        while(P!=Nil) {
            P1 = Alokasi(Info(P));
            if(P1==Nil){
                z=1;
            }
            InsertFirst(&L1,P1);
            P = next(P);
        }
        if(z==1){
            DelAll(&L1);
            First(L1) = Nil;
            return (L1);
        }
    return (L1);
    }
}

void CopyList(List *L1, List *L2)
{
    First(*L2)=First(*L1);
}

List FCopyList(List L)
{
    // kamus lokal
    address P,P1;
    List L1;
    int z=0;

    // algoritma
    if(First(L)==Nil){
        First(L1)=Nil;
    } 
    else{
        P = First(L);
        First(L1) = Nil;

        while(P!=Nil){
            P1 = Alokasi(Info(P));
            if(P1==Nil)
                { z=1; }
            InsertLast(&L1,P1);
            P = next(P);
    }

    if(z==1){
        DelAll(&L1);
        First(L1) = Nil;
        return (L1);
    }
    return (L1);
    }
}

void Konkat(List L1, List L2, List *L3)
{
    // kamus lokal
    address P,P1;
    int z=0;

    // algoritma
    if((First(L1)&&First(L2))==Nil){
        First(*L3)=Nil;
    } 
    else{
        if(First(L1)!=Nil){
            P = First(L1);
            First(*L3) = Nil;
            while (P!=Nil){
                P1 = Alokasi(Info(P));
                if (P1 == Nil){
                    z=1;
                }
            InsertLast(&(*L3),P1);
            P = next(P);
            }
        }
        else{
            First(*L3)=Nil;
        }
        if(First(L2)!=Nil){
            P = First(L2);
            while(P!=Nil){
                P1 = Alokasi(Info(P));
                if (P1 == Nil){
                    z=1;
                }
            InsertLast(&(*L3),P1);
            P = next(P);
            }
        }
        if(z==1){
            DelAll(&L3);
            First(*L3) = Nil;
        }
    }
}

void Konkat1(List *L1, List *L2, List *L3)
{
    // kamus lokal
    address P,P1;
    int z=0;

    // algoritma
    if((First(*L1)&&First(*L2))==Nil){
        First(*L3)=Nil;
    }
    else{
        if(First(*L1)!=Nil){
            P = First(*L1);
            First(*L3) = Nil;
            while(P!=Nil){
                P1 = Alokasi(Info(P));
                if(P1==Nil){
                    z=1;
                }
                InsertLast(&(*L3),P1);
                P = next(P);
            }
        }
        else{
            First(*L3)=Nil;
        }
        if(First(*L2)!=Nil){
            P = First(*L2);
            while(P!=Nil){
                P1 = Alokasi(Info(P));
                if(P1==Nil){
                    z=1;
                }
                InsertLast(&(*L3),P1);
                P = next(P);
            }
        }
        if(z==1){
            DelAll(&L3);
            First(*L3) = Nil;
        }
    }
    DelAll(&(*L1));
    DelAll(&(*L2));
}

void PecahList(List *L1, List *L2, List L)
{
    // kamus lokal
    int x,i=0;
    address P,P1;

    // algoritma
    x=NbElmt(L);
    P=First(L);
    if(i==Nil){
        First (*L1)=Nil;
        First (*L2)=Nil;
    }
    if(i==1){
        First (*L2)=Nil;
    }
    while(i!=(x/2)){
        i++;
        P1 = Alokasi(Info(P));
        InsertLast(&(*L1),P1);
        P = next(P);
    }
    while(P!=Nil){
        P1 = Alokasi(Info(P));
        InsertLast(&(*L2),P1);
        P = next(P);
    }
}