#include <iostream>
using namespace std;

struct nodo
{ 
    int info; nodo*next;
	nodo(int a=0, nodo*b=0){ info=a; next=b;}
};

struct NN 
{ 
    nodo *lista; NN*next;
	NN( nodo*a=0, NN*b=0){lista=a; next=b;}
};

void stampa(nodo*n){
	if(n){
		cout << n->info << " ";
		stampa(n->next);	
	}
}
void stampaNN(NN*w){
	if(w){
		stampa(w->lista);
		cout << endl;
		stampaNN(w->next);
	}
}
//PRE: L è una lista corretta eventualmente vuota, x è un intero
void Gric(nodo*&L, int x){
	if(L){
		if(L->info==x){
			nodo*q=L;
			L=L->next;
			delete q;
			Gric(L, x);
		}
		else
			Gric(L->next, x);
	}
}
//POST: alla fine di Gric L sarà L-L', considerando L' l'insieme dei nodi con campo info uguale a x, L e L' possono essere
//		eventualmente vuote

//PRE: LL è una lista di liste ben formata di valore k e x è un intero
void Fric(NN*&LL, int x){
	if(LL){
		nodo*L=LL->lista;
		Gric(L, x);
		if(!L){
			NN*q=LL;
			LL=LL->next;
			delete q;
			Fric(LL,x);
		}
		else
		Fric(LL->next, x);
	}
}
//POST: alla fine dell'esecuzione di Fric il valore di LL è diventato quello ottenuto da k dopo aver eliminato
//		i nodi di tipo nodo che contengono xe i nodi di tipo NN che risultino puntare a liste vuote dopo le 
//		eliminazioni precendenti, i nodi eliminati vengono deallocati

/* F Gric: CASO BASE: L è una lista vuota => non ci sono nodi in cui è possibile trovare x quindi restituisce la lista vuota
						come da post
			PSS IND: L=a @ L'
					- se il campo info di a è uguale a x => viene eliminato a, quindi L= L', la chiamata ricorsiva soddisfa la 
					 PRE_ric poichè L' è una lista eventualmente vuota, e per il passo induttivo soddisfa la POST_ric poichè
					 L è una lista a cui sono stati eliminati i nodi con campo info uguale a x
					- se a->info != x => la chiamata ricorsiva soddisfa la PRE_ric poichè L' è una lista eventualmente vuota
					  e per il passo induttivo soddisfa la POST_ric poichè a @ L' è una lista privata dei nodi con campo info
					  uguale a x	
*/

main(){
	nodo *ter=new nodo(1,0), *sec=new nodo(2, ter), *ini= new nodo(4,sec);
	nodo *sec2=new nodo(2,0), *ini2=new nodo(2,sec2);
	nodo* ini3=new nodo(3,0);
	NN *l3=new NN(ini3, 0), *l2= new NN(ini2, l3), *l= new NN(ini, l2);

	Fric(l, 2);
	stampaNN(l); cout << endl;
	system("PAUSE");
}
