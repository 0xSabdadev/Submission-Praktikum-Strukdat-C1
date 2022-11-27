#ifndef listLinear_C
#define listLinear_C
#include "boolean.h"
#include "listLinear.h"
#include <stdio.h>

/* Program   : listLinear.c */
/* Deskripsi : realisasi body file modul ADT Linked List Linear */
/* NIM/Nama  : 24060121120039/ Nida' Naafilatul Haniifah*/
/* Tanggal   : 29 Oktober 2022*/
/***********************************/

/* ----- Test List Kosong ----- */
/* Mengirim true jika list kosong */
boolean ListEmpty (List L){
    /*Kamus Lokal*/

    /*Algoritma*/
    return First(L) == Nil;

}


/* ----- Pembuatan List Kosong ----- */
/* I.S. : sembarang
F.S. : Terbentuk list kosong */
void CreateList (List *L){
    /*Kamus Lokal*/

    /*Algoritma*/
    First((*L)) = Nil;
}

/*  ----- Manajemen Memori ----- */
/*  Mengirimkan address hasil alokasi sebuah elemen */
/*  Jika alokasi berhasil, maka address tidak Nil,
    dan misalnya menghasilkan P, maka
    Info(P) = X, Next(P) = Nil
    Jika alokasi gagal, mengirimkan Nil */
address Alokasi (infotype X){
    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    P = (address)malloc(sizeof(ElmtList));

    if (P != Nil){
        info(P) = X;
        next(P) = Nil;
    }

    return P;
}

