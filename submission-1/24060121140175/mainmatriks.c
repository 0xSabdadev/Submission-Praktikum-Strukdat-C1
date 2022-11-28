/* Program   : mainmatriks.c */
/* Deskripsi : realisasi matriks */
/* NIM/Nama  : Maulana Pasya Zefanya/ 24060121140175*/
/* Tanggal   : 16 September 2022*/
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
    printf("--- FUNGSI DAN PROSEDURAL SD-3 --\n");
	printf("\n");
	printf("--- printMatriks A (STATE AWAL) ---\n\n");
	printMatriks(A);
	printf("\n");
	printf("--- viewMatriks A (STATE AWAL) ---\n");
	viewMatriks(A);
	printf("\n");
	printf("--- isEmptyMatriks A ---\n");
	printf("Apakah matriks kosong? : %s\n\n",isEmptyMatriks(A)?"True":"False");
	printf("\n");
	printf("--- isFullMatriks A ---\n");
	printf("Apakah matriks penuh? : %s\n\n",isFullMatriks(A)?"True":"False");
	printf("\n");
	printf("--- setMatriks A (NBbar, NBkol) ---\n");

	printf("Masukkan jumlah baris : ");
	scanf("%d",&NBbar);
	setNbbar(&A,NBbar);
	printf("Masukkan jumlah kolom : ");
	scanf("%d",&NBkol);
	setNbkol(&A,NBkol);

	setMatriks(&A,NBbar,NBkol);
	printf("--- PRINT MATRIKS A ---\n");
	printMatriks(A);
	printf("--- VIEW MATRIKS A ---\n");
	viewMatriks(A);
	printf("--- isEmptyMatriks ---\n");
	printf("Apakah matriks kosong? : %s\n\n",isEmptyMatriks(A)?"True":"False");
	printf("--- isFullMatriks ---\n");
	printf("Apakah matriks penuh? : %s\n\n",isFullMatriks(A)?"True":"False");
	printf("--- getNbbar ---\n");
	printf("Jumlah Baris : %d\n\n",getNbbar(A));
	printf("--- getNbkol ---\n");
	printf("Jumlah Kolom : %d\n\n",getNbkol(A));
	printf("--- GET INFO CELL MATRIKS ---\n");
	printf("Nilai Cell : %d\n\n",getInfoCell(A,2,3));
	printf("--- sumCellMatriks ---\n");
	printf("Sum Cell : %d\n\n",sumCellMatriks(A));
	printf("--- avgCellMatriks ---\n");
	printf("Rata-rata nilai cell pada matriks : %.1f\n\n",avgCellMatriks(A));
	printf("--- searchMatriks (mencari nilai 2 pada matriks A) ---\n");
	searchMatriks(A,2);
	printf("--- countA ---\n");
	printf("Kemunculan nilai yang dicari : %d kali\n\n",countA(A,5));
	printf("--- minCellMatriks ---\n");
	printf("Nilai Cell Min : %d\n\n",minCellMatriks(A));
	printf("--- maxCellMatriks ---\n");
	printf("Nilai Cell Max : %d\n\n",maxCellMatriks(A));
	printf("--- viewMatriks (STATE BARU, menambahkan angka 9 pada baris 1 kolom 2) ---\n");
	setInfoCell(&A,0,1,9);
	viewMatriks(A);
	printf("--- viewMatriks (Transpose dari state akhir Matriks A setelah ditambah angka 9 pada baris 1 kolom 2) ---\n");
	transpose(&A);
	viewMatriks(A);

	// Tugas Pertemuan 3
	printf("\n\n");
	printf("#### TUGAS PERTEMUAN 3 ####\n");
	printf("\n\n");
	printf("--- Menyusun Matriks Custom B %dx%d ---\n", NBbar, NBkol);
	setNbbar(&B, NBbar);
	setNbkol(&B, NBkol);
	setMatriks(&B, NBbar, NBkol);
	printf("\n");
	printf("--- viewMatriks A ---\n");
	viewMatriks(A);
	printf("--- viewMatriks B ---\n");
	viewMatriks(B);
	printf("\n");
	printf("--- Perkalian Matriks A dan B menghasilkan matriks C ---\n");
	C = MulMatriks(A, B);
	viewMatriks(C);

	printf("--- isEqualMatriks A B ---\n");
	printf("Apakah matriks A sama dengan matriks B? : %s\n\n", isEqualMatriks(A, B) ? "True" : "False");
	printf("--- isSquareMatriks A ---\n");
	printf("Apakah Matriks A merupakan matriks persegi? : %s\n\n", IsSquareMatriks(A) ? "True" : "False");

	printf("--- Determinan ---\n");
	printf("Determinan matriks A: %f\n", DeterminanMatriks(A));
	printf("Determinan matriks B: %f\n", DeterminanMatriks(B));
	printf("Determinan matriks C: %f\n", DeterminanMatriks(C));
	printf("\n");

	printf("--- isSatuanMatriks C ---\n");
	printf("Matriks Satuan : %s\n\n", IsSatuanMatriks(B) ? "True" : "False");
	printf("\n");

	printf("--- Menyusun matriks satuan D ---\n");
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

	printf("--- IsSatuanMatriks D ---\n");
	printf("Matriks Satuan : %s\n\n", IsSatuanMatriks(D) ? "True" : "False");
	printf("\n");


	printf("--- IsSparseMatriks D ---\n");
	printf("Matriks Sparse : %s\n\n", IsSparseMatriks(D) ? "True" : "False");
	printf("\n");

	printf("--- IsSparseMatriks B ---\n");
	printf("Matriks Sparse : %s\n\n", IsSparseMatriks(B) ? "True" : "False");
	printf("\n");



	return 0;
}
