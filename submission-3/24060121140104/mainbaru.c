/***********************************/
/* Program   : mainbaru.c */
/* Deskripsi : driver modul list ganda tanpa last */
/* NIM/Nama  : 24060121140104/Divia Shinta Sukarsaatmadja */
/* Tanggal   : 23 November 2022*/
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "listganda.c"

int main(void){
    //Kamus Global
    address P1, P2, P3, P4, P5, P6, P7, P8, P9, D1;
    address Q1, Q2, Q3, Q4, Q5, D2;
    List L, L2, L3, L4, L5, L6;
    infotype I1;

    //Algoritma
    printf("\n\n========================================\n");
    printf("======= SD-9 DOUBLE LINEAR LL START ====\n");
	printf("========================================\n\n");
    CreateList(&L);
    CreateList(&L2);
    CreateList(&L3);

    P1 = Alokasi(10);
    P2 = Alokasi(20);
    P3 = Alokasi(30);
    P4 = Alokasi(40);
    P5 = Alokasi(50);
    P6 = Alokasi(80);
    P7 = Alokasi(90);
    P8 = Alokasi(12);
    P9 = Alokasi(23);
    Q1 = Alokasi(90);
    Q2 = Alokasi(80);
    Q3 = Alokasi(70);
    Q4 = Alokasi(60);
    Q5 = Alokasi(50);
    D2 = Alokasi(0);

    printf("\nCreating List...\n\n");
    printf("Apakah L kosong? %s\n", ListEmpty(L) ? "True" : "False");
    printf("Apakah L2 kosong? %s\n", ListEmpty(L2) ? "True" : "False");
    printf("Apakah L3 kosong? %s\n", ListEmpty(L3) ? "True" : "False");

    printf("\n======= FUNGSI PRIMITIF BERDASARKAN NILAI ========\n");

    printf("===== PENAMBAHAN ELEMENT BERDASARKAN ALAMAT ======\n\n");
    printf("==== INSERT FIRST ====\n");
    printf("Element L : ");
    PrintInfo(L);
    printf("\nElement L2 : ");
    PrintInfo(L2);
    printf("\nElement L3 : ");
    PrintInfo(L3);
    printf("\nNilai Penambahan : %d %d %d\n", info(P1), info(P2), info(P3));
    InsertFirst(&L, P1);
    InsertFirst(&L, P2);
    InsertFirst(&L, P3);
    printf("Element L (after): ");
    PrintInfo(L);    
    InsertFirst(&L2, P6);
    InsertFirst(&L2, P7);
    printf("\nElement L2 (after): ");
    PrintInfo(L2);
    InsertFirst(&L3, P8);
    InsertFirst(&L3, P9);
    printf("\nElement L3 (after): ");
    PrintInfo(L3);    

    printf("\n==== INSERT AFTER ====\n");
    printf("Element L: ");
    PrintInfo(L);
    printf("\nInserting %d after %d...\n", info(P4), info(P2));
    InsertAfter(&L, P4, P2);
    printf("Element L (after): ");
    PrintInfo(L);

    printf("\n==== INSERT LAST ====\n");
    printf("Element L: ");
    PrintInfo(L);
    InsertLast(&L, P5);
    printf("\nElement L (after): ");
    PrintInfo(L);
    printf("\n");

    printf("\n\n===== PENGHAPUSAN ELEMENT BERDASARKAN ALAMAT ====\n\n");
    printf("==== DEL FIRST ====\n");
    printf("Element L: ");
    PrintInfo(L);
    DelFirst(&L, &D1);
    printf("\nElement L (after): ");
    PrintInfo(L);

    printf("\n==== DEL AFTER ====\n");
    printf("Element L: ");
    PrintInfo(L);
    printf("\ndeleting element after %d...\n", info(P2));
    DelAfter(&L, &D1, P2);
    printf("Element L (after): ");
    PrintInfo(L);

    printf("\n==== DEL LAST ====\n");
    printf("Element L: ");
    PrintInfo(L);
    DelLast(&L, &D1);
    printf("\nElement L (after): ");
    PrintInfo(L);
    
    printf("\n==== DEL ALL ====\n");
    printf("Element L2: ");
    PrintInfo(L2);
    DelAll(&L2);
    printf("\nElement L2 (after): ");
    PrintInfo(L2);   

    printf("\n\n==== PENAMBAHAN ELEMENT BERDASARKAN INFOTYPE =====\n\n");
    printf("==== INSV FIRST ====\n");
    printf("Element pada L1 saat ini: ");
    PrintInfo(L);
    InsVFirst(&L, 200);
    printf("Element pada L1 setelah pengujian: ");
    PrintInfo(L);

    printf("\n==== INSV LAST ====\n");
    printf("Element pada L saat ini: ");
    PrintInfo(L);
    InsVLast(&L, 212);
    printf("Element pada L setelah pengujian: ");
    PrintInfo(L);

    printf("\n==== INSV AFTER ====\n");
    printf("Element pada L saat ini: ");
    PrintInfo(L);
    printf("Inserting %d after %d...\n", 50, 20);
    InsVAfter(&L, 20, 50);
    printf("Element pada L setelah pengujian: ");
    PrintInfo(L);

    printf("\n==== DELV FIRST ====\n");
    printf("Element pada L saat ini: ");
    PrintInfo(L);
    DelVFirst(&L, &I1);
    printf("Element pada L setelah pengujian: ");
    PrintInfo(L);

    printf("\n==== DELV LAST ====\n");
    printf("Element pada L saat ini: ");
    PrintInfo(L);
    DelVLast(&L, &I1);
    printf("Element pada L setelah pengujian: ");
    PrintInfo(L);

    printf("\n==== DELV AFTER ====\n");
    printf("Element pada L saat ini: ");
    PrintInfo(L);
    printf("Deleting element after %d...\n", 20);
    DelVAfter(&L, &I1, 20);
    printf("Element pada L setelah pengujian: ");
    PrintInfo(L);

    printf("\n========= PENCARIAN ELEMENT DALAM LIST ==========\n\n");
    printf("==== SEARCH LIST ====\n");
    printf("Element 20 pada L ditemukan pada alamat %d\n\n", Search(L, 20));

    printf("==== FSEARCH LIST ====\n");
    printf("Apakah alamat %d ditemukan pada L2? %s\n\n", Q2, FSearch(L, Q2) ? "True" : "False");

    printf("==== SEARCHPREC LIST ====\n");
    printf("Alamat sebelum element 10 pada L adalah %d\n", SearchPrec(L, 10,&D1));

    printf("\n===== OPERASI UNTUK SELURUH ELEMENT LIST =======\n\n");
    printf("==== NB ELEMENT ====\n");
    printf("Jumlah element pada L: %d\n", NbElmt(L));

    printf("\n===== PROSES TERHADAP LIST =======\n\n");
    printf("==== INVERS LIST ====\n");
    printf("Element L3: ");
    PrintInfo(L3);
    printf("\nElement pada L3 setelah di-invers: ");
    InversList(&L3);
    PrintInfo(L3);

    printf("\n==== FINVERS LIST ====\n");
    printf("Element L: ");
    PrintInfo(L);
    printf("\nElement pada L4 setelah di-Finvers: ");
    CreateList(&L4);
    L4 = FInversList(L); 
    PrintInfo(L4);

    printf("\n==== COPY LIST ====\n");
    printf("Element L3: ");
    PrintInfo(L3);
    printf("\nElement L2: ");
    PrintInfo(L2);
    printf("\nElement pada L2 setelah copy element L3: ");
    CopyList(&L3, &L2);
    PrintInfo(L2);

    printf("\n==== FCOPY LIST ====\n");
    printf("Element L2: ");
    PrintInfo(L2);
    printf("\nElement pada L4 setelah di-copy: ");
    L4 = FCopyList(L2); 
    PrintInfo(L4);

    printf("\n==== KONKAT ====\n");
    printf("Element L3: ");
    PrintInfo(L3);
    printf("\nElement L: ");
    PrintInfo(L);
    CreateList(&L5);
    printf("\nHasil konkat L3 & L: ");
    Konkat(L3, L, &L5);
    PrintInfo(L5);

    printf("\n==== KONKAT 1 ====\n");
    printf("Element L2: ");
    PrintInfo(L2);
    printf("\nElement L: ");
    PrintInfo(L);
    CreateList(&L6);
    printf("\nHasil konkat L2 & L: ");
    Konkat1(&L2, &L, &L6);
    PrintInfo(L6);

    printf("\n==== PECAH LIST ====\n");
    printf("Element L6: ");
    PrintInfo(L6);
    printf("\nHasil pecah list L6");
    PecahList(&L, &L2, L6);
    printf("\nElement L: ");
    PrintInfo(L);
    printf("\nElement L2: ");
    PrintInfo(L2);

    printf("\n==== END =====");
    return 0;

}