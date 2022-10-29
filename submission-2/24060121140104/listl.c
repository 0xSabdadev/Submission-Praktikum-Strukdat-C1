#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/***********************************/
/* Program   : listl.c */
/* Deskripsi : realisasi file modul list linear */
/* NIM/Nama  : 24060121140104/Divia Shinta Sukarsaatmadja */
/* Tanggal   : 24 Oktober 2022 */
/***********************************/

/****************** TEST LIST KOSONG ******************/
/*Function ListEmpty(L: List) -> boolean*/
/*{Mengirim true jika list kosong}*/
boolean ListEmpty (List L){
/*Kamus lokal*/

/*Algoritma*/
    if (First(L) == Nil){
        return true;
    }
    else{
        return false;
    }
}

/****************** PEMBUATAN LIST KOSONG ******************/
/*Procedure CreateList(output L: List)*/
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
void CreateList (List *L){
/*Kamus lokal*/

/*Algoritma*/
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
/*Function Alokasi(X: infotype)-->address*/
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
address Alokasi (infotype X){
/*Kamus lokal*/
    address P;
/*Algoritma*/
    P = (address) malloc(sizeof(ElmtList));
    if (P != Nil){
        info(P) = X;
        next(P) = Nil;
    }
    else{
        P = Nil;
    }
}

/*Procedure Dealokasi(output P: address)*/
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
void Dealokasi (address *P){
/*Kamus lokal*/

/*Algoritma*/
    free(*P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
/* Procedure InsertFirst(input/output L: List, input P: address*/
/* Penambahan Elemen Berdasarkan Alamat */
/* I.S. 	: Sembarang, P sudah dialokasi
   F.S.		: Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertFirst (List *L, address P){
/*Kamus lokal*/

/*Algoritma*/
    next(P) = First(*L);
    First(*L) = P;
}

/* Procedure InsertAfter(input/output L: List, input P: address, input Prec: address*/
/* Menyisipkan sebuah elemen beralamat P setelah sebagai suksesor dari sebuah elemen list linier yang beralamat Prec*/
/* I.S.		: Prec pastilah elemen list dan bukan elemen terakhir,
			  P sudah dialokasi
   F.S. 	: Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertAfter (List *L, address P, address Prec){
/*Kamus lokal*/

/*Algoritma*/
    next(P) = next(Prec);
    next(Prec) = P;
}

/* Procedure InsertLast(input/output L: List, input P: address*/
/* Menyisipkan sebuah elemen beralamat P setelah sebagai elemen terakhir sebuah list linier*/
/* I.S.		: Sembarang, P sudah dialokasi
   F.S.		: P ditambahkan sebagai elemen terakhir yang baru */
void InsertLast (List *L, address P){
/*Kamus lokal*/
    address Last;
/*Algoritma*/
    if (First(*L) == Nil) {
        InsertFirst(&L,P);
    }
    else{
        Last = First(*L);
        while(next(Last) != Nil){
            Last = next(Last);
        }
        InsertAfter(&L,P,Last);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
/* Procedure DelFirst(input/output L: List, input P: address*/
/* Menghapus elemen pertama list linier*/
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen pertama list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              First element yang baru adalah suksesor elemen pertama yang
              lama */
void DelFirst (List *L, address *P){
/*Kamus lokal*/

/*Algoritma*/
    (*P) = First(*L);
    First(*L) = next(First(*L));
}

/* Procedure DelLast(input/output L: List, input P: address*/
/* Menghapus elemen terakhir list*/
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen terakhir list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              Last element baru adalah predesesor elemen pertama yang
              lama, jika ada */
void DelLast (List *L, address *P){
/*Kamus lokal*/
    address Last, PrecLast;

/*Algoritma*/
    Last = First(*L);
    PrecLast = Nil;
    while (next(Last)!= Nil){
        PrecLast = Last;
        Last = next(Last);
    }
    (*P) = Last;
    if(PrecLast==Nil){
        First(*L) = Nil;
    }
    else{
        next(PrecLast) = Nil;
    }
}

/* Procedure DelAfter(input/output L: List, input Pdel: address, input Prec: address*/
/* Penghapusan suksesor sebuah elemen*/
/* I.S.     : List tidak kosong. Prec adalah anggota list L.
   F.S.     : Menghapus Next(Prec) :
              Pdel adalah alamat elemen list yang dihapus*/
void DelAfter (List *L, address *Pdel, address Prec){
/*Kamus lokal*/

/*Algoritma*/
    (*Pdel) = next(Prec);
    next(Prec) = next(next(Prec));
    next(*Pdel) = Nil;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
/*procedure InsVFirst (input/output L : List, input X : InfoType)*/
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVFirst (List *L, infotype X){
/*Kamus lokal*/
    address P;
/*Algoritma*/
    P = Alokasi(X);
    if(P!=Nil){
        next(P) = First(*L);
        First(*L) = P;
    }
}

/*procedure InsVLast (input/output L : List, input X : InfoType)*/
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void InsVLast (List *L, infotype X){
/*Kamus lokal*/
    address P;
/*Algoritma*/
    P = Alokasi(X);
    if(P!=Nil){
        InsertLast(&L,P);
    }
}

/*procedure InsVAfter (input/output L : List, input X : InfoType)*/
/* I.S. 	: L mungkin kosong
   F.S.		: X ditambahkan sebagai elemen setelah Prec
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
   			  setelah Prec yaitu
   			  jika alokasi berhasil, elemen setelah Prec yang baru bernilai X
   			  Jika alokasi gagal, maka I.S.= F.S. */
void InsVAfter (List *L, infotype X){ /*Pak Aris bilang bahwa Prec yang dimaksud di sini adalah Prec dari Last (Sebelum elemen terakhir) */
/*Kamus lokal*/
    address P, Prec, last;
/*Algoritma*/
    if(!ListEmpty(*L)){
        AdrLast(&(*L), &Prec, &last);
        P = Alokasi(X);
        if(P!=Nil){
            InsertAfter(&L,P,Prec);
        }
    }
    else{
        InsVFirst(&L,X);
    }
}

void InsVAfter2 (List *L, infotype X, infotype Y){
/*Kamus lokal*/
    address P, prec;
/*Algoritma*/
    if(!ListEmpty(*L)){
        prec=Search((*L),Y);
        P = Alokasi(X);
        if(P!=Nil){
            InsertAfter(&L,P,prec);
        }
    }
    else{
        InsVFirst(&L,X);
    }
}

/*procedure AdrLast (input/output L : List, input Prec : address, input Last : address)*/
/*mencari alamat elemen terakhir dan sebelumnya*/
void AdrLast(List *L, address *Prec, address *Last){
/*Kamus lokal*/

/*Algoritma*/
    (*Last) = First(*L);
    (*Prec) = Nil;
    while (next(*Last)!=Nil){
        (*Prec) = (*Last);
        (*Last) = next(*Last);
    }
}


/*** PENGHAPUSAN ELEMEN ***/
/*procedure DelVFirst(input/output L : List, input X : InfoType)*/
/* I.S. List L tidak kosong */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/* dan alamat elemen pertama di-dealokasi */
void DelVFirst (List *L, infotype *X){
/*Kamus lokal*/
    address P;
/*Algoritma*/
    P = First(*L);
    (*X) = info(P);
    DelFirst(L,P);
    Dealokasi(P);
}

/*procedure DelVLast (input/output L : List, input X : InfoType)*/
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/* dan alamat elemen terakhir di-dealokasi */
void DelVLast (List *L, infotype *X){
/*Kamus lokal*/
    address PrecLast, Last, P;

/*Algoritma*/
    Last = First(*L);
    PrecLast = Nil;
    while (next(Last)!= Nil){
        PrecLast = Last;
        Last = next(Last);
    }
    P = Last;
    (*X) = info(P);
    DelLast(L,P);
    Dealokasi(P);
}

/*procedure DelVLast (input/output L : List, input X : InfoType)*/
/* I.S.		: List L tidak kosong
   F.S.		: Elemen list setelah Prec dihapus : nilai info disimpan pada X
   			  dan alamat elemen setelah Prec di-dealokasi */
void DelVAfter (List *L, infotype *X){/*Asumsi: Prec yang dimaksud di sini sama dengan Prec di InsVAfter (Prec dari Last)*/
/*Kamus lokal*/
    address P, Prec, last;
/*Algoritma*/
    if(!ListEmpty(*L)){
        AdrLast(&(*L), &Prec, &last);
        P = Alokasi(X);
        if(P!=Nil){
            DelAfter(&L,P,Prec);
        }
        Dealokasi(&last);
    }
}

void DelVAfter2 (List *L, infotype *X, infotype Y){
/*Kamus lokal*/
    address P, prec;
/*Algoritma*/
    if(!ListEmpty(*L)){
        prec=Search(*L,Y);
        P = Alokasi(X);
        if(P!=Nil){
            DelAfter(&L,P,prec);
        }
        Dealokasi(P);
    }
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
/*Procedure Printinfo(input L: List)*/
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */
void PrintInfo (List L){
/*Kamus lokal*/
    address P;
/*Algoritma*/
    if(ListEmpty(L)){
        printf("list kosong");
    }
    else{
        P = First(L);
        while (P != Nil){
            printf("%d ",info(P));
            P = next(P);
        }
    }
}

/*Function NbElmt (L: List) --> integer*/
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
int NbElmt (List L){
/*Kamus lokal*/
    int count;
    address P;
/*Algoritma*/
    count = 0;
    if(!ListEmpty(L)){
        P = First(L);
        while (P != Nil){
            count=count+1;
            P = next(P);
        }
    }
    return count;
}


/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
/*Function Search(L: List, X: Infotype)-> boolean*/
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
address Search (List L, infotype X){
/*Kamus lokal*/
    address P;
/*Algoritma*/
    P = First(L);
    if(P!=Nil){
        while (info(P)!=X){
            P = next(P);
        }
        return P;
    }
    else{
        return Nil;
    }

}

/*Function FSearch(L: List, P: address) -> boolean*/
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
boolean FSearch (List L, address P){
/*Kamus lokal*/
    address cek;
/*Algoritma*/
    if(!ListEmpty(L)){
        cek = First(L);
        while(cek != P){
            cek = next(cek);
        }
        if(cek == Nil){
            return false; /*Sudah sampai last, address P tidak ketemu*/
        }
        else{
            return true;
        }
    }
}

/*Procedure SearchPrec(input L: List, input X: infotype, output Prec: address)*/
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P */
/* dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain*/
address SearchPrec (List L, infotype X, address *Prec){
/*Kamus lokal*/
    address P;
/*Algoritma*/
    P = First(L);
    (*Prec) = Nil;
    if(P!=Nil){
        while (info(P)!=X){
            (*Prec) = P;
            P = next(P);
        }
    }
    printf("%d", (*Prec));
}


