
//soluzione by: Robertino B.


#include<iostream>
#include<fstream>
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
int f1(innesto*& Inn,ifstream & IN)
{
	int el,innest=0; IN>>el;nodo *temp;
	if (!Inn || el==-2) // caso base el=-2 o lista vuota
		return 0;
	if (Inn->l && Inn->r) // se l e r aggiungo i due nodi a destra e a sinistra
		{
			innest++;
			temp=new nodo(el);
			Inn->N->left=temp;
			IN>>el;
			if (el==-2)
				{Inn->l=false;return innest;}
			else
				{innest++; temp=new nodo(el);Inn->N->right=temp;}
		}
	else // altrimenti verifico se posso attaccare a sinistra o a destra
		if (Inn->l)
			{innest++;temp=new nodo(el);Inn->N->left=temp;}
		else
			{innest++;temp=new nodo(el);Inn->N->right=temp;}
			
	innesto *aux=Inn;//stacco il nodo utilizzato
	Inn=aux->next;
	delete aux;
	return innest+f1(Inn,IN);
			

}

innesto *creaIn(innesto *n1,innesto *n2)
{
	if (!n1)
		return n2;
	else
	{
		n1->next=creaIn(n1->next,n2);
		return n1;
	}
}


innesto* f0(nodo*R)
{
	bool l=0,r=0;
	if (!R) // caso base albero vuoto
		return 0;
	
	innesto *n1=f0(R->left);
	innesto *n2=f0(R->right);
	if (!n1 && !n2)
			{l=true;r=true;}
	else
		{
			if (!n1)
				{l=true;r=false; }
			if (!n2)
				{l=false;r=true; }					
					
		}
	if(l || r) 
		n2= new innesto(l,r,R,n2);
				
	return creaIn(n1,n2);
					
		
	
	
}


main()
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
