/* Program   : matriks.c */
/* Deskripsi : realisasi body file modul ADT Matriks */
/* NIM/Nama  : 24060121120025/ Annisa Kumala Dewi*/
/* Tanggal   : 12 September 2022 */
/***********************************/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "matriks.h"

/*******KONSTRUKTOR********/
/* procedure makeMatriks(output M:Matriks)*/
/* {I.S: -} */
/* {F.S: M terdefinisi, M.nbbar=0, M.nbkol=0 } */
/* {Proses: menginisialisasi semua cell matriks M dengan -999 } */
void makeMatriks(Matriks *M)
{

    // algoritma
    (*M).nbbar=0;
    (*M).nbkol=0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            (*M).wadah[i][j] = -999;
        }
    }
}


/*DESTRUKTOR tidak perlu*/


/**********SELEKTOR*********/
/*function getNbbar(M:Matriks)->integer*/
/*{mengembalikan nilai banyak baris matriks M}*/
int getNbbar(Matriks M)
{
    // algoritma
    return M.nbbar;
}

/*function getNbbar(M:Matriks)->integer*/
/*{mengembalikan nilai banyak baris matriks M}*/
int getNbkol(Matriks M)
{
    // algoritma
    return M.nbkol;
}

/*function getInfoCell(M:Matriks,X:integer,Y:integer)->integer*/
/*{mengembalikan nilai/isi elemen baris X, kolom Y, matriks M}*/
int getInfoCell(Matriks M, int X, int Y)
{
    return M.wadah[X-1][Y-1];
}


/*********MUTATOR*********/
/*procedure setNbbar(input/output M:Matriks, input X:integer)*/
/*{I.S.: M,X terdefinisi}*/
/*{F.S.: -}*/
/*{proses: mengisi banyak baris efektif dengan X}*/
void setNbbar(Matriks *M, int X)
{
    // algoritma
    (*M).nbbar=X;
}

/*procedure setNbkol(input/output M:Matriks, input Y:integer)*/
/*{I.S.: M,Y terdefinisi}*/
/*{F.S.: -}*/
/*{proses: mengisi banyak kolom efektif dengan Y}*/
void setNbkol(Matriks *M, int Y)
{
    // algoritma
    (*M).nbkol=Y;
}

/*procedure setInfoCell(input/output M:Matriks,
  input X:integer, input Y:integer, input C:integer)*/
/*{I.S.: M,X,Y,C terdefinisi, C=nilai/info pengganti}*/
/*{F.S.: cell (X,Y) berisi C }*/
/*{proses: mengisi cell pada baris X, kolom Y dengan C }*/
void setInfoCell(Matriks *M, int X, int Y, int C)
{
    // algoritma
    (*M).wadah[X][Y] = C;
}


/*********PREDIKAT*/
/*function isEmptyMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M kosong}*/
bool isEmptyMatriks(Matriks M)
{
    // algoritma
    return M.nbbar == 0 || M.nbkol == 0;

}

/*function isFullMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M penuh}*/
bool isFullMatriks(Matriks M)
{
    // algoritma
    return M.nbbar == 10 && M.nbkol == 10;
}


/*********SUBRUTIN LAIN*/
/*procedure printMatriks(input M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{Proses: mencetak info cell matriks ke layar, termasuk sel kosong}*/
void printMatriks(Matriks M)
{
    // algoritma
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", (M).wadah[i][j]);
        }
        printf("\n");
    }
}

/*procedure viewMatriks(input M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{Proses: mencetak info cell matriks yang tidak kosong ke layar}*/
void viewMatriks(Matriks M)
{
    // algoritma
    if(!isEmptyMatriks(M))
    {
       for (int i = 0; i < M.nbbar; i++)
       {
            for (int j = 0; j < M.nbkol; j++)
            {
                printf("%d ", (M).wadah[i][j]);
            }
        printf("\n");
        }
    }
    else
    {
        printf("Matriks masih kosong \n");
    }
}

