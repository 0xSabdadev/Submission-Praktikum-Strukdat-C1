/* Program   : matriks.c */
/* Deskripsi : realisasi body file modul ADT Matriks */
/* NIM/Nama  : 24060121130090/Dorino Baharson */
/* Tanggal   : 18 September 2022 */
/***********************************/

#include <stdio.h>
#include <stdbool.h>
#include "matriks.h"

void makeMatriks(Matriks *M)
{
	(*M).nbbar = 0;
	M->nbkol = 0;
	for (int i = 0; i < 10; i++)
	{
		for(int j=0;j<10;j++)
        {
			(*M).wadah[i][j] = -999;
		}
	}
}
void printMatriks(Matriks M)
{
	for (int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
        {
			printf("%d ",(M).wadah[i][j]);
		}
		printf("\n");
	}
}
void viewMatriks(Matriks M)
{
	if(!isEmptyMatriks(M))
    {
		for (int i = 0; i < M.nbbar; i++)
		{
			for(int j = 0; j < M.nbkol; j++)
            {
				printf("%d ",(M).wadah[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("Matriks Kosong!\n");
	}
}
int getNbbar(Matriks M)
{
	return M.nbbar;
}
int getNbkol(Matriks M)
{
	return M.nbkol;
}
int getInfoCell(Matriks M, int X, int Y)
{
	return M.wadah[X-1][Y-1];
}
void setNbbar(Matriks *M, int X)
{
	M->nbbar = X;
}
void setNbkol(Matriks *M, int Y)
{
	M->nbkol = Y;
}
void setInfoCell(Matriks *M, int X, int Y, int C)
{
	M->wadah[X][Y] = C;
}
bool isEmptyMatriks(Matriks M)
{
	return M.nbbar == 0 || M.nbkol == 0;
}
bool isFullMatriks(Matriks M)
{
	return M.nbbar == 10 && M.nbkol == 10;
}
int sumCellMatriks(Matriks M)
{
	int sum;
	if(!isEmptyMatriks(M))
    {
		for (int i = 0; i < M.nbbar ; i++)
		{
			for(int j = 0; j < M.nbkol; j++)
			{
				sum += M.wadah[i][j];
			}
		}
	}
	return sum;
}
float avgCellMatriks(Matriks M)
{
	return (!isEmptyMatriks(M)?sumCellMatriks(M)/(M.nbbar*M.nbkol) : '\0');
}
int maxCellMatriks(Matriks M)
{
	int max = M.wadah[0][0];
	if(!isEmptyMatriks(M))
    {
		for (int i = 0; i < M.nbbar; i++)
		{
			for(int j = 0; j < M.nbkol; j++)
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
int minCellMatriks(Matriks M)
{
	int min = M.wadah[0][0];
	if(!isEmptyMatriks(M))
        {
		for (int i = 0; i < M.nbbar; i++)
		{
			for(int j = 0; j < M.nbkol; j++)
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
int countA(Matriks M, int A)
{
	int count;
	if(!isEmptyMatriks(M))
    {
		for (int i = 0; i < M.nbbar; i++)
		{
			for(int j = 0; j < M.nbkol; j++)
			{
				if(M.wadah[i][j]==A)
				{
					count++;
				}
			}
		}
	}
	return count;
}
void searchMatriks(Matriks M, int A)
{
	int X=-999,Y=-999;
	if(!isEmptyMatriks(M))
    {
		for (int i = 0; i < M.nbbar; i++)
		{
			for(int j = 0; j < M.nbkol; j++)
			{
				if(M.wadah[i][j]==A)
				{
					X=i+1;
					Y=j+1;
				}
			}
		}

	}
	printf("Nilai %d ada di baris ke- %d kolom ke- %d\n",A,X,Y);
}
void transpose(Matriks *M)
{
	if(!isEmptyMatriks(*M))
    {
		for( int i = 0; i < M->nbbar; i++)
		{
			for ( int j = i+1; j < M->nbkol; j++ )
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

void setMatriks(Matriks *M, int X, int Y)
{
	int valBar, valKol;
	for (int i = 0; i < X; i++)
	{
		for(int j = 0; j < Y; j++)
        {
			printf("Matriks [%d][%d] : ",i,j);
			scanf("%d",&M->wadah[i][j]);
			fflush(stdin);
		}
	}
}

///////////////////////////////////////
/* Tugas 1 Praktikum Strukdat Lab C1 */
//////////////////////////////////////

Matriks MulMatriks (Matriks M1, Matriks M2)
{
 int mul[M1.nbbar][M2.nbkol];
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

bool isEqualMatriks (Matriks M1, Matriks M2)
{
    return M1.nbbar == M2.nbbar && M1.nbkol == M2.nbkol;
}

bool IsSquareMatriks (Matriks M)
{
    return M.nbkol == M.nbbar;
}

float DeterminanMatriks (Matriks M)
{
    float a[11][11];
    float ratio,det = 1;
    int i,j,k,n=M.nbbar;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=M.wadah[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        if(isEmptyMatriks(M)||!IsSquareMatriks(M))
        {
            printf("Error");
        }
        for(j=i+1;j<n;j++){
            ratio = a[j][i]/a[i][i];
            for(k=0;k<n;k++)
            {
                a[j][k]=a[j][k]-ratio*a[i][k];
            }
        }
    }
    for(i=0;i<n;i++)
    {
        det = det*a[i][i];
    }
    return det;
}

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
