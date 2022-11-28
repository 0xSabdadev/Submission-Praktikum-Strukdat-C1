#include <stdio.h>
#include <stdlib.h>
#include "listDouble.h"

bool ListEmpty(List L){
    return First(L) == Nil && Last(L) == Nil;
    //return First(L) == Nil;
}
void CreateList(List *L){
    First((*L)) = Nil;
    Last((*L)) = Nil;
    //First((*L)) = Nil;
}
address Alokasi(infotype X){
    address P = (address)malloc(sizeof(ElmtList));
    if(P!=Nil){
        info(P) = X;
        next(P) = Nil;
        prev(P) = Nil;
    }
    return P;
}
void Dealokasi(address *P){
    free(*P);
}
address Search(List L, infotype X){
    address P = First(L);
    while(P!=Nil){
        if(X == info(P)){
            return P;
        }else{
            P = next(P);
        }
    }
    return Nil;
}
bool FSearch(List L, address P){
    address Q = First(L);
    while(Q!=Nil){
        if(Q==P){
            return true;
        }else{
            Q = next(Q);
        }
    }
    return false;
}
address SearchPrec(List L, infotype X, address *Prec){
    address P = First(L);
    while(next(P)!=Nil){
        if(info(next(P))==X){
            return P;
        }else{
            P = next(P);
        }
    }
    return Nil;
}
void InsVFirst(List *L, infotype X){
    address P = Alokasi(X);
    InsertFirst(&(*L),P);
}
void InsVLast(List *L, infotype X){
    address P = Alokasi(X);
    InsertLast(&(*L),P);
}
void InsVAfter(List *L, infotype Prec, infotype X){
    address P = Alokasi(X);
    address Q = First((*L));
    if(ListEmpty((*L))){
        InsVFirst(&(*L),X);
    }else{
        while(info(Q)!=Prec){
            Q = next(Q);
        }
        next(P) = next(Q);
        next(Q) = P;
    }
}
void DelVFirst(List *L, infotype *X){
    address P;
    DelFirst(&(*L),&P);
    (*X) = info(P);
    Dealokasi(&P);
}
void DelVLast(List *L, infotype *X){
    address P;
    DelLast(&(*L),&P);
    (*X) = info(P);
    Dealokasi(&P);
}
void DelVAfter(List *L, infotype *X, infotype Y){
    address P = First(*L);
    address Q;
    if(info(First(*L))==Y){
        Q = next(P);
        (*X) = info(P);

    }else{
        while(info(P)!=Y){
            P = next(P);
        }
        Q = next(P);
        (*X) = info(next(P));
    }
    next(P) = next(Q);
    next(Q) = Nil;
    //prev(next(Q)) = P;
    Dealokasi(&Q);
}
void InsertFirst(List *L, address P){
    if(!ListEmpty(*L)){
        next(P) = First(*L);
        prev(First(*L)) = P;
    }else{
        Last(*L) = P;
    }
    First(*L) = P;
}
void InsertAfter(List *L, address P, address Prec){
    next(P) = next(Prec);
    prev(P) = Prec;
    prev(next(Prec)) = P;
    next(Prec) = P;
}
void InsertLast(List *L, address P){
    if(!ListEmpty(*L)){
        prev(P) = Last(*L);
        next(Last(*L)) = P;
    }else{
        First(*L) = P;
    }
    Last(*L) = P;

    // address Last;
    // if (ListEmpty(*L)){
    //     InsertFirst(L, P);
    // }
    // else{
    //     Last = First(*L);
    //     while (next(Last) != Nil)
    //     {
    //         Last = next(Last);
    //     }
    //     next(Last) = P;
    //     prev(P) = Last;
    //     next(P) = Nil;
    // }
}
void DelFirst(List *L, address *P){
    (*P) = First(*L);
    First(*L) = next(First(*L));
    prev(First(*L)) =Nil;
}
void DelLast(List *L, address *P){
    *P = Last(*L);
    Last(*L) = prev(*P);
    if(Last(*L) != Nil){
        next(Last(*L)) = Nil;
    }else{
        First(*L) = Nil;
    }
    prev(*P) = Nil;

    // address Last;
    // if (!(ListEmpty(*L))){
    //     Last = First(*L);
    //     while (next(Last) != Nil)
    //     {
    //         Last = next(Last);
    //     }
    //     (*P) = Last;
    //     if (prev(*P) == Nil)
    //     {
    //         First(*L) = Nil;
    //     }
    //     else
    //     {
    //         Last = prev(*P);
    //         next(Last) = Nil;
    //     }
    // }
}
void DelAfter(List *L, address *Pdel, address Prec){
    address P = next(Prec);
    (*Pdel) = P;
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    Dealokasi(&P);
}
void DelP(List *L, infotype X){
    address P = First(*L);
    address Q;
    if(info(P)==X && next(P) == Nil){
        DelFirst(&(*L),&P);
    }else{
        while(info(next(P)) != X){
            P = next(P);
        }
        DelAfter(&(*L),&Q,P);
    }
}
void Printinfo(List L){
    address P= First(L);
    if (!ListEmpty(L))
    {
        while (next(P) != Nil)
        {
            printf("%d,", info(P));
            P = next(P);
        }
        printf("%d\n", info(P));
    }
}
int NbElmt(List L){
    int counter = 0;
    address P = First(L);
    while(P!=Nil){
        counter++;
        P=next(P);
    }
    return counter;
}

