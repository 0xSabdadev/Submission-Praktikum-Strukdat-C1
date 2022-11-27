/***********************************************************/
/* Program   : main.c */
/* Deskripsi : driver file modul ADT Double List */
/* NIM/Nama  : 24060121120031/ Yesy Margharetta Munthe*/
/* Tanggal   : 27 - 11- 2022*/
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
    printf("===========nama/nim/judul : Yesy Margharetta Munthe/24060121120031/LIST DOUBLE===========\n");
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
    P1 = Alokasi(10);
    P2 = Alokasi(19);
    P3 = Alokasi(22);
    P4 = Alokasi(5);
    P5 = Alokasi(16);
    P6 = Alokasi(11);
    P7 = Alokasi(80);
    P8 = Alokasi(71);
    P9 = Alokasi(20);
    P10 = Alokasi(18);

    /*Membuat List L1*/
    printf("\n==========LIST L1========\n");
    InsVFirst(&L1,59);
    InsVLast(&L1,29);
    InsVLast(&L1,21);
    InsVLast(&L1,11);
    InsVLast(&L1,90);
    printf("Elemen list L1:\n");
    Printinfo(L1);

    /*Menghapus semua element di L3*/
    printf("\n\n==========(DELALL) ========");
    printf("\nElemen list L1:\n");
    DelAll(&L1);
    Printinfo(L1);

    /*Membuat List Baru L4*/
    printf("\n\n==========LIST L2========\n");
    InsVFirst(&L2,61);
    InsVLast(&L2,65);
    InsVLast(&L2,89);
    InsVLast(&L2,77);
    InsVLast(&L2,3);
    printf("Elemen list L2:\n");
    Printinfo(L2);


    printf("\n\n==========(INVERSTLIST)==========");
    printf("\nHasil Inverst dari list L2:\n");
    InversList(&L2);
    Printinfo(L2);

    printf("\n\n==========(FINVERSTLIST)==========");
    L3 = FInversList(L2);
    printf("\nMengembalikan list L2\n");
    printf("Hasil list L3:\n");
    Printinfo(L3);

    printf("\n\n==========APLIKASI DARI COPYLIST==========");
    printf("\nMengcopy List L3 :\n");
    CopyList(&L3, &L4);
    Printinfo(L4);

    /*Membuat List L5*/
    printf("\n\n==========LIST L5========\n");
    InsVFirst(&L5,89);
    InsVLast(&L5,29);
    InsVLast(&L5,12);
    InsVLast(&L5,15);
    InsVLast(&L5,20);
    printf("Elemen List Baru L5:\n");
    Printinfo(L5);

    printf("\n\n==========(FCOPYLIST)=========");
    printf("\nMengcopy List L5\n");
    L6 = FCopyList(L5);
    printf("Hasil list L6:\n");
    Printinfo(L6);

    printf("\n\n==========(CPALOKLIST==========");
    printf("\nMengcopy List L6\n");
    CpAlokList(L6, &L7);
    printf("Hasil list L7:\n");
    Printinfo(L7);

    printf("\n\n==========LIST L8========\n");
    InsVFirst(&L8,12);
    InsVLast(&L8,36);
    InsVLast(&L8,7);
    InsVLast(&L8,78);
    printf("Elemen pada List Baru L8:\n");
    Printinfo(L8);

    printf("\n\n==========(KONKAT)=========");
    printf("\nMenggabungkan List L7 dengan L8\n");
    Konkat(L7, L8, &L9);
    printf("Hasil list L9:\n");
    Printinfo(L9);

    printf("\n\n==========(KONKAT1)==========");
    printf("\nMenggabungkan List L7 dengan L8");
    Konkat1(&L7, &L8, &L9);
    printf("\nHasil list L9:\n");
    Printinfo(L9);

    printf("\n\n==========(PECAH LIST==========");
    printf("\nList yang akan dipecah :\n");
    Printinfo(L9);
    PecahList(&L10, &L11, L9);

    printf("\n\nHasil dari Pecah List :\n");
    printf("Elemen pada list L11:\n");
    Printinfo(L11);

    printf("\n\nElemen pada list L10:\n");
    Printinfo(L10);

    return 0;
}
