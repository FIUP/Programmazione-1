// la dimostrazione di deleteX non è completa
#include <iostream>
#include <fstream>
using namespace std;
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}}; // nodo di lista 
struct FIFOX{nodo* primo, *ultimo; int valp, valu,nele; FIFOX(nodo*a=0, int b=0, int c=0, int d=0){primo=a; ultimo=a;valp=b;valu=c;nele=d;}};

ostream & operator<<(ostream & OUT, FIFOX& a)
{
  OUT<< '['<<"nele="<<a.nele<<" valp="<<a.valp<<" valu="<<a.valu<<']'<<endl; 
  int x=0;
  nodo*z=a.primo;
  while(x<a.nele)
  {OUT<<z->info<<' ';z=z->next; x++;}
  OUT<<endl;
  return OUT;
}
//--------------------------ITERATIVA-------------------------------------------

//PRE=(A è un valore FIFOX corretto che gestisce una lista corretta e b è un nodo. Si assume che i nodi della lista abbiano campo info distinti e anche diversi dal campo info di b)
FIFOX push_iter( FIFOX A, nodo*b)
{
    if(!A.primo)
    {
        FIFOX B=0;
        B.primo=B.ultimo=b;
        B.nele=1;
        B.valp=B.valu=b->info;
        return B;
    }
    nodo*inizio=A.primo;
    bool inserito=false;
    if(inizio->info>b->info)
    {
        b->next=A.primo;
        A.primo=b;
        A.nele=A.nele+1;
        A.valp=b->info;
    }
    else
    {
        bool inserito=false;
        while(!inserito)    //R=(inserito=false && i nodi di A.primo con campo info minore di quello di b sono stati superati)
        {
            if(!inizio->next)
            {
                A.ultimo->next=b;
                A.ultimo=b;
                A.nele=A.nele+1;
                A.valu=b->info;
                inserito=true;
            }
            else 
            {
                if(inizio->next->info>b->info)
                {
                    b->next=inizio->next;
                    inizio->next=b;
                    A.nele=A.nele+1;
                    inserito=true;
                }
            }
            inizio=inizio->next;
        }
        
    }
    return A;
}
//POST=(restituisce un nuovo valore FIFOX corretto che corrisponde alla lista ordinata ottenuta dalla lista di A inserendo il nodo b in essa)

//--------------------------RICORSIVA-------------------------------------------

//PRE_ric_eliminaU(L(lista->next) e' una lista corretta non vuota, z e' l'intero definito presente nell'ultimo nodo della lista, vL(lista->next)=lista->next, L(lista->next) ha i nodi distinti)
//PRE_eliminaU(L(lista) e' una lista corretta non vuota, z e' l'intero definito presente nell'ultimo nodo della lista, vL(lista)=lista, L(lista) ha i nodi distinti
nodo*eliminaU(nodo* lista, int z, nodo*&ultimo)
{
    if(lista->next->info==z)
    {
        lista->next=0;
        ultimo=lista;
        return lista;
    }
    lista->next=eliminaU(lista->next, z, ultimo);
    return lista;
}
//POST_eliminaU(L(lista) non contiene piu' l'ultimo nodo di vL(lista), ultimo e' il puntatore al nuovo ultimo elemento della lista)
//POST_ric_eliminaU(L(lista->next) non contiene piu' l'ultimo nodo di vL(lista->next), ultimo e' il puntatore al nuovo ultimo elemento della lista)

//PRE_ric_elimina=(L(lista->next) e' una lista corretta di nodi non vuota, z e' un intero definito, presente=false, L(lista->next)=vL(lista->next), L(lista->next) ha i nodi distinti)
//PRE_elimina=(L(lista) e' una lista corretta di nodi non vuota, z e' un intero definito, presente=false, L(lista)=vL(lista), L(lista) ha i nodi distinti)
nodo*elimina(nodo*lista, int z, bool &presente)
{
    if(lista->next->info==z)
    {
        lista->next=lista->next->next;
        presente=true;
        return lista;
    }
    lista->next=elimina(lista->next, z, presente);
    return lista;
}
//POST_elimina=(se presente=true e' stato eliminato il nodo nella lista vL(lista) con il campo info uguale a z;
// in caso di assenza di tale nodo si restituisce la lista L(lista) senza cambiamenti e presente=false)
//POST_ric_elimina=(se presente=true e' stato eliminato il nodo nella lista vL(lista->next) con il campo info uguale a z;
// in caso di assenza di tale nodo si restituisce la lista L(lista->next) senza cambiamenti e presente=false)

