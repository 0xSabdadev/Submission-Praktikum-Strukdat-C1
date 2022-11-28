/***********************************************************/
/* Program   : main.c */
/* Deskripsi : driver file modul ADT Double List */
/* NIM/Nama  : 24060121120023/ Arynda Anna Salsabiela*/
/* Tanggal   : 22 November 2022*/
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
    printf("               LIST DOUBLE           \n");
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

    //Melakukan alokasi dan memasukkan nilai ke dalam list
    P1 = Alokasi(1);
    P2 = Alokasi(4);
    P3 = Alokasi(11);
    P4 = Alokasi(27);
    P5 = Alokasi(20);
    P6 = Alokasi(32);
    P7 = Alokasi(60);
    P8 = Alokasi(52);
    P9 = Alokasi(90);
    P10 = Alokasi(18);

    /*Membuat List L3*/
    printf("\n****************** L3 ******************\n");
    InsVFirst(&L3,3);
    InsVLast(&L3,12);
    InsVLast(&L3,10);
    InsVLast(&L3,24);
    InsVLast(&L3,21);
    printf("Elemen pada list L3 adalah \n");
    Printinfo(L3);

    /*Menghapus semua elemen di L3*/
    printf("\n\n****************** DELLALL ******************");
    printf("\nElemen pada list L3 adalah \n");
    DelAll(&L3);
    Printinfo(L3);

    /*Membuat List Baru L4*/
    printf("\n\n*************** LIST BARU L4 ****************\n");
    InsVFirst(&L4,10);
    InsVLast(&L4,20);
    InsVLast(&L4,11);
    InsVLast(&L4,21);
    InsVLast(&L4,4);
    printf("Elemen pada list L4 adalah \n");
    Printinfo(L4);

    printf("\n\n************ INVERSTLIST **********");
    printf("\nHasil Inverst dari list L4 adalah \n");
    InversList(&L4);
    Printinfo(L4);

    printf("\n\n************ FINVERSTLIST *********");
    L5 = FInversList(L4);
    printf("\nMengembalikan list L4\n");
    printf("Hasil list L5 adalah \n");
    Printinfo(L5);

    printf("\n\n************ COPYLIST ********");
    printf("\nMengcopy List L5 adalah \n");
    CopyList(&L5, &L6);
    Printinfo(L6);

    /*Membuat List L7*/
    printf("\n\n**************** LIST BARU ******************\n");
    InsVFirst(&L7,3);
    InsVLast(&L7,12);
    InsVLast(&L7,10);
    InsVLast(&L7,24);
    InsVLast(&L7,21);
    printf("Elemen pada List Baru L7 adalah \n");
    Printinfo(L7);

    printf("\n\n*********** FCOPYLIST ********");
    printf("\nMengcopy List L7\n");
    L8 = FCopyList(L7);
    printf("Hasil list L8 adalah \n");
    Printinfo(L8);

    printf("\n\n************ CPALOKLIST *******");
    printf("\nMengcopy List L7\n");
    CpAlokList(L7, &L8);
    printf("Hasil list L8 adalah \n");
    Printinfo(L8);

    printf("\n\n****************** LIST BARU ****************\n");
    InsVFirst(&L9,85);
    InsVLast(&L9,15);
    InsVLast(&L9,60);
    InsVLast(&L9,17);
    printf("Elemen pada List Baru L9 adalah \n");
    Printinfo(L9);

    printf("\n\n************ KONKAT **********");
    printf("\nMenggabungkan List L8 dengan L9\n");
    Konkat(L8, L9, &L10);
    printf("Hasil list L10 adalah \n");
    Printinfo(L10);

    printf("\n\n************ KONKAT1 **********");
    printf("\nMenggabungkan List L8 dengan L9");
    Konkat1(&L8, &L9, &L10);
    printf("\nHasil list L10 adalah \n");
    Printinfo(L10);

    printf("\n\n************ PECAHLIST ********");
    printf("\nList yang akan dipecah adalah \n");
    Printinfo(L10);
    PecahList(&L11, &L12, L10);

    printf("\n\nHasil PecahList adalah \n");
    printf("Elemen pada list L11 adalah \n");
    Printinfo(L11);

    printf("\n\nElemen pada list L12 adalah \n");
    Printinfo(L12);
    printf("\n");

    return 0;
}
