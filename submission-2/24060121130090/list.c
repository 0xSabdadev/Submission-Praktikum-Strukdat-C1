/*********************************************/
/* Program   : list.c                        */
/* Deskripsi : file c modul list             */
/* NIM/Nama  : 24060121130090/Dorino Baharson*/
/* Tanggal   :27/10/2022                     */
/*********************************************/

#include <stdio.h>
#include "list1.h"
#include <stdbool.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
bool ListEmpty(List L){
    /* Mengirim true jika list kosong */

    //Kamus Lokal

    //Algoritma
    if(First(L)==Nil){
        return true;
    }return false;
}


/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *L){
    /* I.S. sembarang */
    /* F.S. Terbentuk list kosong */
    
    //Kamus Lokal

    //Algoritma
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi(infotype X){
    /* Mengirimkan address hasil alokasi sebuah elemen */
    /* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
    /* menghasilkan P, maka info(P)=X, Next(P)=Nil */
    /* Jika alokasi gagal, mengirimkan Nil */

    //Kamus Lokal
    address P;

    //Algoritma
    P = (address) malloc(sizeof(ElmtList));
    if(P!=Nil){
        info(P) = X;
        next(P) = Nil;
        return P;
    }return Nil;
}

void Dealokasi(address *P){
    /* I.S. P terdefinisi */
    /* F.S. P dikembalikan ke sistem */
    /* Melakukan dealokasi/pengembalian address P */

    //Kamus Lokal

    //Algoritma
    free(*P);
}


/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search(List L, infotype X){
    /* Mencari apakah ada elemen list dengan info(P)= X */
    /* Jika ada, mengirimkan address elemen tersebut. */
    /* Jika tidak ada, mengirimkan Nil */

    //Kamus Lokal
    address P;

    //Algoritma
    P = First(L);
    while(P!=Nil){
        if(info(P)==X){
            return P;
        }P = next(P);
    }return Nil;
}

bool FSearch(List L, address P){
    /* Mencari apakah ada elemen list yang beralamat P */
    /* Mengirimkan true jika ada, false jika tidak ada */
    
    //Kamus Lokal
    address Q;

    //Algoritma
    Q = First(L);
    while(Q!=Nil){
        if(Q==P){
            return true;
        }Q = next(Q);
    }return false;
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

    //Kamus Lokal
    address P;

    //Algoritma
    P = First(L);
    while(P!=Nil){
        if(info(P)==X){
            return P;
        }*Prec = P;
        P = next(P);
    }return Nil;
}


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst(List *L, infotype X){
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    
    //Kamus Lokal
    address P;

    //Algoritma
    P = Alokasi(X);
    if(P!=Nil){
        next(P) = First(*L);
        First(*L) = P;
    }
}

void InsVLast(List *L, infotype X){
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen list di akhir: elemen terakhir yang baru */
    /* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    
    //Kamus Lokal
    address P, Q;

    //Algoritma
    P = Alokasi(X);
    if(P!=Nil){
        if(ListEmpty(*L)){
            InsVFirst(L,X);
        }else{
            Q = First(*L);
            while(next(Q)!=Nil){
                Q = next(Q);
            }next(Q) = P;
        }
    }
}

void InsVAfter2(List *L, infotype Prec, infotype X){
    /* procedure InsVAfter2 (input/output L: List, input Prec: infotype, input X: infotype)
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen bernilai X setelah elemen bernilai Prec */
    /* Jika alokasi gagal: I.S.= F.S. */

    //Kamus Lokal
    address P, Q;

    //Algoritma
    P = Alokasi(X);
    if(P!=Nil){
        Q = First(*L);
        while(Q!=Nil){
            if(info(Q)==Prec){
                next(P) = next(Q);
                next(Q) = P;
                break;
            }Q = next(Q);
        }
    }
}

void InsVAfter1(List *L, address Prec, address X){
    /* procedure InsVAfter1 (input/output L: List, input Prec: address, input X: address)
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen bernilai X setelah elemen bernilai Prec */
    /* Jika alokasi gagal: I.S.= F.S. */

    //Kamus Lokal

    //Algoritma
    next(X) = next(Prec);
    next(Prec) = X;
}


/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(List *L, infotype *X){
    /* I.S. List L tidak kosong  */
    /* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
    /*      dan alamat elemen pertama di-dealokasi */

    //Kamus Lokal
    address P;

    //Algoritma
    P = First(*L);
    First(*L) = next(P);
    *X = info(P);
    Dealokasi(&P);
}

void DelVLast(List *L, infotype *X){
    /* I.S. list tidak kosong */
    /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
    /*      dan alamat elemen terakhir di-dealokasi */

    //Kamus Lokal
    address P, Q;

    //Algoritma
    P = First(*L);
    while(next(next(P))!=Nil){
        P = next(P);
    }Q = next(P);
    next(P) = Nil;
    *X = info(Q);
    Dealokasi(&Q);
}

void DelVAfter2(List *L, address *X, address Y){
    /* procedure DelVAfter2 (input/output L: List, output X: address, input Y: address)
    /* I.S. L tidak kosong */
    /* F.S. Elemen setelah Y dihapus: nilai info disimpan pada X */
    /*      dan alamat elemen setelah Y di-dealokasi */

    //Kamus Lokal

    //Algoritma
    *X = next(Y);
    next(Y) = next(*X);
    next(*X) = Nil;
}

void DelVAfter1(List *L, infotype *X, infotype Y){
    /* procedure DelVAfter1 (input/output L: List, output X: infotype, input Y: infotype)
    /* I.S. L tidak kosong */
    /* F.S. Elemen setelah Y dihapus: nilai info disimpan pada X */
    /*      dan alamat elemen setelah Y di-dealokasi */

    //Kamus Lokal
    address P;

    //Algoritma
    P = First(*L);
    while(P!=Nil){
        if(info(P)==Y){
            DelVAfter2(L,X,P);
            break;
        }P = next(P);
    }
}


/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst(List *L, address P){
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. Menambahkan elemen ber-alamat P sebagai elemen pertama */

    //Kamus Lokal

    //Algoritma
    next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter(List *L, address P, address Prec){
    /* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
    /*      P sudah dialokasi  */
    /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

    //Kamus Lokal

    //Algoritma
    next(P) = next(Prec);
    next(Prec) = P;
}

void InsertLast(List *L, address P){
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. P ditambahkan sebagai elemen terakhir yang baru */

    //Kamus Lokal
    address Q;

    //Algoritma
    if(ListEmpty(*L)){
        InsertFirst(L,P);
    }else{
        Q = First(*L);
        while(next(Q)!=Nil){
            Q = next(Q);
        }next(Q) = P;
    }
}

void DelFirst(List *L, address *P){
    /* I.S. List tidak kosong  */
    /* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
    /*      Elemen list berkurang satu (mungkin menjadi kosong) */
    /* First element yg baru adalah suksesor elemen pertama yang lama */

    //Kamus Lokal

    //Algoritma
    *P = First(*L);
    First(*L) = next(*P);
    next(*P) = Nil;
}

void DelP(List *L, infotype X){
    /* I.S. Sembarang */
    /* F.S. Jika ada elemen list ber-alamat P, dengan info(P)=X  */
    /* Maka P dihapus dari list dan di-dealokasi */
    /* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
    /* List mungkin menjadi kosong karena penghapusan */

    //Kamus Lokal
    address P, Q;

    //Algoritma
    P = First(*L);
    if(info(P)==X){
        DelFirst(L,&Q);
    }else{
        while(next(P)!=Nil){
            if(info(next(P))==X){
                Q = next(P);
                next(P) = next(Q);
                next(Q) = Nil;
                Dealokasi(&Q);
                break;
            }P = next(P);
        }
    }
}

void DelLast(List *L, address *P){
    /* I.S. List tidak kosong */
    /* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
    /*      Elemen list berkurang 1 (mungkin menjadi kosong) */
    /* Last element baru adalah predesesor elemen pertama yg lama, */
    /* jika ada */

    //Kamus Lokal
    address Q;

    //Algoritma
    Q = First(*L);
    if(next(Q)==Nil){
        DelFirst(L,P);
    }else{
        while(next(next(Q))!=Nil){
            Q = next(Q);
        }*P = next(Q);
        next(Q) = Nil;
    }
}

void DelAfter(List *L, address *Pdel, address Prec){
    /* I.S. List tidak kosong. Prec adalah anggota list  */
    /* F.S. Menghapus Next(Prec): */
    /*      Pdel adalah alamat elemen list yang dihapus  */

    //Kamus Lokal

    //Algoritma
    *Pdel = next(Prec);
    next(Prec) = next(*Pdel);
    next(*Pdel) = Nil;
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void Printinfo(List L){
    /* I.S. List mungkin kosong */
    /* F.S. Jika list tidak kosong, semua info yang disimpan pada elemen */
    /* list diprint. Jika list kosong, hanya menuliskan "List Kosong" */

    //Kamus Lokal
    address P;

    //Algoritma
    if(ListEmpty(L)){
        printf("List Kosong\n");
    }else{
        P = First(L);
        while(P!=Nil){
            printf("%d ",info(P));
            P = next(P);
        }printf("\n");
    }
}

int NbElmt(List L){
    /* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

    //Kamus Lokal
    address P;
    int count;

    //Algoritma
    count = 0;
    P = First(L);
    while(P!=Nil){
        count++;
        P = next(P);
    }return count;
}