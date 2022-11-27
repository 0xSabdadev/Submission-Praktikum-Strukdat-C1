#ifndef lisdouble_C
#define listdouble_C

/* Program   : listganda.c */
/* Deskripsi : realisasi body modul list ganda tanpa last*/
/* NIM/Nama  : 24060121140104/Divia Shinta Sukarsaatmadja*/
/* Tanggal   : 23 November 2022*/
/************************************************************/

#include <stdio.h>
#include "listganda.h"


/*Prototype*/
/* ----- Test List Kosong ----- */
/* Mengirim true jika list kosong */
boolean ListEmpty (List L){
    //Kamus Lokal

    //Algoritma
    return First(L) == Nil;
}

/* ----- Pembuatan List Kosong ----- */
/* I.S.		: sembarang
   F.S.		: Terbentuk list kosong */
void CreateList (List *L){
    //Kamus Lokal

    //Algoritma
    First(*L) = Nil;
}

/* ----- Manajemen Memori ----- */
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil,
   dan misalnya menghasilkan P, maka
   Info(P) = X, Next(P) = Nil
   Jika alokasi gagal, mengirimkan Nil */
address Alokasi (infotype X){
    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    P = (address)malloc(sizeof(ElmtList));
    if(P!=Nil){
        info(P)=X;
        next(P)=Nil;
    }
    return P;
}

/* procedure DeAlokasi (input P : address)
   { I.S. P pernah dialokasi. F.S. P=Nil }
   { F.S. Mengembalikan address yang pernah dialokasi. P=Nil } */
void DeAlokasi(address P){
    /*Kamus Lokal*/

    /*Algoritma*/
    free(P);
}

/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
/* I.S. 	: Sembarang, P sudah dialokasi
   F.S.		: Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertFirst (List *L, address P){
    //Kamus Lokal

    //Algoritma
    if (ListEmpty(*L)){
        First(*L) = P;
    } else {
        next(P) = First(*L);
        prev(First(*L)) = P;
        First(*L) = P;
    }
}

/* I.S.		: Prec pastilah elemen list dan bukan elemen terakhir,
			  P sudah dialokasi
   F.S. 	: Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertAfter (List *L, address P, address Prec){
    //Kamus Lokal

    //Algoritma
    next(P) = next(Prec);
    prev(next(Prec)) = P;
    next(Prec) = P;
    prev(P) = Prec;
}

/* I.S.		: Sembarang, P sudah dialokasi
   F.S.		: P ditambahkan sebagai elemen terakhir yang baru */
void InsertLast (List *L, address P){
    //Kamus Lokal
    address Prec, Last;

    //Algoritma
    if (ListEmpty(*L)){
        First(*L) = P;
    } else {
        AdrLast(L, &Prec, &Last);
        next(Last) = P;
        prev(P) = Last;
    }
}

/* Penghapusan Sebuah Elemen */
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen pertama list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              First element yang baru adalah suksesor elemen pertama yang
              lama */
void DelFirst (List *L, address *P){
    //Kamus Lokal

    //Algortima
    if (NbElmt(*L) == 1){
        First(*L) = Nil;
    } else {
        *P = First(*L);
        First(*L) = next(*P);
        next(*P) = Nil;
        prev(First(*L)) = Nil;
    }
}

/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen terakhir list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              Last element baru adalah predesesor elemen pertama yang
              lama, jika ada */
void DelLast (List *L, address *P){
    //Kamus Lokal
    address Prec, Last;

    //Algoritma
    if (NbElmt(*L) == 1){
        *P = First(*L);
        First(*L) = Nil;
    } else {
        AdrLast(L, &Prec, &Last);
        *P = Last;
        next(Prec) = Nil;
        prev(*P) = Nil;
    }
}

/* I.S.     : List tidak kosong. Prec adalah anggota list L.
   F.S.     : Menghapus Next(Prec) :
              Pdel adalah alamat elemen list yang dihapus*/
void DelAfter (List *L, address *Pdel, address Prec){
    //Kamus Lokal

    //Algoritma
    next(Prec) = next(next(Prec));
    prev(next(Prec)) = Prec;
    prev(*Pdel) = Nil;
    next(*Pdel) = Nil;
}