/*function sumCellMatriks(M:Matriks)->integer*/
/*{mengembalikan jumlah nilai elemen matriks M}*/
int sumCellMatriks(Matriks M)
{
    //kamus lokal
    int sum;

    // algoritma
    if(!isEmptyMatriks(M))
    {
        for (int i = 0; i < M.nbbar; i++)
        {
            for (int j = 0; j < M.nbkol; j++)
            {
                sum += (M).wadah[i][j];
            }
        }
    }
    return sum;
}

/*function avgCellMatriks(M:Matriks)->real*/
/*{mengembalikan rataan nilai elemen matriks M}*/
float avgCellMatriks(Matriks M)
{
    // algoritma
    return ( !isEmptyMatriks(M) ? (sumCellMatriks(M) / (M.nbbar * M.nbkol)) : '\0' );
}

/*function maxCellMatriks(M:Matriks)->integer*/
/*{mengembalikan nilai terbesar elemen matriks M}*/
int maxCellMatriks(Matriks M)
{
    // kamus lokal
    int max = M.wadah[0][0];

    // algoritma
    if(!isEmptyMatriks(M))
    {
        for (int i = 0; i < M.nbbar; i++)
        {
            for (int j = 0; j < M.nbkol; j++)
            {
                if(max<M.wadah[i][j])
                {
                    max = M.wadah[i][j];
                }
            }
        }
    }
    return max;
}

/*function minCellMatriks(M:Matriks)->integer*/
/*{mengembalikan nilai terkecil elemen matriks M}*/
int minCellMatriks(Matriks M)
{
    // kamus lokal
    int min = M.wadah[0][0];

    // algoritma
    if(!isEmptyMatriks(M))
    {
        for (int i = 0; i < M.nbbar; i++)
        {
            for (int j = 0; j < M.nbkol; j++)
            {
                if(min>M.wadah[i][j])
                {
                    min = M.wadah[i][j];
                }
            }
        }
    }
    return min;
}

