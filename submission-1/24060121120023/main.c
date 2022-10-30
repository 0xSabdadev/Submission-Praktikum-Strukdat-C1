///* Program   : mmatriks.c */
///* Deskripsi : driver file modul ADT Matriks */
///* NIM/Nama  : 24060121120023/Arynda Anna Salsabiela*/
///* Tanggal   : 16 September 2022*/
///***********************************/
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "matriks.h"


int main() {
	/*kamus*/
	Matriks A;
	int barisA;
	int kolomA;
	Matriks X;
	Matriks Y;
	Matriks Z;

	/*algoritma*/
	makeMatriks(&A);
	makeMatriks(&X);
	setMatriks(&A,2,2);
	printf("\nMATRIKS A\n");
	viewMatriks(A);
	printf("\n");

	setMatriks(&X,2,3);
	printf("\nMATRIKS X\n");
	viewMatriks(X);
	Y = MulMatriks(A, X);
	printf("\n");
	printf("\nMATRIKS Y\n");
	viewMatriks(Y);

	printf("Apakah matriks A memiliki ukuran yang sama dengan matriks X?? %s\n", isEqualMatriks(A, X)? "True":"False");
	printf("Apakah matriks A matriks square?? %s\n", IsSquareMatriks(A)? "True":"False");

	printf("\nDeterminan Matriks\n");
	printf("Determinan matriks A = %f\n", DeterminanMatriks(A));
	printf("\n");

    setMatriks(&Z,1,1);
    printf("\nMATRIKS Z\n");
    viewMatriks(Z);
    printf("Apakah matriks Z matriks satuan?? %s\n", IsSatuanMatriks(Z)? "True":"False");
    IsSparseMatriks(A);
    printf("Apakah matriks A matriks sparse?? %s\n", IsSparseMatriks(A)? "True":"False");
    printf("\n");

	return 0;
}
