#include<iostream>
#include<fstream>
using namespace std;
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};


//PRE_cut=(L è una lista corretta, k1 e k2 sono definite e 0<=k1<=k2)

nodo* cut(nodo*&L, int k1, int k2);


//POST_cut=( F restituisce L_(k1,k2) attraverso il parametro L passato per riferimento e restituisce L_(0,k1-1)@L_(k2+1,U) col return ).



void stampa(nodo* x, ofstream & OUT)
{
  if(x)
    {
      OUT<< x->info<<' ';
      stampa(x->next, OUT);
    }


}
void stampa1(nodo* x)
{
  if(x)
    {
      cout<< x->info<<' ';
      stampa1(x->next);
    }


}

void crea(nodo*& L,int dim, ifstream & INP)
{
  if(dim)
    {
      int x;
      INP>>x;
      L=new nodo(x);
      crea(L->next,dim-1,INP);
    }
  else
    L=0;

}
main()
{
  ifstream INP("input2");
  ofstream OUT("output2");
  int dim, k1,k2;
  INP>>dim>>k1>>k2;
  
  nodo* inizio;
  crea(inizio,dim,INP); //fatta
    
  nodo* y=cut(inizio, k1, k2);//da fare
  stampa(y, OUT); //fatta
  OUT<<endl;
  stampa(inizio,OUT);//fatta
  INP.close();
  OUT.close();
}



nodo* cut(nodo*&L, int k1, int k2){
	if(!L) return 0;   //caso base (1)
	
	if(k1 > 0){			//caso ricorsivo (a)
		nodo* n = L;
		L = L->next;
		n->next = cut(L, k1-1, k2-1);
		return n;
		}
			
	else {
		if(k2 > 0){
			return cut(L->next, k1, k2-1);		//caso ricorsivo (b)
		}
		if(k2 == 0){			//caso base (2)
			nodo* a = L->next;
			L->next = 0;
			return a;
		}
	}
	
} 


/* 
 
 DIMOSTRAZIONE 
 
	Casi Base :
		(1)	(!L)
			Lista vuota e post condizione verificata. L rimane invariato. L_(k1, k2) = 0;
		
		(2) (L) && (k1 == 0) && (k2 == 0)
			• L(k1, k2) = L(0, 0)
			• L(0, k1-1)@L(k2+1, U) = L(1, U)
 
 
	Casi Ricorsivi:
		(a) (k1>0) && (L)
			da PRE -> (k2 ≥ k1) && (L lista valida quindi L->next è valido) 
 
			L=n@L'
			cut(L', k1-1. k2-1):
				• L'_(k1-1, k2-1)
				• L'_(0, (k1-1)-1)@L'_((k2-1)+1, U) = L_(0, k1-2)@L_(k2, U)
 
			L'_(k1-1, k2-1) = L_(k1, k2)
			n@L'_(Ø, k1-2)@L'_(k2,U) = L_(Ø, k1-1)@L_(k2+1,U)
 
		(b) (k1 == 0) && (k2>0) && (L)
			L=n@L' cut(L->next, k1, k2-1)  //(L->next = L')
				• L'_(k1, k2-1) = L_(k1=0, k2)	//per riferimento
				• L'_(0, k1-1)@L'_((k2-1)+1, U) = L'_(k2, U) -> L(k2+1, U) //con return

*/






