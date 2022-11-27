#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list1.h"

/***********************************/
/* Program   : main.c */
/* Deskripsi : driver file modul list berkait */
/* NIM/Nama  : 24060121130063 / Givandra Haikal Adjie */
/* Tanggal   : 24/11/2022 */
/***********************************/
void printCenter(char *text, int fieldWidth) {
    int padLen = (fieldWidth - strlen(text)) / 2;
    printf("\n%.*s %s %.*s\n", padLen, "==================", text, padLen + strlen(text)%2, "==================");
} 

int main(){
    /*Kamus*/
    List A;
    address a, b, c, d;
    address e, s;
    infotype X;

    /*Algoritma*/
    /*-------- Membuat List Kosong --------*/
    CreateList(&A);

    printCenter("ListEmpty", 30);
    printf("%s", ListEmpty(A) ? "List kosong\n" : "List tidak kosong\n");

    printCenter("Mengisi list...", 30);
    for (char c = 'a'; c <='z'; c++) InsertLast(&A, Alokasi(c));
    printf("Isi list : "); Printinfo(A);

    printCenter("InsertFirst 'a'", 30);
    a = Alokasi('a');
    InsertFirst(&A, a);
    printf("Isi list : "); Printinfo(A);

    printCenter("InsertAfter 'b' a", 30);
    b = Alokasi('b');
    InsertAfter(&A, b, a);
    printf("Isi list : "); Printinfo(A);

    printCenter("InsVAfter1 b c", 30);
    c = Alokasi('c');
    InsVAfter1(&A, b, c);
    printf("Isi list : "); Printinfo(A);

    printCenter("InsVAfter2 'a' 'f'", 30);
    InsVAfter2(&A, 'a', 'f');
    printf("Isi list : "); Printinfo(A);

    printCenter("InsertLast 'd'", 30);
    d = Alokasi('d');
    InsertLast(&A, d);
    printf("Isi list : "); Printinfo(A);

    printCenter("InsVFirst 'z'", 30);
    InsVFirst(&A, 'z');
    printf("Isi list : "); Printinfo(A);

    printCenter("InsVLast 'a'", 30);
    InsVLast(&A, 'a');
    printf("Isi list : "); Printinfo(A);

    printCenter("InsVFirst", 30);
    InsVFirst(&A, 'e');
    printf("Isi list : "); Printinfo(A);

    printCenter("InsVLast", 30);
    InsVLast(&A, 'f');
    printf("Isi list : "); Printinfo(A);

    printCenter("DelFirst", 30);
    DelFirst(&A, &e);
    printf("Elemen terhapus: %c\n", e->info);
    printf("Isi list : "); Printinfo(A);

    printCenter("DeleteLast", 30);
    DelLast(&A, &e);
    printf("Elemen terhapus: %c\n", e->info);
    printf("Isi list : "); Printinfo(A);

    printCenter("DelAfter c", 30);
    DelAfter(&A, &e, c);
    printf("Elemen terhapus: %c\n", e->info);
    printf("Isi list : "); Printinfo(A);    

    printCenter("DelVFirst", 30);
    DelVFirst(&A, &X);
    printf("Elemen terhapus: %c\n", X);
    printf("Isi list : "); Printinfo(A);

    printCenter("DelVAfter1 'g'", 30);
    DelVAfter1(&A, &X, 'g');
    printf("Elemen terhapus: %c\n", X);
    printf("Isi list : "); Printinfo(A);

    printCenter("DelVLast", 30);
    DelVLast(&A, &X);
    printf("Elemen terhapus: %c\n", X);
    printf("Isi list : "); Printinfo(A);

    printCenter("FSearch 'u'", 30);
    printCenter("Search 'u'", 30);
    s = Search(A, 'u');

    printCenter("DelVAfter2", 30);
    DelVAfter2(&A, &e, s);
    printf("Elemen terhapus: %c\n", e->info);
    printf("Isi list : "); Printinfo(A);

    printCenter("SearchPrec 'x'", 30);
    SearchPrec(A, 'x', &s);

    printCenter("DelP 'r'", 30);
    DelP(&A, 'r');
    printf("Isi list : "); Printinfo(A);

    printCenter("NbElmt", 30);
    printf("NbElmt: %d\n",NbElmt(A));

    return 0;
}
