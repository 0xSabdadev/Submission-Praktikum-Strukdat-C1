#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/***********************************/
/* Program   : main.c */
/* Deskripsi : driver file modul list linear */
/* NIM/Nama  : 24060121140104/Divia Shinta Sukarsaatmadja */
/* Tanggal   : 24 Oktober 2022 */
/***********************************/

int main(){
/*Kamus global*/
    List A;
    address al,bl,cl,dl, sebelum;
    infotype bin1, bin2, bin3, bin4;

/*Algoritma*/
    printf("\n=== PEMBUATAN LIST KOSONG ===\n");
    CreateList(&A);

    printf("\n=== TEST LIST KOSONG ===\n");
    if(ListEmpty(A)){
        printf("List kosong\n");
    }
    else{
        printf("List tidak kosong\n");
    }

    printf("\n=== PRIMITIF BERDASARKAN ALAMAT ===");
    printf("\n=== Mengisi List Dengan InsertFirst ===\n");
    al = Alokasi(25);
    InsertFirst(&A,al);
    printf("List diisi elemen 25: \n");
    PrintInfo(A);
    printf("\n");

    printf("\n=== TEST LIST KOSONG LAGI ===\n");
    if(ListEmpty(A)){
        printf("List kosong\n");
    }
    else{
        printf("List tidak kosong\n");
    }

    printf("\n=== Mengisi List dengan InsertAfter ===");
    printf("\nInsert elemen 15 setelah elemen 25 pada list: \n");
    bl = Alokasi(15);
    InsertAfter(&A,bl,al);
    PrintInfo(A);
    printf("\nInsert elemen 23 setelah elemen 25 pada list: \n");
    cl = Alokasi(23);
    InsertAfter(&A,cl,al);
    PrintInfo(A);

    printf("\n\n=== Mengisi List dengan InsertLast ===");
    printf("\nInsert elemen terakhir list dengan elemen 50: \n");
    dl = Alokasi(50);
    InsertLast(&A,dl);
    PrintInfo(A);

    printf("\n\n=== PENCARIAN SEBUAH ELEMEN LIST ===");
    printf("\n=== Mencari elemen list dengan SearchPrec ===");
    printf("\nMencari alamat Prec sebelum elemen 23\n");
    printf("Address berdasarkan SearchPrec: ");
    SearchPrec(A,23,&sebelum);
    printf("\nAddress berdasarkan variabel a1 yang sebelumnya dialokasi: %d", al);

    printf("\n\n=== PENGHAPUSAN ELEMEN ===");
    printf("\n=== Menghapus elemen list dengan DelFirst ===");
    printf("\nElemen pertama pada list dihapus: \n");
    DelFirst(&A,&al);
    PrintInfo(A);

    printf("\n\n=== Menghapus elemen List dengan DelAfter ===");
    printf("\nElemen setelah 23 pada list dihapus: \n");
    DelAfter(&A,&bl,cl);
    PrintInfo(A);

    printf("\n\n==== Menghapus elemen List dengan DelLast ===");
    printf("\nElemen terakhir pada list dihapus: \n");
    DelLast(&A,&dl);
    PrintInfo(A);

    printf("\n\n=== PRIMITIF BERDASARKAN NILAI ===");
    printf("\n=== Mengisi List dengan InsertVFirst ===");
    printf("\nInsert elemen pertama list dengan 1: \n");
    InsVFirst(&A,1);
    PrintInfo(A);

    printf("\n\n=== Mengisi List dengan InsertVLast ===");
    printf("\nInsert elemen terakhir list dengan 8: \n");
    InsVLast(&A,8);
    PrintInfo(A);
    printf("\nInsert elemen terakhir list dengan 6: \n");
    InsVLast(&A,6);
    PrintInfo(A);

    printf("\n\n=== Mengisi elemen List dengan InsertVAfter (Prec static) ===");
    printf("\nInsert 9 pada list dengan InsertVAfter: \n");
    InsVAfter(&A,9);
    PrintInfo(A);

    printf("\n\n=== PENGHAPUSAN ELEMEN ===");
    printf("\n=== Menghapus elemen List dengan DelVFirst ===");
    printf("\nHapus elemen pertama list dengan DelVFirst: \n");
    DelVFirst(&A,&bin1);
    PrintInfo(A);

    printf("\n\n=== Menghapus elemen List dengan DelVLast ===");
    printf("\nHapus elemen terakhir list dengan DelVLast: \n");
    DelVLast(&A,&bin3);
    PrintInfo(A);

    printf("\n\n=== Menghapus elemen List dengan DelVAfter (Prec static) ===");
    printf("\nHapus elemen list dengan prec of last: \n");
    DelVAfter(&A,&bin2);
    PrintInfo(A);

    printf("\n\n=== PRIMITIF BERDASARKAN NILAI ===");
    printf("\n=== Mengisi List dengan InsertVAfter2 (Prec dinamis) ===");
    printf("\nInsert elemen 14 setelah 23 dengan InsertVAfter2: \n");
    InsVAfter2(&A,14,23);
    PrintInfo(A);

    printf("\n\n=== PENGHAPUSAN ELEMEN ===");
    printf("\n=== Menghapus elemen List dengan DelVAfter2 (Prec dinamis) ===");
    printf("\nHapus elemen setelah 23 pada list dengan DelVAfter2: \n");
    DelVAfter2(&A,&bin4,23);
    PrintInfo(A);

    printf("\n\n=== PENCARIAN SEBUAH ELEMEN LIST ===");
    printf("\n=== Mencari address elemen dengan Search ===");
    printf("\nSearch address elemen 23 \n");
    printf("Address elemen 23 yaitu: %d",Search(A,23));
    printf("\nAddress dari variabel cl yang sebelumnya dialokasi: %d",cl);

    printf("\n\n=== Mengecek keberadaan address dalam List dengan FSearch ===");
    printf("\nAddress cl (1: true, 0: false):\n%d",FSearch(A,cl));

    printf("\n\n=== PROSES SEMUA ELEMEN LIST ===");
    printf("\n=== Menghitung elemen List dengan NbElmt===");
    printf("\nJumlah elemen list: %d", NbElmt(A));

    printf("\n\n=== Dealokasi ===");
    printf("\nElemen 15 sudah dihapus, tapi alamat belum didealokasi: %d", info(bl));
    Dealokasi(&bl);
    printf("\nElemen 15 sudah dihapus, alamat sudah didealokasi: %d", info(bl));
}
