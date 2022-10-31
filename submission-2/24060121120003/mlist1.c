/****************************************************/
/* Program   : mList1.c                             */
/* Deskripsi : file MAIN modul list               */
/* NIM/Nama  : 24060121120003/Dafa Kurnia Dinata*/
/* Tanggal   : 30 Oktober 2022*/
/*************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "List1.c"

int main(void){
    /*Kamus Lokal*/
    List L1, L2, L3, L4;
    address A1, A2, A3, A4, A5;
    address B1, B2, B3, Prec1, Prec2;
    infotype T1;

    /*Algoritma*/

    /*Membuat List*/
    CreateList(&L1);
    CreateList(&L2);
    CreateList(&L3);

    /*Memeriksa apakah list kosong*/
    printf("======================CEK LIST KOSONG=============================\n");
    printf("Apakah List L1 Kosong : %d\n", ListEmpty(L1));
    printf("Apakah List L2 Kosong : %d\n", ListEmpty(L2));
    printf("Apakah List L3 Kosong : %d\n", ListEmpty(L3));
    printf("\n");

    /*Melakukan alokasi dan memasukan nilainya kedalam List */
    A1 = Alokasi(1);
    A2 = Alokasi(2);
    A3 = Alokasi(3);
    A4 = Alokasi(4);
    A5 = Alokasi(5);

	printf("======================CEK ELEMEN LIST KOSONG=============================\n");
    printf("Elemen pada List L1 adalah : ");
    Printinfo(L1);
    printf("Elemen pada List L2 adalah : ");
    Printinfo(L2);
    printf("Elemen pada List L3 adalah : ");
    Printinfo(L3);
    printf("\n");

	printf("======================MEMASUKKAN ELEMEN V1=============================\n");
    InsertFirst(&L1, A2);
    printf("Elemen pada List L1 adalah : ");
    Printinfo(L1);
    InsertFirst(&L1, A3);
    printf("Elemen pada List L1 adalah : ");
    Printinfo(L1);
    InsertFirst(&L1, A4);
    printf("Elemen pada List L1 adalah : ");
    Printinfo(L1);
    InsertAfter(&L1, A2, A5);
    printf("Elemen pada List L1 adalah : ");
    Printinfo(L1);
    InsertLast(&L1, A1);
    printf("Elemen pada List L1 adalah : ");
    Printinfo(L1);
    printf("\n");

    /*Print alamat*/
    printf("======================PRINT ALAMAT=============================\n");
    printf("Alamat elemen pertama L1 adalah : %d\n", First(L1));
    B1 = Search(L1, 1);
    printf("Alamat elemen terakhir L1 adalah : %d\n", B1);
    printf("\n");

    /*mencari elemen pada list*/
    printf("======================PENCARIAN ELEMEN=============================\n");
    B1 = Search(L1, 3);
    printf("elemen 3, ditemukan pada alamat = %d\n", B1);
    printf("apakah address P1 sama dengan F1? %d\n", A1 == B1);

    printf("\nmencari elemen pada list dengan fungsi Fsearch\n");
	printf("Apakah terdapat alamat %d didalam list? %d\n", A2, FSearch(L1, A2));

	printf("\nmencari elemen pada list dengan fungsi SearchPrec\n");
	printf("alamat sebelum elemen 2 pada list L1 adalah = %d\n\n", SearchPrec(L1, 2, &Prec1));

	/*menghapus elemen pada list*/
	printf("======================PENGHAPUSAN ELEMEN=============================\n");
	printf("\nmenghapus elemen pertama pada list dengan fungsi DelFirst\n");
	DelFirst(&L1, &B1);
	printf("address elemen pertama adalah %d, address elemen yang dihapus adalah %d\n", A5, B1);
	printf("info pada address P5 adalah %d, info pada address F1 adalah %d\n", info(A5), info(B1));
	Printinfo(L1);

	printf("\nmenghapus elemen 3 dari list dengan fungsi DelP\n");
	DelP(&L1, 3);
	Printinfo(L1);

	printf("\nmenghapus elemen terakhir dari list dengan fungsi DelLast\n");
	DelLast(&L1, &B1);
	Printinfo(L1);

	printf("\nmenghapus elemen kedua dari list dengan fungsi DelAfter\n");
	DelAfter(&L1, &B1, A4);
	Printinfo(L1);

	/*memasukkan elemen kedalam list v2*/
	printf("======================MEMASUKKAN ELEMEN V2 PRIMITIF BERDASAR NILAI=============================\n");
	printf("\nmemasukkan elemen 25 ke dalam list L2 dengan fungsi InsVFirst\n");
	InsVFirst(&L2, 25);
	Printinfo(L2);

	printf("\nmemasukkan elemen 24 ke dalam list L2 dengan fungsi InsVLast\n");
	InsVLast(&L2, 24);
	Printinfo(L2);

	printf("\nmemasukkan elemen tambahan kedalam list L2\n");
	InsVFirst(&L2, 26);
	InsVFirst(&L2, 27);
	InsVLast(&L2, 23);
	Printinfo(L2);

	/*menghapus elemen pada list v2*/
	printf("======================MENGHAPUS ELEMEN V2 PRIMITIF BERDASAR NILAI=============================\n");
	printf("\nmenghapus elemen pertama dari list L2 dengan fungsi DelVFirst\n");
	DelVFirst(&L2, &T1);
	Printinfo(L2);

	printf("\nmenghapus elemen terakhir dari list L2 dengan fungsi DelVLast\n");
	DelVLast(&L2, &T1);
	Printinfo(L2);

	/*menambahkan elemen*/
	printf("======================MENAMBAHKAN ELEMEN AFTER=============================\n");
	printf("\nmemasukkan elemen 15 kedalam list L3 dengan fungsi InsVFirst\n");
	InsVLast(&L3, 15);
	Printinfo(L3);
	printf("\nmenambahkan elemen dengan fungsi InsVAfter1\n");
	A1 = Alokasi(1);
	InsertFirst(&L3, A1);
	InsVAfter1(&L3, A1, Alokasi(12));
	Printinfo(L3);

	printf("\nmenambahkan elemen dengan fungsi InsVAfter2\n");
	InsVAfter2(&L3, 15, 30);
	Printinfo(L3);

	/*menghapus elemen*/
	printf("======================MENGHAPUS ELEMEN AFTER=============================\n");
	printf("\nmenghapus elemen dengan fungsi DelVAfter1\n");
	DelVAfter1(&L3, &T1, 12);
	Printinfo(L3);

	printf("\nmenghapus elemen dengan fungsi DelVAfter2\n");
	DelVAfter2(&L3, &B1, A1);
	Printinfo(L3);

	/*menghitung jumlah elemen*/
	printf("\nmenghitung jumlah elemen pada L3, dengan fungsi NbElmt\n");
	printf("Jumlah elemen pada L3 adalah: %d\n", NbElmt(L3));

    return 0;
}

