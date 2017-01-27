#include<iostream>
#include<fstream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};

nodo* crea(int dim, ifstream & INP)
{
  if(!dim)
    return 0;
  else{
    int el;
    INP>>el;
    return new nodo(el,crea(dim-1,INP));
  }
}

//PRE_F=( L è lista corretta e L=vL, P ha dimP elementi definiti con dimP>=0)
nodo* F(nodo*&L, int*P, int dimP)
{
  if(!dimP || !L) 
    return 0;
  if(P[0]==L->info){
    nodo* R=L;
    L=L->next;
    R->next=F(L,P+1,dimP-1);
    return R;
  }
  else
    return F(L->next,P,dimP);  
}
//POST_F=(F restituisce col return R(vL,P) e vL-P attraverso il parametro L passato per riferimento).

/*
  DIM IND di F
  CASO BASE:
  se dimP==0 o L->next==0
  usiamo il OR perche' basta che una delle due sia vera perche' la F termini, infatti se dimP==0 allora tutto P e' stato scorso e quindi e' stato trovato il match massimo di dimensione dimP, se L->next==0 significa che la lista L e' terminata e abbiamo controllato tutti gli elementi, ritorniamo infatti 0 che termina la lista R(L,P)
  CASO INDUTTIVO:
  se P[0]==L->info
  significa che c'e' un match tra L->info e l'elemento di P, in questo caso assegnamo l'indirizzo puntato da L ad un puntatore R quindi adesso L->info=R->info e L->next=R->next ora dobbiamo eliminare dalla lista L l'elemento puntato da L quindi riassegnamo L con L->next facendo puntare cosi' L all'elemento successivo, facciamo puntare R al ritorno della funzione F(L,P+1,dimP-1), che sara' un nuovo R in caso di match futuro o 0 se non ci saranno altri match, ritorniamo il puntatore R che punta all'elemento escluso dalla lista L.
*/

void stampa(nodo* x, ofstream & OUT)
{
  if(x)
    {
      OUT<< x->info<<' ';
      stampa(x->next, OUT);
    }
}


main()
{
  ifstream INP("input1");
  ofstream OUT("output1");
  if(!INP || ! OUT)
    cout<<"problemi con i file"<<endl;
  else
    {
      int dim, dimP, P[20],x;
      INP>>dim;
      nodo* L=crea(dim, INP); // funzione da fare
      
      INP>>dimP;
      for(int i=0; i<dimP; i++)
	INP>>P[i];
      nodo* Q=F(L, P, dimP); // funzione da fare
      stampa(Q, OUT);
      OUT<<endl;
      
      stampa(L,OUT);
      INP.close();
      OUT.close();
    }
}
/*
  TEORIA:
  1)//PRE=(L1 e L2 sono liste corrette, L1 e L2 ordinate in senso decrescente)
  nodo* F(nodo* L1, nodo*L2) {
    if (!L1) return L2;
    if (!L2) return L1;
    if (L1->info >=L2->info)
      {L1->next=F(L1->next,L2); return L1;}
    else
      {L2->next=F(L1,L2->next); return L2;}
  } 
  //POST=(restituisce un puntatore ad una lista ordinata in modo decrescente con tutti gli elementi di L1 e L2

2)y e' una variabile globale quindi per la funzione G a cui viene passata solo la x(=30), la y vale 10 in quanto la y del main e' una sua variabile locale valida solo all'interno del main.
  Quindi il programma stampa a video 40.

3)viene richiamata
  void G(int x){...}
  in quanto e' la prima ma il double deve essere arrotondato ad un int
*/