/* ----- Proses Semua Elemen List ----- */
/* I.S.     : List mungkin kosong
   F.S.     : Jika list tidak kosong, semua info yg disimpan pada elemen
              list diprint
              Jika list kosong, hanya menuliskan "list kosong" */
void PrintInfo (List L){
    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    if(ListEmpty(L)){
        printf("list kosong");
    } else {
        P = First(L);
        do{
            printf("%d ",info(P));
            P = next(P);
        }while (P!=Nil);
    }
}

/* procedure InsVFirst (input/output L : List, input X : infoType)
   { I.S. List L mungkin kosong}
   { F.S. sebuah elemen dialokasi dan menjadi elemen pertama list L, jika alokasi berhasil. Jika alokasi gagal list tetap seperti semula}
   { insert sebuah elemen sbg. elemen pertama list linier L yang mungkin kosong} */
void InsVFirst(List *L, infotype X){
    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    P = Alokasi(X);
    if (P != Nil) {
        InsertFirst(L, P);
    }
}

/* procedure InsVLast (input/output L : List, input X : infoType)
   { I.S. List L mungkin kosong}
   { F.S. X ditambahkan sebagai elemen terakhir L }
   { Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir yaitu jika alokasi berhasil, 
     elemen terakhir yang baru bernilai X, jika alokasi gagal maka I.S. = F.S.} */
void InsVLast(List *L, infotype X){
    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    P = Alokasi(X);
    if (P != Nil) {
        InsertLast(L,P);
    }
}

/* procedure InsVAfter (input/output L : List, input Prec : address,  input X : infoType)
   { I.S. List L mungkin kosong}
   { F.S. X ditambahkan sebagai elemen setelah Prec}
   { Melakukan alokasi sebuah elemen dan menambahkan elemen list setelah Prec yaitu jika alokasi berhasil,
      elemen setelah Prec yang baru bernilai X, Jika alokasi gagal, maka I.S. = F.S.} */
void InsVAfter(List *L, infotype Prec, infotype X){
    /*Kamus Lokal*/
    address P, Q;

    /*Algoritma*/
    P = Alokasi(X);
    Q = First((*L));
    if(ListEmpty((*L))){
        InsVFirst(&(*L),X);
    }else{
        while(info(Q)!=Prec){
            Q = next(Q);
        }
        next(P) = next(Q);
        next(Q) = P;
    }
}

/* procedure DelVFirst (input/output L : List, output X : infotype)
   { I.S. List L tidak kososng, minimal 1 elemen, elemen pertama pasti ada }
   { F.S. Menghapus elemen pertama L }
   { info disimpan pada X dan alamat elemen pertama di-dealokasi } */
void DelVFirst(List *L, infotype *X){
    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    P = First(*L);
    *X = info(P);
    DelFirst(L, &P);
    DeAlokasi(P);
}

/* procedure DelVLast (input/output L : List, output X : infotype)
   { I.S. List L tidak kososng, minimal 1 elemen, elemen pertama pasti ada }
   { F.S. elemen list Last dihapus}
   { info disimpan pada X dan alamat elemen Last di-dealokasi } */
void DelVLast(List *L, infotype *X){
    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    P = First(*L);
    *X = info(P);
    DelLast(L, &P);
    DeAlokasi(P);
}

/* procedure DelVAfter (input/output L : List, address Prec, output X : infotype)
   { I.S. List L tidak kososng, minimal 1 elemen, elemen pertama pasti ada }
   { F.S. elemen list setelah Prec dihapus}
   { info disimpan pada X dan alamat elemen Prec di-dealokasi } */
void DelVAfter(List *L, infotype *X, infotype Y){
    /*Kamus Lokal*/
    address P, Q;

    /*Algoritma*/
    P = First(*L);
    Q;
    if(info(First(*L))==Y){
        Q = next(P);
        (*X) = info(P);
        
    }else{
        while(info(P)!=Y){
            P = next(P);
        }
        Q = next(P);
        (*X) = info(next(P));
    }
    next(P) = next(Q);
    next(Q) = Nil;
    //prev(next(Q)) = P;
    DeAlokasi(Q);
}

/* procedure AdrLast (input/output L : List, output Prec, Last : address)
   { I.S. List tidak kosong, minimal 2 emlemen}
   { F.S. - }
   { Menghasilkan info dari elemen terakhir yang akan disimpan di Last, dan menghasilkan info
     elemen sebelum elemen terakhir yang akan disimpan di Prec} */
