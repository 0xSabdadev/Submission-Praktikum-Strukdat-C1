/* Program   : mmatriks.c */
/* Deskripsi : driver file modul ADT Matriks */
/* NIM/Nama  : 24060121120025/ Annisa Kumala Dewi*/
/* Tanggal   : 12 September 2022 */
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
    printf("\n\n___________________________________\n");
    printf("___________SD-3 MATRIKS ___________\n");
    printf("___________________________________\n");
    
    printf("\n");

    makeMatriks(&A);

    printf("___________PRINT MATRIKS __________\n");
    printMatriks(A);
    
    printf("\n");

    printf("___________VIEW MATRIKS __________\n");
    viewMatriks(A);
    
    printf("\n");

    printf("SET MATRIKS [BARIS & KOLOM]\n");
    printf("Jumlah Baris : ");
    scanf("%d",&NBbar);
    fflush(stdin);
    setNbbar(&A,NBbar);
    printf("Jumlah Kolom : ");
    scanf("%d",&NBkol);
    fflush(stdin);
    setNbkol(&A,NBkol);
    setMatriks(&A,NBbar,NBkol);

	printf("\n");
	
	printf("___________PRINT MATRIKS __________\n");
	printMatriks(A);
	
	printf("\n");
	
	printf("___________VIEW MATRIKS __________\n");
	viewMatriks(A);

	printf("\n");
	
	printf("___________IS EMPTY MATRIKS __________\n");
	printf("Empty Matriks : %s\n",isEmptyMatriks(A)?"True":"False");
	printf("___________IS FULL MATRIKS __________\n");
	printf("Full Matriks : %s\n",isFullMatriks(A)?"True":"False");

	printf("\n");
	
	printf("___________GET NBBARIS MATRIKS __________\n");
	printf("Jumlah Baris Matriks : %d\n",getNbbar(A));
	printf("___________GET NBKOLOM __________\n");
	printf("Jumlah Kolom Matriks : %d\n",getNbkol(A));

	printf("\n");
	
	printf("___________GET INFO CEL MATRIKS __________\n");
	printf("Nilai Cell [2][3] : %d\n",getInfoCell(A,2,3));

	printf("\n");
	
	printf("___________SUM CELL MATRIKS __________\n");
	printf("Sum Cell : %d\n",sumCellMatriks(A));
	printf("___________AVERAGE CELL MATRIKS __________\n");
	printf("Average Cell : %.1f\n",avgCellMatriks(A));

	printf("\n");
	
	printf("___________SEARCH MATRIKS __________\n");
	searchMatriks(A,5);
	
	printf("\n");
	
	printf("___________COUNT A MATRIKS __________\n");
	printf("Kemunculan nilai yang dicari : %d kali\n",countA(A,5));

	printf("\n");
	
	printf("___________MINIMAL CELL MATRIKS __________\n");
	printf("Nilai Cell Min : %d\n",minCellMatriks(A));
	printf("___________MAXIMAL CELL MATRIKS __________\n");
	printf("Nilai Cell Max : %d\n",maxCellMatriks(A));

	printf("\n");
	
	printf("Setelah di Set Info Cell [0][0] dengan 5\n");

	setInfoCell(&A,0,0,5);
	
	printf("___________VIEW MATRIKS [NEW CELL] __________\n");
	viewMatriks(A);
	transpose(&A);
	printf("___________VIEW MATRIKS [TRANSPORE] __________\n");
	viewMatriks(A);

    printf("\n");
    
    printf("SET MATRIKS M1 [BARIS & KOLOM]\n");
    printf("Jumlah Baris : ");
    scanf("%d",&NBbar);
    fflush(stdin);
    setNbbar(&M1,NBbar);
    printf("Jumlah Kolom : ");
    scanf("%d",&NBkol);
    fflush(stdin);
    setNbkol(&M1,NBkol);
    setMatriks(&M1,NBbar,NBkol);

    printf("\n");
    
    printf("SET MATRIKS M2 [BARIS & KOLOM]\n");
    printf("Jumlah Baris : ");
    scanf("%d",&NBbar);
    fflush(stdin);
    setNbbar(&M2,NBbar);
    printf("Jumlah Kolom : ");
    scanf("%d",&NBkol);
    fflush(stdin);
    setNbkol(&M2,NBkol);
    setMatriks(&M2,NBbar,NBkol);

	printf("\n");
	
	printf("___________VIEW MATRIKS __________\n");
	printf("MATRIKS M1\n");
	viewMatriks(M1);
	printf("MATRIKS M2\n");
	viewMatriks(M2);

	printf("\n");
	
	printf("HASIL KALI DARI MATRIKS M1 * M2  : \n");
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
