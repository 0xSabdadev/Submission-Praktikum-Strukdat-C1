/***************************************************/
/* Program   : list1.c                             */
/* Deskripsi : file realisasi modul list              */
/* NIM/Nama  : 24060121130063/Givandra Haikal Adjie*/
/* Tanggal   : 24/10/2022
/***************************************************/

#include "boolean.h"
#include "list1.h"
#include "stdlib.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean ListEmpty(List L){
    // Kamus lokal
    
    
    // Algoritma
    return L.First == Nil;
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *L){
    // Kamus lokal
    
    
    // Algoritma
    L->First = Nil;
}
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
/****************** Manajemen Memori ******************/
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
address Alokasi(infotype X){
    // Kamus lokal
    address addr_X;

    
    // Algoritma
    addr_X = (address)malloc( sizeof (address));
    if (addr_X != Nil){
        addr_X->info = X;
        addr_X->next = Nil;
    } else {
        addr_X = Nil;
    }
    return addr_X;
}

/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
void Dealokasi(address *P){
    // Kamus lokal
    
    
    // Algoritma
    free(P);
}


/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
address Search(List L, infotype X){
    // Kamus lokal
    address addr_search;

    // Algoritma
    addr_search = L.First;
    while(addr_search && addr_search->info != X){
        addr_search = addr_search->next;
    }
    return addr_search;    
}

/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
boolean FSearch(List L, address P){
    // Kamus lokal
    address addr_search;

    // Algoritma
    addr_search = L.First;
    while(addr_search && addr_search != P){
        addr_search = addr_search->next;
    }
    return addr_search == P; 
}

/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P */
/* dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain*/

// TODO:problematic
address SearchPrec(List L, infotype X, address *Prec){
    // Kamus lokal
    address addr_search;

    // Algoritma
    addr_search = L.First;
    while(addr_search && addr_search->info != X){
        addr_search = addr_search->next;
    }
    return addr_search;    
}


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVFirst(List *L, infotype X){
    // Kamus lokal
    address p;
    
    // Algoritma
    p = Alokasi(X);
    if (L->First){
        p->next = L->First->next;
    }
    L->First = p;
}

/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void InsVLast(List *L, infotype X){
    // Kamus lokal
    address addr_it;
    
    // Algoritma
    if(L->First == Nil){
        L->First = Alokasi(X);
    } else {
        addr_it = L->First;
        while(addr_it->next){
            addr_it = addr_it->next;
        }
        addr_it->next = Alokasi(X);
    }
    
}
/* procedure InsVAfter2 (input/output L: List, input Prec: infotype, input X: infotype)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen bernilai X setelah elemen bernilai Prec */
/* Jika alokasi gagal: I.S.= F.S. */
void InsVAfter2(List *L, infotype Prec, infotype X){
    // Kamus lokal
    address addr_it;
    address node;
    
    // Algoritma
    addr_it = L->First;
    if(addr_it != Nil){
       
        while(addr_it != Nil && addr_it->info != Prec){
            addr_it = addr_it->next;
        }
        if(addr_it != Nil){
            node = Alokasi(X);
            node->next = addr_it->next;
            addr_it->next = node;
        }
    }
}
/* procedure InsVAfter1 (input/output L: List, input Prec: address, input X: address)*/
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen bernilai X setelah elemen bernilai Prec */
/* Jika alokasi gagal: I.S.= F.S. */
void InsVAfter1(List *L, address Prec, address X){
    // Kamus lokal
    
    
    // Algoritma
    X->next = Prec->next;
    Prec->next = X;
}

