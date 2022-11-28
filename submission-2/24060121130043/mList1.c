/****************************************************/
/* Program   : mList1.H                              */
/* Deskripsi : file Main modul list               */
/* NIM/Nama  : 24060121130043/Zahid Muhammad Mahfudz*/
/* Tanggal   : 25 Oktober 2022                      */
/*************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "List1.c"

int main(void){
    /*Kamus Lokal*/
    List L1, L2, L3, L4;
    address P1, P2, P3, P4, P5;
    address F1, F2, F3, Prec1, Prec2;
    infotype T1;

    /*Algoritma*/

    /*Membuat List*/
    CreateList(&L1);
    CreateList(&L2);
    CreateList(&L3);

    /*Memeriksa apakah list kosong*/
    printf("Apakah List L1 Kosong : %d\n", ListEmpty(L1));
    printf("Apakah List L2 Kosong : %d\n", ListEmpty(L2));
    printf("Apakah List L3 Kosong : %d\n", ListEmpty(L3));
    printf("\n");

    /*Melakukan alokasi dan memasukan nilainya kedalam List */
    P1 = Alokasi(3);
    P2 = Alokasi(2);
    P3 = Alokasi(1);
    P4 = Alokasi(4);
    P5 = Alokasi(5);

    printf("Elemen pada List L1 adalah : ");
    Printinfo(L1);
    printf("Elemen pada List L2 adalah : ");
    Printinfo(L2);
    printf("Elemen pada List L3 adalah : ");
    Printinfo(L3);
    printf("\n");

    InsertFirst(&L1, P1);
    printf("Elemen pada List L1 adalah : ");
    Printinfo(L1);
    InsertFirst(&L1, P4);
    printf("Elemen pada List L1 adalah : ");
    Printinfo(L1);
    InsertFirst(&L1, P5);
    printf("Elemen pada List L1 adalah : ");
    Printinfo(L1);
    InsertAfter(&L1, P2, P1);
    printf("Elemen pada List L1 adalah : ");
    Printinfo(L1);
    InsertLast(&L1, P3);
    printf("Elemen pada List L1 adalah : ");
    Printinfo(L1);
    printf("\n");

    /*Print alamat*/
    printf("Alamat elemen pertama L1 adalah : %d\n", First(L1));
    F1 = Search(L1, 1);
    printf("Alamat elemen terakhir L1 adalah : %d\n", F1);
    printf("\n");

    /*mencari elemen pada list*/
    printf("Mencari elemen dengan fungsi search\n");
    F1 = Search(L1,2);
    printf("Elemen 3 ditemukan pada alamat : %d\n", F1);
    printf("Apakah address P1 sama dengan f1 : %d\n", P1 == F1);
    AdrLast(&L1, &Prec2, &F3);
    printf("\n");
    printf("mencari elemen list dengan fungsi FSearch\n");
    printf("Apakah terdapat elemen %d didalam list : \n", P2, FSearch(L1,P2));
    printf("\n");
    printf("Mencari elemen pada list dengan fungsi SearchPrec\n");
    printf("Alamat sebelum elemen 2 pada List L1 adalah : %d\n", SearchPrec(L1, 2, &Prec1));
    printf("\n");

    /*menghapus elemen pada list*/
    printf("Menghapus elemen pertama dengan fungsi DelFirst\n");
    DelFirst(&L1, &F1);
    printf("address elemen pertama adalah %d, address elemen yang dihapus adalah %d\n", P5, F1);
    printf("info pada address P5 = %d, info pada F1 = %d\n", info(P5), info(F1));

    printf("Menghapus elemen 3 dari list dengan fungsi DelP : ");
    DelP(&L1, 3);
    Printinfo(L1);
    
    printf("Menghapus elemen terakhir dari list dengan fungsi DelLast : ");
    DelLast(&L1, &F1);
    Printinfo(L1);
   
    printf("menghapus elemen kedua dari list dengan fungsi DelAfter : ");
    DelAfter(&L1, &F1, P4);
    Printinfo(L1);
    printf("\n");

    /*Memasukan elemen kedalam List*/
    printf("Memasukan elemen 15 kedalam List L2 dengan fungsi InsVFirst : ");
    InsVFirst(&L2, 15);
    Printinfo(L2);

    printf("Memasukan elemen 14 kedalam List L2 dengan fungsi InsVLast : ");
    InsVLast(&L2, 14);
    Printinfo(L2);

    printf("Memasukan elemen tambahan kedalam List L2 : ");
    InsVFirst(&L2, 16);
    InsVFirst(&L2, 17);
    InsVLast(&L2, 13);
    Printinfo(L2);
    printf("\n");

    printf("Menghapus Elemen pertama dari List L2 dengan fungsi DelVFirst : ");
    DelVFirst(&L2, &T1);
    Printinfo(L2);
    
    printf("Menghapus elemen terakhir dari List L2 dengan fungsi DelVLast : ");
    DelVLast(&L2, &T1);
    Printinfo(L2);
    printf("\n");

    printf("memasukan elemen 15 kedalam List L3 dengan fungsi insVFirst : ");
    InsVFirst(&L3, 15);
    Printinfo(L3);

    /*menambahkan elemen*/
    printf("menambahkan elemen 12 dengan alokasi P1 kedalam List L3 dengan fungsi InsVafter1 : ");
    P1 = Alokasi(1);
    InsertFirst(&L3, P1);
    InsVAfter1(&L3, P1, Alokasi(12));
    Printinfo(L3);
    printf("menambahkan elemen dengan fungsi InsVAfter2 : ");
    InsVAfter2(&L3, 15, 30);
    Printinfo(L3);
    printf("\n");

    /*menghapus Elemen*/
    printf("menghapus elemen dengan fungsi delVAfter1 : ");
    DelVAfter1(&L3, &T1, 12);
    Printinfo(L3);

    printf("menghapus elemen dengan fungsi DelVAfter2 : ");
    DelVAfter2(&L3, &F1, P1);
    Printinfo(L3);
    printf("\n");

    /*menghitung jumlah elemen*/
    printf("menghitung jumlah elemen pada List L3 dengan fungsi nbElmt\n");
    printf("Jumlah elemen pada List L3 adalah : %d\n", NbElmt(L3));
    return 0;
}