/*Nama File : Matriks.c*/
/*Deskripsi :file body untuk modul matriks*/
/*Nama      :Zahid Muhammad Mahfudz*/
/*NIM       :24060121130043*/
/*Tanggal   :Selasa, 13 September 2022*/

#include <stdio.h>
#include <stdbool.h>
#include "Matriks.h"

/*KONSTRUKTOR*/

/* procedure makeMatriks(output M:Matriks)*/
/* {I.S: -} */
/* {F.S: M terdefinisi, M.nbbar=0, M.nbkol=0 } */
/* {Proses: menginisialisasi semua cell matriks M dengan -999 } */
void makeMatriks(Matriks *M){
    /*Kamus Lokal*/
    int i;
    int j;
    /*algoritma*/
    M->nbbar = 0;
    M->nbkol = 0;
    for (i=0; i<10; i++){
        for (j=0; j<10; j++){
            (*M).wadah[i][j]=-999;
        }
    }
}

/*SELEKTOR*/

/*function getNbbar(M:Matriks)->integer*/
/*{mengembalikan nilai banyak baris matriks M}*/
int getNbbar(Matriks M){
    /*Kamus Lokal*/

    /*Algoritma*/
    return M.nbbar;
}

/*function getNbbar(M:Matriks)->integer*/
/*{mengembalikan nilai banyak baris matriks M}*/
int getNbkol(Matriks M){
    /*Kamus Lokal*/

    /*Algoritma*/
    return M.nbkol;
}

/*function getInfoCell(M:Matriks,X:integer,Y:integer)->integer*/
/*{mengembalikan nilai/isi elemen baris X, kolom Y, matriks M}*/
int getInfoCell(Matriks M, int X, int Y){
    /*Kamus Lokal*/

    /*Algoritma*/
    return M.wadah[X-1][Y-1];
}

/*MUTATOR*/

/*procedure setNbbar(input/output M:Matriks, input X:integer)*/
/*{I.S.: M,X terdefinisi}*/
/*{F.S.: -}*/
/*{proses: mengisi banyak baris efektif dengan X}*/
void setNbbar(Matriks *M, int X){
    /*Kamus Lokal*/

    /*Algoritma*/
    (*M).nbbar = X;
}

/*procedure setNbkol(input/output M:Matriks, input Y:integer)*/
/*{I.S.: M,Y terdefinisi}*/
/*{F.S.: -}*/
/*{proses: mengisi banyak kolom efektif dengan Y}*/
void setNbkol(Matriks *M, int Y){
   /*Kamus Lokal*/

    /*Algoritma*/
    (*M).nbkol = Y;
}

/*procedure setInfoCell(input/output M:Matriks,
  input X:integer, input Y:integer, input C:integer)*/
/*{I.S.: M,X,Y,C terdefinisi, C=nilai/info pengganti}*/
/*{F.S.: cell (X,Y) berisi C }*/
/*{proses: mengisi cell pada baris X, kolom Y dengan C }*/
void setInfoCell(Matriks *M, int X, int Y, int C){
    /*Kamus Lokal*/

    /*Algoritma*/
    (*M).wadah[X][Y] = C;
}

/*PREDIKAT*/

/*function isEmptyMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M kosong}*/
bool isEmptyMatriks(Matriks M){
    /*Kamus Lokal*/

    /*Algoritma*/
    return M.nbbar == 0 || M.nbkol ==0;
}

/*function isFullMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M penuh}*/
bool isFullMatriks(Matriks M){
    /*Kamus Lokal*/

    /*Algoritma*/
    return M.nbbar == 10 && M.nbkol == 10;
}

/*SUBRUTIN LAIN*/

/*procedure printMatriks(input M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{Proses: mencetak info cell matriks ke layar, termasuk sel kosong}*/
void printMatriks(Matriks M){
    /*Kamus Lokal*/
    int i;
    int j;
    /*Algoritma*/
    for(i=0; i<10; i++){
        for (j=0; j<10; j++){
            printf("%d", (M).wadah[i][j]);
        }
        printf("\n");
    }
}

/*procedure viewMatriks(input M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{Proses: mencetak info cell matriks yang tidak kosong ke layar}*/
void viewMatriks(Matriks M){
    /*Kamus Lokal*/
    int i;
    int j;
    /*Algoritma*/
    if(!isEmptyMatriks(M)){
        for(i=0; i<M.nbbar; i++){
            for(j=0; j<M.nbkol; j++){
                printf("%d", (M).wadah[i][j]);
            }
            printf("\n");
        }
    }
    else{
        printf("Matriks Kosong\n");
    }
}

