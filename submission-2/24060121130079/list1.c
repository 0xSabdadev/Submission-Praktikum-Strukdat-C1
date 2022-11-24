/********************************************/
/* Program   : list1.c                      */
/* Deskripsi : file BODY modul list         */
/* NIM/Nama  : 24060121130079 / Ganar K F Z */
/* Tanggal   : 29 Oktober 2022              */
/********************************************/

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

/****************** TEST LIST KOSONG ******************/
/* Mengirim true jika list kosong */
boolean ListEmpty(List L){
    // kamus lokal

    // algoritma
    return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
void CreateList(List *L){
    // kamus lokal

    // algoritma
    First((*L)) = Nil;
}

/****************** Manajemen Memori ******************/
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
address Alokasi(infotype X){
    // kamus lokal
    address P;

    // algoritma
    P = (address)malloc(sizeof(ElmtList));

    if (P != Nil){
        info(P) = X;
        next(P) = Nil;
    }

    return P;
}

/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
void Dealokasi(address *P){
    // kamus lokal

    // algoritma
    info((*P)) = 0;
    next((*P)) = Nil;
    (*P) = Nil;
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
address Search(List L, infotype X){
    // kamus lokal
    address P;

    // algoritma
    P = First(L);

    while (P != Nil){
        if (X == info(P)){
            return P;
        }
        else{
            P = next(P);
        }
    }
    return Nil;
}

/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
boolean FSearch(List L, address P){
    // kamus lokal
    address Q;

    // algoritma
    Q = First(L);

    while (Q != Nil){
        if (Q == P){
            return true;
        }
        else{
            Q = next(Q);
        }
    }
    return false;
}

/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P */
/* dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain*/
address SearchPrec(List L, infotype X, address *Prec){
    // kamus lokal
    address P;

    // algoritma
    P = First(L);

    while (next(P) != Nil){
        if (info(next(P)) == X){
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
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVFirst(List *L, infotype X){
    // kamus lokal
    address P;

    // algoritma
    P = Alokasi(X);
    if (P != Nil){
        InsertFirst(L,P);
    }
}

/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void InsVLast(List *L, infotype X){
    // kamus lokal
    address P;

    // algoritma
    P = Alokasi(X);
    if (P != Nil){
        InsertLast(L,P);
    }
}

/* procedure InsVAfter2 (input/output L: List, input Prec: infotype, input X: infotype)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen bernilai X setelah elemen bernilai Prec */
/* Jika alokasi gagal: I.S.= F.S. */
void InsVAfter2(List *L, infotype Prec, infotype X){
    // kamus lokal
    address P;
    address Q;

    // algoritma
    P = Alokasi(X);
    Q = First(*L);

    if (ListEmpty((*L))){
        InsVFirst(&(*L),X);
    }
    else{
        while(info(Q) != Prec){
            Q = next(Q);
        }
        
        next(P) = next(Q);
    }
}

/* procedure InsVAfter1 (input/output L: List, input Prec: address, input X: address)*/
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen bernilai X setelah elemen bernilai Prec */
/* Jika alokasi gagal: I.S.= F.S. */
void InsVAfter1(List *L, address Prec, address X){
    // kamus lokal

    // algoritma
    next(X) = next(Prec);
    next(Prec) = X;
}

/*** PENGHAPUSAN ELEMEN ***/
/* I.S. List L tidak kosong */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/* dan alamat elemen pertama di-dealokasi */
void DelVFirst(List *L, infotype *X){
    // kamus lokal
    address P;

    // algoritma
    P = First(*L);
    (*X) = info(P);
    First(*L) = next(P);
    next(P) = Nil;
    Dealokasi(&P);
}

/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/* dan alamat elemen terakhir di-dealokasi */
void DelVLast(List *L, infotype *X){
    // kamus lokal
    address P;

    // algoritma
    DelLast(L,P);
    (*X) = info(P);
    Dealokasi(&P);
}

/* procedure DelVAfter2 (input/output L: List, input/output X: infotype, input Y: infotype)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir setelah elemen dengan nilai address Y: nilai address disimpan pada X */
/*      dan alamat elemen X tersebut di-dealokasi */
void DelVAfter2(List *L, address *X, address Y){
    // kamus lokal
    address P;

    // algoritma
    (*X) = next(Y);
    next(Y) = next(next(Y));
    Dealokasi(&(*X));
}

/* procedure DelVAfter1 (input/output L: List, input/output X: infotype, input Y: infotype)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir setelah elemen dengan nilai info Y: nilai info disimpan pada X */
/*      dan alamat elemen nilsi info Y tersebut di-dealokasi */
void DelVAfter1(List *L, infotype *X, infotype Y){
    // kamus lokal
    address P;
    address Q;

    // algoritma
    P = First(*L);
    if (info(First(*L)) == Y){
        Q = next(P);
        (*X) = info(Q);
        next(P) = next(Q);
        Dealokasi(&Q);
    }
    else{
        while (info(P) != Y){
           P = next(P); 
        }
        Q = next(P);
        (*X) = info(next(P));
        next(P) = next(Q);
        Dealokasi(&Q);
    }
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertFirst(List *L, address P){
    // kamus lokal
    
    // algoritma
    next(P) = First(*L);
    First(*L) = P;
}

/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertAfter(List *L, address P, address Prec){
    // kamus lokal

    // algoritma
    next(P) = next(Prec);
    next(Prec) = P;
}

/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void InsertLast(List *L, address P){
    // kamus lokal
    address Last;

    // algoritma
    if (First(*L) == Nil){
        InsertFirst(&(*L),P);
    }
    else{
        Last = First((*L));
        while (next(Last) != Nil){
            Last = next(Last);
        }

        InsertAfter(&(*L),P,Last);
    }
}

/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelFirst(List *L, address *P){
    // kamus lokal

    // algoritma
    if (!ListEmpty((*L))){
        (*P) = First(*L);
        First(*L) = next(First(*L));
    }
    else{
        printf("List Kosong");
    }
}

/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelP(List *L, infotype X){
    // kamus lokal
    address P;
    address Prec;

    // algoritma
    if (!ListEmpty(*L)){
        if (info(First(*L)) == X){
            DelFirst(&(*L),&P);
        }
        else{
            Prec = First(*L);
            while (info(next(Prec)) != X){
                Prec = next(Prec);
            }
            DelAfter(&(*L),&P,Prec);
        }
    }
}

/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelLast(List *L, address *P){
    // kamus lokal
    address PrecLast;
    address Last;

    // algoritma
    Last = First(*L);
    PrecLast = Nil;
    while (next(Last) != Nil){
        PrecLast = Last;
        Last = next(Last);
    }
    (*P) = Last;
    if (PrecLast == Nil){
        First(*L) = Nil;
    }
    else{
        next(PrecLast) = Nil;
    }
}

/* I.S. List tidak kosong. Prec adalah anggota list */
/* F.S. Menghapus Next(Prec): */
/* Pdel adalah alamat elemen list yang dihapus */
void DelAfter(List *L, address *Pdel, address Prec){
    // kamus lokal

    // algoritma
    (*Pdel) = next(Prec);
    next(Prec) = next(next(Prec));
    next((*Pdel)) = Nil;
    Dealokasi(&(*Pdel));
}

/* Mencari alamat elemen terakhir dan sebelumnya*/
void AdrLast(List *L, address *Prec, address *Last){
    // kamus lokal
    address Last;
    address PrecLast;

    // algoritma
    Last = First(*L);
    PrecLast = Nil;
    while (NEXT(Last) != Nil){
        PrecLast = Last;
        Last = next(*Last);
    }
    printf("\nAlamat elemen terakhir adalah : %d", Last);
    printf("\nAlamat elemen sebelum terakhir adalah : %d",PrecLast);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */
void Printinfo(List L){
    // kamus lokal
    address P;

    // algoritma
    P = First(L);
    if (P == Nil){
        printf("List Kosong\n");
    }
    else{
        while (next(P) != Nil){
            printf("%d, ",info(P));
            P = next(P);
        }
        printf("%d\n",info(P));
    }
}

/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
int NbElmt(List L){
    // kamus lokal
    int counter;
    address P;

    // algoritma
    counter = 0;
    if (!ListEmpty(L)){
        P = First(L);
        while (P != Nil){
            counter++;
            P = next(P);
        }
    }
    return counter;
}
