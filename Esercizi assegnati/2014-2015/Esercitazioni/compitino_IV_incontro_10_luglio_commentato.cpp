#include<iostream>
#include<fstream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};

void stampa(nodo* x)
{
 if(x)
 {cout<<x->info<<' '; stampa(x->next);}
 else
  cout<<endl;
}

nodo* F(int n_el)
{
    if(n_el==0)
        return 0;
    int valore;
    cin>>valore;
    return new nodo(valore, F(--n_el));
}

nodo* sUk(nodo*&Q, int k, int z, int & ck){
	if(Q){											//Se la lista non è vuota
		if(Q->info==z){								//e il campo info del nodo che stiamo valutando è uguale al valore da cercare
			ck++;									//incrementiamo ck, che indica all'andata i nodi con info == z
			nodo*T=sUk(Q->next,k,z,ck);				//creiamo un puntatore T che conterrà la lista dei nodi rimossi a partire dalla prossima posizione della lista
			if(ck !=-1 && ck<k){					//se c'è qualcosa in ck e ck vale meno di k (nodi da togliere)
				nodo*w=Q;							//facciamo puntare w alla lista originale 
				Q=Q->next;							//la lista d'origine scorre in avanti
				w->next=T;							//a w->next colleghiamo il nodo della lista dei nodi rimossi
				ck++;								//e incrementiamo ck
				return w;							//ritorniamo w, la lista dei nodi rimossi
			}
			else									//non abbiamo nodi da staccare ma dobbiamo comunque								
				return T; 							//ritornare la lista contenente i nodi rimossi dall'originale
		}
		else										//Se il campo info del nodo che stiamo valutando non è uguale a z
			return sUk(Q->next,k,z,ck);				//ritorna la lista originale meno i nodi staccati invocando sUk sul resto della lista
	}
	else{											//Se la lista d'origine è vuota			
		if(ck>=k)									//se ck vale come o più di k
			ck=0;									//non abbiamo comunque niente da cercare e lo impostiamo a 0
		else										//se ck vale meno di k
			ck=-1;									//lo impostiamo a -1, valore di default per far terminare correttamente le ricorsioni
		return 0;									//e torniamo una lista con zero nodi staccati, cioè vuota, indicata da 0
	}
}

/*POST=(se vL(Q) contiene x nodi con info=z e vck+x >=k, allora viene restituito col return la lista che consiste
degli ultimi k-ck nodi di vL(Q) che contengono info=z ed L(Q) è vL(Q) meno i nodi restituiti col return)
&&(se vL(Q) contiene x nodi con info=z e vck+x<k, allora L(Q)=vL(Q) e viene restituito 0 col return)*/

main()
{
 int n_el, k, z, ck=0;
 //n_el dimensione della lista L(Q)
 
 cin>>n_el>>k>>z;
 nodo* x=F(n_el);				//esercizio 0 11/5
 cout<<"x= ";
 stampa(x);
 nodo*y=sUk(x,k,z,ck);//da fare 
 cout<<"y= ";
 stampa(y);
 cout<<"x= ";
 stampa(x);
 cout<<"end"<<endl;
}
