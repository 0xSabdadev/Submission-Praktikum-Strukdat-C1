/****************************************************/
/* Program   : mlist1.c*/
/* Deskripsi : file main modul list*/
/* NIM/Nama  : 24060121120023/Arynda Anna Salsabiela*/
/* Tanggal   : 29 Oktober 2022*/
/*************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list1.h"

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
    printf("CEK LIST KOSONG\n");
    printf("Apakah List L1 Kosong: %d\n", ListEmpty(L1));
    printf("Apakah List L2 Kosong: %d\n", ListEmpty(L2));
    printf("Apakah List L3 Kosong: %d\n", ListEmpty(L3));
    printf("\n");

    /*Melakukan alokasi dan memasukan nilainya kedalam List */
    P1 = Alokasi(4);
    P2 = Alokasi(2);
    P3 = Alokasi(10);
    P4 = Alokasi(9);
    P5 = Alokasi(1);

	printf("CEK ELEMEN LIST KOSONG\n");
    printf("Elemen pada List L1: ");
    Printinfo(L1);
    printf("Elemen pada List L2: ");
    Printinfo(L2);
    printf("Elemen pada List L3: ");
    Printinfo(L3);
    printf("\n");

	printf("MEMASUKKAN ELEMEN V1\n");
    InsertFirst(&L1, P1);
    printf("Elemen pada List L1: ");
    Printinfo(L1);
    InsertFirst(&L1, P4);
    printf("Elemen pada List L1: ");
    Printinfo(L1);
    InsertFirst(&L1, P5);
    printf("Elemen pada List L1: ");
    Printinfo(L1);
    InsertAfter(&L1, P2, P1);
    printf("Elemen pada List L1: ");
    Printinfo(L1);
    InsertLast(&L1, P3);
    printf("Elemen pada List L1: ");
    Printinfo(L1);
    printf("\n");

    /*Print alamat*/
    printf("PRINT ALAMAT\n");
    printf("Alamat elemen pertama L1: %d\n", First(L1));
    F1 = Search(L1, 10);
    printf("Alamat elemen terakhir L1: %d\n", F1);
    printf("\n");

    /*mencari elemen pada list*/
    printf("PENCARIAN ELEMEN\n");
    F1 = Search(L1, 2);
    printf("Elemen 2, ditemukan pada alamat: %d\n", F1);
    printf("Apakah address P1 sama dengan F1? %d\n", P1 == F1);

    printf("\nMencari elemen pada list dengan fungsi Fsearch\n");
	printf("Apakah terdapat alamat %d didalam list? %d\n", P2, FSearch(L1, P2));

	printf("\nMencari elemen pada list dengan fungsi SearchPrec\n");
	printf("Alamat sebelum elemen 2 pada list L1 adalah: %d\n\n", SearchPrec(L1, 2, &Prec1));

	/*menghapus elemen pada list*/
	printf("PENGHAPUSAN ELEMEN");
	printf("\nMenghapus elemen pertama pada list dengan fungsi DelFirst\n");
	DelFirst(&L1, &F1);
	printf("Address elemen pertama adalah %d, address elemen yang dihapus adalah %d\n", P5, F1);
	printf("Info pada address P5 adalah %d, info pada address F1 adalah %d\n", info(P5), info(F1));
	printf("--> ");
	Printinfo(L1);
	printf("Menghapus elemen 4 dari list dengan fungsi DelP\n");
	DelP(&L1, 4);
	printf("--> ");
	Printinfo(L1);
	printf("Menghapus elemen terakhir dari list dengan fungsi DelLast\n");
	DelLast(&L1, &F1);
	printf("--> ");
	Printinfo(L1);
	printf("Menghapus elemen kedua dari list dengan fungsi DelAfter\n");
	DelAfter(&L1, &F1, P4);
	printf("L1 --> ");
	Printinfo(L1);

	/*memasukkan elemen kedalam list v2*/
	printf("\nMEMASUKKAN ELEMEN V2 PRIMITIF BERDASAR NILAI");
	printf("\nMemasukkan elemen 24 ke dalam list L2 dengan fungsi InsVFirst\n");
	InsVFirst(&L2, 24);
	printf("--> ");
	Printinfo(L2);
	printf("Memasukkan elemen 100 ke dalam list L2 dengan fungsi InsVLast\n");
	InsVLast(&L2, 100);
	printf("--> ");
	Printinfo(L2);
	printf("Memasukkan elemen tambahan ke dalam list L2\n");
	InsVFirst(&L2, 15);
	InsVFirst(&L2, 21);
	InsVLast(&L2, 30);
	printf("--> ");
	Printinfo(L2);

	/*menghapus elemen pada list v2*/
	printf("\nMENGHAPUS ELEMEN V2 PRIMITIF BERDASARKAN NILAI");
	printf("\nMenghapus elemen pertama dari list L2 dengan fungsi DelVFirst\n");
	DelVFirst(&L2, &T1);
	printf("--> ");
	Printinfo(L2);
	printf("Menghapus elemen terakhir dari list L2 dengan fungsi DelVLast\n");
	DelVLast(&L2, &T1);
	printf("L2 --> ");
	Printinfo(L2);

	/*menambahkan elemen*/
	printf("\nMENAMBAHKAN ELEMEN AFTER");
	printf("\nMemasukkan elemen 13 kedalam list L3 dengan fungsi InsVFirst\n");
	InsVLast(&L3, 13);
	printf("--> ");
	Printinfo(L3);
	printf("Menambahkan elemen dengan fungsi InsVAfter1\n");
	P1 = Alokasi(10);
	InsertFirst(&L3, P1);
	InsVAfter1(&L3, P1, Alokasi(13));
	printf("--> ");
	Printinfo(L3);
	printf("Menambahkan elemen dengan fungsi InsVAfter2\n");
	InsVAfter2(&L3, 13, 30);
	printf("--> ");
	Printinfo(L3);

	/*menghapus elemen*/
	printf("\nMENGHAPUS ELEMEN AFTER");
	printf("\nMenghapus elemen dengan fungsi DelVAfter1\n");
	DelVAfter1(&L3, &T1, 13);
	printf("--> ");
	Printinfo(L3);
	printf("Menghapus elemen dengan fungsi DelVAfter2\n");
	DelVAfter2(&L3, &F1, P1);
	printf("L3 --> ");
	Printinfo(L3);

	/*menghitung jumlah elemen*/
	printf("\nMenghitung jumlah elemen pada L3, dengan fungsi NbElmt\n");
	printf("Jumlah elemen pada L3: %d\n", NbElmt(L3));

    return 0;
}
