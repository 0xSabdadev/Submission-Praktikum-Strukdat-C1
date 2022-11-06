/*********************************************/
/* Program   : mainlist1.c                       */
/* Deskripsi : */
/* NIM/Nama  : 24060121140167 / Agung Surya Permana */


#include <stdio.h>
#include "list1.h"

int main()
{
    // kamus lokal
    List li1, li2, li3, li4;
    address AD1, AD2, AD3, AD3, AD5;
    address F1, F2, F3, Prec1, Prec2;
    infotype T1;

    // algoritma
    CreateList(&li1);
    CreateList(&li2);
    CreateList(&li3);
    CreateList(&li4);

    printf("Is ListEmpty : %d \n\n", ListEmpty(li1));
    printf("===============================================\n");

    AD1 = Alokasi(2);
    AD2 = Alokasi(1);
    AD3 = Alokasi(3);
    AD3 = Alokasi(9);
    AD5 = Alokasi(4);

    printf("Elemen pada list li1: \n");
    Printinfo(li1);
    printf("===============================================\n");

    InsertFirst(&li1, AD1);
    printf("Elemen pada list li1 setelah insert first: \n");
    Printinfo(li1);
    printf("===============================================\n");

    InsertFirst(&li1, AD3);
    printf("Elemen pada list li1 setelah insert first: \n");
    Printinfo(li1);
    printf("===============================================\n");

    InsertFirst(&li1, AD5);
    printf("Elemen pada list li1 setelah insert first: \n");
    Printinfo(li1);
    printf("===============================================\n");

    InsertAfter(&li1, AD2, AD1);
    printf("Elemen pada list li1 setelah insert After: \n");
    Printinfo(li1);
    printf("===============================================\n");

    InsertLast(&li1, AD3);
    printf("Elemen pada list li1 setelah insert Last: \n");
    Printinfo(li1);
    printf("===============================================\n");

    F1 = Search(li1, 5);
    printf("Alamat elemen terakhir: %d\n", F1);
    printf("===============================================\n");

    F1 = Search(li1, 3);
    printf("Elemen 3, ditemukan pada alamat = %d\n", F1);
    printf("===============================================\n");

    printf("Apakah address AD1 sama dengan F1? %d\n", AD1 == F1);
    printf("===============================================\n");

    printf("Mencari elemen pada list dengan fungsi Fsearch\n");
    printf("===============================================\n");

    printf("Apakah terdapat alamat %d di dalam list? %d\n\n", AD2, FSearch(li1,AD2));
}