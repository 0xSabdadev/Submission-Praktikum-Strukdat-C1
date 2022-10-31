/* Program   : mmatriks.c */
/* Deskripsi : driver file modul ADT Matriks */
/* NIM/Nama  : 24060121140139/Thirafi Syahir Saputra */
/* Tanggal   : 18 September 2022 */
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
    printf("=========== SD-3 MATRIKS START ============\n");
	printf("===========================================\n\n");
	printf("======== PRINT MATRIKS [DEFAULT] ==========\n");
	printMatriks(A);
	printf("======== VIEW MATRIKS [DEFAULT] ===========\n");
	viewMatriks(A);
	printf("============ IS EMPTY MATRIKS =============\n");
	printf("Matriks Kosong : %s\n\n",isEmptyMatriks(A)?"True":"False");
	printf("============= IS FULL MATRIKS =============\n");
	printf("Matriks Full : %s\n\n",isFullMatriks(A)?"True":"False");
	printf("==== SET MATRIKS A [SET NBBAR | NBKOL ] ===\n");

	printf("Masukkan jumlah baris : ");
	scanf("%d",&NBbar);
	setNbbar(&A,NBbar);
	printf("Masukkan jumlah kolom : ");
	scanf("%d",&NBkol);
	setNbkol(&A,NBkol);

	setMatriks(&A,NBbar,NBkol);
	printf("============= PRINT MATRIKS A ==============\n");
	printMatriks(A);
	printf("============= VIEW MATRIKS A ===============\n");
	viewMatriks(A);
	printf("============ IS EMPTY MATRIKS ==============\n");
	printf("Matriks Kosong : %s\n\n",isEmptyMatriks(A)?"True":"False");
	printf("============= IS FULL MATRIKS =============\n");
	printf("Matriks Full : %s\n\n",isFullMatriks(A)?"True":"False");
	printf("============ GET NBBAR MATRIKS ============\n");
	printf("Jumlah Baris : %d\n\n",getNbbar(A));
	printf("============ GET NBKOL MATRIKS ============\n");
	printf("Jumlah Kolom : %d\n\n",getNbkol(A));
	printf("========== GET INFO CELL MATRIKS ==========\n");
	printf("Nilai Cell : %d\n\n",getInfoCell(A,2,3));
	printf("============= SUM CELL MATRIKS ============\n");
	printf("Sum Cell : %d\n\n",sumCellMatriks(A));
	printf("========= AVG CELL MATRIKS MATRIKS ========\n");
	printf("AVG Cell : %.1f\n\n",avgCellMatriks(A));
	printf("========== SEARCH MATRIKS MATRIKS =========\n");
	searchMatriks(A,5);
	printf("============== COUNT A MATRIKS ============\n");
	printf("Kemunculan nilai yang dicari : %d kali\n\n",countA(A,5));
	printf("============== MIN CELL MATRIKS ===========\n");
	printf("Nilai Cell Min : %d\n\n",minCellMatriks(A));
	printf("============== MAX CELL MATRIKS ===========\n");
	printf("Nilai Cell Max : %d\n\n",maxCellMatriks(A));
	printf("========== VIEW MATRIKS [NEW CELL] ========\n");
	setInfoCell(&A,0,0,5);
	viewMatriks(A);
	printf("========== VIEW MATRIKS [TRANSPOSE] =======\n");
	transpose(&A);
	viewMatriks(A);

	//============================ TUGAS 1 ==========================
	printf("\n\n\n\n\n");
	printf("====================== TUGAS 1 =======================\n");
	printf("\n\n");
	printf("CUSTOM MATRIKS B %dx%d \n", NBbar, NBkol);
	setNbbar(&B, NBbar);
	setNbkol(&B, NBkol);
	setMatriks(&B, NBbar, NBkol);
	printf("\n");
	printf("================= VIEW MATRIKS A ======================\n");
	viewMatriks(A);
	printf("================= VIEW MATRIKS B =====================\n");
	viewMatriks(B);
	printf("\n");
	printf("================== PERKALIAN MATRIKS A * B ===================\n");
	C = MulMatriks(A, B);
	viewMatriks(C);

	printf("=============== IS EQUAL MATRIKS A = B =================\n");
	printf("A equals B : %s\n\n", isEqualMatriks(A, B) ? "True" : "False");
	printf("================ IS SQUARE MATRIKS B =================\n");
	printf("Matriks Square : %s\n\n", IsSquareMatriks(B) ? "True" : "False");

	printf("===================== DETERMINAN MATRIKS =====================\n");
	printf("Determinan matrix A: %f\n", DeterminanMatriks(A));
	printf("Determinan matrix B: %f\n", DeterminanMatriks(B));
	printf("Determinan matrix C: %f\n", DeterminanMatriks(C));
	printf("\n");

	printf("================= IS SATUAN MATRIKS B ================\n");
	printf("Matriks Satuan : %s\n\n", IsSatuanMatriks(B) ? "True" : "False");
	printf("\n");

	printf("=============== MEMBUAT MATRIKS SATUAN D ===============\n");
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

	printf("================= IS SATUAN MATRIKS D ================\n");
	printf("Matriks Satuan : %s\n\n", IsSatuanMatriks(D) ? "True" : "False");
	printf("\n");


	printf("================= IS SPARSE MATRIKS D ================\n");
	printf("Matriks Sparse : %s\n\n", IsSparseMatriks(D) ? "True" : "False");
	printf("\n");

	printf("================= IS SPARSE MATRIKS B ================\n");
	printf("Matriks Sparse : %s\n\n", IsSparseMatriks(B) ? "True" : "False");
	printf("\n");

	return 0;
}

