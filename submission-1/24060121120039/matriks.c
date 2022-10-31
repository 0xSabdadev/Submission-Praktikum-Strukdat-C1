/* Program   : matriks.c */
/* Deskripsi : realisasi body file modul ADT Matriks */
/* NIM/Nama  : 24060121120039/ Nida' Naafilatul Haniifah*/
/* Tanggal   : */
/***********************************/
#ifndef   matriks_c
#define   matriks_c
#include <stdio.h>
#include "matriks.h"

/*salin dan tempel SEBUAH definisi dan spesifikasi fungsi/prosedur*/
/*ganti ";" dengan "{}" lalu masuk ke dalam kurung, tekan enter*/
/*khusus fungsi: tambahkan return value sebelum tanda "}" */
/*pastikan siklus compile-build-run setiap satu fungsi/prosedur selesai*/

/*KONSTRUKTOR*/
/* procedure makeMatriks(output M:Matriks)*/
/* {I.S: -} */
/* {F.S: M terdefinisi, M.nbbar=0, M.nbkol=0 } */
/* {Proses: menginisialisasi semua cell matriks M dengan -999 } */
void makeMatriks(Matriks *M){
    /*Kamus Lokal*/
    int j;
    int i;


    /*Algoritma*/
    (*M).nbbar = 0;
    (*M).nbkol = 0;
    for (i = 1; i <= 10; i++){
        for (j = 1; j <= 10; j++){
            (*M).wadah[i][j] = -999;
        }
    }
}

/**********SELEKTOR*/
/*function getNbbar(M:Matriks)->integer*/
/*{mengembalikan nilai banyak baris matriks M}*/
int getNbbar(Matriks M){
    /*Kamus Lokal*/
    int hasil;

    /*Algoritma*/
    hasil = M.nbbar;
    return hasil;
}


/*function getNbbar(M:Matriks)->integer*/
/*{mengembalikan nilai banyak baris matriks M}*/
int getNbkol(Matriks M){
    /*Kamus Lokal*/
    int hasil;

    /*Algoritma*/
    hasil = M.nbkol;
    return hasil;
}


/*function getInfoCell(M:Matriks,X:integer,Y:integer)->integer*/
/*{mengembalikan nilai/isi elemen baris X, kolom Y, matriks M}*/
int getInfoCell(Matriks M, int X, int Y){
    /*Kamus Lokal*/
    int hasil;

    /*Algoritma*/
    hasil = M.wadah[X][Y];

    return hasil;
}

/*********MUTATOR*/
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

/*********PREDIKAT*/
/*function isEmptyMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M kosong}*/
boolean isEmptyMatriks(Matriks M){
    /*Kamus Lokal*/
    boolean hasil;

    /*Algoritma*/
    hasil = (M.nbbar == 0 && M.nbkol == 0);
    return hasil;
}

/*function isFullMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M penuh}*/
boolean isFullMatriks(Matriks M){
    /*Kamus Lokal*/
    boolean hasil;

    /*Algoritma*/
    hasil = (M.nbbar == 10 && M.nbkol == 10);
    return hasil;
}

