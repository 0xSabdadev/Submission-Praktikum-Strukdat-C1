#include <stdio.h>
#include <stdlib.h>
#include "listdouble.c"
#include <string.h>

void printCenter(char *text, int fieldWidth) {
    int padLen = (fieldWidth - strlen(text)) / 2;
    printf("\n%.*s %s %.*s\n", padLen, "==================", text, padLen + strlen(text)%2, "==================");
} 

int main(void)
{
    address P1, P2, P3, P4, P5, D1;
    address Q1, Q2, Q3, Q4, Q5, D2;
    List L, L2, L3, L4;
    infotype I1;
    printf("\n\n========================================\n");
    printf("======= SD-9 DOUBLE LINEAR LL START ====\n");
	printf("========================================\n\n");
    CreateList(&L);

    P1 = Alokasi(10);
    P2 = Alokasi(20);
    P3 = Alokasi(30);
    P4 = Alokasi(40);
    P5 = Alokasi(50);
    Q1 = Alokasi(90);
    Q2 = Alokasi(80);
    Q3 = Alokasi(70);
    Q4 = Alokasi(60);
    Q5 = Alokasi(50);
    D2 = Alokasi(0);

    printf("\nCreating List...\n\n");
    printf("Apakah L kosong? %s\n", ListEmpty(L) ? "True" : "False");

    printf("\n======= FUNGSI PRIMITIF BERDASARKAN NILAI ========\n");
    printf("===== PENAMBAHAN ELEMENT BERDASARKAN ALAMAT ======\n\n");
    printf("==== INSERT FIRST ====\n");
    printf("Element L : ");
    Printinfo(L);
    printf("\nNilai Penambahan : %d %d %d\n", info(P1), info(P2), info(P3));
    InsertFirst(&L, P1);
    InsertFirst(&L, P2);
    InsertFirst(&L, P3);
    printf("Element L (after): ");
    Printinfo(L);

    printf("\n==== INSERT AFTER ====\n");
    printf("Element L1: ");
    Printinfo(L);
    printf("Inserting %d after %d...\n", info(P4), info(P2));
    InsertAfter(&L, P4, P2);
    printf("Element L (after): ");
    Printinfo(L);

    printf("\n==== INSERT LAST ====\n");
    printf("Element L1: ");
    Printinfo(L);
    InsertLast(&L, P5);
    printf("Element L (after): ");
    Printinfo(L);
    printf("\n");

    printf("===== PENGHAPUSAN ELEMENT BERDASARKAN ALAMAT ====\n\n");
    printf("==== DEL FIRST ====\n");
    printf("Element L1 : ");
    Printinfo(L);
    DelFirst(&L, &D1);
    printf("Element L (after): ");
    Printinfo(L);

    printf("\n==== DEL AFTER ====\n");
    printf("Element L1 : ");
    Printinfo(L);
    printf("deleting element after %d...\n", info(P2));
    DelAfter(&L, &D1, P2);
    printf("Element L (after): ");
    Printinfo(L);

    printf("\n==== DEL LAST ====\n");
    printf("Element L1 : ");
    Printinfo(L);
    DelLast(&L, &D1);
    printf("Element L (after): ");
    Printinfo(L);
    printf("\n==== PENAMBAHAN ELEMENT BERDASARKAN INFOTYPE =====\n\n");

    printf("==== INSV FIRST ====\n");
    printf("Element pada L1 saat ini: ");
    Printinfo(L);
    InsVFirst(&L, 200);
    printf("Element pada L1 setelah pengujian: ");
    Printinfo(L);

    printf("\n==== INSV LAST ====\n");
    printf("Element pada L saat ini: ");
    Printinfo(L);
    InsVLast(&L, 212);
    printf("Element pada L setelah pengujian: ");
    Printinfo(L);

    printf("\n==== INSV AFTER ====\n");
    printf("Element pada L saat ini: ");
    Printinfo(L);
    printf("Inserting %d after %d...\n", 50, 20);
    InsVAfter(&L, 20, 50);
    printf("Element pada L setelah pengujian: ");
    Printinfo(L);

    printf("\n==== DELV FIRST ====\n");
    printf("Element pada L saat ini: ");
    Printinfo(L);
    DelVFirst(&L, &I1);
    printf("Element pada L setelah pengujian: ");
    Printinfo(L);

    printf("\n==== DELV LAST ====\n");
    printf("Element pada L saat ini: ");
    Printinfo(L);
    DelVLast(&L, &I1);
    printf("Element pada L setelah pengujian: ");
    Printinfo(L);

    printf("\n==== DELV AFTER ====\n");
    printf("Element pada L saat ini: ");
    Printinfo(L);
    printf("Deleting element after %d...\n", 20);
    DelVAfter(&L, &I1, 20);
    printf("Element pada L setelah pengujian: ");
    Printinfo(L);

    printf("\n========= PENCARIAN ELEMENT DALAM LIST ==========\n\n");
    printf("==== SEARCH LIST ====\n");
    printf("Element 20 pada L ditemukan pada alamat %d\n\n", Search(L, 20));

    printf("==== FSEARCH LIST ====\n");
    printf("Apakah alamat %d ditemukan pada L2? %s\n\n", Q2, FSearch(L, Q2) ? "True" : "False");

    printf("==== SEARCHPREC LIST ====\n");
    printf("Alamat sebelum element 10 pada L adalah %d\n", SearchPrec(L, 10, &D1));

    printf("\n===== OPERASI UNTUK SELURUH ELEMENT LIST =======\n\n");
    printf("==== NB ELEMENT ====\n");
    printf("Jumlah element pada L: %d\n", NbElmt(L));
    
    InsVFirst(&L, 50);
    InsVFirst(&L, 30);
    CreateList(&L2);
    CreateList(&L3);
    CreateList(&L4);
    printCenter("Kondisi List", 30);
    printf("Element L1: ");    Printinfo(L);
    printf("Element L2: ");    Printinfo(L2);
    printf("Element L3: ");    Printinfo(L3);
    printf("Element L4: ");    Printinfo(L4);

    printCenter("InverstList L1", 30);
    InversList(&L);
    printf("Element L1: ");    Printinfo(L);
    printf("Element L2: ");    Printinfo(L2);
    printf("Element L3: ");    Printinfo(L3);
    printf("Element L4: ");    Printinfo(L4);

    printCenter("FInverstList L1 -> L2", 30);
    L2 = FInversList(L);
    printf("Element L1: ");    Printinfo(L);
    printf("Element L2: ");    Printinfo(L2);
    printf("Element L3: ");    Printinfo(L3);
    printf("Element L4: ");    Printinfo(L4);
    printf("Element L2 (FInverseList L1): ");  Printinfo(L2);

    printCenter("Copy L2 -> L3", 30);
    CopyList(&L2, &L3);
    printf("Element L1: ");    Printinfo(L);
    printf("Element L2: ");    Printinfo(L2);
    printf("Element L3: ");    Printinfo(L3);
    printf("Element L4: ");    Printinfo(L4);

    printCenter("FCopy L2 -> L3", 30);
    L4 = FCopyList(L2);
    printf("Element L1: ");    Printinfo(L);
    printf("Element L2: ");    Printinfo(L2);
    printf("Element L3: ");    Printinfo(L3);
    printf("Element L4: ");    Printinfo(L4);

    printCenter("DelAll L1,L2,L3", 30);
    DelAll(&L);
    DelAll(&L2);
    DelAll(&L3);
    printf("Element L1: ");    Printinfo(L);
    printf("Element L2: ");    Printinfo(L2);
    printf("Element L3: ");    Printinfo(L3);
    printf("Element L4: ");    Printinfo(L4);

    printCenter("CpAlokList L4 -> L1", 30);
    CpAlokList(L4, &L);
    printf("Element L1: ");    Printinfo(L);
    printf("Element L2: ");    Printinfo(L2);
    printf("Element L3: ");    Printinfo(L3);
    printf("Element L4: ");    Printinfo(L4);

    printCenter("Mengisi L2", 30);
    CreateList(&L2);
    InsVFirst(&L2, 40);
    InsVFirst(&L2, 60);
    InsVFirst(&L2, 80);
    InsVFirst(&L2, 100);
    printf("Element L1: ");    Printinfo(L);
    printf("Element L2: ");    Printinfo(L2);
    printf("Element L3: ");    Printinfo(L3);
    printf("Element L4: ");    Printinfo(L4);

    printCenter("Konkat L1,L2 -> L3", 30);
    Konkat(L, L2, &L3);
    printf("Element L1: ");    Printinfo(L);
    printf("Element L2: ");    Printinfo(L2);
    printf("Element L3: ");    Printinfo(L3);
    printf("Element L4: ");    Printinfo(L4);

    printCenter("DelAll L4", 30);
    DelAll(&L4);
    printf("Element L1: ");    Printinfo(L);
    printf("Element L2: ");    Printinfo(L2);
    printf("Element L3: ");    Printinfo(L3);
    printf("Element L4: ");    Printinfo(L4);


    printCenter("Konkat1 L3,L2 -> L4", 30);
    Konkat1(&L3, &L2, &L4);
    printf("Element L1: ");    Printinfo(L);
    printf("Element L2: ");    Printinfo(L2);
    printf("Element L3: ");    Printinfo(L3);
    printf("Element L4: ");    Printinfo(L4);

    printCenter("PecahList L4 -> L2,L3", 30);
    PecahList(&L2, &L3, L4);
    printf("Element L1: ");    Printinfo(L);
    printf("Element L2: ");    Printinfo(L2);
    printf("Element L3: ");    Printinfo(L3);
    printf("Element L4: ");    Printinfo(L4);


    printf("\n==== END =====");
    return 0;
}