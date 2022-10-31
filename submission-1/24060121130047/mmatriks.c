/* Program   : mmatriks.c */
/* Deskripsi : driver file modul ADT Matriks */
/* NIM/Nama  : 24060121130047/Benjamin Sipayung*/
/* Tanggal   : 17 September 2022*/
/***********************************/
#include <stdio.h>
#include "matriks.c"


int main (){
	int i,j,command=1;
	int submit,answer;
	matriks result;
	matriks M1,M2;
	
	//input matriks 1
	printf ("\n Isi matriks pertama");
	printf ("\n\nBaris matriks pertama -> ");
	scanf ("%d", &M1.baris);
	printf ("\nColom matriks pertama -> ");
	scanf ("%d", &M1.colom);
	for (i=0;i<M1.baris;i++){
		for (j=0; j<M1.colom;j++){
			printf ("\nIsi Matriks baris ke %d colom ke %d -> ", i+1,j+1);
			scanf ("%d", &M1.nilai[i][j]);
		}
	}
	
	//input matriks 2
	printf ("\n Isi matriks kedua");
	printf ("\n\nBaris matriks kedua -> ");
	scanf ("%d", &M2.baris);
	printf ("\nColom matriks kedua -> ");
	scanf ("%d", &M2.colom);
	for (i=0;i<M2.baris;i++){
		for (j=0; j<M2.colom;j++){
			printf ("\nIsi Matriks baris ke %d colom ke %d -> ", i+1,j+1);
			scanf ("%d", &M2.nilai[i][j]);
		}
	}
	
	while (command !=0){
		printf ("\n__________________________________________");
		printf ("\nDaftar Menu	:\n1. Membandingkan element kedua matriks\n2. Memastikan apakah suatu matriks merupakan matriks persegi");
		printf ("\n3. Mencari Determinan matriks\n4. Memastikan apakah suatu matriks merupakan matriks satuan atau bukan\n5. Memastikan matriks merupakan suatu matriks sparse atau bukan.");
		printf ("\nMasukkan Menu yang ingin kamu gunakan ->");
		scanf ("%d", &command);
		switch (command){
			case 1:
				if (isEqualMatriks(M1,M2) == true){
					printf ("\nKedua matriks memiliki baris dan colom yang sama.");
				}
				else if (isEqualMatriks(M1,M2) == false){
					printf ("\nKedua matriks tidak memiliki baris dan colom yang sama.");
				}
				break;
			case 2:
				printf ("\nMatriks manakah yang ingin Anda check?(1/2) ->");
				scanf ("%d", &submit);
				if (submit == 1){
					if (isSquareMatriks(M1) == true){
						printf ("\nMatriks ini merupakan matriks persegi");
					}
					else if(isSquareMatriks(M1) == false){
						printf ("\nMatriks ini bukan merupakan matriks persegi");
					}
				}
				else if (submit == 2){
					if (isSquareMatriks(M2) == true){
						printf ("\nMatriks ini merupakan matriks persegi");
					}
					else if(isSquareMatriks(M2) == false){
						printf ("\nMatriks ini bukan merupakan matriks persegi");
					}
				}
				break;
			case 3:
				printf ("\nMatriks manakah yang ingin Anda check determinannya?(1/2) ->");
				scanf ("%d", &submit);
				if (submit == 1){
					printf ("%.3lf", DeterminanMatriks(M1));
				}
				else if (submit == 2){
					printf ("%.3lf", DeterminanMatriks(M2));
				}
				break;
			case 4:
				printf ("\nMatriks manakah yang ingin Anda check apakah matriks satuan atau bukan?(1/2) ->");
				scanf ("%d", &submit);
				if (submit == 1){
					if (isSatuanMatriks(M1) == true){
						printf ("\nMatriks ini merupakan matriks satuan");
					}
					else if(isSatuanMatriks(M1) == false){
						printf ("\nMatriks ini bukan merupakan matriks satuan");
					}
				}
				else if (submit == 2){
					if (isSatuanMatriks(M2) == true){
						printf ("\nMatriks ini merupakan matriks satuan");
					}
					else if(isSatuanMatriks(M2) == false){
						printf ("\nMatriks ini bukan merupakan matriks satuan");
					}
				}
				break;
			case 5:
				printf ("\nMatriks manakah yang ingin Anda check apakah matriks sparse atau bukan?(1/2) ->");
				scanf ("%d", &submit);
				if (submit == 1){
					if (isSparseMatriks(M1) == true){
						printf ("\nMatriks ini merupakan matriks sparse");
					}
					else if(isSparseMatriks(M1) == false){
						printf ("\nMatriks ini bukan merupakan matriks sparse");
					}
				}
				else if (submit == 2){
					if (isSparseMatriks(M2) == true){
						printf ("\nMatriks ini merupakan matriks sparse");
					}
					else if(isSparseMatriks(M2) == false){
						printf ("\nMatriks ini bukan merupakan matriks sparse");
					}
				}
				break;
		}
	}
	return 0;
}
