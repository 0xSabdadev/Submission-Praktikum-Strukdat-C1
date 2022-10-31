/* Program   : mainmatriks.c */
/* Deskripsi : driver file modul ADT Matriks */
/* NIM/Nama  : 24060121120003/Dafa Kurnia Dinata*/
/* Tanggal   : 18 September 2022*/
/***********************************/
#include <stdio.h>
#include "matriks.h"

int main() {
	// kamus
	Matriks A, B, C, D;
	int NBbar,NBkol;
	int i, j;

	// algoritma
	makeMatriks(&A);
	printf("\n\n");
    printf("===========================================\n");
    printf("===== TUGAS SD 3 MATRIKS \n");
	printf("===== Print Matriks (Default) \n");
	printMatriks(A);
	printf("===== View Matriks (Default) \n");
	viewMatriks(A);
	printf("===== Is Empty Matriks \n");
	printf("Apakah Matriks Kosong: %s\n\n",isEmptyMatriks(A)?"True":"False");
	printf("===== Is Full Matriks \n");
	printf("Apakah Matriks Penuh: %s\n\n",isFullMatriks(A)?"True":"False");
	printf("==== Set Matriks A (Set NBBAR | NBKOL ) ===\n");

	printf("Masukkan jumlah baris: ");
	scanf("%d",&NBbar);
	setNbbar(&A,NBbar);
	printf("Masukkan jumlah kolom: ");
	scanf("%d",&NBkol);
	setNbkol(&A,NBkol);

	setMatriks(&A,NBbar,NBkol);
	printf("===== Print Matriks A \n");
	printMatriks(A);
	printf("===== View Matriks A \n");
	viewMatriks(A);
	printf("===== Is Empty Matriks \n");
	printf("Apakah Matriks Kosong: %s\n\n",isEmptyMatriks(A)?"True":"False");
	printf("===== Is Full Matriks \n");
	printf("Apakah Matriks Penuh: %s\n\n",isFullMatriks(A)?"True":"False");
	printf("===== NBBAR Matriks \n");
	printf("Jumlah Baris Matriks: %d\n\n",getNbbar(A));
	printf("===== NBKOL Matriks \n");
	printf("Jumlah Kolom Matriks: %d\n\n",getNbkol(A));
	printf("===== Get Info Cell Matriks \n");
	printf("Nilai Cell Matriks: %d\n\n",getInfoCell(A,3,4));
	printf("===== SUM Cell Matriks \n");
	printf("Sum Cell Matriks: %d\n\n",sumCellMatriks(A));
	printf("===== AVG Cell Matriks \n");
	printf("AVG (rata-rata) Cell Matriks: %.1f\n\n",avgCellMatriks(A));
	printf("===== Search Matriks \n");
	searchMatriks(A,4);
	printf("===== Count A Matriks \n");
	printf("Kemunculan nilai matriks yang dicari : %d kali\n\n",countA(A,5));
	printf("===== MIN Cell Matriks \n");
	printf("Nilai Cell Min (Terendah): %d\n\n",minCellMatriks(A));
	printf("===== MAX Cell Matriks \n");
	printf("Nilai Cell Max (Tertinggi): %d\n\n",maxCellMatriks(A));
	printf("===== View Matriks (Cell Baru) \n");
	setInfoCell(&A,0,0,6);
	viewMatriks(A);
	printf("===== View Matriks (Transpose) \n");
	transpose(&A);
	viewMatriks(A);

	//===== TUGAS 1
	printf("\n\n\n\n\n");
	printf("===== Tugas 1 \n");
	printf("\n\n");
	printf("Custom Matriks B %dx%d \n", NBbar, NBkol);
	setNbbar(&B, NBbar);
	setNbkol(&B, NBkol);
	setMatriks(&B, NBbar, NBkol);
	printf("\n");
	printf("===== View Matriks A \n");
	viewMatriks(A);
	printf("===== View Matriks B \n");
	viewMatriks(B);
	printf("\n");
	printf("===== Perkalian Matriks A * B \n");
	C = MulMatriks(A, B);
	viewMatriks(C);

	printf("===== Is Equal Matriks A = B \n");
	printf("Apakah A equals B: %s\n\n", isEqualMatriks(A, B) ? "True" : "False");
	printf("===== Is Square Matriks B \n");
	printf("Apakah Matriks Square: %s\n\n", IsSquareMatriks(B) ? "True" : "False");

	printf("===== Determinan Matriks \n");
	printf("Determinan matriks A: %f\n", DeterminanMatriks(A));
	printf("Determinan matriks B: %f\n", DeterminanMatriks(B));
	printf("Determinan matriks C: %f\n", DeterminanMatriks(C));
	printf("\n");

	printf("===== Is Satuan Matriks B \n");
	printf("Apakah Matriks Satuan: %s\n\n", IsSatuanMatriks(B) ? "True" : "False");
	printf("\n");

	printf("===== Matriks Satuan D \n");
	setNbbar(&D, 9);
	setNbkol(&D, 9);
	for( i = 0; i < 9; i++){
		for( j = 0; j < 9; j++){
			if((i == j) || (i == 9 - j - 1) || (j == 9 - i - 1)){
				setInfoCell(&D, i, j, 1);
			} else {
				setInfoCell(&D, i, j, 0);
			}
		}
	}
	viewMatriks(D);
	printf("\n");

	printf("===== Is Satuan Matriks D\n");
	printf("Apakah Matriks Satuan: %s\n\n", IsSatuanMatriks(D) ? "True" : "False");
	printf("\n");

	printf("===== Is Sparse Matriks D \n");
	printf("Apakah Matriks Sparse: %s\n\n", IsSparseMatriks(D) ? "True" : "False");
	printf("\n");

	printf("===== Is Sparse Matriks B \n");
	printf("Apakah Matriks Sparse: %s\n\n", IsSparseMatriks(B) ? "True" : "False");
	printf("\n");

	return 0;
}
