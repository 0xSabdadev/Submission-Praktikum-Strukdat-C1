#include <stdio.h>
#include <stdlib.h>
#include "matriks.c"

int main(void)
{
    // kamus
	Matriks A, B;
	int NBbar,NBkol;
	makeMatriks(&A);
    printf("\n\n=================================\n");
    printf("====== SD-3 MATRIKS START =======\n");
	printf("=================================\n\n");
	printf("====== PRINT MATRIKS [DEFAULT] =======\n");
	printMatriks(A);
	printf("====== VIEW MATRIKS [DEFAULT] =======\n");
	viewMatriks(A);
	printf("====== IS EMPTY MATRIKS =======\n");
	printf("Matriks Kosong : %s\n",isEmptyMatriks(A)?"True":"False");
	printf("====== IS FULL MATRIKS =======\n");
	printf("Matriks Full : %s\n",isFullMatriks(A)?"True":"False");

	printf("====== SET MATRIKS [SET NBBAR | NBKOL ] =======\n");
	printf("Masukkan jumlah baris : ");
	scanf("%d",&NBbar);
    fflush(stdin);
	setNbbar(&A,NBbar);
	printf("Masukkan jumlah kolom : ");
	scanf("%d",&NBkol);
	fflush(stdin);
	setNbkol(&A,NBkol);
	setMatriks(&A,NBbar,NBkol);

	printf("====== PRINT MATRIKS [CUSTOM] =======\n");
	printMatriks(A);
	printf("====== VIEW MATRIKS [CUSTOM] =======\n");
	viewMatriks(A);
	printf("====== IS EMPTY MATRIKS =======\n");
	printf("Matriks Kosong : %s\n",isEmptyMatriks(A)?"True":"False");
	printf("====== IS FULL MATRIKS =======\n");
	printf("Matriks Full : %s\n",isFullMatriks(A)?"True":"False");
	printf("====== GET NBBAR MATRIKS =======\n");
	printf("Jumlah Baris : %d\n",getNbbar(A));
	printf("====== GET NBKOL MATRIKS =======\n");
	printf("Jumlah Kolom : %d\n",getNbkol(A));
	printf("====== GET INFO CELL MATRIKS =======\n");
	printf("Nilai Cell : %d\n",getInfoCell(A,2,3));
	printf("====== SUM CELL MATRIKS =======\n");
	printf("Sum Cell : %d\n",sumCellMatriks(A));
	printf("====== AVG CELL MATRIKS MATRIKS =======\n");
	printf("AVG Cell : %.1f\n",avgCellMatriks(A));
	printf("====== SEARCH MATRIKS MATRIKS =======\n");
	searchMatriks(A,2);
	printf("====== COUNT A MATRIKS =======\n");
	printf("Kemunculan nilai yang dicari : %d kali\n",countA(A,5));
	printf("====== MIN CELL MATRIKS =======\n");
	printf("Nilai Cell Min : %d\n",minCellMatriks(A));
	printf("====== MAX CELL MATRIKS =======\n");
	printf("Nilai Cell Max : %d\n",maxCellMatriks(A));
	setInfoCell(&A,0,0,5);
	printf("====== VIEW MATRIKS [NEW CELL] =======\n");
	viewMatriks(A);
	transpose(&A);
	printf("====== VIEW MATRIKS [TRANSPOSE] =======\n");
	viewMatriks(A);

	makeMatriks(&B);
	printf("====== PRINT MATRIKS B [DEFAULT] =======\n");
	printMatriks(B);
	printf("====== VIEW MATRIKS B [DEFAULT] =======\n");
	viewMatriks(B);
	printf("====== IS EMPTY MATRIKS =======\n");
	printf("Matriks Kosong : %s\n",isEmptyMatriks(B)?"True":"False");
	printf("====== IS FULL MATRIKS =======\n");
	printf("Matriks Full : %s\n",isFullMatriks(B)?"True":"False");

	printf("====== SET MATRIKS B [SET NBBAR | NBKOL ] =======\n");
	printf("Masukkan jumlah baris : ");
	scanf("%d",&NBbar);
    fflush(stdin);
	setNbbar(&B,NBbar);
	printf("Masukkan jumlah kolom : ");
	scanf("%d",&NBkol);
	fflush(stdin);
	setNbkol(&B,NBkol);
	setMatriks(&B,NBbar,NBkol);

	printf("Is Equal Matriks : %s\n",isEqualMatriks(A,B)?"True":"False");

	printf("Is Square Matriks : %s\n",IsSquareMatriks(A)?"True":"False");

	DeterminanMatriks(A);
	printf("Nilai Cell Min : %d\n",DeterminanMatriks(A));

	printf("Is Satuan Matriks : %s\n",IsSatuanMatriks(A)?"True":"False");

	printf("Is Sparse Matriks : %s\n",IsSparseMatriks(A)?"True":"False");

	MulMatriks(A, B);

    return 0;
}