/* Program   : mmatriks.c */
/* Deskripsi : driver file modul ADT Matriks */
/* NIM/Nama  : 24060121130090/Dorino Baharson */
/* Tanggal   : 18 September 2022 */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"

int main(void){
	/* kamus */
	Matriks A;
	Matriks M1,M2;
	int NBbar, NBkol;

	/* algoritma */
    printf("\n\n-||\n");
    printf("SD-3 MATRIKS ===========--||\n");
    printf("=========================-||\n\n");

    makeMatriks(&A);

    printf("PRINT MATRIKS ===========\n");
    printMatriks(A);
    printf("\n");

    printf("VIEW MATRIKS ============\n");
    viewMatriks(A);
    printf("\n");

    printf("SET MATRIKS [NBBAR & NBKOL]\n");
    printf("Masukkan Jumlah Baris : ");
    scanf("%d",&NBbar);
    fflush(stdin);
    setNbbar(&A,NBbar);
    printf("Masukkan Jumlah Kolom : ");
    scanf("%d",&NBkol);
    fflush(stdin);
    setNbkol(&A,NBkol);
	setMatriks(&A,NBbar,NBkol);

	printf("\n");
    printf("PRINT MATRIKS\n");
	printMatriks(A);
	printf("\n");
	printf("VIEW MATRIKS\n");
	viewMatriks(A);

	printf("\n");
	printf("====== IS EMPTY MATRIKS ========\n");
	printf("Matriks Kosong : %s\n",isEmptyMatriks(A)?"True":"False");
	printf("====== IS FULL MATRIKS =========\n");
	printf("Matriks Full : %s\n",isFullMatriks(A)?"True":"False");

	printf("\n");
	printf("====== GET NBBAR MATRIKS =======\n");
	printf("Jumlah Baris : %d\n",getNbbar(A));
	printf("====== GET NBKOL MATRIKS =======\n");
	printf("Jumlah Kolom : %d\n",getNbkol(A));

	printf("\n");
	printf("==== GET INFO CELL MATRIKS =====\n");
	printf("Nilai Cell [2][3] : %d\n",getInfoCell(A,2,3));

	printf("\n");
	printf("==== SUM CELL MATRIKS ==========\n");
	printf("Sum Cell : %d\n",sumCellMatriks(A));
	printf("=== AVG CELL MATRIKS MATRIKS ===\n");
	printf("AVG Cell : %.1f\n",avgCellMatriks(A));

	printf("\n");
	printf("==== SEARCH MATRIKS MATRIKS ====\n");
	searchMatriks(A,5);
	printf("\n");
	printf("====== COUNT A MATRIKS =========\n");
	printf("Kemunculan nilai yang dicari : %d kali\n",countA(A,5));

	printf("\n");
	printf("====== MIN CELL MATRIKS ========\n");
	printf("Nilai Cell Min : %d\n",minCellMatriks(A));
	printf("====== MAX CELL MATRIKS ========\n");
	printf("Nilai Cell Max : %d\n",maxCellMatriks(A));

	printf("\n");
	printf("Setelah di Set Info Cell [0][0] dengan 5\n");
	// ===================
	setInfoCell(&A,0,0,5);
	// ===================
	printf("=== VIEW MATRIKS [NEW CELL] ====\n");
	viewMatriks(A);
	transpose(&A);
	printf("=== VIEW MATRIKS [TRANSPOSE] ===\n");
	viewMatriks(A);

	printf("\n");
	printf("SET MATRIKS M1 [NBBAR & NBKOL]\n");
    printf("Masukkan Jumlah Baris : ");
    scanf("%d",&NBbar);
    fflush(stdin);
    setNbbar(&M1,NBbar);
    printf("Masukkan Jumlah Kolom : ");
    scanf("%d",&NBkol);
    fflush(stdin);
    setNbkol(&M1,NBkol);
	setMatriks(&M1,NBbar,NBkol);

	printf("\n");
	printf("SET MATRIKS M2 [NBBAR & NBKOL]\n");
    printf("Masukkan Jumlah Baris : ");
    scanf("%d",&NBbar);
    fflush(stdin);
    setNbbar(&M2,NBbar);
    printf("Masukkan Jumlah Kolom : ");
    scanf("%d",&NBkol);
    fflush(stdin);
    setNbkol(&M2,NBkol);
	setMatriks(&M2,NBbar,NBkol);

	printf("\n");
	printf("VIEW MATRIKS ===================\n");
	printf("MATRIKS M1\n");
	viewMatriks(M1);
	printf("MATRIKS M2\n");
	viewMatriks(M2);

	printf("\n");
	printf("HASIL M1 * M2 ADALAH : \n");
	MulMatriks(M1,M2);

	printf("\n");
	printf("MATRIKS M : \n");
	viewMatriks(A);
	printf("\n");


	printf("\n");
	printf("MATRIKS M ADALAH SATUAN MATRIKS : %s \n",IsSatuanMatriks(A)?"True":"False");
	printf("\n");
	printf("MATRIKS M ADALAH SPARSE MATRIKS : %s \n",IsSparseMatriks(A)?"True":"False");

	printf("\n");
	printf("DETERMINAN MATRIKS M ADALAH : %.3f \n",DeterminanMatriks(A));

	return 0;
}
