#include <stdio.h>
#include <stdlib.h>
#include "listdouble.h"

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
    InsertFirst(L, P);
}
void InsVLast(List *L, infotype X){
    address P = Alokasi(X);
    InsertLast(L, P);
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
    *P = L->First;
    if (L->First){
        L->First = L->First->next;
        if(L->First){
            L->First->prev = Nil;
        }
        (*P)->next = Nil;
    }
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
    address P = First(L);
    if (P)
    {
        while (next(P) != Nil)
        {
            printf("%d,", info(P));
            P = next(P);
        }
        printf("%d", info(P));
    }
    printf("\n");
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

void DelAll(List *L){
    address P;

    while(First(*L) != Nil) {
        DelFirst(L, &P);
    }
}
void InversList(List *L){
    List* L2 = (List*) malloc(sizeof(List));
    address P;
    CreateList(L2);

    DelFirst(L, &P);
    while(P){
        InsertFirst(L2, P);
        DelFirst(L, &P);
    }
    *L = *L2;
    
}
List FInversList(List L){
    List* L2 = (List*) malloc(sizeof(List));
    address P, Q;
    CreateList(L2);

    P = L.First;
    while(P){
        Q = Alokasi(P->info);
        InsertFirst(L2, Q);
        P = P->next;
    }
    return *L2;
}

void CopyList(List *L1, List *L2){
    *L2 = *L1;
} 

List FCopyList(List L){
    List L2;
    address P, Q;
    CreateList(&L2);

    P = First(L);
    while(P != Nil){
        Q = Alokasi(info(P));
        if( Q != Nil){
            InsertLast(&L2, Q);
        } else {
            DelAll(&L2);
            break;
        }
        P = next(P);
    }

    return L2;
}

void CpAlokList(List Lin, List *Lout){
    address P, Q;
    CreateList(Lout);

    P = First(Lin);
    while(P != Nil){
        Q = Alokasi(info(P));
        if( Q != Nil){
            InsertLast(Lout, Q);
        } else {
            DelAll(Lout);
            break;
        }
        P = next(P);
    }
}
void Konkat(List L1, List L2, List *L3){
    address P, Q;
    CreateList(L3);

    P = First(L1);
    while(P != Nil){
        Q = Alokasi(info(P));
        if( Q != Nil){
            InsertLast(L3, Q);
        } else {
            DelAll(L3);
            return;
        }
        P = next(P);
    }

    P = First(L2);
    while(P != Nil){
        Q = Alokasi(info(P));
        if( Q != Nil){
            InsertLast(L3, Q);
        } else {
            DelAll(L3);
            return;
        }
        P = next(P);
    }
}
void Konkat1(List *L1, List *L2, List *L3){
    address P;
    CreateList(L3);

    while(First(*L1) != Nil){
        DelLast(L1, &P);
        InsertFirst(L3, P);
    }
    while(First(*L2) != Nil){
        DelLast(L2, &P);
        InsertFirst(L3, P);
    }
}
void PecahList(List *L1, List *L2, List L){
    int divl, i;
    address P, Q;

    divl = NbElmt(L)/2;
    P = First(L);
    for(i = 0; i < divl; i++){
        Q = Alokasi(info(P));
        InsertLast(L1, Q);
        P = next(P);
    }
    while(P != Nil){
        Q = Alokasi(info(P));
        InsertLast(L2, Q);
        P = next(P);
    }
}