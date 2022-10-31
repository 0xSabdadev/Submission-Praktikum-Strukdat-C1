/* Program   : matriks.c */
/* Deskripsi : realisasi body file modul ADT Matriks */
/* NIM/Nama  : 24060121130047/Benjamin Sipayung*/
/* Tanggal   : 17 September 2022*/
/***********************************/
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
	int nilai[11][11];
	int baris;
	int colom;
}matriks;

bool isEqualMatriks(matriks M1,matriks M2){
	if (M1.baris == M2.baris && M1.colom == M2.colom){
		return true;
	}
	else{
		return false;
	}
}

bool isSquareMatriks(matriks M){
	if (M.colom == M.baris){
		return true;
	}
	else{
		return false;
	}
}

float DeterminanMatriks(matriks M){
	int i,j;
	matriks temp;
	temp = M;
	int cur_colom=0;
	int cur_baris=0;
	int temp_calc, determinan;
	int plus,negative;
	if (isSquareMatriks(M) == true){
		temp.colom = M.colom +2;
		for (i=0; i<M.baris;i++){
			for (j=0;j<M.colom-1;j++){
				temp.nilai[i][j+M.colom+1] = M.nilai[i][j];
			}
		}
		for (i=0; i<M.colom;i++){
			cur_baris=0;
			cur_colom = i;
			for (j=0; j<M.baris;j++){
				temp_calc *= temp.nilai[cur_baris+j][cur_colom+j];
			}
			plus += temp_calc;
		}
		
		cur_colom = M.colom;
		for (i=0; i<M.colom;i++){
			cur_baris=0;			
			for (j=0; j<M.baris;j++){
				temp_calc *= temp.nilai[cur_baris+j][cur_colom-j];
			}
			negative += temp_calc;
			cur_colom++;
		}
		
		determinan = plus - negative;
		return determinan;
	}
	else{
		printf ("Determinan tidak bisa dicari, karena matriks Anda tidak matriks persegi");
	}
}

bool isSatuanMatriks (matriks M){
	int i,j;
	for (i=0;i<M.baris;i++){
		for (j=0;j<M.colom;j++){
			if (i == j && M.nilai[i][j] != 1){
				return false;
				break;
			}else if (i != j && M.nilai[i][j] != 0){
				return false;
				break;
			}
		}
	}
	return true;
}

bool isSparseMatriks (matriks M){
	int i,j,count=0;
	int element,final;
	element = M.baris*M.colom;
	for (i=0;i<M.baris;i++){
		for (j=0;j<M.colom;j++){			
			if(M.nilai[i][j] !=0 ){
				count++;
			}
		}
	}
	final = count/element *100;
	if (final <5){
		return true;
	}
	else{
		return false;
	}
}
