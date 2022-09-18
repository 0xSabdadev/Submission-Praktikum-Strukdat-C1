/* Program   : mmatriks.c */
/* Deskripsi : driver file modul ADT Matriks */
/* NIM/Nama  : 24060121110042 / Naufal Arya Ramadhan */
/* Tanggal   : 18 September 2022 */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"
#include "matriks.c"

int main(void){
	/* kamus */
	Matriks A;
	Matriks M1,M2;
	int NBbar, NBkol;

	/* algoritma */
    makeMatriks(&A);

    printf("Wadah matriks awal\n");
    printMatriks(A);
    printf("\n");

	printf("=====Mengisi matriks=====\n");
    printf("Masukkan jumlah baris : ");
    scanf("%d",&NBbar);
    setNbbar(&A,NBbar);
    printf("Masukkan Jumlah Kolom : ");
    scanf("%d",&NBkol);

    setNbkol(&A,NBkol);
	setMatriks(&A,NBbar,NBkol);

	printf("\n");
    printf("Print matriks\n");
	printMatriks(A);
	printf("\n");
	printf("View matriks\n");
	viewMatriks(A);

	printf("Mengecek isi matriks\n");
	printf("Apakah matriksnya kosong? %s\n",isEmptyMatriks(A)?"True":"False");
	printf("Apakah matriksnya Penuh? %s\n",isFullMatriks(A)?"True":"False");

	printf("Menghitung jumlah baris & kolom\n");
	printf("Jumlah Baris : %d\n",getNbbar(A));
	printf("Jumlah Kolom : %d\n",getNbkol(A));
	printf("\n");
	printf("Jumlah semua cell : %d\n",sumCellMatriks(A));
	printf("Nilai rata-rata : %.1f\n",avgCellMatriks(A));

	printf("\n");
	printf("Mencari Nilai 5 dalam matriks\n");
	searchMatriks(A,5);
	printf("\n");
	printf("Jumlah kemunculan nilai yang dicari : %d kali\n",countA(A,5));

	printf("\n");
	printf("Nilai cell terkecil : %d\n",minCellMatriks(A));
	printf("Nilai c3ell terbesar : %d\n",maxCellMatriks(A));

	printf("\n");
	printf("Mengubah cell 0,0 dengan 5\n");
	setInfoCell(&A,0,0,5);
	printf("Matriks A\n");
	viewMatriks(A);
	transpose(&A);
	printf("=== VIEW MATRIKS [TRANSPOSE] ===\n");
	viewMatriks(A);

	printf("\n");
	printf("Membuat matriks M1\n");
    printf("Masukkan Jumlah Baris : ");
    scanf("%d",&NBbar);

    setNbbar(&M1,NBbar);
    printf("Masukkan Jumlah Kolom : ");
    scanf("%d",&NBkol);

    setNbkol(&M1,NBkol);
	setMatriks(&M1,NBbar,NBkol);

	printf("\n");
	printf("Membuat Matriks M2\n");
    printf("Masukkan Jumlah Baris : ");
    scanf("%d",&NBbar);

    setNbbar(&M2,NBbar);
    printf("Masukkan Jumlah Kolom : ");
    scanf("%d",&NBkol);

    setNbkol(&M2,NBkol);
	setMatriks(&M2,NBbar,NBkol);

	printf("\n");
	printf("MATRIKS M1\n");
	viewMatriks(M1);
	printf("MATRIKS M2\n");
	viewMatriks(M2);

	printf("\n");
	printf("Hasil M1*M2 : \n");
	MulMatriks(M1,M2);

	printf("\n");
	printf("Matriks M : \n");
	viewMatriks(A);
	printf("\n");


	printf("\n");
	printf("Matriks M adalah satuan matriks : %s \n",IsSatuanMatriks(A)?"True":"False");
	printf("\n");
	printf("Matriks M adalah separse matriks : %s \n",IsSparseMatriks(A)?"True":"False");

	printf("\n");
	printf("Determinan matriks M : %.3f \n",DeterminanMatriks(A));

	return 0;
}