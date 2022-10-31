#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    /*Kamus*/
    List L1, L2, L3, L4;
    address P1, P2, P3, P4, P5;
    address F1, F2, F3, Prec1, Prec2;
    infotype T1;

    /*Algoritma*/
    CreateList(&L1);
    CreateList(&L2);
    CreateList(&L3);
    printf("Apakah list kosong? %d\n\n", ListEmpty(L1));
    P1 = Alokasi(3);
    P2 = Alokasi(2);
    P3 = Alokasi(1);
    P4 = Alokasi(4);
    P5 = Alokasi(5);

    printf("Elemen pada list L1: \n");
    Printinfo(L1);

    InsertFirst(&L1, P1);
    printf("\nElemen pada list L1: \n");
    Printinfo(L1);
    InsertFirst(&L1, P4);
    printf("\nElemen pada list L1 :\n");
    Printinfo(L1);
    InsertFirst(&L1, P5);
    printf("\nElemen pada list L1 :\n");
    Printinfo(L1);
    InsertAfter(&L1, P2, P1);
    printf("\nElemen pada list L1: \n");
    Printinfo(L1);
    InsertLast(&L1, P3);

    printf("Elemen pada list L1: \n");
    Printinfo(L1);

    printf("\nAlamat elemen pertama: %d\n", First(L1));
    F1 = Search(L1, 1);
    printf("Alamat elemen terakhir: %d\n", F1);

    // Mencari elemen pada list
    printf("\nMencari elemen pada list dengan fungsi Search: \n");
    F1 = Search(L1, 2);
    printf("Elemen 2, ditemukan pada alamat = %d\n", F1);
    printf("Apakaah addres P1 sama dengan F1? %d\n", P1 == F1);
    AdrLast(&L1, &Prec2, &F3);
    printf("\nMencari elemen pada list dengan fungsi FSearch\n");
    printf("Apakah terdapat alamat %d didalam list? %d\n\n", P2, FSearch(L1, P2));

    printf("Mencari elemen pada list dengan fungsi SeacrhPrec\n");
    printf("Alamat sebelum elemen 2 pada list L1 adalah = %d\n\n", SearchPrec(L1, 2, Prec1));

    // Menghapus elemen pada list
    printf("Menghapus elemen pertama pada list dengan fungsi DelFirst\n");
    DelFirst(&L1, &F1);
    printf("address elemen pertama adalah %d, address elemen yang dihapus adalah %d\n",  P5, F1);
    printf("info pada address P5 = %d, info pada address F1 = %d\n", info(P5));
    info((F1));
    Printinfo(L1);

    printf("\nMenghapus elemen 3 dari list dengan fungsi DelP\n");
    DelP(&L1, 3);
    Printinfo(L1);

    printf("\nMenghapus elemen terakhir dari list dengan fungsi DelLast\n");
    DelLast(&L1, &F1);
    Printinfo(L1);

    printf("\nMenghapus elemen kedua dari list dengan fungsi DelAfter\n");
    DelAfter(&L1, &F1, P4);
    Printinfo(L1);

    // Memasukkan elemen ke dalam list
    printf("\nMemasukkan elemen 15 ke dalam list L2 dengan fungsi InsVFirst\n");
    InsVFirst(&L2, 15);
    Printinfo(L2);

    printf("\nMemasukkan elemen 14 ke dalam list L2 dengan fungsi InsVLast\n");
    InsVLast(&L2, 14);
    Printinfo(L2);

    printf("\nMemasukkan elemen tambahan ke dalam list L2\n");
    InsVFirst(&L2, 16);
    InsVFirst(&L2, 17);
    InsVFirst(&L2, 13);
    Printinfo(L2);

    printf("\Menghapus elemen pertama dari list L2 dengan fungsi DelVFirst\n");
    DelVFirst(&L2, &T1);
    Printinfo(L2);

    printf("\nMenghapus elemen terakhir dari list L2 dengan fungsi DelVLast\n");
    DelVLast(&L2, &T1);
    Printinfo(L2);

    printf("\nMemasukkan elemen 15 ke dalam list L3 dengan fungsi InsVFirst\n");
    InsVFirst(&L3, 15);
    Printinfo(L3);

    // Menambahkan elemen
    printf("\nMenambahkan elemen dengan fungsi InsVAfter1\n");
    P1 = Alokasi(1);
    InsertFirst(&L3, P1);
    InsVAfter1(&L3, P1, Alokasi(12));
    Printinfo(L3);

    printf("\nMenambahkan elemen dengan fungsi InsVAfter2\n");
    InsVAfter2(&L3, 15, 30);
    Printinfo(L3);

    // Menghapus elemen
    printf("\nMenghapus lemen dengan fungsi DelVAfter1\n");
    DelVAfter1(&L3, &T1, 12);
    Printinfo(L3);

    printf("\nMenghapus lemen dengan fungsi DelVAfter2\n");
    DelVAfter2(&L3, &F1, P1);
    Printinfo(L3);

    // Menghitung jumlah elemen
    printf("\nMenghitung jumlah elemen pada L3, dengan fungsi NbElmt\n");
    printf("Jumlah elemen pada L3 adalah %d\n", NbElmt(L3));
}
