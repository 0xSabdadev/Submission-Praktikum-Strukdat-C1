/***********************************************************/
/* Program   : listDouble.c */
/* Deskripsi : realisasi body file modul ADT Double List */
/* NIM/Nama  : 24060121120039/ Nida' Naafilatul Haniifah*/
/* Tanggal   : 21 November 2022*/
/***********************************************************/

#ifndef listDouble_C
#define listDouble_C
#include "boolean.h"
#include "listDouble.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean ListEmpty(List L){
    /* Mengirim true jika list kosong */
    /*Kamus Lokal*/


    /*Algoritma*/
    return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *L){
    /* I.S. sembarang */
    /* F.S. Terbentuk list kosong */
    /*Kamus Lokal*/

    /*Algoritma*/
    First(*L) = Nil;
    Last(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi(infotype X){
    /* Mengirimkan address hasil alokasi sebuah elemen */
    /* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
    /* menghasilkan P, maka info(P)=X, Next(P)=Nil */
    /* Jika alokasi gagal, mengirimkan Nil */

    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    P = (address)malloc(sizeof(ElmtList));

    if (P != Nil){
        info(P) = X;
        prev(P) = Nil;
        next(P) = Nil;
    }

    return P;

}

void Dealokasi(address *P){
    /* I.S. P terdefinisi */
    /* F.S. P dikembalikan ke sistem */
    /* Melakukan dealokasi/pengembalian address P */

    /*Kamus Lokal*/

    /*Algoritma*/
    free(*P);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void Printinfo(List L){
    /* I.S. List mungkin kosong */
    /* F.S. Jika list tidak kosong, */
    /* Semua info yg disimpan pada elemen list diprint */
    /* Jika list kosong, hanya menuliskan "list kosong" */

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

int NbElmt(List L){
    /* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

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


/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst(List *L, address P){
    /* I.S. Sembarang, P sudah dialokasi */
    /* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */

    /*Kamus Lokal*/


    /*Algoritma*/
    if (ListEmpty(*L)){
        Last(*L) = P;
    }else{
        prev(First(*L)) = P;
        next(P) = First((*L));
    }
    First((*L)) = P;

}

void InsertAfter(List *L, address P, address Prec){
    /* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
    /* P sudah dialokasi */
    /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

    /*Kamus Lokal*/


    /*Algoritma*/
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;

}

void InsertLast(List *L, address P){
    /* I.S. Sembarang, P sudah dialokasi */
    /* F.S. P ditambahkan sebagai elemen terakhir yang baru */

    /*Kamus Lokal*/


    /*Algoritma*/
    if (ListEmpty(*L)){
        First(*L) = P;
    }else{
        prev(P) = Last(*L);
        next(Last(*L)) = P;
    }
    Last(*L) = P;
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst(List *L, address *P){
    /* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
    /* Elemen list berkurang satu (mungkin menjadi kosong) */
    /* First element yg baru adalah suksesor elemen pertama yang lama */

    /*Kamus Lokal*/

    /*Algoritma*/
    (*P) = First(*L);
    if (NbElmt(*L) == 1){
        First(*L) = Nil;
    }else{
        First(*L) = next(First(*L));
        prev(First(*L)) = Nil;
    }
    prev(*P) = Nil;
    next(*P) = Nil;

}

void DelLast(List *L, address *P){
    /* I.S. List tidak kosong */
    /* F.S. P adalah alamat elemen terakhir list sebelum penghapusan */
    /* Elemen list berkurang satu (mungkin menjadi kosong) */
    /* Last element baru adalah predesesor elemen pertama yg lama, */
    /* jika ada */

    /*Kamus Lokal*/

    /*Algoritma*/
    (*P) = Last(*L);
    Last(*L) = prev(Last(*L));
    if(!ListEmpty(*L)){
        next(Last(*L)) = Nil;
    }else{
        First(*L) = Nil;
        Last(*L) = Nil;
    }
    prev(*P) = Nil;
}

void DelAfter(List *L, address *Pdel, address Prec){
    /* I.S. List tidak kosong. Prec adalah anggota list */
    /* F.S. Menghapus Next(Prec): */
    /* Pdel adalah alamat elemen list yang dihapus */

    /*Kamus Lokal*/

    /*Algoritma*/
    (*Pdel) = next(Prec);
    prev(next(next(Prec))) = Prec;
    next(Prec) = next(next(Prec));
}

void DelP(List *L, infotype X){
    /* I.S. Sembarang */
    /* F.S. Jika ada elemen list beraddress P, dengan info(P)=X */
    /* Maka P dihapus dari list dan di-dealokasi */
    /* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
    /* List mungkin menjadi kosong karena penghapusan */

    /*Kamus Lokal*/
    address P, Pdel;

    /*Algoritma*/
    P = First(*L);
    if(info(P)==X && next(P) == Nil){
        DelFirst(&(*L),&P);
    }else{
        while(info(next(P)) != X){
            P = next(P);
        }
        DelAfter(&(*L),&Pdel,P);
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst(List *L, infotype X){
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    P = Alokasi(X);
    InsertFirst(&(*L),P);

}

void InsVLast(List *L, infotype X){
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen list di akhir: elemen terakhir yang baru */
    /* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    P = Alokasi(X);
    InsertLast(&(*L),P);

}

void InsVAfter(List *L, infotype Prec, infotype X){
    /* procedure InsVAfter2 (input/output L: List, input Prec: infotype, input X: infotype)
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen bernilai X setelah elemen bernilai Prec */
    /* Jika alokasi gagal: I.S.= F.S. */

    /*Kamus Lokal*/
    address P, Q;

    /*Algoritma*/
    P = Alokasi(X);
    Q = First((*L));

    if(ListEmpty(*L)){
        InsVFirst(&(*L),X);
    }else{
        while(info(Q)!=Prec){
            Q = next(Q);
        }
        InsertAfter(&(*L),P,Q);
    }

}


/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(List *L, infotype *X){
    /* I.S. List L tidak kosong */
    /* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
    /* dan alamat elemen pertama di-dealokasi */

    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    DelFirst(&(*L),&P);
    (*X) = info(P);
    Dealokasi(&P);

}

void DelVLast(List *L, infotype *X){
    /* I.S. list tidak kosong */
    /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
    /* dan alamat elemen terakhir di-dealokasi */

    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    DelLast(&(*L), &P);
    (*X) = info(P);
    Dealokasi(&P);
}

void DelVAfter(List *L, infotype *X, infotype Y){
    /* procedure DelVAfter1 (input/output L: List, input/output X: infotype, input Y: infotype)
    /* I.S. list tidak kosong */
    /* F.S. Elemen terakhir setelah elemen dengan nilai info Y: nilai info disimpan pada X */
    /* dan alamat elemen nilsi info Y tersebut di-dealokasi */

    /*Kamus Lokal*/
    address P, Q;

    /*Algoritma*/
    P = First(*L);
    if(info(First(*L))==Y){
        Q = next(P);
        (*X) = info(Q);

    }else{
        while(info(P)!=Y){
            P = next(P);
        }
        Q = next(P);
        (*X) = info(next(P));
    }
    prev(next(next(P))) = P;
    next(P) = next(next(P));
    Dealokasi(&Q);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search(List L, infotype X){
    /* Mencari apakah ada elemen list dengan info(P)= X */
    /* Jika ada, mengirimkan address elemen tersebut. */
    /* Jika tidak ada, mengirimkan Nil */

    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    P = First(L);
    while(P!=Nil){
        if(X == info(P)){
            return P;
        }else{
            P = next(P);
        }
    }
    return Nil;
}
boolean FSearch(List L, address P){
    /* Mencari apakah ada elemen list yang beralamat P */
    /* Mengirimkan true jika ada, false jika tidak ada */

    /*Kamus Lokal*/
    address Q;

    /*Algoritma*/
    Q = First(L);
    while(Q!=Nil){
        if(Q==P){
            return true;
        }else{
            Q = next(Q);
        }
    }
    return false;
}
address SearchPrec(List L, infotype X, address *Prec){
    /* Mengirimkan address elemen sebelum elemen yang nilainya=X */
    /* Mencari apakah ada elemen list dengan info(P)= X */
    /* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P */
    /* dan Info(P)=X. */
    /* Jika tidak ada, mengirimkan Nil */
    /* Jika P adalah elemen pertama, maka Prec=Nil */
    /* Search dengan spesifikasi seperti ini menghindari */
    /* traversal ulang jika setelah Search akan dilakukan operasi lain*/

    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    P = First(L);
    while(next(P)!=Nil){
        if(info(next(P))==X){
            return P;
        }else{
            P = next(P);
        }
    }
    return Nil;
}


/****************** PROSES TERHADAP LIST ******************/
void AdrLast(List *L, address *Prec, address *Last){
    /*mencari alamat elemen terakhir dan sebelumnya*/

    /*Kamus Lokal*/

    /*Algoritma*/
    (*Last) = Last(*L);
    (*Prec) = prev(Last(*L));
}

void DelAll(List *L){
    /* Delete semua elemen list dan alamat elemen di-dealokasi

    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    while (First((*L)) != Nil){
        DelFirst(&(*L), &P);
        Dealokasi(&P);
    }
}

void InversList(List *L){
    /* I.S. sembarang. */
    /* F.S. elemen list dibalik : */
    /* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
    /* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

    /*Kamus Lokal*/
    address P, curr, prec;


    /*Algoritma*/
    P = First((*L));
    prec = Nil;
    while (P != Nil){
        curr = P;
        P = next(P);
        next(curr) = prec;
        prev(curr) = P;
        prec = curr;
    }First((*L)) = prec;

}

List FInversList(List L){
    /* Mengirimkan list baru, hasil invers dari L */
    /* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
    /* Jika alokasi gagal, hasilnya list kosong */
    /* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */

    /*Kamus Lokal*/
    List L1;
    address P,E;

    /*Algoritma*/
    CreateList(&L1);
    P = First(L);
    while (P != Nil){
        E = Alokasi(info(P));
        if (E != Nil){
            InsertFirst(&L1, E);
        }else{
            DelAll(&L1);
            P = Nil;
        }
        P = next(P);
    }
    return L1;

}

void CopyList(List *L1, List *L2){
    /* I.S. L1 sembarang. F.S. L2=L1 */
    /* L1 dan L2 "menunjuk" kepada list yang sama.*/
    /* Tidak ada alokasi/dealokasi elemen */

    /*Kamus Lokal*/

    /*Algoritma*/
    CreateList(&(*L2));
    First((*L2)) = First((*L1));
}

List FCopyList(List L){
    /* Mengirimkan list yang merupakan salinan L */
    /* dengan melakukan alokasi. */
    /* Jika ada alokasi gagal, hasilnya list kosong dan */
    /* semua elemen yang terlanjur di-alokasi, harus didealokasi */

    /*Kamus Lokal*/
    List L1;
    address P,E;

    /*Algoritma*/
    CreateList(&L1);
    P = First(L);
    while(P != Nil){
        E = Alokasi(info(P));
        if (E != Nil){
            InsertLast(&L1, E);
        }else{
            DelAll(&L1);
            P = Nil;
        }
        P = next(P);
    }
    return L1;
}

void CpAlokList(List Lin, List *Lout){
    /* I.S. Lin sembarang. */
    /* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
    /* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur
    dialokasi, didealokasi */
    /* dengan melakukan alokasi elemen. */
    /* Lout adalah list kosong jika ada alokasi elemen yang gagal */

    /*Kamus Lokal*/
    address P,E;

    /*Algoritma*/
    CreateList(&(*Lout));
    P = First(Lin);
    while(P != Nil){
        E = Alokasi(info(P));
        if (E != Nil){
            InsertLast(&(*Lout), E);
        }else{
            DelAll(&(*Lout));
            P = Nil;
        }
        P = next(P);
    }
}

void Konkat(List L1, List L2, List *L3){
    /* I.S. L1 dan L2 sembarang */
    /* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
    /* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
    /* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
    /* harus di-dealokasi dan L3=Nil*/
    /* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang baru*/
    /* Elemen L3 adalah hasil alokasi elemen yang baru. */
    /* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
    /* dan semua elemen yang pernah dialokasi didealokasi */

    /*Kamus Lokal*/
    address P,Q,E;

    /*Algoritma*/
    CreateList(&(*L3));
    P = First(L1);
    while (P != Nil){
        E = Alokasi(info(P));
        if (E != Nil){
            InsertLast(&(*L3), E);
        }else{
            DelAll(&(*L3));
            P = Nil;
        }
        P = next(P);
    }
    Q = First(L2);
    while (Q != Nil){
        E = Alokasi(info(Q));
        if (E != Nil){
            InsertLast(&(*L3), E);
        }else{
            DelAll(&(*L3));
            Q = Nil;
        }
        Q = next(Q);
    }
}

void Konkat1(List *L1, List *L2, List *L3){
    /* I.S. L1 dan L2 sembarang */
    /* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
    /* Konkatenasi dua buah list : L1 dan L2 */
    /* menghasilkan L3 yang baru (dengan elemen list L1 dan L2)*/
    /* dan L1 serta L2 menjadi list kosong.*/
    /* Tidak ada alokasi/dealokasi pada prosedur ini */

    /*Kamus Lokal*/

    /*Algoritma*/
    CreateList(&(*L3));
    if (ListEmpty((*L1))){
        First((*L3)) = First((*L2));
    }else{
        First((*L3)) = First((*L1));
        next(Last(*L1)) = First((*L2));
        prev(First((*L2))) = Last(*L1);
        First((*L1)) = Nil;
    }
    First((*L2)) = Nil;
}

void PecahList(List *L1, List *L2, List L){
    /* I.S. L mungkin kosong */
    /* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
    /* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
    /* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
    /* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */

    /*Kamus Lokal*/
    int mid;
    address P;

    /*Algoritma*/
    mid = (NbElmt(L) / 2);
    P= First(L);
    CreateList(&(*L1));
    CreateList(&(*L2));
    for (int i = 1; i <= mid; i++)
    {
        InsertLast(&(*L1), Alokasi(info(P)));
        P = next(P);
    }
    while (P != Nil)
    {
        InsertLast(&(*L2), Alokasi(info(P)));
        P = next(P);
    }
}
#endif