void AdrLast(List *L, address *Prec, address *Last){
    /*Kamus Lokal*/

    /*Algoritma*/
    *Last = First(*L);
    *Prec = Nil;
    while (next(*Last) != Nil){
        *Prec = *Last;
        *Last = next(*Last);
    }
}

/* function NbElmt (L : List) --> integer
   {Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong }*/
int NbElmt(List L){
    /*Kamus Lokal*/
    int banyak;
    address P;

    /*Algoritma*/
    P = First(L);
    banyak = 0;
    while (P != Nil){
        banyak ++;
        P = next(P);
    }
    return banyak;
}

/* function Search (L : List, X : infotype) --> address
   {Mencari apakah ada elemen list dengan info(P) = X
    Jika ada, mengirimkan address elemen tersebut.
    Jika tidak ada, mengirimkan Nil}*/
address Search(List L, infotype X){
    /*Kamus Lokal*/
    address P;
    boolean found;

    /*Algoritma*/
    P = First(L);
    found = false;
    while (P != Nil && !found){
        if (info(P) == X){
            found = true;
        } else {
            P = next(P);
        }
    }

    return P;
}

/* function FSearch (L : List, P ; address) -- boolean
   { mencari apakah ada elemen list yang ebralamat P
     Mengirimkan true jika ada, false jika tidak ada}*/
boolean FSearch(List L, address P){
    /*Kamus Lokal*/
    address A;
    boolean found;

    /*Algoritma*/
    A = First(L);
    found = false;
    while (A != Nil && !found){
        if (A == P){
            found = true;
        } else {
            A = next(A);
        }
    }

    return found;
}

/* function SearchPrec (L : List, X : InfoType) --> address
   { Mengirimkan address elemen sebelum elemen yang nilainya=X }
   { Mencari apakah ada elemen list dengan info(P)= X }
   { Jika ada, mengirimkan address Prec, dengan Next(Prec)=P }
   { dan Info(P)=X. }
   { Jika tidak ada, mengirimkan Nil }
   { Jika P adalah elemen pertama, maka Prec=Nil }
   { Search dengan spesifikasi seperti ini menghindari }
   { traversal ulang jika setelah Search akan dilakukan operasi lain }*/
address SearchPrec(List L, infotype X, address *Prec){
    address P = First(L);
    while(next(P)!=Nil){
        if(info(next(P))==X){
            return P;
        }else{
            P = next(P);
        }
    }
    return Nil;
}

/* Procedure DelAll (input/output: L: List)
   { I.S. sembarang }
   { F.S. Delete semua elemen list dan alamat elemen di-dealokasi }
   {      List L menjadi list kosong} */
void DelAll(List *L){
    /*Kamus Lokal*/
    address P;
    infotype Z;

    /*Algoritma*/
    if (First(*L) != Nil){
        P = First(*L);

        while(P != Nil){
            P = next(P);
            DelVFirst(L, &Z);
        } 
    }
}


/* procedure InversList (input/output L : List)
   { I.S. sembarang. }
   { F.S. elemen list dibalik : }
   { Elemen terakhir menjadi elemen pertama, dan seterusnya. }
   { Membalik elemen list, tanpa melakukan alokasi/dealokasi. } */
void InversList(List *L){
    /*Kamus Lokal*/
    address P, Prec, Curr;

    /*Algoritma*/
    P = First(*L);   //Curr = P;
    Prec = Nil;      //next 

    while (P != Nil){
        Curr = P;
        P = next(P);
        next(Curr) = Prec;
        prev(Curr) = P;
        Prec = Curr;
    }

    First(*L) = Curr;
    prev(First(*L)) = Nil;
}

    /* function FInversList (L : List) --> List
    { Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemn list. Alokasi mungkin gagal.}
    { Jika alokasi gagal, hasilnya list kosong dan semua elemen yang terlanjur di-alokasi, harus didealokasi } */
List FInversList(List L){
    /*Kamus Lokal*/
    List L1;
    address P, Prec, P1;
    boolean gagal;

    /*Algoritma*/
    CreateList(&L1);
    gagal = false;
    P = First(L);

    while((P != Nil) && (!gagal)){
        P1 = Alokasi(info(P));
        if (P != Nil){
            InsertFirst(&L1, P1);
            P = next(P);
        } else {
            DelAll(&L1);
            gagal = true;
        }
    }

    return L1;
}