/*function sumCellMatriks(M:Matriks)->integer*/
/*{mengembalikan jumlah nilai elemen matriks M}*/
int sumCellMatriks(Matriks M){
    /*Kamus Lokal*/
    int sum;
    int i;
    int j;
    /*Algoritma*/
    if(!isEmptyMatriks(M)){
        for(i=0; i<M.nbbar; i++){
            for(j=0; j<M.nbkol; j++){
                sum += M.wadah[i][j];
            }
        }
    }
    return sum;
}

/*function avgCellMatriks(M:Matriks)->real*/
/*{mengembalikan rataan nilai elemen matriks M}*/
float avgCellMatriks(Matriks M){
    /*Kamus Lokal*/

    /*Algoritma*/
    return(!isEmptyMatriks(M)? sumCellMatriks(M)/(M.nbbar*M.nbkol) : '\0');
}

/*function maxCellMatriks(M:Matriks)->integer*/
/*{mengembalikan nilai terbesar elemen matriks M}*/
int maxCellMatriks(Matriks M){
    /*Kamus Lokal*/
    int max;
    int i;
    int j;
    /*Algoritma*/
    max = M.wadah[0][0];
    if(!isEmptyMatriks(M)){
        for(i=0; i<M.nbbar; i++){
            for(j=0; j<M.nbkol; j++){
                if(max<M.wadah[i][j]){
                    max=M.wadah[i][j];
                }
            }
        }
    }
    return max;
}

/*function minCellMatriks(M:Matriks)->integer*/
/*{mengembalikan nilai terkecil elemen matriks M}*/
int minCellMatriks(Matriks M){
    /*Kamus Lokal*/
    int min;
    int i;
    int j;
    /*Algoritma*/
    min = M.wadah[0][0];
    if(!isEmptyMatriks(M)){
        for(i=0; i<M.nbbar; i++){
            for(j=0; j<M.nbkol; j++){
                if(min>M.wadah[i][j]){
                    min=M.wadah[i][j];
                }
            }
        }
    }
    return min;
}

/*function countA(M:Matriks,A:integer)->integer*/
/*{mengembalikan banyak elemen bernilai A dalam matriks M}*/
int countA(Matriks M, int A){
    /*Kamus Lokal*/
    int count;
    int i;
    int j;
    /*Algoritma*/
    if(!isEmptyMatriks(M)){
        for(i=0; i<M.nbbar; i++){
            for(j=0; j<M.nbkol; j++){
                if(M.wadah[i][j]==A){
                    count++;
                }
            }
        }
    }
    return count;
}

/*procedure searchMatriks(input M:Matriks, input A:integer,
output X:integer, output Y:integer)*/
/*{I.S.: M,A terdefinisi, A=nilai/info cell yang dicari}*/
/*{F.S.: X=indeks baris, Y=indeks kolom, tempat ditemukannya A}*/
/*{proses: mencari nilai A dalam cell matriks M}*/
/*{bila tidak ketemu, X=Y=-999}*/
void searchMatriks(Matriks M, int A){
    /*Kamus Lokal*/
    int i;
    int j;
    /*Algoritma*/
    int X=-999, Y=-999;
    if(!isEmptyMatriks(M)){
        for(i=0; i<M.nbbar; i++){
            for(j=0; j<M.nbkol; j++){
                if(M.wadah[i][j]==A){
                    X=i+1;
                    Y=j+1;
                }
            }
        }
    }
    printf("Nilai %d ada dibaris ke-%d kolom ke-%d\n", A,X,Y);
}

/*procedure transpose(input/output M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{proses: mengubah susunan cell matriks,
baris menjadi kolom dan sebaliknya}*/
/*{misal: M=[1,2] menjadi [1,4]
____________[4,5]         [2,5] }*/
void transpose(Matriks *M){
    /*Kamus Lokal*/
    int i;
    int j;
    int buffer;
    /*Algoritma*/
        for(i=0; i<(*M).nbbar; i++){
            for(j=0; j<(*M).nbkol; j++){
                buffer = M->wadah[i][j];
                M->wadah[i][j] = M->wadah[j][i];
                M->wadah[j][i] = buffer;
            }
        }
        buffer = M->nbbar;
        M->nbbar = M->nbkol;
        M->nbkol = buffer;

}

/*procedure setMatriks(input/output M:Matriks,
  input X:integer, input Y:integer)*/
/*{I.S.: M,X,Y, terdefinisi}*/
/*{F.S.: M terdefinisi, M.nbbar=X, M.nbkol=Y }*/
/*{proses: membuat matriks dengan baris dan kolom efektif yang diinputkan }*/
void setMatriks(Matriks *M, int X, int Y){
    /*Kamus Lokal*/
    int i;
    int j;
    /*Algoritma*/
    for(i=0; i<X; i++){
        for(j=0; j<Y; j++){
            printf("Matriks [%d][%d] : ", i,j);
            scanf("%d", &M->wadah[i][j]);
            fflush(stdin);
        }
    }
}

