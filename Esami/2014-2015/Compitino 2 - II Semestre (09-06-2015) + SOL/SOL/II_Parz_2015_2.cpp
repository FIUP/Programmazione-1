
//soluzione by: Marco G.

#include <iostream>
#include <fstream>
using namespace std;
struct nodo{int info; nodo* left,*right; nodo(int a=0, nodo* b=0, nodo*c=0){info=a; left=b;right=c;}};
struct innesto{ bool l, r; nodo* N; innesto* next; innesto(bool a=false, bool b=false, nodo* c=0, innesto* d=0){l=a;r=b;N=c;next=d;}};

void stampa_l(nodo *r, ofstream & OUT)
{
  if(r)
    {
      OUT<<r->info<<'(';
      stampa_l(r->left,OUT);
      OUT<<',';
      stampa_l(r->right,OUT);
      OUT<<')';
    }
  else
    OUT<< '_';
}
int conta_n(nodo*r)
{
   if(!r) return 0;
     else
    return conta_n(r->left)+conta_n(r->right)+1;
}

nodo* insert(nodo*r, int y)
{
  if(!r) return new nodo(y);
   
  if(conta_n(r->left)<=conta_n(r->right))
    r->left=insert(r->left,y);
   else   
    r->right=insert(r->right,y); 
  return r;
}

nodo* rep_ins(nodo*r, int dim, ifstream & INP)
{
  if(dim)
   {
    int z;
    INP>>z;
    nodo*x=insert(r,z);
    return rep_ins(x,dim-1,INP);
   }
  return r;
}

void stampa(innesto* a, ofstream & OUT)
{
  if(a)
   {OUT<<"left="<<a->l<<" right="<<a->r<<" nodo="<<a->N->info<<endl; stampa(a->next,OUT);}
  else
    OUT<<endl;

}

void attaccalista (innesto *& listasinistra, innesto *listadestra) {

	if(!listasinistra) {
		listasinistra=listadestra;
		return;
	}    
attaccalista(listasinistra->next, listadestra);
}



innesto * f0(nodo *R) {
    // se è vuoto non fai nulla - FATTO
    // se c'è figlio sinistro ma non destro --> otteniamo lista sinistra e aggiungo nodo alla fine e ritorno -FATTO
    // se c'è figlio destro ma non sinistro --> creo nodo e ci attaco la llista di destra - FATTO
    // se non c'è nessuno dei 2 - FATTO
    // se ci sono entrambi --> lista di sinistra + lista di destra (attaccarle e ritornarle)
    if(!R)
        return 0;
    if(!R->left) { //Se non c'è il figlio sinistro
        innesto *x=new innesto();
        x->l=true;
        x->N=R;
        innesto *listadestra = f0(R ->right);
        x->next = listadestra;
        if(!R->right) { //Se non c'è neanche il figlio destro
            x->r=true;
        }
        else {
            x->r = false;
        }
        return x;      
    }
    // Se il figlio sinistro c'è
    if (!R->right) { //Non c'è figlio destro
        innesto *listasinistra=f0(R->left);
        innesto *node = new innesto();
        node->l = false;
        node->r=true;
        node->N=R;
        // attaca node alla fine di listasinistra
        attaccalista(listasinistra,node);
        return listasinistra;
    }
    // ci sono entrambi
    innesto *listasinistra=f0(R->left);
    innesto *listadestra = f0(R ->right);
    attaccalista(listasinistra,listadestra);
    return listasinistra;
    
    // attacchi lista destra alla fine della sinistra
    // ritorni sinistra

}


int f1(innesto *& Inn, ifstream &IN) {
	int m;
	IN>>m;
	if(m==-2 || !Inn) // Se la lista da cui leggere i nodi da inserire è vuota oppure
		return 0;	 // leggo un -2 restituisco 0
	if(Inn->l) {cout<<m<<"sinistra"<<endl; //Se è possibile l'innesto a sx
		Inn->N->left=new nodo(m);
		Inn->l=false;
		if(Inn->r) //Se era possibile anche l'innesto a dx
			return 1+f1(Inn,IN);
		else { //Se non era possibile l'innesto a dx
			innesto *prossimo=Inn->next;
			delete Inn;
			Inn=prossimo;
			return 1+f1(Inn,IN);
		}	
	}
	else { //Se è possibile l'innesto a destra
		Inn->N->right=new nodo(m);
		innesto *prossimo=Inn->next;
		delete Inn;
		Inn=prossimo;
		return 1+f1(Inn,IN);
	}		
}

int main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT) 
  { 
   int dim;
   IN>>dim;
   nodo* R=rep_ins(0,dim,IN);//data
   stampa_l(R,OUT);//data
   OUT<<endl;
   innesto* x=f0(R);//da fare
   stampa(x,OUT); //data
   int a=f1(x,IN); //da fare
   OUT<<"n. innesti="<<a<<endl;
   stampa_l(R,OUT); //data
   OUT<<endl;
   stampa(x,OUT); //data
   IN.close(); OUT.close(); 
  }
  else
   cout<<"errore con i files";
 }
