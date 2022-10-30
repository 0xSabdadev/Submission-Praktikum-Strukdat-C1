/*********************************************/
/* Program   : list1.c                       */
/* Deskripsi : file c modul list        */
/* NIM/Nama  : 24060121130083/Alfarizi Hidayah */
/* Tanggal   : 29 Oktober 2022 */
/*********************************************/
#include <stdio.h>
#include "list1.h"

int main()
{
    // kamus
    List L1, L2, L3, L4;
    address P1, P2, P3, P4, P5;
    address F1, F2, F3, Prec1, Prec2;
    infotype T1;

    // algo
    CreateList(&L1);
    CreateList(&L2);
    CreateList(&L3);
    CreateList(&L4);

    printf("apakah listnya kosong : %d \n\n", ListEmpty(L1));

    P1 = Alokasi(3);
    P2 = Alokasi(2);
    P3 = Alokasi(1);
    P4 = Alokasi(4);
    P5 = Alokasi(5);

    printf("Elemen pada list L1: \n");
    Printinfo(L1);

    InsertFirst(&L1, P1);
    printf("\nElemen pada list L1 setelah insert first: \n");
    Printinfo(L1);
    InsertFirst(&L1, P4);
    printf("\nElemen pada list L1 setelah insert first: \n");
    Printinfo(L1);
    InsertFirst(&L1, P5);
    printf("\nElemen pada list L1 setelah insert first: \n");
    Printinfo(L1);
    InsertAfter(&L1, P2, P1);
    printf("\nElemen pada list L1 setelah insert After: \n");
    Printinfo(L1);

    InsertLast(&L1, P3);
    printf("\nElemen pada list L1 setelah insert Last: \n");
    Printinfo(L1);

    F1 = Search(L1, 1);
    printf("Alamat elemen terakhir: %d\n", F1);

    F1 = Search(L1, 2);
    printf("Elemen 3, ditemukan pada alamat = %d\n", F1);

    printf("Apakah address P1 sama dengan F1? %d\n", P1 == F1);
    printf("\nMencari elemen pada list dengan fungsi Fsearch\n");
    printf("\nApakah terdapat alamat %d di dalam list? %d\n\n", P2, FSearch(L1,P2));
}