//PRE_modifica(A e' una lista FIFOX corretta e non vuota, z e' un intero non nullo, vA=A, La lista gestita da A ha i nodi con info distinti)
FIFOX modifica(FIFOX A, int z)
{
    if(A.primo->info==z)
    {
        if(A.primo->next)
        {
            A.primo=A.primo->next;
            A.valp=A.primo->info;
            A.nele=A.nele-1;
            
        }
        else
            A=NULL;
    }
    else
    {
        if(A.ultimo->info==z)
        {
            nodo*ultimo=0;
            A.primo=eliminaU(A.primo, z, ultimo);
            ultimo->next=0;
            A.ultimo=ultimo;
            A.valu=ultimo->info;
            A.nele=A.nele-1;
        }
        else
        {
            bool presente=false;
            A.primo=elimina(A.primo, z, presente);
            if(presente)
                A.nele=A.nele-1;
        }
    }
    return A;
}
//POST_modifica(restituisco la lista A di tipo FIFOX uguale alla lista vA meno il nodo di campo info uguale a z se presente;
//restituisco altrimenti A=vA)

//PRE_deleteX=(A è un FIFOX corretto e z è un intero. La lista gestita da A ha i nodi con info distinti)
FIFOX deleteX(FIFOX A, int z)
{
  if(z>A.valu || z<A.valp || !A.primo)
  {
    return A;
  }
  else
  {
    A=modifica(A, z);
  }
  return A;
}
//POST_deleteX=(restituisce un FIFOX corretto rispetto alla lista ottenuta da quella di A dopo aver eliminato un nodo con in
//fo=z, se un tale nodo esiste e altrimenti restituisce A)

/* PROVA INDUTTIVA deleteX
caso base (z>A.valu || z<A.valp || !A.primo)
    nel caso in cui non ci siano nodi con campo info compreso tra A.valu e A.valp restituisco A senza modifiche;
    stessa cosa avviene se non ho alcun nodo presente in A

funzione modifica
caso (A.primo->info==z) 
    se il valore del primo nodo della lista A e' uguale a z pongo come nuovo nodo di partenza il nodo ad esso successivo, pongo
    come valore di partenza quello contenuto nel nuovo primo nodo di A e riduco di 1 il numero di nodi presenti in A;
    nel caso avessi eliminato tutti i nodi ritorno 0.
caso (A.ultimo->info==z)
    se l'ultimo nodo della lista ha il campo info uguale a z tolgo tale nodo dalla lista e pongo il precedente come nuovo ultimo
    nodo della lista A, riducendo di 1 il numero di nodi presenti in A
caso (A.ultimo->info!=z&&A.primo->info!=z)
    se z non e' il valore di uno dei nodi agli estremi di A allora cerco la posizione di un nodo adatto all'interno della lista;
    se e' presente tale nodo viene tolto dalla lista e vengono collegati i nodi precedente e successivo ad esso, riducendo anche
    il contatore di nodi A.nele di 1; in caso contrario la lista rimane uguale a prima senza modifiche;
    
    */
main()
{
   int dim1,dim2, x;
   
   cin>>dim1>>dim2;
   FIFOX a;
   while(dim1)
   {
   
   cin>>x;
   a=push_iter(a,new nodo(x));
   dim1--;
  }
   cout<< a;

   while(dim2)
   {
     cin>>x;
     a=deleteX(a,x);
     dim2--;
   }
   cout<<a;

   cout<<"end"<<endl;  
}