/*********SUBRUTIN LAIN*/
/*procedure printMatriks(input M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{Proses: mencetak info cell matriks ke layar, termasuk sel kosong}*/
void printMatriks(Matriks M){
    /*Kamus Lokal*/
    int i;
    int j;


    /*Algoritma*/
    for(i = 1; i <= 10; i++){
        for(j = 1; j <= 10; j++){
            printf("%d\t", M.wadah[i][j]);
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
    if(isEmptyMatriks(M)){
        printf("Matriks Kosong");
    }else{
        for(i = 1; i <= M.nbbar; i++){
            for(j = 1; j <= M.nbkol; j++){
                printf("%d\t", M.wadah[i][j]);
            }
            printf("\n");
        }
    }
}

/*function sumCellMatriks(M:Matriks)->integer*/
/*{mengembalikan jumlah nilai elemen matriks M}*/
int sumCellMatriks(Matriks M){
    /*Kamus Lokal*/
    int i;
    int j;
    int sum;


    /*Algoritma*/
    sum = 0;
    if (!isEmptyMatriks(M)){
        for (i = 1; i <= M.nbbar; i++){
            for(j = 1; j <= M.nbkol; j++){
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
    int i;
    int j;
    float sum;
    int count;
    float average;


    /*Algoritma*/
    sum = 0;
    count = 0;
    if (!isEmptyMatriks(M)){
        for (i = 1; i <= M.nbbar; i++){
            for(j = 1; j <= M.nbkol; j++){
                sum += M.wadah[i][j];
                count += 1;
            }
        }
        average = sum / count;
    } else{
        average = '\0';
    }
    return average;
}


/*function maxCellMatriks(M:Matriks)->integer*/
/*{mengembalikan nilai terbesar elemen matriks M}*/
int maxCellMatriks(Matriks M){
    /*Kamus Lokal*/
    int i;
    int j;
    int max;

    /*Algoritma*/
    max = M.wadah[1][1];
    if(!isEmptyMatriks(M)){
        for(i = 1; i <= M.nbbar; i++){
            for(j = 1; j <= M.nbkol; j++){
                if(M.wadah[i][j] > max){
                    max = M.wadah[i][j];
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
    int i;
    int j;
    int min;

    /*Algoritma*/
    min = M.wadah[1][1];
    if(!isEmptyMatriks(M)){
        for(i = 1; i <= M.nbbar; i++){
            for(j = 1; j <= M.nbkol; j++){
                if(M.wadah[i][j] < min){
                    min = M.wadah[i][j];
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
    int i;
    int j;
    int count;

    /*Algorima*/
    count = 0;
    if(!isEmptyMatriks(M)){
        for(i = 1; i <= M.nbbar; i++){
            for(j = 1; j <= M.nbkol; j++){
                if(M.wadah[i][j] == A){
                    count += 1;
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
void searchMatriks(Matriks M, int A, int *X, int *Y){
    /*Kamus Lokal*/
    int i;
    int j;
    (*X) = -999;
    (*Y) = -999;

    /*Algoritma*/
    i = 1;
    j = 1;
    if(!isEmptyMatriks(M)){
        if(M.wadah[i][j] == A){
                (*X) = i;
                (*Y) = j;
        }else {
            while (M.wadah[i][j] != A && i <= M.nbbar){
                while(M.wadah[i][j] != A && j < M.nbkol){
                    j++;
                }
                if(M.wadah[i][j] == A){
                    (*X) = i;
                    (*Y) = j;
                }else{
                    j = 1;
                    i++;
                }
            }
            if(M.wadah[i][j] == A){
                    (*X) = i;
                    (*Y) = j;
            }
        }
    }
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
    int temp;
    int transpose[11][11];

    /*Algoritma*/
    if (!isEmptyMatriks(*M)){
        for (i = 1; i <= (*M).nbbar; i++){
            for(j = 1; j <= (*M).nbkol; j++){
                transpose[i][j] = (*M).wadah[j][i];
            }
        }
        for (i = 1; i <= (*M).nbbar; i++){
            for(j = 1; j <= (*M).nbkol; j++){
                (*M).wadah[i][j]=transpose[i][j];
            }
        }
    }
    temp = (*M).nbbar;
    (*M).nbbar = (*M).nbkol;
    (*M).nbkol = temp;
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
    setNbbar(M, X);
    setNbkol(M, Y);

    for (i = 1; i <= (*M).nbbar ; i++){
        for(j = 1; j <= (*M).nbkol; j++){
            printf("Matriks [%d][%d]: ", i, j);
            scanf("%d", &(*M).wadah[i][j]);
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
    int i;
    int j;
    int k;
    Matriks C;

    /*Algoritma*/
    if(M1.nbkol != M2.nbbar){
        printf("Tidak dapat dilakukan perkalian karena tidak memenuhi syarat\n");
        printf("Syarat perkalian matriks : jumlah kolom pada Matriks A harus sama dengan jumlah baris pada Matriks B");
    }else{
        C.nbbar = M1.nbbar;
        C.nbkol = M2.nbkol;
        for(i = 1; i <= C.nbbar; i++){
            for(j = 1; j <= C.nbkol; j++){
                C.wadah[i][j] = 0;
                for (k = 1; k <= M1.nbkol; k++){
                    C.wadah[i][j] += (M1.wadah[i][k] * M2.wadah[k][j]);
                }
            }
        }
        return C;

    }

}

/*function isEqualMatriks(input M1:Matriks,M2:Matriks)->boolean*/
/*{proses: Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 }*/
boolean isEqualMatriks (Matriks M1, Matriks M2){
    /*Kamus Lokal*/
    boolean hasil;

    /*Algoritma*/
    hasil = ((M1.nbbar == M2.nbbar) && (M1.nbkol == M2.nbkol));
    return hasil;
}

/*function IsSquareMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M adalah matriks dg ukuran baris dan kolom sama}*/
boolean IsSquareMatriks (Matriks M){
    /*Kamus Lokal*/
    boolean hasil;

    /*Algoritma*/
    hasil = false;
    if(!isEmptyMatriks(M)){
        hasil = (M.nbbar == M.nbkol);
    }
    return hasil;
}

/*function DeterminanMatriks(M:Matriks)->float*/
/*{proses: Menghitung nilai determinan M}*/
float DeterminanMatriks (Matriks M){
    /*Kamus Lokal*/
    int i;
    int j;
    int k;
    float hasil;
    int mul;
    Matriks T;


    /*Algoritma*/
    hasil = 0;
    mul = 1;
    int iAwal;
    int jAwal;
    if(IsSquareMatriks(M)){
        if(M.nbbar == 2 && M.nbkol == 2){
            hasil = (M.wadah[1][1]*M.wadah[2][2]) - (M.wadah[1][2]*M.wadah[2][1]);
        }else if(M.nbbar == 3 && M.nbkol == 3){
            hasil = M.wadah[1][1]*M.wadah[2][2]*M.wadah[3][3]+ M.wadah[1][2]*M.wadah[2][3]*M.wadah[3][1] + M.wadah[1][3]*M.wadah[2][1]*M.wadah[3][2] - M.wadah[1][3]*M.wadah[2][2]*M.wadah[3][1] - M.wadah[1][1]*M.wadah[2][3]*M.wadah[3][2] - M.wadah[1][2]*M.wadah[2][1]*M.wadah[3][3];
        }else{
            printf("Tidak dapat menentukan determianan matriks pada orde lebih dari 3 x 3");
        }

    }

    return hasil;
}


/*function IsSatuanMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M adalah matriks satuan
dg setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0}*/
boolean IsSatuanMatriks (Matriks M){
    /*Kamus Lokal*/
    int i;
    int j;
    boolean hasil;

    /*Algoritma*/
    hasil = true;
    if(!isEmptyMatriks(M) && IsSquareMatriks(M)){
        for(i = 1; i <= M.nbbar; i++){
            for(j = 1; j <= M.nbkol; j++){
                if(i == j && M.wadah[i][j] != 1){
                    hasil = false;
                }else if(i != j && M.wadah[i][j] != 0){
                    hasil = false;
                }
            }
        }
    }else{
        hasil = false;
    }
    return hasil;
}

/*function IsSparseMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M adalah matriks sparse: matriks “jarang” dengan definisi:
hanya maksimal 5% dari element matriks yang efektif bukan bernilai kosong(-999)}*/
boolean IsSparseMatriks (Matriks M){
    /*Kamus Lokal*/
    int i;
    int j;
    int tidakKosong;
    int limaPersen;
    boolean hasil;

    /*Algoritma*/
    tidakKosong = 0;
    hasil = false;
    if(!isEmptyMatriks(M)){
        for (i = 1; i <= M.nbbar; i++){
            for(j = 1; j <= M.nbkol; j++){
                if(M.wadah[i][j] != -999){
                    tidakKosong++;
                }
            }

        }
    }
    limaPersen = ((5*M.nbbar*M.nbkol)/100);
    if (tidakKosong <= limaPersen){
        hasil = true;
    }
    return hasil;
}
#endif

