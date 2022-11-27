/***********************************************************/
/* Program   : main.c */
/* Deskripsi : driver file modul ADT Double List */
/* NIM/Nama  : 24060121120039/ Nida' Naafilatul Haniifah*/
/* Tanggal   : 21 November 2022*/
/***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listDouble.h"


int main()
{
    /*Kamus Lokal*/
    List L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12;
    address P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14;
    address F1, F2 , F3, Prec1, Prec2, Last1;
    infotype T1;
    boolean hasil;

    /*Algoritma*/
    printf("===========LIST DOUBLE===========\n");
    //Membuat List
    CreateList(&L1);
    CreateList(&L2);
    CreateList(&L3);
    CreateList(&L4);
    CreateList(&L5);
    CreateList(&L6);
    CreateList(&L7);
    CreateList(&L8);
    CreateList(&L9);
    CreateList(&L10);
    CreateList(&L11);
    CreateList(&L12);

    //Melakukan alokasi dan memasukkan nilai kedalam list
    P1 = Alokasi(4);
    P2 = Alokasi(9);
    P3 = Alokasi(18);
    P4 = Alokasi(7);
    P5 = Alokasi(10);
    P6 = Alokasi(12);
    P7 = Alokasi(90);
    P8 = Alokasi(62);
    P9 = Alokasi(30);
    P10 = Alokasi(17);

    /*Membuat List L3*/
    printf("\n==========LIST L3========\n");
    InsVFirst(&L3,89);
    InsVLast(&L3,29);
    InsVLast(&L3,12);
    InsVLast(&L3,15);
    InsVLast(&L3,20);
    printf("Elemen pada list L3:\n");
    Printinfo(L3);

    /*Menghapus semua element di L3*/
    printf("\n\n==========APLIKASI DELALL========");
    printf("\nElemen pada list L3:\n");
    DelAll(&L3);
    Printinfo(L3);

    /*Membuat List Baru L4*/
    printf("\n\n==========LIST BARU L4========\n");
    InsVFirst(&L4,20);
    InsVLast(&L4,90);
    InsVLast(&L4,21);
    InsVLast(&L4,11);
    InsVLast(&L4,5);
    printf("Elemen pada list L4:\n");
    Printinfo(L4);


    printf("\n\n==========APLIKASI INVERSTLIST==========");
    printf("\nHasil Inverst dari list L4:\n");
    InversList(&L4);
    Printinfo(L4);

    printf("\n\n==========APLIKASI FINVERSTLIST==========");
    L5 = FInversList(L4);
    printf("\nMengembalikan list L4\n");
    printf("Hasil list L5:\n");
    Printinfo(L5);

    printf("\n\n==========APLIKASI DARI COPYLIST==========");
    printf("\nMengcopy List L5 :\n");
    CopyList(&L5, &L6);
    Printinfo(L6);

    /*Membuat List L7*/
    printf("\n\n==========LIST BARU========\n");
    InsVFirst(&L7,89);
    InsVLast(&L7,29);
    InsVLast(&L7,12);
    InsVLast(&L7,15);
    InsVLast(&L7,20);
    printf("Elemen pada List Baru L7:\n");
    Printinfo(L7);

    printf("\n\n==========APLIKASI DARI FCOPYLIST==========");
    printf("\nMengcopy List L7\n");
    L8 = FCopyList(L7);
    printf("Hasil list L8:\n");
    Printinfo(L8);

    printf("\n\n==========APLIKASI DARI CPALOKLIST==========");
    printf("\nMengcopy List L7\n");
    CpAlokList(L7, &L8);
    printf("Hasil list L8:\n");
    Printinfo(L8);

    printf("\n\n==========LIST BARU========\n");
    InsVFirst(&L9,72);
    InsVLast(&L9,56);
    InsVLast(&L9,1);
    InsVLast(&L9,15);
    printf("Elemen pada List Baru L9:\n");
    Printinfo(L9);

    printf("\n\n==========APLIKASI DARI KONKAT==========");
    printf("\nMenggabungkan List L8 dengan L9\n");
    Konkat(L8, L9, &L10);
    printf("Hasil list L10:\n");
    Printinfo(L10);

    printf("\n\n==========APLIKASI DARI KONKAT1==========");
    printf("\nMenggabungkan List L8 dengan L9");
    Konkat1(&L8, &L9, &L10);
    printf("\nHasil list L10:\n");
    Printinfo(L10);

    printf("\n\n==========APLIKASI DARI PECAH LIST==========");
    printf("\nList yang akan dipecah :\n");
    Printinfo(L10);
    PecahList(&L11, &L12, L10);

    printf("\n\nHasil Pecah List :\n");
    printf("Elemen pada list L11:\n");
    Printinfo(L11);

    printf("\n\nElemen pada list L12:\n");
    Printinfo(L12);

    return 0;
}
