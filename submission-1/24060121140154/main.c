/* Program   : mmatriks.c */
/* Deskripsi : driver file modul ADT Matriks */
/* NIM/Nama  : 24060121140154/Mutiara Permata Putri*/
/* Tanggal   : 13 September 2022*/
/***********************************/
#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"

int main()
{
	/*Kamus*/
	Matriks A;
	Matriks M1;
	Matriks M2;
	Matriks M;
	int NBbar;
	int NBkol;
	makeMatriks(&A);

	/*Algoritma*/
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
	searchMatriks(A,5);

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

	printf("\n\n");
	printf("====== SET MATRIKS M1 ======\n");
	printf("Masukkan jumlah baris : ");
	scanf("%d", &NBbar);
	fflush(stdin);
	setNbbar(&M1, NBbar);
	printf("Masukkan jumlah kolom : ");
	scanf("%d", &NBkol);
	fflush(stdin);
	setNbkol(&M1, NBkol);
	setMatriks(&M1, NBbar, NBkol);

	printf("\n");
	printf("====== SET MATRIKS M2 ======\n");
	printf("Masukkan jumlah baris : ");
	scanf("%d", &NBbar);
	fflush(stdin);
	setNbbar(&M2, NBbar);
	printf("Masukkan jumlah kolom : ");
	scanf("%d", &NBkol);
	fflush(stdin);
	setNbkol(&M2, NBkol);
	setMatriks(&M2, NBbar, NBkol);

	printf("\n\n");
    printf("====== VIEW MATRIKS [NEW]  =======\n");
    printf("Matriks M1\n");
	viewMatriks(M1);
	printf("Matriks M2\n");
	viewMatriks(M2);

	printf("Hasil dari Matriks M1*Matriks M2 : \n");
	MulMatriks(M1,M2);

	printf("Matriks M : \n");
	viewMatriks(M);
	printf("Determinan dari Matriks M : %.3f \n", DeterminanMatriks(A));

	printf("Matriks M merupakan satuan matriks : %s \n",isSatuanMatriks(A)?"True":"False");

	printf("Matriks M merupakan sparse matriks : %s \n",isSparseMatriks(A)?"True":"False");

	return 0;
}
