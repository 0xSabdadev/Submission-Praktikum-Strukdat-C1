/****************************************************/
/* Program   : mList1.c */
/* Deskripsi : file Main modul list */
/* NIM/Nama  : 24060121140151/Dhiya Mazaya */
/* Tanggal   : 30 oktober 2022 */
/****************************************************/

#include <stdio.h>
#include "list1.h"

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
    CreateList(&L4);

    printf("CEK LIST KOSONG\n");
    printf("Apakah List L1 Kosong : %d\n", ListEmpty(L1));
    printf("Apakah List L2 Kosong : %d\n", ListEmpty(L2));
    printf("Apakah List L3 Kosong : %d\n", ListEmpty(L3));
    printf("\n");

    P1 = Alokasi(3);
    P2 = Alokasi(2);
    P3 = Alokasi(1);
    P4 = Alokasi(4);
    P5 = Alokasi(5);

    printf("CEK ELEMEN LIST KOSONG\n");
    printf("Elemen pada List L1 adalah : ");
    Printinfo(L1);
    printf("Elemen pada List L2 adalah : ");
    Printinfo(L2);
    printf("Elemen pada List L3 adalah : ");
    Printinfo(L3);
    printf("\n");

    printf("MEMASUKKAN ELEMEN V1\n");
    InsertFirst(&L1, P1);
    printf("Elemen pada List L1 setelah insert first adalah : ");
    Printinfo(L1);
    InsertFirst(&L1, P4);
    printf("Elemen pada List L1 setelah insert first adalah : ");
    Printinfo(L1);
    InsertFirst(&L1, P5);
    printf("Elemen pada List L1 setelah insert first adalah : ");
    Printinfo(L1);
    InsertAfter(&L1, P2, P1);
    printf("Elemen pada List L1 setelah insert After adalah : ");
    Printinfo(L1);
    InsertLast(&L1, P3);
    printf("Elemen pada List L1 setelah insert Last adalah : ");
    Printinfo(L1);
    printf("\n");

    printf("PRINT ALAMAT\n");
    printf("Alamat elemen pertama L1 adalah : %d\n", First(L1));
    F1 = Search(L1, 1);
    printf("Alamat elemen terakhir L1 adalah : %d\n", F1);
    printf("\n");

    printf("PENCARIAN ELEMEN\n");
    F1 = Search(L1, 2);
    printf("Elemen 3, ditemukan pada alamat = %d\n", F1);
    printf("Apakah address P1 sama dengan F1? %d\n", P1 == F1);

    printf("Mencari elemen pada list dengan fungsi Fsearch\n");
	printf("Apakah terdapat alamat %d didalam list? %d\n", P2, FSearch(L1, P2));
	printf("\n");

	printf("PENGHAPUSAN ELEMEN\n");
	printf("Menghapus elemen pertama pada list dengan fungsi DelFirst\n");
	DelFirst(&L1, &F1);
	printf("Address elemen pertama adalah %d, address elemen yang dihapus adalah %d\n", P5, F1);
	printf("Info pada address P5 adalah %d, info pada address F1 adalah %d\n", info(P5), info(F1));
	Printinfo(L1);

	printf("Menghapus elemen 3 dari list dengan fungsi DelP\n");
	DelP(&L1, 3);
	Printinfo(L1);

	printf("Menghapus elemen terakhir dari list dengan fungsi DelLast\n");
	DelLast(&L1, &F1);
	Printinfo(L1);

	printf("Menghapus elemen kedua dari list dengan fungsi DelAfter\n");
	DelAfter(&L1, &F1, P4);
	Printinfo(L1);
	printf("\n");

	printf("MEMASUKKAN ELEMEN V2 PRIMITIF BERDASAR NILAI\n");
	printf("Memasukkan elemen 15 kedalam list L2 dengan fungsi InsVFirst\n");
	InsVFirst(&L2, 15);
	Printinfo(L2);

	printf("Memasukkan elemen 14 kedalam list L2 dengan fungsi InsVLast\n");
	InsVLast(&L2, 14);
	Printinfo(L2);

	printf("Memasukkan elemen tambahan kedalam list L2\n");
	InsVFirst(&L2, 16);
	InsVFirst(&L2, 17);
	InsVLast(&L2, 13);
	Printinfo(L2);
	printf("\n");

	printf("MENGHAPUS ELEMEN V2 PRIMITIF BERDASAR NILAI\n");
	printf("Menghapus elemen pertama dari list L2 dengan fungsi DelVFirst\n");
	DelVFirst(&L2, &T1);
	Printinfo(L2);

	printf("Menghapus elemen terakhir dari list L2 dengan fungsi DelVLast\n");
	DelVLast(&L2, &T1);
	Printinfo(L2);

	printf("MENAMBAHKAN ELEMEN AFTER\n");
	printf("Memasukkan elemen 15 kedalam list L3 dengan fungsi InsVFirst\n");
	InsVLast(&L3, 15);
	Printinfo(L3);
	printf("Menambahkan elemen dengan fungsi InsVAfter1\n");
	P1 = Alokasi(1);
	InsertFirst(&L3, P1);
	InsVAfter1(&L3, P1, Alokasi(12));
	Printinfo(L3);

	printf("Menambahkan elemen dengan fungsi InsVAfter2\n");
	InsVAfter2(&L3, 15, 30);
	Printinfo(L3);
	printf("\n");

	printf("MENGHAPUS ELEMEN AFTER\n");
	printf("Menghapus elemen dengan fungsi DelVAfter1\n");
	DelVAfter1(&L3, &T1, 12);
	Printinfo(L3);

	printf("Menghapus elemen dengan fungsi DelVAfter2\n");
	DelVAfter2(&L3, &F1, P1);
	Printinfo(L3);
	printf("\n");

	printf("MENGHITUNG JUMLAH ELEMEN\n");
	printf("Menghitung jumlah elemen pada L3, dengan fungsi NbElmt\n");
	printf("Jumlah elemen pada L3 adalah: %d\n", NbElmt(L3));

    return 0;

}
