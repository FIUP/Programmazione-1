#include<iostream>
#include<fstream>
using namespace std;

struct coord{int s,r,c; coord(int a=0, int b=0, int d=0){s=a;r=b;c=d;}};
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};
struct FIFO{nodo* inizio,*fine; FIFO(nodo*a=0,nodo*b=0){inizio=a; fine=b;}};

void metti_fondo(FIFO &a, nodo* b){
    if(!a.fine){
        a.inizio=b;
        a.fine=a.inizio;
        return ;
    }
    else{
        (a.fine)->next=b;
        a.fine=b;
        return ;
    }
}

coord calc_coord(int lim1,int lim2,int lim3,int HF,int i){
    coord a;
    
    a.s=i%lim1;
    a.r=HF;
    a.c=i/lim1;
    
    return a;
}
void allunga(int* &S, int &dimS){
    int *A=new int[dimS+3];
    
    for(int i=0; i<dimS; i++){
        A[i]=S[i];
        
    }
    dimS=dimS+3;
    S=A;
}


void sposta_sx(nodo*&L1, nodo*&L2, int S, ofstream &OUT){
    
    if(!S || !L2->next){
        return;
    }
    
    else{
        nodo*p=L2->next;
        L2->next=L1;
        L1=L2;
        L2=p;
        sposta_sx(L1, L2, S-1, OUT);
    }
    
}

void sposta_dx(nodo*&L1, nodo*&L2, int S, ofstream &OUT){
    
    if(!S || !L1){
        return;
    }
    else{
        nodo*p=L1->next;
        L1->next=L2;
        L2=L1;
        L1=p;
        
        sposta_dx(L1, L2, S+1, OUT);
    }
}

//PRE=(A contiene almeno lim1*lim2*lim3 valori, 0<=HF<lim2)
nodo* buildL(int*A,int lim1, int lim2, int lim3, int HF){
    coord a;
    FIFO x;
    int i=0;
    while(i<lim1*lim3){
        a=calc_coord(lim1, lim2, lim3, HF, i);
        nodo* L=new nodo(A[(a.s*lim2*lim3)+(a.r*lim3)+a.c]);
        metti_fondo(x, L);
        
        i++;
    }
    return x.inizio;
}
//POST=(restituisce una lista di lim1*lim3 nodi i cui campi info sono i valori della H-fetta HF considerati in
//ordine per tasselli)

//PRE=(L1 ed L2 sono liste corrette, con L2 non vuota, S ha dimS elementi, vL1=L1 e vL2=L2)
void F(nodo*&L1, nodo*& L2, int*S, int dimS, ofstream & OUT){
    
    if(!dimS){
        
        sposta_dx(L1,L2,1000,OUT);
        return;
    }
    if(dimS){
        if(*S>0){
            sposta_sx(L1, L2, *S, OUT);
            OUT<<L2->info<<" ";
            F(L1, L2, S+1, dimS-1, OUT);
            
        }
        else{
            sposta_dx(L1, L2, *S, OUT);
            OUT<<L2->info<<" ";
            
            F(L1, L2, S+1, dimS-1, OUT);
        }
    }
}
//POST=(L1=0 e L2 è la lista rappresentata da vL1 e vL2, inoltre sono stati eseguiti gli spostamenti richiesti da
//S[0..dimS-1] (partendo dalla situazione rappresentata da vL1 e vL2) ed è stato stampato il campo info dei
//nodi raggiunti dopo ciascuno spostamento)



void legge(int* A, int lim1, int lim2, int lim3, ifstream & IN)
{
    for(int i=0; i<lim1*lim2*lim3; i++)
        IN>>A[i];
}


int leggiS(int*& S, int & dimS, ifstream &IN)
{
    int x,i=0;
    IN>>x;
    while(x!=1000)
    {
        if(i==dimS)
            allunga(S,dimS);
        S[i]=x;
        i++;
        IN>>x;
    }
    return i;
}



void stampaL(nodo*L,ofstream & OUT)
{
    if(!L)
        OUT<<endl;
    else
    {
        OUT<<L->info<<' ';
        stampaL(L->next,OUT);
    }
}


main()
{
    ifstream IN("input");
    ofstream OUT("output");
    if(IN && OUT)
    {
        int A[400], lim1,lim2,lim3;
        IN>>lim1>>lim2>>lim3;
        legge(A,lim1, lim2, lim3, IN);//data
        
        int dimS=3;
        int*S=new int[dimS];
        int neS=leggiS(S,dimS,IN); // e' data ma invoca allunga da fare
        OUT<<neS<<' '<<dimS<<endl; //attenzione output !!
        int HF;
        IN>>HF;
        nodo* L=buildL(A,lim1,lim2,lim3,HF);
        
        nodo*X=0;
        
        F(X,L,S,neS,OUT);
        OUT<<endl;
        stampaL(L,OUT);
        OUT<<"fine"<<endl;
        IN.close(); OUT.close();
        
    }
    else
        cout<<"errore con i files";
}