/*** PENGHAPUSAN ELEMEN ***/
/* I.S. List L tidak kosong */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/* dan alamat elemen pertama di-dealokasi */
void DelVFirst(List *L, infotype *X){
    // Kamus lokal
    address t_node;
    
    // Algoritma
    *X = L->First->info;
    t_node = L->First->next;
    Dealokasi(&L->First);
    L->First = t_node;
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/* dan alamat elemen terakhir di-dealokasi */
void DelVLast(List *L, infotype *X){
    // Kamus lokal
    address addr_it;
    
    // Algoritma
    if (L->First->next == Nil){
        Dealokasi(&L->First);
        L->First = Nil;
    } else {
        addr_it = L->First;
        while (addr_it->next->next){
            addr_it = addr_it->next;
        }
        *X = addr_it->next->info;
        Dealokasi(&addr_it->next);
        addr_it->next = Nil;
    }

}
/* procedure DelVAfter2 (input/output L: List, input/output X: infotype, input Y: infotype)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir setelah elemen dengan nilai address Y: nilai address disimpan pada X */
/*      dan alamat elemen X tersebut di-dealokasi */
void DelVAfter2(List *L, address *X, address Y){
    // Kamus lokal
    
    
    // Algoritma
    *X = Y->next;
    Y->next = Y->next->next;
}

/* procedure DelVAfter1 (input/output L: List, input/output X: infotype, input Y: infotype)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir setelah elemen dengan nilai info Y: nilai info disimpan pada X */
/*      dan alamat elemen nilsi info Y tersebut di-dealokasi */
void DelVAfter1(List *L, infotype *X, infotype Y){
    // Kamus lokal
    address prec;
    address t_addr;
    
    // Algoritma
    prec = Search(*L, Y);
    if(prec != Nil && prec->next != Nil){
        *X = prec->next->info;
        t_addr = prec->next;
        prec->next = prec->next->next;
        Dealokasi(&t_addr);
    }
}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertFirst(List *L, address P){
    // Kamus lokal
    
    // Algoritma
    P->next = L->First;
    L->First = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertAfter(List *L, address P, address Prec){
    // Kamus lokal
    
    
    // Algoritma
    P->next = Prec->next;
    Prec->next = P;
}
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertLast(List *L, address P){
    // Kamus lokal
    address addr_it;
    
    // Algoritma
    addr_it = L->First;
    if(addr_it == Nil){
        L->First = P;
    }
    while(addr_it){
        if(addr_it->next == Nil){
            addr_it->next = P;
            break;
        }
        addr_it = addr_it->next;
    }
}
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelFirst(List *L, address *P){
    // Kamus lokal
    
    
    // Algoritma
    *P = L->First;
    if (L->First->next != Nil) {
        L->First = L->First->next;
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelP(List *L, infotype X){
    // Kamus lokal
    address addr_it, prec;
    
    // Algoritma
    addr_it = L->First;
    prec = Nil;
    while (addr_it){
        if (addr_it->info == X){
            prec->next = addr_it->next;
            Dealokasi(&addr_it);
            break;
        }
        prec = addr_it;
        addr_it = addr_it->next;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelLast(List *L, address *P){
    // Kamus lokal
    address addr_it;
    
    // Algoritma
    if (L->First == Nil){
        *P = L->First;
        L->First = Nil;
    } else {
        addr_it = L->First;
        if (addr_it->next){
            while (addr_it->next->next){
                addr_it = addr_it->next;
            }
        }
        
        *P = addr_it->next;
        addr_it->next = Nil;
    }
}
/* I.S. List tidak kosong. Prec adalah anggota list */
/* F.S. Menghapus Next(Prec): */
/* Pdel adalah alamat elemen list yang dihapus */
void DelAfter(List *L, address *Pdel, address Prec){
    // Kamus lokal
    
    
    // Algoritma
    *Pdel = Prec->next;
    Prec->next = Prec->next->next;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */
void Printinfo(List L){
    // Kamus lokal
    address addr_it;
    
    // Algoritma
    if(ListEmpty(L)){
        printf("list kosong\n");
    } else {
        addr_it = L.First;
        printf("[ ");
        while(addr_it != Nil){
            printf("%c ", addr_it->info);
            addr_it = addr_it->next;
        }
        printf("]\n");
    }
}
/* Mengirimkan banyaknya elemen list;
mengirimkan 0 jika list kosong */
/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
int NbElmt(List L){
    // Kamus lokal
    int c;
    address addr_it;
    
    // Algoritma
    addr_it = L.First;
    c = 0;
    while(addr_it != Nil){
        c++;
        addr_it = addr_it->next;
    }
    return c;
}
