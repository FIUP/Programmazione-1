//Soluzione di S.Righetto

#include<iostream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};

bool trovato(nodo*n, int *P, int dimP){
    if(!dimP) 
    	return true; //finisco P ho trovato tutti i match
    if(!n) 
    	return false; //finisco la lista, non ho più nulla da matchare
    if(*P != (n->info)) 
    	return false; //P e info sono diversi, non matcha
    return trovato(n->next,P+1,dimP-1); //P e info sono uguali vado avanti a controllare
}


 nodo* match(nodo *&n,int *P,int dimP){
     if(!dimP) 
     	return 0;
     if(!n) 
     	return 0;
     if(!trovato(n,P,dimP)){
         return match(n->next,P,dimP); //se non l ho trovato cerco dal nodo successivo
     } 
     nodo*temp=n; 
     n=n->next;
     temp->next=match(n,P+1,dimP-1);
     
     return temp;
 }

 
 void stampa(nodo *n){ //stampa la lista passata per valore
     if(!n) return ; 
    cout << n->info << ' '; 
    stampa(n->next);
 }

nodo* crea(int dim){
 if(dim){
    int x;
    cin>>x;
    return new nodo(x,crea(dim-1));
  }
 return 0;
}


void leggi(int dim, int*P){
  if(dim){
    cin>>*P;
    leggi(dim-1,P+1);
   }

}

main(){
      int dim, dimP, P[20];
      cout<<"start"<<endl;
      cin>>dim;
      nodo* L1=crea(dim);
      cin>>dimP;
      leggi(dimP, P);
      nodo* L2= match(L1,P, dimP);//da fare
      stampa(L2); //da fare
      //if(trovato(L1,P,dimP)) cout<< 's';
      //else cout<< 'n';
      stampa(L1);
      cout<<endl<<"end";
}


