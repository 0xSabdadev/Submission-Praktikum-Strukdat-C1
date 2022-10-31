/* Program   : mmatriks.c */
/* Deskripsi : driver file modul ADT Matriks */
/* NIM/Nama  : 24060121120039/ Nida' Naafilatul Haniifah*/
/* Tanggal   : */
/***********************************/
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "matriks.h"


int main() {
	/*kamus*/
	Matriks A;
	int barisA;
	int kolomA;
	Matriks B;
	Matriks C;
	Matriks D;


	/*algoritma*/
	makeMatriks(&A);
	makeMatriks(&B);
	setMatriks(&A,2,2);
	printf("=============MATRIKS A==============\n");
	viewMatriks(A);
	setMatriks(&B,3,2);
	printf("=============MATRIKS B==============\n");
	viewMatriks(B);
	C = MulMatriks(A, B);
	printf("\n=============MATRIKS C==============\n");
	viewMatriks(C);
	printf("\n");
	printf("Apakah matriks A berukuran sama dengan matriks B?? %s\n", isEqualMatriks(A, B)? "true":"false");
	printf("Apakah matriks A merupakan matriks square?? %s\n", IsSquareMatriks(A)? "true":"false");
    setMatriks(&D,2,2);
    viewMatriks(D);
    printf("Apakah matriks D merupakan matriks satuan?? %s\n", IsSatuanMatriks(D)? "true":"false");
    IsSparseMatriks(A);
    printf("Apakah matriks A merupakan matriks sparse?? %s\n", IsSparseMatriks(A)? "true":"false");
    float detA = DeterminanMatriks(D);
    printf("Determinan Matriks A adalah %f", detA);

	return 0;
}

