/* Program   : mmatriks.c */
/* Deskripsi : driver file modul ADT Matriks */
/* NIM/Nama  : 24060121130062/Varrel */
/* Tanggal   : 18-09-2022 */
/***********************************/
#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"


int main(void) {
	/*kamus*/
	Matriks A, M1, M2;
	int NBbar, NBkol;

	/*algoritma*/

	printf("\n==============================================");
	printf("\n============= SD-3 MATRIKS START =============");
	printf("\n==============================================");

	makeMatriks(&A);

	printf("\n\n1. PRINT MATRIKS [DEFAULT]\n");
	printMatriks(A);

	printf("\n\n2. VIEW MATRIKS [DEFAULT]\n");
	viewMatriks(A);

	printf("\n\n3. IS EMPTY MATRIKS [DEFAULT]\n");
	printf("Matriks Kosong : %s\n", isEmptyMatriks(A)?"True":"False");

	printf("\n\n4. SET MATRIKS (KOLOM DAN BARIS)\n");
	printf("Masukkan jumlah baris efektif (terpakai): ");
	scanf("%d", &NBbar);
	fflush(stdin);
	setNbbar(&A,NBbar);
	printf("Masukkan jumlah kolom efektif (terpakai): ");
	scanf("%d", &NBkol);
	fflush(stdin);
	setNbkol(&A,NBkol);

	printf("\n5. MEMBUAT MATRIKS EFEKTIF BARU\n");
	setMatriks(&A,NBbar, NBkol);
	printf("\nPRINT MATRIKS [BARU]\n");
	printMatriks(A);
	printf("\n\n VIEW MATRIKS [BARU]\n");
	viewMatriks(A);
	printf("\n\nIS EMPTY MATRIKS [BARU]\n");
	printf("Matriks Kosong : %s\n", isEmptyMatriks(A)?"True":"False");

	printf("\n\n6. IS FULL MATRIKS [BARU]\n");
	printf("Matriks Full : %s\n", isFullMatriks(A)?"True":"False");

	printf("\n\n7. GET NBBAR MATRIKS\n");
	printf("Jumlah Baris : %d\n",getNbbar(A));

	printf("\n\n8. GET NBKOL MATRIKS\n");
	printf("Jumlah Kolom : %d\n",getNbkol(A));

	printf("\n\n9. GET INFO CELL MATRIKS (BARIS 1, KOLOM 2)\n");
	printf("Nilai Cell : %d\n",getInfoCell(A,1,2));

	printf("\n\n10. SUM CELL MATRIKS\n");
	printf("Sum Cell : %d\n",sumCellMatriks(A));

	printf("\n\n11. AVG CELL MATRIKS\n");
	printf("AVG Cell : %.1f\n",avgCellMatriks(A));

	printf("\n\n12. SEARCH MATRIKS (2)\n");
	searchMatriks(A,2);

	printf("\n\n13. COUNT A MATRIKS (1)\n");
	printf("Kemunculan nilai yang dicari : %d kali\n",countA(A,1));

	printf("\n\n14. MIN CELL MATRIKS\n");
	printf("Nilai Cell Min : %d\n",minCellMatriks(A));

	printf("\n\n15. MAX CELL MATRIKS\n");
	printf("Nilai Cell Max : %d\n",maxCellMatriks(A));

	setInfoCell(&A,0,0,5);

	printf("\n\n16. VIEW MATRIKS [NEW CELL]\n");
	viewMatriks(A);
	transpose(&A);

	printf("\n\n17. VIEW CELL MATRIKS [TRANSPOSE]\n");
	viewMatriks(A);


	/* ---------TUGAS 1 MATRIKS LAB C1-------- */

	printf("---------TUGAS 1 MATRIKS LAB C1--------");

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
	viewMatriks(M1);
	printf("\n");

    printf("\n");
	printf("MATRIKS M1 dan M2 ADALAH SAMA : %s \n",isEqualMatriks(M1,M2)?"True":"False");

    printf("\n");
	printf("MATRIKS M1 ADALAH SQUARE MATRIKS : %s \n",IsSquareMatriks(M1)?"True":"False");

	printf("\n");
	printf("MATRIKS M1 ADALAH SATUAN MATRIKS : %s \n",IsSatuanMatriks(M1)?"True":"False");

	printf("\n");
	printf("MATRIKS M1 ADALAH SPARSE MATRIKS : %s \n",IsSparseMatriks(M1)?"True":"False");

	printf("\n");
	printf("DETERMINAN MATRIKS M1 ADALAH : %.3f \n",DeterminanMatriks(M1));

	return 0;
}
