/*********************************************/
/* Program   : mainlist1.c                       */
/* Deskripsi : */
/* NIM/Nama  : 24060121120025/Annisa Kumala Dewi */


#include <stdio.h>
#include "list1.h"

int main()
{
    // kamus lokal
    List L1, L2, L3, L4;
    address P1, P2, P3, P4, P5;
    address F1, F2, F3, Prec1, Prec2;
    infotype T1;

    // algoritma
    CreateList(&L1);
    CreateList(&L2);
    CreateList(&L3);
    CreateList(&L4);

    printf("Is ListEmpty : %d \n\n", ListEmpty(L1));
    printf("________________________________________________\n");

    P1 = Alokasi(2);
    P2 = Alokasi(1);
    P3 = Alokasi(3);
    P4 = Alokasi(9);
    P5 = Alokasi(4);

    printf("Elemen pada list L1: \n");
    Printinfo(L1);
    printf("________________________________________________\n");

    InsertFirst(&L1, P1);
    printf("Elemen pada list L1 setelah insert first: \n");
    Printinfo(L1);
    printf("________________________________________________\n");

    InsertFirst(&L1, P4);
    printf("Elemen pada list L1 setelah insert first: \n");
    Printinfo(L1);
    printf("________________________________________________\n");

    InsertFirst(&L1, P5);
    printf("Elemen pada list L1 setelah insert first: \n");
    Printinfo(L1);
    printf("________________________________________________\n");

    InsertAfter(&L1, P2, P1);
    printf("Elemen pada list L1 setelah insert After: \n");
    Printinfo(L1);
    printf("________________________________________________\n");

    InsertLast(&L1, P3);
    printf("Elemen pada list L1 setelah insert Last: \n");
    Printinfo(L1);
    printf("________________________________________________\n");

    F1 = Search(L1, 5);
    printf("Alamat elemen terakhir: %d\n", F1);
    printf("________________________________________________\n");

    F1 = Search(L1, 3);
    printf("Elemen 3, ditemukan pada alamat = %d\n", F1);
    printf("________________________________________________\n");

    printf("Apakah address P1 sama dengan F1? %d\n", P1 == F1);
    printf("________________________________________________\n");

    printf("Mencari elemen pada list dengan fungsi Fsearch\n");
    printf("________________________________________________\n");

    printf("Apakah terdapat alamat %d di dalam list? %d\n\n", P2, FSearch(L1,P2));
}