void DelAll(List *L)
{
    /* Kamus Lokal */
	address P;

	/* Algoritma */
	while (!IsListEmpty(*L))
    {
		DelFirst(L,&P);
		Dealokasi(&P);
	}
}

void InversList(List *L)
{
    /* Kamus Lokal */
	address P, Temp;

	/* Algoritma */
	P = First(*L);
	if (!IsListEmpty(*L))
    {
		Temp = First(*L);
		First(*L) = Last(*L);
		Last(*L) = Temp;
	}
	while (P != Nil)
    {
		Temp = Next(P);
		Next(P) = Prev(P);
		Prev(P) = Temp;
		P = Temp;
	}
}

List FInversList(List L)
{
    /* Kamus Lokal */
	address P, Temp;
	List L1;
	boolean fail;

	/* Algoritma */
	fail = false;
	P = First(L);
	CreateList(&L1);
	while ((P != Nil) && (!fail)) {
		Temp = Alokasi(Info(P));
		if (Temp != Nil) {
			InsertFirst(&L1,Temp);
			P = Next(P);
		} else {
			DelAll(&L1);
			fail = true;
		}
	}
	return L1;
}

void CopyList(List *L1, List *L2)
{
    First(L2) == First(L1);
}
List FCopyList(List L)
{
    /* Kamus Lokal */
	address P, Temp;
	List L1;
	boolean fail;

	/* Algoritma */
	fail = false;
	CreateList(&L1);
	P = First(L);
	while ((P != Nil) && (!fail)) {
		Temp = Alokasi(Info(P));
		if (Temp != Nil) {
			InsertLast(&L1,Temp);
			P = Next(P);
		} else {
			fail = true;
			DelAll(&L1);
		}
	}
	return L1;
}

void CpAlokList(List Lin, List *Lout)
{
    /* Kamus Lokal */
	address P, Pt;
	boolean gagal;

	/* Algoritma */
	CreateList(Lout);
	gagal = false;
	P = First(Lin);
	while ((P != Nil)&&(!gagal)) {
		Pt = Alokasi(Info(P));
		if (Pt != Nil) {
			InsertLast(Lout,Pt);
			P = Next(P);
		} else {
			gagal = true;
			DelAll(Lout);
		}
	}
}

void AdrLast(List *L, address *Prec, address *Last)
{
    *Prec = Nil;
    *Last = First(*L);
    while(next(*Last)!=Nil){
        *Prec = *Last;
        *Last = next(*Last);
    }
}

void Konkat(List L1, List L2, List *L3)
{
    /* Kamus Lokal */
	address P, Pt;
	boolean gagal;

	/* Algoritma */
	CreateList(L3);
	gagal = false;
	P = First(L1);
	while ((P != Nil)&&(!gagal)) {
		Pt = Alokasi(Info(P));
		if (Pt != Nil) {
			InsertLast(L3,Pt);
			P = Next(P);
		} else {
			gagal = true;
			DelAll(L3);
		}
	}
	if (!gagal) {
		P = First(L2);
		while ((P != Nil)&&(!gagal)) {
			Pt = Alokasi(Info(P));
			if (Pt != Nil) {
				InsertLast(L3,Pt);
				P = Next(P);
			} else {
				gagal = true;
				DelAll(L3);
			}
		}
	}
}

void Konkat1(List *L1, List *L2, List *L3)
{
    /* Kamus Lokal */
	address P, Pt;
	boolean gagal;

	/* Algoritma */
	CreateList(L3);
	gagal = false;
	P = First(L1);
	while ((P != Nil)&&(!gagal)) {
		Pt = Alokasi(Info(P));
		if (Pt != Nil) {
			InsertLast(L3,Pt);
			P = Next(P);
		} else {
			gagal = true;
			DelAll(L3);
		}
	}
	if (!gagal) {
		P = First(L2);
		while ((P != Nil)&&(!gagal)) {
			Pt = Alokasi(Info(P));
			if (Pt != Nil) {
				InsertLast(L3,Pt);
				P = Next(P);
			} else {
				gagal = true;
				DelAll(L3);
			}
		}
	}
}

void PecahList(List *L1, List *L2, List L)
{
    /* Kamus Lokal */
	address P, Pt;
	boolean gagal;
	int i, N;

	/* Algoritma */
	CreateList(L1);
	CreateList(L2);
	gagal = false;
	i = 1;
	N = NbElmt(L)/2;
	P = First(L);
	while ((P != Nil) && (!gagal)) {
		Pt = Alokasi(Info(P));
		if (i <= N) {
			if (Pt != Nil) {
				InsertLast(L1,Pt);
				P = Next(P);
				i++;
			} else {
				gagal = true;
				DelAll(L1);
			}
		} else {
			if (Pt != Nil) {
				InsertLast(L2,Pt);
				P = Next(P);
				i++;
			} else {
				gagal = true;
				DelAll(L2);
			}
		}
	}
}

MulMatriks(List L1, List L2, List *L3)
{
    CreateList(&(*L3));
    address P = First(L1);
    address Q = First(L2);
    while(P!=Nil){
        InsVLast(&(*L3),info(P)*info(Q));
        P = next(P);
        Q = next(Q);
    }
}
