//Soluzione di S.Righetto

#include<iostream>
using namespace std;


struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};
struct doppialista{nodo* listamatch, * restante; doppialista(nodo*a=0, nodo* b=0){listamatch=a; restante=b;}};



nodo* crea(int dim)
{
 if(dim)
  {
    int x;
    cin>>x;
    return new nodo(x,crea(dim-1));
  }
 return 0;
}

void stampa(nodo*L)
{
  if(L)
  {
    cout<<L->info<<' ';
    stampa(L->next);
  }
 else
    cout<<endl;
}

void leggi(int dim, int*P)
{
  if(dim)
   {
    cin>>*P;
    leggi(dim-1,P+1);
   }

}

/*l'idea fondamentale è di sfruttare il ritorno delle chiamate per staccare ogni volta un nodo 
e metterlo in doppialista(a) nel modo corretto, soltanto se l'ultimo elemento dell'array(P) è presente 
nella lista(t), altrimenti si ritorna sempre zero ad ogni chiamata*/

doppialista* match(nodo*t, int*P, int dimP) 
{
  doppialista *a= new doppialista(0,0);
  if(!t){
    return 0;
    }

  if(*P == t->info)
  {
    if(dimP == 1) //ho trovato l'ultimo match, lo restituisco 
    {
      a->listamatch = t;
      if(t->next){
        a->restante = t->next; //se nella lista rimane qualcosa(che non fa parte del match) lo devo mettere in restante
        }
      a->listamatch->next = NULL; //stacco il nodo(t) del match dal resto della lista
      return a;
    }
    a = match(t->next, P+1, dimP-1); //faccio tutte le chiamate
    if(a == 0) //se la chiamata mi restituisce 0
      return 0;
    else //se la chiamata mi restituisce qualcosa
    {
      t->next = a->listamatch;
      a->listamatch = t;
      return a;
    }
  }
  else
  {
    a = match(t->next, P, dimP); //faccio tutte le chiamate
    if(a == 0) //se la chiamata mi restituisce 0
      return 0;
    else //se la chiamata mi restituisce qualcosa
    {
      t->next = a->restante;
      a->restante = t;
      return a;
    }
  }
  return a;
}


/*POST=(se esiste match di P in L(n) allora match2 restituisce il puntatore Xad un valore 
di tipo doppialistatale che X->listamatch sia la lista del match trovato e X->restantesia 
lalista restante, se invece non c’èmatch, match2 restituisce il puntatore 0eL(n) resta inalterata).
*/


main()
{
   int dim, dimP, P[20];
   cin>>dim;
   nodo* L1=crea(dim);
   cin>>dimP;
   leggi(dimP, P);
   cout<<"start"<<endl;
   
   nodo* l= stacca(L1,P, dimP);
   stampa (l);
   
   doppialista* D= match(L1,P, dimP); //da fare
   if(!D)
     {
       cout<<"no match"<<endl;
       cout<<"Lista T e':";
       stampa(L1);
     }
   else
     {
       stampa(D->listamatch);
       if(D->restante)
	 stampa(D->restante);
       else
	 cout<<"Lista restante vuota"<<endl;
     }
     
   cout<<"end"<<endl;
}