/*function countA(M:Matriks,A:integer)->integer*/
/*{mengembalikan banyak elemen bernilai A dalam matriks M}*/
int countA(Matriks M, int A)
{
    // kamus lokal
    int count = 0;

    // algoritma
    if(!isEmptyMatriks(M))
    {
        for (int i = 0; i < M.nbbar; i++)
        {
            for (int j = 0; j < M.nbkol; j++)
            {
                if(M.wadah[i][j] == A)
                {
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
void searchMatriks(Matriks M, int A)
{
    // kamus lokal
    int X = -999, Y = -999;

    // algoritma
    if(!isEmptyMatriks(M))
    {
        for (int i = 0; i < M.nbbar; i++)
        {
            for (int j = 0; j < M.nbkol; j++)
            {
                if(M.wadah[i][j] == A)
                {
                    X=i+1;
                    Y=j+1;
                }
            }
        }
    }
    printf("Nilai %d ada di baris ke %d dan kolom ke %d",A,X,Y);
}

/*procedure transpose(input/output M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{proses: mengubah susunan cell matriks,
baris menjadi kolom dan sebaliknya}*/
/*{misal: M=[1,2] menjadi [1,4]
____________[4,5]         [2,5] }*/
void transpose(Matriks *M)
{
    // algoritma
    if(!isEmptyMatriks(*M))
    {
        for (int i = 0; i < (*M).nbbar; i++)
        {
            for (int j = i+1; j < (*M).nbkol; j++)
            {
                int buffer = M->wadah[i][j];
				M->wadah[i][j] = M->wadah[j][i];
				M->wadah[j][i] = buffer;
            }
        }
        int buffer = M->nbbar;
		M->nbbar = M->nbkol;
		M->nbkol = buffer;
    }
}

/*procedure setMatriks(input/output M:Matriks,
  input X:integer, input Y:integer)*/
/*{I.S.: M,X,Y, terdefinisi}*/
/*{F.S.: M terdefinisi, M.nbbar=X, M.nbkol=Y }*/
/*{proses: membuat matriks dengan baris dan kolom efektif yang diinputkan }*/
void setMatriks(Matriks *M, int X, int Y)
{
    // kamus lokal
    int valBar, valKol;

    // algoritma
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            printf("Matriks [%d] [%d] : ",i,j);
            scanf("%d",&M->wadah[i][j]);
            fflush(stdin);
        }
    }
}


// TUGAS SD03


/*function MulMatriks(M1:Matriks,M2:Matriks)->Matriks*/
/*{proses: Mengirim hasil perkalian matriks: salinan M1 * M2 }*/
Matriks MulMatriks (Matriks M1, Matriks M2)
{
    // kamus lokal
    int mul[M1.nbbar][M2.nbkol];

    // algoritma
    for(int i=0;i<M1.nbbar;i++)
    {
        for(int j=0;j<M2.nbkol;j++)
        {
            mul[i][j]=0;
            for(int k=0;k<M1.nbbar;k++)
            {
                mul[i][j]+=M1.wadah[i][k]*M2.wadah[k][j];
            }
        }
    }
    for(int i=0;i<M1.nbbar;i++)
    {
        for(int j=0;j<M2.nbkol;j++)
        {
            printf("%d\t",mul[i][j]);
        }
        printf("\n");
    }
}

/*function isEqualMatriks(input M1:Matriks,M2:Matriks)->boolean*/
/*{proses: Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 }*/
bool isEqualMatriks (Matriks M1, Matriks M2)
{
    // algoritma
    return M1.nbbar == M2.nbbar && M1.nbkol == M2.nbkol;
}

/*function IsSquareMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M adalah matriks dg ukuran baris dan kolom sama}*/
bool IsSquareMatriks (Matriks M)
{
    // algoritma
    return M.nbkol == M.nbbar;
}

/*function DeterminanMatriks(M:Matriks)->float*/
/*{proses: Menghitung nilai determinan M}*/
float DeterminanMatriks (Matriks M)
{
    // kamus lokal
    float a[11][11];
    float ratio, det = 1;
    int i,j,k,n=M.nbbar; // n = orde { n x n }

    // algoritma
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j] = M.wadah[i][j];
        }
    }

    for(i=0;i<n;i++)
    {
        if(isEmptyMatriks(M) || !IsSquareMatriks(M))
        {
            printf("Error!");
        }
        for(j=i+1;j<n;j++)
        {
            ratio = a[j][i]/a[i][i];
            for(k=0;k< n;k++)
            {
                a[j][k] = a[j][k] - ratio*a[i][k];
            }
        }
    }
    for(i=0;i<n;i++)
    {
        det = det * a[i][i];
    }
    return det;
}

/*function IsSatuanMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M adalah matriks satuan
dg setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0}*/
bool IsSatuanMatriks (Matriks M)
{
    // kamus lokal
    int temp = 0;
    int i,j;

    // algoritma
    for (i = 0; i < M.nbbar; i++)
    {
		for (j = 0; j < M.nbkol; j++)
		{
			if (i == j && M.wadah[i][j] != 1)
			{
				temp = -1;
				break;
			}
			else if (i != j && M.wadah[i][j] != 0)
			{
				temp = -1;
				break;
			}
		}
	}

	if (temp == 0)
    {
		return true;
	}
	else
	{
		return false;
	}
}

/*function IsSparseMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M adalah matriks sparse: matriks jarang dengan definisi:
hanya maksimal 5% dari element matriks yang efektif bukan bernilai kosong(-999)}*/
bool IsSparseMatriks (Matriks M)
{
    // kamus lokal
    int count;
    int i,j;

    // algoritma
    for(i = 0; i < M.nbbar; i++)
    {
      for(j = 0; j < M.nbkol; j++)
      {
         if(M.wadah[i][j] == 0)
         {
            count++;
         }
      }
   }
   if(count > ((M.nbbar * M.nbkol)/2))
   {
      return true;
   }
   else
   {
      return false;
   }
}
