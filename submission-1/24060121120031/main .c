/* Program   : main.c */
/* Deskripsi : driver file modul ADT Matriks */
/* NIM/Nama  : 24060121120031/Yesy Margharetta Munthe*/
/* Tanggal   : 18 September 2022*/
/***********************************/
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "matriks.h"

 // int main() {
	/*kamus*/
//	Matriks A;
//	int barisA;
//	int kolomA;
//	int infoCell;
//	int jumlahA;
//	float rataRataA;
//	int minA;
//	int maxA;
//	int banyakX;
//	int posisiBarisX;
//	int posisiKolomX;


	/*algoritma*/
//	makeMatriks(&A);
//    barisA = getNbbar(A);
//    printf("Jumlah baris pada matriks A adalah %d\n", barisA);
//    kolomA = getNbkol(A);
//    printf("Jumlah kolom pada matriks A adalah %d\n", kolomA);
    
    
// 	setNbbar(&A,4);
//	setNbkol(&A,4);

//  barisA = getNbbar(A);
//    printf("Jumlah baris aktif pada matriks A adalah %d\n", barisA);

//    kolomA = getNbkol(A);
//    printf("Jumlah kolom aktif pada matriks A adalah %d\n", kolomA);

//   A.wadah[1][1] = 101;
//    A.wadah[1][2] = 201;
//    A.wadah[2][1] = 100;
//  A.wadah[2][2] = 200;

//    infoCell = getInfoCell(A, 1, 2);
//  printf("Cell ke [1][2] adalah %d\n", infoCell);

//    setInfoCell(&A, 1, 3, 50);

//    printf("Apakah Matriks A kosong??? %s\n", isEmptyMatriks(A)? "true":"false");
//    printf("Apakah Matriks A penuh??? %s\n", isFullMatriks(A)? "true":"false");
//
//	printMatriks(A);
//	viewMatriks(A);

//    printf("MASUKAN NILAI MATRIKS YANG INGIN DI INPUTKAN\n");
//   setMatriks(&A,3,3);
//    viewMatriks(A);
//    printf("Jumlah baris dari matriks A adalah %d\n", A.nbbar);
//   printf("Jumlah kolom dari matriks A adalah %d\n", A.nbkol);
//    jumlahA = sumCellMatriks(A);
//    printf("Jumlah semua element di matriks A adalah %d\n", jumlahA);
//    rataRataA = avgCellMatriks(A);
//    printf("Rata - rata dari semua element matriks A adalah %f\n", rataRataA);
//    minA = minCellMatriks(A);
//    maxA = maxCellMatriks(A);
//    printf("Nilai minimum dari matriks A adalah %d\n", minA);
//   printf("Nilai maksimum dari matriks A adalah %d\n", maxA);
//   banyakX = countA(A, 2);
//    printf("Banyaknya element angka 2 pada matriks A adalah %d\n", banyakX);
//   searchMatriks(A, 6, &posisiBarisX, &posisiKolomX);
//   printf("Element angka 6 berada di matriks baris ke-%d kolom ke-%d\n", posisiBarisX, posisiKolomX);
//    printf("+=======Transpose Matriks A===========\n");
//    transpose(&A);
//   viewMatriks(A);  
    
   
   int main() {
	/*kamus*/
	Matriks A;
	int barisA;
	int kolomA;
	Matriks B;
	Matriks C;
	Matriks D;

	/*algoritma*/
	printf("+=====Tugas Submission 1=====+\n");

	makeMatriks(&A);
	makeMatriks(&B);
	setMatriks(&A,3,3);
	printf("\nMatriks  A\n");
	viewMatriks(A);
	printf("\n");

	setMatriks(&B,3,3);
	printf("\nMatriks B\n");
	viewMatriks(B);
	C = MulMatriks(A, B);
	printf("\n");
	printf("\nMatriks C\n");
	viewMatriks(C);

	printf("Apakah matriks A memiliki ukuran yang sama dengan matriks B?? %s\n", isEqualMatriks(A, B)? "True":"False");
	printf("Apakah matriks A matriks square?? %s\n", IsSquareMatriks(A)? "True":"False");

	printf("\nDeterminan Matriks\n");
	printf("Determinan matriks A = %f\n", DeterminanMatriks(A));
	printf("\n");

    setMatriks(&D,1,2);
    printf("\nMatriks D\n");
    viewMatriks(D);
    printf("Apakah matriks D matriks satuan?? %s\n", IsSatuanMatriks(D)? "True":"False");
    IsSparseMatriks(A);
    printf("Apakah matriks A matriks sparse?? %s\n", IsSparseMatriks(A)? "True":"False");
    printf("\n");

	return 0;
}
    