/* procedure CopyList (input/output L1 : List, input/output L2 : List)
   { I.S. L1 sembarang. }
   { F.S. L2=L1 }
   { L1 dan L2 "menunjuk" kepada list yang sama. }
   { Tidak ada alokasi/dealokasi elemen }*/
void CopyList(List *L1, List *L2){
    /*Kamus Lokal*/

    /*Algoritma*/
    First(*L2) = First(*L1);
}

/* function FCopyList(L : List) --> List
   { Mengirimkan list yang merupakan salinan L dengan melakukan alokasi.}
   { Jika ada alokasi gagal, hasilnya list kosong dan semua elemen yang terlanjur di-alokasi, harus didealokasi}*/
List FCopyList(List L){
    /*Kamus Lokal*/
    List L1;
    address P, P1;
    boolean gagal;

    /*Algoritma*/
    CreateList(&L1);
    gagal = false;
    P = First(L);
    while((P != Nil) && (!gagal)){
        P1 = Alokasi(info(P));
        if (P != Nil){
            InsertLast(&L1, P1);
            P = next(P);
        } else {
            DelAll(&L1);
            gagal = true;
        }
    }

    return L1;
}

/* procedure KonKat(input L1 : List, input L2 : List, output L3 : List)
   { I.S. L1 dan L2 sembarang }
   { F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 }
   { Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi }
   { Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi harus di-dealokasi dan L3=Nil }
   { Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang “baru” }
   { Elemen L3 adalah hasil alokasi elemen yang “baru”. }
   { Jika ada alokasi yang gagal, maka L3 harus bernilai Nil dan semua elemen yang pernah dialokasi didealokasi} */
void Konkat(List L1, List L2, List *L3){
    /*Kamus Lokal*/
    address Last, P;
    boolean gagal;

    /*Algoritma*/
    CreateList(L3);
    gagal = false;

    if (ListEmpty(L1)){ 
        *L3 = FCopyList(L2);
    } else {
        *L3 = FCopyList(L1);

        Last = First(L2);
        while((Last != Nil) && !gagal){
            P = Alokasi(info(Last));
            if (P != Nil) {
                InsertLast(L3, P);
                Last = next(Last);
            } else {
                gagal = true;
                DelAll(L3);
            }
            
        }
    }
}

/* procedure Konkat1(input/output L1 : List, input/output L2 : List, output L3 : List)
   { I.S. L1 dan L2 sembarang }
   { F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 }
   { Konkatenasi dua buah list : L1 dan L2 menghasilkan L3 yang baru (dengan elemen list L1 dan L2 }
   { dan L1 serta L2 menjadi list kosong. }
   { Tidak ada alokasi/dealokasi pada prosedur ini } */
void Konkat1(List *L1, List *L2, List *L3){
    /*Kamus Lokal*/
    address LastL1, PrecL1;
    address LastL2, PrecL2;

    /*Algoritma*/
    CreateList(L3);

    if (ListEmpty(*L1)){
        CopyList(L2, L3);
    } else {
        CopyList(L1, L3);

        AdrLast(L1, &PrecL1, &LastL1);
        AdrLast(L2, &PrecL2, &LastL2);

        next(LastL1) = First(*L2);
        next(LastL2) = Nil;
    }

    CreateList(L1);
    CreateList(L2);
}

/* procedure PecahList(output L1 : List, output L2 : List, input L : List)
   { I.S. L mungkin kosong }
   { F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 }
   { L tidak berubah: untuk membentuk L1 dan L2 harus alokasi }
   { L1 berisi separuh elemen L dan L2 berisi sisa elemen L }
   { Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 }*/
void PecahList(List *L1, List *L2, List L){
    /*Kamus Lokal*/
    int N, i; /*N adalah separuh */
    address P;

    /*Algoritma*/
    CreateList(L1);
    CreateList(L2);

    P = First(L);
    N = NbElmt(L)/2;
    i = 0;

    while (P != Nil){
        i++;
        if (i <= N){
            InsVLast(L1, info(P));
        } else {
            InsVLast(L2, info(P));
        }
        P = next(P);
    }
}




#endif