/* I.S. : P terdefinisi
F.S. : P dikembalikan ke sistem
Melakukan dealokasi/pengembalian address P */
void Dealokasi (address *P){
    /*Kamus Lokal*/

    /*Algoritma*/
    info((*P)) = 0;
    next((*P)) = Nil;
    (*P) = Nil;
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
address Search(List L, infotype X){
    /*Kamus Lokal*/
    address P;


    /*Algoritma*/
    P = First(L);

    while (P != Nil){
        if (X == info(P)){
            return P;
        }else{
            P = next(P);
        }
    }
    return Nil;
}

/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
boolean FSearch(List L, address P){
    /*Kamus Lokal*/
    address Q;


    /*Algoritma*/
    Q = First(L);
    while (P != Nil){
        if (Q == P){
            return true;
        }else{
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
    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    (*Prec) = Nil;
    P = First(L);
    while (P != Nil){
        if (X == info(P)){
            return *Prec;
        }else{
            (*Prec) = P;
            P = next(P);
        }
    }
    return Nil;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/

/*  I.S. : Sembarang, P sudah dialokasi
    F.S. : Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertFirst (List *L, address P){
    /*Kamus Lokal*/


    /*Algoritma*/
    next(P) = First((*L));
    First((*L)) = P;
}


/* I.S. : Prec pastilah elemen list dan bukan elemen terakhir,
P sudah dialokasi
F.S. : Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertAfter (List *L, address P, address Prec){
    /*Kamus Lokal*/


    /*Algoritma*/
    next(P) = next(Prec);
    next(Prec) = P;

}

/* I.S. : Sembarang, P sudah dialokasi
F.S. : P ditambahkan sebagai elemen terakhir yang baru */
void InsertLast (List *L, address P){
    /*Kamus Lokal*/
    address last, prec;


    /*Algoritma*/
    if (ListEmpty(*L)){
        InsertFirst(&(*L), P);
    }else{
        last = First((*L));
        while (next(last) != Nil){
            last = next(last);
        }
        InsertAfter(&(*L), P, last);
    }

}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/

/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelFirst(List *L, address *P){
    /*Kamus Lokal*/


    /*Algoritma*/
    if (!ListEmpty((*L))){
        (*P) = First((*L));
        First((*L)) = next(First((*L)));
    }else{
        printf("List Kosong");
    }
}

/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelLast(List *L, address *P){
    /*Kamus Lokal*/
    address Last, PrecLast;

    /*Algoritma*/
    PrecLast = Nil;
    Last = First((*L));
    while(next(Last) != Nil){
        PrecLast = Last;
        Last = next(Last);
    }
    (*P) = Last;
    if (next(First((*L))) == Nil){
        First((*L)) = Nil;
    }else{
        next(PrecLast) = Nil;
    }
}


/*Mencari alamat elemen terakhir dan sebelumnya*/
void AdrLast(List *L, address *Prec, address *Last){
    /*Kamus Lokal*/

    /*Algoritma*/
    (*Prec) = Nil;
    (*Last) = First((*L));
    while (next(*Last) != Nil){
        (*Prec) = (*Last);
        (*Last) = next(*Last);
    }

}

/* I.S. List tidak kosong. Prec adalah anggota list */
/* F.S. Menghapus Next(Prec): */
/* Pdel adalah alamat elemen list yang dihapus */
void DelAfter(List *L, address *Pdel, address Prec){
    /*Kamus Lokal*/


    /*Algoritma*/
    (*Pdel) = next(Prec);
    next(Prec) = next(next(Prec));
    next((*Pdel)) = Nil;
}

/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelP(List *L, infotype X){
    /*Kamus Lokal*/
    address P, Prec;


    /*Algoritma*/
    if(!ListEmpty((*L)) && Search((*L), X) != Nil){
        if(info(First(*L)) == X){
            P = First((*L));
            First((*L)) = next(First((*L)));
        }
        else{
            Prec = First(*L);
            while (info(next(Prec)) != X){
                Prec = next(Prec);
            }
            if (info(next(Prec)) == X){
                DelAfter(&(*L), &P, Prec);
            }
        }
    }


}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVFirst(List *L, infotype X){
    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    P = Alokasi(X);
    if (P != Nil){
        InsertFirst(&(*L), P);
    }
}

/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void InsVLast(List *L, infotype X){
    /*Kamus Lokal*/
    address P;


    /*Algoritma*/
    P = Alokasi(X);
    if (P != Nil){
        InsertLast(&(*L), P);
    }
}
/* procedure InsVAfter2 (input/output L: List, input Prec: infotype, input X: infotype)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen bernilai X setelah elemen bernilai Prec */
/* Jika alokasi gagal: I.S.= F.S. */
void InsVAfter2(List *L, infotype Prec, infotype X){
    /*Kamus Lokal*/
    address P, Q;


    /*Algoritma*/
    P = Alokasi(X);
    Q = First(*L);
    if (ListEmpty((*L))){
        InsVFirst(&(*L), X);
    }else{
        while (info(Q) != Prec){
            Q = next(Q);
        }
        next(P) = next(Q);
        next(Q) = P;
    }
}

/* procedure InsVAfter1 (input/output L: List, input Prec: address, input X: address)*/
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen bernilai X setelah elemen bernilai Prec */
/* Jika alokasi gagal: I.S.= F.S. */
void InsVAfter1(List *L, address Prec, address X){
    /*Kamus Lokal*/

    /*Algoritma*/
    next(X) = next(Prec);
    next(Prec) = X;
}


/*** PENGHAPUSAN ELEMEN ***/
/* I.S. List L tidak kosong */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/* dan alamat elemen pertama di-dealokasi */
void DelVFirst(List *L, infotype *X){
    /*Kamus Lokal*/
    address P;


    /*Algoritma*/
    P = First((*L));
    (*X) = info(P);
    First((*L)) = next(First(*L));
    next(P) = Nil;
    Dealokasi(&P);

}

/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/* dan alamat elemen terakhir di-dealokasi */
void DelVLast(List *L, infotype *X){
    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    DelLast(&(*L), &P);
    (*X) = info(P);
    Dealokasi(&P);
}

/* procedure DelVAfter2 (input/output L: List, input/output X: infotype, input Y: address)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir setelah elemen dengan nilai address Y: nilai address disimpan pada X */
/*      dan alamat elemen X tersebut di-dealokasi */
void DelVAfter2(List *L, address *X, address Y){
    /*Kamus Lokal*/


    /*Algoritma*/
    if (next(Y) != Nil){
        (*X) = next(Y);
        next(Y) = next(next(Y));
        next((*X)) = Nil;

        Dealokasi(&(*X));
    }else{
        (*X) = Nil;
    }

}

/* procedure DelVAfter1 (input/output L: List, input/output X: infotype, input Y: infotype)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir setelah elemen dengan nilai info Y: nilai info disimpan pada X */
/*      dan alamat elemen nilsi info Y tersebut di-dealokasi */
void DelVAfter1(List *L, infotype *X, infotype Y){
    /*Kamus Lokal*/
    address P, Q;

    /*Algortima*/
    P = First((*L));
    while(info(P) != Y){
        P = next(P);
    }
    Q = next(P);
    (*X) = info(next(P));

    next(P) = next(next(P));
    next(Q) = Nil;
    Dealokasi(&Q);

}

//
//
/****************** PROSES SEMUA ELEMEN LIST ******************/
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */
void Printinfo(List L){
    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    if (ListEmpty(L)){
        printf("List Kosong");
    }else{
        P = First(L);
        while (P != Nil){
            printf("%d ", info(P));
            P = next(P);
        }
    }

}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
int NbElmt(List L){
    /*Kamus Lokal*/
    address P;
    int banyak;

    /*Algoritma*/
    banyak = 0;
    P = First(L);
    while (P != Nil){
        banyak += 1;
        P = next(P);
    }

    return banyak;
}


//


#endif
