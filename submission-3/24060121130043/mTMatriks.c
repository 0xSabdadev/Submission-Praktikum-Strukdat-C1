/*Nama File : mTMatriks.c*/
/*Deskripsi :file main untuk tugas submisson 1 matriks*/
/*Nama      :Zahid Muhammad Mahfudz*/
/*NIM       :24060121130043*/
/*Tanggal   :Minggu, 18 September 2022*/

#include <stdio.h>
#include <stdlib.h>
#include "Matriks.h"
#include "matriks.c"

int main (void){
    /*Kamus*/
    Matriks M1;
    Matriks M2;
    Matriks Mul;
    int nbbarM1;
    int nbkolM1;
    int nbbarM2;
    int nbkolM2;
    /*Algoritma*/
    printf("\n====== Set M1 M2 ======\n");
    printf("Masukan Jumlah Baris  M1: ");
    scanf("%d", &nbbarM1);
    fflush(stdin);
    setNbbar(&M1, nbbarM1);
    printf("Masukan Jumlah Kolom M1: ");
    scanf("%d", &nbkolM1);
    fflush(stdin);
    setNbkol(&M1, nbkolM1);
    setMatriks(&M1, nbbarM1, nbkolM1);
    printf("Matriks M1 adalah : \n");
    viewMatriks(M1);
    printf("Masukan Jumlah Baris  M2: ");
    scanf("%d", &nbbarM2);
    fflush(stdin);
    setNbbar(&M2, nbbarM2);
    printf("Masukan Jumlah Kolom M2: ");
    scanf("%d", &nbkolM2);
    fflush(stdin);
    setNbkol(&M2, nbkolM2);
    setMatriks(&M2, nbbarM2, nbkolM2);
    printf("Matriks M2 adalah : \n");
    viewMatriks(M2);
    printf("====== MulMatriks ======\n");
    Mul = MulMatriks(M1,M2);
    viewMatriks(Mul);
    printf("====== ISEQUAL Matriks ======\n");
    printf("Apakah ukuran Matriks M1 dan M2 ssama : ");
    isEqualMatriks(M1,M2);
    printf("\n");
    printf("====== ISSUQARE Matriks ======\n");
    printf("Apakah Matriks M1 square : ");
    IsSquareMatriks(M1);
    printf("\nApakah Matriks M2 square : ");
    IsSquareMatriks(M2);
    printf("\n");
    printf("====== DETERMINAN Matriks ======\n");
    printf("determinan dari M1 adalah : %2.f", DeterminanMatriks(M1));
    printf("\ndeterminan dari M2 adalah : %2.f", DeterminanMatriks(M2));
    printf("\nJika mengembalikan 1 maka matriks harus square");
    printf("\n");
    printf("====== ISSatuan Matriks ======\n");
    printf("apakah matriks M1 adalah matriks satuan : ");
    IsSatuanMatriks(M1);
    printf("\napakah matriks M2 adalah matriks satuan : ");
    IsSatuanMatriks(M2);
    printf("\n");
    printf("====== IsSparse Matriks ======\n");
    printf("Apakah Matriks M1 Merupakan Matriks jarang : ");
    IsSparseMatriks(M1);
    printf("\nApakah Matriks M2 Merupakan Matriks jarang : ");
    IsSparseMatriks(M2);


    
    return 0;
}