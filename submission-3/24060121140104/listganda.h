/* Program   : listganda.h */
/* Deskripsi : file modul List Linear */
/* NIM/Nama  : 24060121140104/Divia Shinta Sukarsaatmadja */
/* Tanggal   : 23 November 2022*/
/* contoh ADT list berkait dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#ifndef listGanda_H
#define listGanda_H

#include "boolean.h"

#define Nil          NULL
#define info(P)      (P)->info
#define next(P)      (P)->next
#define prev(P)      (P)->prev
#define First(L)     (L).First

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype   	info;
    address    	next;
    address 	prev;
}ElmtList;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

typedef struct {
    address First;
}List;

/*
ListEmpty(L)
CreateList(L)
InsertFirst(L,P)
InsertAfter(L,P,Prec)
InsertLast(L,P)
DelFirst(L,P)
DelAfter(L,PDel,Prec)
DelLast(L,P)
Alokasi(X)
PrintInfo(L)
*/

/*Prototype*/
/* ----- Test List Kosong ----- */
boolean ListEmpty (List L);
/* Mengirim true jika list kosong */

/* ----- Pembuatan List Kosong ----- */
void CreateList (List *L);
/* I.S.		: sembarang
   F.S.		: Terbentuk list kosong */

/* ----- Manajemen Memori ----- */
address Alokasi (infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil,
   dan misalnya menghasilkan P, maka
   Info(P) = X, Next(P) = Nil
   Jika alokasi gagal, mengirimkan Nil */

void DeAlokasi(address P);
/* procedure DeAlokasi (input P : address)
   { I.S. P pernah dialokasi. F.S. P=Nil }
   { F.S. Mengembalikan address yang pernah dialokasi. P=Nil } */

/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
void InsertFirst (List *L, address P);
/* I.S. 	: Sembarang, P sudah dialokasi
   F.S.		: Menambahkan elemen ber-address P sebagai elemen pertama */

void InsertAfter (List *L, address P, address Prec);
/* I.S.		: Prec pastilah elemen list dan bukan elemen terakhir,
			  P sudah dialokasi
   F.S. 	: Insert P sebagai elemen sesudah elemen beralamat Prec */

void InsertLast (List *L, address P);
/* I.S.		: Sembarang, P sudah dialokasi
   F.S.		: P ditambahkan sebagai elemen terakhir yang baru */

/* Penghapusan Sebuah Elemen */
void DelFirst (List *L, address *P);
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen pertama list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              First element yang baru adalah suksesor elemen pertama yang
              lama */

void DelLast (List *L, address *P);
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen terakhir list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              Last element baru adalah predesesor elemen pertama yang
              lama, jika ada */

void DelAfter (List *L, address * Pdel, address Prec);
/* I.S.     : List tidak kosong. Prec adalah anggota list L.
   F.S.     : Menghapus Next(Prec) :
              Pdel adalah alamat elemen list yang dihapus*/

/* ----- Proses Semua Elemen List ----- */
void PrintInfo (List L);
/* I.S.     : List mungkin kosong
   F.S.     : Jika list tidak kosong, semua info yg disimpan pada elemen
              list diprint
              Jika list kosong, hanya menuliskan "list kosong" */

void InsVFirst(List *L, infotype X);
/* procedure InsVFirst (input/output L : List, input X : infoType)
   { I.S. List L mungkin kosong}
   { F.S. sebuah elemen dialokasi dan menjadi elemen pertama list L, jika alokasi berhasil. Jika alokasi gagal list tetap seperti semula}
   { insert sebuah elemen sbg. elemen pertama list linier L yang mungkin kosong} */

void InsVLast(List *L, infotype X);
/* procedure InsVLast (input/output L : List, input X : infoType)
   { I.S. List L mungkin kosong}
   { F.S. X ditambahkan sebagai elemen terakhir L }
   { Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir yaitu jika alokasi berhasil, 
     elemen terakhir yang baru bernilai X, jika alokasi gagal maka I.S. = F.S.} */

void InsVAfter(List *L, infotype Prec, infotype X);
/* procedure InsVAfter (input/output L : List, input Prec : address,  input X : infoType)
   { I.S. List L mungkin kosong}
   { F.S. X ditambahkan sebagai elemen setelah Prec}
   { Melakukan alokasi sebuah elemen dan menambahkan elemen list setelah Prec yaitu jika alokasi berhasil,
      elemen setelah Prec yang baru bernilai X, Jika alokasi gagal, maka I.S. = F.S.} */

void DelVFirst(List *L, infotype *X);
/* procedure DelVFirst (input/output L : List, output X : infotype)
   { I.S. List L tidak kososng, minimal 1 elemen, elemen pertama pasti ada }
   { F.S. Menghapus elemen pertama L }
   { info disimpan pada X dan alamat elemen pertama di-dealokasi } */

void DelVLast(List *L, infotype *X);
/* procedure DelVLast (input/output L : List, output X : infotype)
   { I.S. List L tidak kososng, minimal 1 elemen, elemen pertama pasti ada }
   { F.S. elemen list Last dihapus}
   { info disimpan pada X dan alamat elemen Last di-dealokasi } */

void DelVAfter(List *L, infotype *X, infotype Y);
/* procedure DelVAfter (input/output L : List, address Prec, output X : infotype)
   { I.S. List L tidak kososng, minimal 1 elemen, elemen pertama pasti ada }
   { F.S. elemen list setelah Prec dihapus}
   { info disimpan pada X dan alamat elemen Prec di-dealokasi } */

void AdrLast(List *L, address *Prec, address *Last);
/* procedure AdrLast (input/output L : List, output Prec, Last : address)
   { I.S. List tidak kosong, minimal 2 emlemen}
   { F.S. - }
   { Menghasilkan info dari elemen terakhir yang akan disimpan di Last, dan menghasilkan info
     elemen sebelum elemen terakhir yang akan disimpan di Prec} */

int NbElmt(List L);
/* function NbElmt (L : List) --> integer
   {Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong }*/

infotype Max(List L);
/* Mengirimkan nilai info(P) yang maksimum */
address AdrMax(List L);
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
infotype Min(List L);
/* Mengirimkan nilai info(P) yang minimum */
address AdrMin(List L);
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
float Average(List L);
/* Mengirimkan nilai rata-rata info(P) */

address Search(List L, infotype X);
/* function Search (L : List, X : infotype) --> address
   {Mencari apakah ada elemen list dengan info(P) = X
    Jika ada, mengirimkan address elemen tersebut.
    Jika tidak ada, mengirimkan Nil}*/

boolean FSearch(List L, address P);
/* function FSearch (L : List, P ; address) -- boolean
   { mencari apakah ada elemen list yang ebralamat P
     Mengirimkan true jika ada, false jika tidak ada}*/

address SearchPrec(List L, infotype X, address *Prec);
/* function SearchPrec (L : List, X : InfoType) --> address
   { Mengirimkan address elemen sebelum elemen yang nilainya=X }
   { Mencari apakah ada elemen list dengan info(P)= X }
   { Jika ada, mengirimkan address Prec, dengan Next(Prec)=P }
   { dan Info(P)=X. }
   { Jika tidak ada, mengirimkan Nil }
   { Jika P adalah elemen pertama, maka Prec=Nil }
   { Search dengan spesifikasi seperti ini menghindari }
   { traversal ulang jika setelah Search akan dilakukan operasi lain }*/

void DelAll(List *L);
/* Delete semua elemen list dan alamat elemen di-dealokasi */

void InversList(List *L);
/* procedure InversList (input/output L : List)
   { I.S. sembarang. }
   { F.S. elemen list dibalik : }
   { Elemen terakhir menjadi elemen pertama, dan seterusnya. }
   { Membalik elemen list, tanpa melakukan alokasi/dealokasi. } */

List FInversList(List L);
/* function FInversList (L : List) --> List
   { Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemn list. Alokasi mungkin gagal.}
   { Jika alokasi gagal, hasilnya list kosong dan semua elemen yang terlanjur di-alokasi, harus didealokasi } */

void CopyList(List *L1, List *L2);
/* procedure CopyList (input/output L1 : List, input/output L2 : List)
   { I.S. L1 sembarang. }
   { F.S. L2=L1 }
   { L1 dan L2 "menunjuk" kepada list yang sama. }
   { Tidak ada alokasi/dealokasi elemen }*/

List FCopyList(List L);
/* function FCopyList(L : List) --> List
   { Mengirimkan list yang merupakan salinan L dengan melakukan alokasi.}
   { Jika ada alokasi gagal, hasilnya list kosong dan semua elemen yang terlanjur di-alokasi, harus didealokasi}*/

void CpAlokList(List Lin, List *Lout);
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur
dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */

void Konkat(List L1, List L2, List *L3);
/* procedure KonKat(input L1 : List, input L2 : List, output L3 : List)
   { I.S. L1 dan L2 sembarang }
   { F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 }
   { Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi }
   { Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi harus di-dealokasi dan L3=Nil }
   { Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang “baru” }
   { Elemen L3 adalah hasil alokasi elemen yang “baru”. }
   { Jika ada alokasi yang gagal, maka L3 harus bernilai Nil dan semua elemen yang pernah dialokasi didealokasi} */

void Konkat1(List *L1, List *L2, List *L3);
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2 */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2)*/
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

void PecahList(List *L1, List *L2, List L);
/* procedure PecahList(output L1 : List, output L2 : List, input L : List)
   { I.S. L mungkin kosong }
   { F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 }
   { L tidak berubah: untuk membentuk L1 dan L2 harus alokasi }
   { L1 berisi separuh elemen L an L2 berisi sisa elemen L }
   { Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 }*/

#endif