/* 
========================================================================
========================= TUGAS Submission 1 ===========================
========================================================================
*/

/*function MulMatriks(M1:Matriks,M2:Matriks)->Matriks*/
/*{proses: Mengirim hasil perkalian matriks: salinan M1 * M2 }*/
Matriks MulMatriks (Matriks M1, Matriks M2){
    /*Kamus Lokal*/
    int i,j,k;
    int Temp;
    Matriks Mul;
    /*Algoritma*/
    makeMatriks(&Mul);
    if(M1.nbbar != M2.nbkol){
        printf("Kolom M1 tidak sama dengan baris M2\n");
    }
    else{
        setNbbar(&Mul, getNbbar(M1));
        setNbkol(&Mul, getNbkol(M2));
        for(i=0; i< getNbbar(Mul); i++){
            for(j=0; j<getNbkol(M2); j++){
                Temp = 0;
                for(k=0; k<getNbkol(M1); k++)
                    Temp += getInfoCell(M1,i,k)*getInfoCell(M2,k,j);
                setInfoCell(&Mul,i,j,Temp);
            }
        }
    }
    return Mul;
}

/*function isEqualMatriks(input M1:Matriks,M2:Matriks)->boolean*/
/*{proses: Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 }*/
bool isEqualMatriks (Matriks M1, Matriks M2){
    /*Kamus Lokal*/
    
    /*Algoritma*/
    if (M1.nbbar == M2.nbbar && M1.nbkol == M2.nbkol){
        printf("Benar");
    }
    else{
        printf("salah");
    }
}

/*function IsSquareMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M adalah matriks dg ukuran baris dan kolom sama}*/
bool IsSquareMatriks (Matriks M){
    /*Kamus Lokal*/

    /*Algoritma*/
    if (M.nbbar == M.nbkol){
        printf("Benar");
    }
    else{
        printf("salah");
    }
}

/*function DeterminanMatriks(M:Matriks)->float*/
/*{proses: Menghitung nilai determinan M}*/
float DeterminanMatriks (Matriks M){
    /*Kamus Lokal*/
    int Dt2;
    int Dt3;
    /*Algoritma*/
    if (M.nbbar == 2 && M.nbkol == 2){
        Dt2 = (M.wadah[0][0]*M.wadah[1][1])-(M.wadah[0][1]*M.wadah[1][0]) ;
        return Dt2;
    }
    else if (M.nbbar == 3 && M.nbkol == 3){
        Dt3 = (((M.wadah[0][0]*M.wadah[1][1]*M.wadah[2][2])+(M.wadah[0][1]*M.wadah[1][2]*M.wadah[2][0])+(M.wadah[0][2]*M.wadah[1][0]*M.wadah[2][1]))-((M.wadah[2][0]*M.wadah[1][1]*M.wadah[0][2])+(M.wadah[2][1]*M.wadah[1][2]*M.wadah[0][0])+(M.wadah[2][2]*M.wadah[1][0]*M.wadah[0][1])));
        return Dt3;
    }
    else if (M.nbbar != 2 && M.nbkol != 2 || M.nbbar != 3 && M.nbkol != 3){
        printf("Matriks Harus square!!");
    }
}

/*function IsSatuanMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M adalah matriks satuan 
dg setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0}*/
bool IsSatuanMatriks (Matriks M){
    /*Kamus Lokal*/

    /*Algoritma*/
    if (M.nbbar == 2 && M.nbkol ==2){
        if (M.wadah[0][0] == 1 && M.wadah[1][1] == 1 || M.wadah[0][1] == 1 && M.wadah[1][0] == 1){
            printf("Benar");
        }
        else{
            printf("salah");
        }    
    }
    else if (M.nbbar == 3 && M.nbkol == 3){
        if (M.wadah[0][0] == 1 && M.wadah[1][1] == 1 && M.wadah[2][2] == 1 || M.wadah[2][0] == 1 && M.wadah[1][1] == 1 && M.wadah[0][2] == 1){
            printf("benar");
        }
        else{
        printf("salah");
        }
    }
    else{
        printf("Matriks harus square!!");
    }
}

/*function IsSparseMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M adalah matriks sparse: matriks “jarang” dengan definisi: 
hanya maksimal 5% dari element matriks yang efektif bukan bernilai kosong(-999)}*/
bool IsSparseMatriks (Matriks M){
    /*Kamus Lokal*/
    int i, j;
    int count;
    int persen;
    /*Algoritma*/
    persen = (5/100)*(M.nbbar*M.nbkol);
    for(i=0; i<M.nbbar; i++){
        for(j=0; j<M.nbkol; j++){
            if(M.wadah[i][j] != 0 ){
                printf("salah");
            }
            else{
                printf("benar");
            }
        }
    }
    //algoritma hanya benar jika nbbar dan nbkol < 3
}

