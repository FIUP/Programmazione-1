//Matteo Gazzato 594140  ESERCITAZIONE DEL 7/3/2013 SETTIMANA 7
/*
TEORIA
(i)
//PRE=(L1 ed L2 sono due liste,eventualmente vuote,ordinate in modo
decrescente)  
nodo* F(nodo* L1, nodo*L2) 
{ 
	if(!L1) 
		return L2; 
	if (!L2) 
		return L1; 
	if (L1->info >=L2->info) 
		{L1->next=F(L1->next,L2); return L1;} 
	else
	{L2->next=F(L1,L2->next); return L2;} 
} 
//POST=(F ritorna un puntatore ad una lista i cui elementi sono gli 
elementi di L1 ed L2 ordinati in modo decrescente)

(ii) che potete dire sul seguente programma?
void G(int x){cout<<x+y<<endl;}
int y=10;
main(){int y=20,x=30; G(x); }
Il programma non compila. Benchè y sia variabile globale è 
dichiarata dopo la definizione di G.

(iii) e su questo programma?
void G(int x){…}
int G(char x){….}
main(){double y=20; G(y); }
Non compila,il compilatore deve essere in grado di decidere quale delle
due funzioni sciegliere.Ambiguità nell'overloading resolution.
*/
#include <iostream>
#include <fstream>
using namespace std;

struct nodo {int info; nodo* next;  nodo(int a=0, nodo* b=0)
{info=a; next=b;}};

nodo * crea(ifstream & INP, int dim)
{ 
	if(!dim)//caso base
     return 0;
	else//passo induttivo
	{
		int k;
		INP>>k;
		nodo *L=new nodo(k,crea(INP,dim-1));
		return L;
	}      
}//fine crea

void stampa(nodo *L, ofstream & OUT)
{ if(L)
    { OUT<<L->info<<" ";
      stampa(L->next, OUT);
    }
}// fine stampa

nodo * F(nodo * &L, int * P, int dimP)
{ 
	if(!L || !dimP)//caso base
    	return 0;
  	else//passo induttivo
	{
		if(L->info==*P)
		{
			nodo*L1=L;
			L=L->next;
			L1->next=F(L,P+1,dimP-1);
			return L1;
		}
		else
			return F(L->next,P,dimP);
	}
}//fine F

main()
{ 
	ifstream INP("input1");
  	ofstream OUT("output1");
  	
	int dim, dimP, P[20];
  	if(!INP || !OUT)
    	cout<<"Errori con i file de input o output"<<endl;
  	INP>>dim;
  	nodo * L=crea(INP, dim);
  	INP>>dimP;
  	for(int i=0; i<dimP; i++)
    	INP>>P[i];
  	nodo * Q=F(L, P, dimP);
  	stampa(Q, OUT);
  	OUT<<endl;
  	stampa(L, OUT);
}
/*
CORRETTEZZA F
N.B. L-p=quello che resta di L se togliamo i nodi del match
	R(L,P)=nodi di L che fanno match con P

PRE_F=( L è lista corretta e L=vL, P ha dimP elementi definiti con 
dimP>=0)
POST_F=(F restituisce col return R(vL,P) e vL-P attraverso il 
parametro L passato per riferimento).

caso base: -array vuoto:p=0=>L-p=L =>ritorno 0 perchè non c'è stato
 			match e non ho rimosso nodi da L ed L non è stato 
			modificato
			-lista vuota:ritorno 0=>perchè non è possibile effettuare
			alcun match e togliere nodi da L (visto che è vuota!) L 
			non	viene modificata poichè L=0. 

passo induttivo: 
PRE_ric=(L=vL-P e P ha dimP elementi definiti),se L era corretta 
rispetto a PRE_F allora e' necessariamente corretta rispetto a 
PRE_ric. 
POST_ric=(L1->next e' un nodo prelevato da L il cui campo info e' 
uguale a P[1] e tale elemento di P e'stato matchato il piu' presto 
possibile in L). 
Quando non c'è match R(vL,P)=R(vL',P) (con vL=a@vL') visto che il 
primo nodo di vL non fa match.
Quando c'è match: vL=a@vL',quindi a==*p,R(vL,P)=a@R(vL',P[1..dimP-1])
(che è ciò che restituisco e ciò che vuole POST) con L=L->next
dico che ora L=vL-p.
*/

  
