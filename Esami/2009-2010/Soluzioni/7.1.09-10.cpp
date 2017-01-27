#include <iostream>
using namespace std;
struct nodo{int info; nodo*next;
	nodo(int a=0, nodo*b=0){info=a; next=b;}
};
struct DN {nodo*L1,*L2;
	DN(nodo*a=0, nodo*b=0){L1=a; L2=b;}
};

DN S(nodo*L){
	DN a;
	if(L){
		a.L1=L;
		if(L->next){
			  a.L2=L->next;
			  DN acc=S(L->next->next);
			  a.L1->next=acc.L1;
			  a.L2->next=acc.L2;
			  return a;			
			}
		
		return a;
	}
	return a;
}

void stampa(nodo*r){
	if(r){
		cout << r->info<< " ";
		stampa(r->next);
	}
}

main(){

nodo *qui=new nodo(5, 0), *qu=new nodo(4, qui), *tre=new nodo(3,qu), *dos=new nodo(2,tre), *ini=new nodo(1,dos);
DN a=S(ini);
stampa(a.L1); cout << endl;
stampa(a.L2); cout << endl;
}
//L= 1 -> 2 -> 3 -> 4 -> 5 vogliamo ottenere L1= 1 -> 3 -> 5 e L2= 2 -> 4.
