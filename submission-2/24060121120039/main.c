/* Program   : listLinear.c */
/* Deskripsi : rdriver file modul ADT Linked List Linear */
/* NIM/Nama  : 24060121120039/ Nida' Naafilatul Haniifah*/
/* Tanggal   : 29 Oktober 2022*/
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listLinear.h"

int main()
{
    /*Kamus Lokal*/
    List L1, L2;
    address P1, P2, P3, P4, P5, P6;
    address F1, F2, F3, Prec1, Prec2, Last1;
    infotype T1;

    /*Algoritma*/
    printf("========List Linear=======\n");
    //Membuat List
    CreateList(&L1);
    CreateList(&L2);

    //Memeriksa apakah list kosong
    printf("Apakah list L1 kosong? %s\n", ListEmpty(L1)? "true":"false");

    //Melakukan alokasi dan memasukkan nilai kedalam list
    P1 = Alokasi(4);
    P2 = Alokasi(9);
    P3 = Alokasi(18);
    P4 = Alokasi(7);
    P5 = Alokasi(10);

    //Element List L1 sebelum diisi
    printf("\n==========SEBELUM DIISII==========\n");
    printf("Elemen pada list L1:\n");
    Printinfo(L1);


    /*Membuat List*/
    printf("\n\n==========SETELAH DIISII==========\n");
    printf("Elemen pada list L1:\n");
    InsertFirst(&L1, P1);
    Printinfo(L1);

    printf("\nElemen pada list L1:\n");
    InsertLast(&L1, P2);
    Printinfo(L1);

    printf("\nElemen pada list L1:\n");
    InsertLast(&L1, P3);
    Printinfo(L1);

    printf("\nElemen pada list L1:\n");
    InsertAfter(&L1, P4, P2);
    Printinfo(L1);

    printf("\nElemen pada list L1:\n");
    InsertFirst(&L1, P5);
    Printinfo(L1);
    printf("\n\nBanyak Element L1 adalah %d\n", NbElmt(L1));

    /*Menerapkan Searching*/
    printf("\n==========APLIKASI SEARCHING===========\n");
    F1 = Search(L1, 7);
    printf("Element 7 ditemukan pada L1 dengan alamat %d\n", F1);

    printf("\nApakah element %d(P4) berada pada L1? %s\n", info(P4),FSearch(L1, P4)? "true":"false");

    SearchPrec(L1, 18, &F1);
    printf("\nAlamat Sebelum Element 18 berada pada alamat %d\n", F1);


    /*Menghapus Salah satu Element di List1*/
    printf("\n======MENGHAPUS ELEMENT DI L1======\n");
    DelFirst(&L1, &P6);
    printf("Alamat Element Pertama yang dihapus adalah %d\n", P6);
    printf("Elemen pada list L1:\n");
    Printinfo(L1);

    DelLast(&L1, &P6);
    printf("\n\nAlamat Element Terakhir yang dihapus adalah %d\n", P6);
    printf("Elemen pada list L1:\n");
    Printinfo(L1);

    DelAfter(&L1, &P6, P2);
    printf("\n\nAlamat Element setelah element P4 yang dihapus adalah %d\n", P6);
    printf("Elemen pada list L1:\n");
    Printinfo(L1);

    DelP(&L1, 4);
    printf("\n\nElemen pada list L1:\n");
    Printinfo(L1);

    DelP(&L1, 4);
    printf("\n\nElemen pada list L1:\n");
    Printinfo(L1);


    printf("\n\n======ALAMAT LAST DAN PREC DI L1======");
    AdrLast(&L1, &Prec1, &Last1);
    printf("\nAlamat Element Sebelum Last adalah %d\n", Prec1);
    printf("Alamat Element Last adalah %d\n", Last1);


    printf("\n=========APLIKASI PRIMITIF BERDASARKAN NILAI : PENAMBAHAN ============\n");
    InsVFirst(&L2, 8);
    printf("Elemen pada list L2:\n");
    Printinfo(L2);

    InsVLast(&L2, 18);
    printf("\nElemen pada list L2:\n");
    Printinfo(L2);

    InsVAfter1(&L2, First(L2), P1);
    printf("\nElemen pada list L2:\n");
    Printinfo(L2);

    InsVAfter2(&L2, 18, 90);
    printf("\nElemen pada list L2:\n");
    Printinfo(L2);

    printf("\n\n=========APLIKASI PRIMITIF BERDASARKAN NILAI : PENGHAPUSAN ============\n");
    DelFirst(&L2, &P6);
    printf("Alamat Element Pertama yang dihapus adalah %d\n", P6);
    printf("Elemen pada list L2:\n");
    Printinfo(L2);

    DelLast(&L2, &P6);
    printf("\n\nAlamat Element Terakhir yang dihapus adalah %d\n", P6);
    printf("Elemen pada list L2:\n");
    Printinfo(L2);

    DelVAfter1(&L2, &T1, 4);
    printf("\n\nElement yang dihapus adalah %d\n", T1);
    printf("Elemen pada list L2:\n");
    Printinfo(L2);


    DelVAfter2(&L2, &P6, P1);
    printf("\n\nAlamat Element yang dihapus adalah %d\n", P6);
    printf("Elemen pada list L2:\n");
    Printinfo(L2);





//    printf("Apakah list L1 kosong? %s\n", ListEmpty(L1)? "true":"false");
//    printf("Address dari info(P) = 9 adalah %d\n", Search(L1, 9));
//    printf("Address dari info(P) = 9 adalah %d\n", Search(L2, 9));
    return 0;
}
