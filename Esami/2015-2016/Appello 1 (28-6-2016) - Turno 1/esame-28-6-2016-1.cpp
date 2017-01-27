#include<iostream>
using namespace std;
#include<fstream>
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}}; // nodo di lista 
struct FIFO{nodo* primo, *ultimo;FIFO(nodo*a=0, nodo*b=0){primo=a; ultimo=b;}};
struct nodot{int info; nodot* left, *right; nodot(int a=0, nodot* b=0, nodot* c=0){info=a; left=b; right=c;}};//nodo di albero

FIFO push_end(FIFO a, nodo*b)
{
  if(!a.primo)
  {a.primo=a.ultimo=b;}
  else
   {a.ultimo->next=b; a.ultimo=b;}
  return a;
}

//esercizio 1 con push_end
FIFO concF(FIFO a, FIFO b){
  if(b.primo){
    a=push_end(a, b.primo);
    a.ultimo=b.ultimo;
  }
  return a;
}

//esercizio 2
FIFO pickric_infix(nodot*R, int &n, int k)
{
  FIFO lista; //definisco una lista FIFO vuota
  if(R == 0) //se il nodo R è 0
    return lista; //restituisco lista
    
  FIFO a = pickric_infix(R->left, n, k); 
  if(n==k){
    a=push_end(a,new nodo(R->info));
    n=1;
    }
    else
    n++;
    
  FIFO b = pickric_infix(R->right, n, k);
  return concF(a, b);
}

//esercizio 3
FIFO tieni_primo(nodo*& Q) {
  FIFO tolti;
  nodo *partenza = Q, *padre = Q, *figlio = Q; //definisco tre tipi di nodi che inizialmente corrispondono tutti a Q
    while(partenza) { //se la partenza non è 0
        padre=partenza; //il padre diventa la partenza
        figlio = partenza->next; //il figlio diventa il nodo dopo la partenza
        while(figlio) { //se il figlio non è zero
            if(figlio->info == partenza->info) { //se info figlio è uguale a info partenza
                padre->next = figlio->next; //il nodo dopo il figlio diventa il nodo dopo il padre
                figlio->next = 0; //il figlio non è più linkato a qualcos'altro
                tolti = push_end(tolti, figlio); //metto il figlio in fondo a tolti
                figlio = padre; //il figlio diventa il padre
            }
            padre = figlio; //il padre diventa il figlio
            figlio = figlio->next; //il figlio diventa il nodo dopo
        }
        partenza = partenza->next;
    }
    return tolti;
}



int conta_n(nodot*r)
{
   if(!r) return 0;
     else
    return conta_n(r->left)+conta_n(r->right)+1;
}

nodot* insert(nodot*r, nodot* y)
{
  if(!r) return y;
   
  if(conta_n(r->left)<=conta_n(r->right))
    r->left=insert(r->left,y);
   else   
    r->right=insert(r->right,y); 
  return r;
}
void stampa_lista(nodo*C)
{
  if(C)
    {cout<<C->info<<' '; stampa_lista(C->next);}
  else
    cout<<endl;
}

nodot* build_tree(nodot*R,int n_el)
{
 if(!n_el) return R;
 int x;
 cin>>x;
 nodot* Q= insert(R,new nodot(x));
 return build_tree(Q,n_el-1);
}
void stampa(nodot *r)
{
  if(r)
    {
      cout<<r->info<<'(';
      stampa(r->left);
      cout<<',';
      stampa(r->right);
      cout<<')';
    }
  else
    cout<< '_';
}

 main()
{
  int test,n_el, k, n=1;
 cin>>test>>n_el>>k;
 
 nodot* R=build_tree(0,n_el);
 cout<<"albero:"<<endl;
 stampa(R);
 FIFO x=pickric_infix(R,n,k);
 cout<<endl<<"lista creata:"<<endl;
 stampa_lista(x.primo);
 if(test>0)
 {
  FIFO y=tieni_primo(x.primo);
  cout<<"lista dei nodi tolti"<<endl;
  stampa_lista(y.primo);
  cout<<"lista dei nodi che restano"<<endl;
  stampa_lista(x.primo);
 }

 cout<<endl<<"end"<<endl;
 
}
