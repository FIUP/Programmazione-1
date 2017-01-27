#include<iostream>
using namespace std;
#include<fstream>
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}}; // nodo di lista 
struct FIFO{nodo* primo, *ultimo;FIFO(nodo*a=0, nodo*b=0){primo=a; ultimo=b;}};
struct nodot{int info; nodot* left, *right; nodot(int a=0, nodot* b=0, nodot* c=0){info=a; left=b; right=c;}};//nodo di albero

FIFO push_end(FIFO a, nodo*b) //aggiunge il nodo b in fondo alla lista e restituisce a che linka al primo e all'ultimo nodo
{
    if(!a.primo) //se a è vuoto
    {a.primo=a.ultimo=b;} //il nodo diventa sia la fine che l'inizio
    else //se no
     {a.ultimo->next=b; a.ultimo=b;} // b è linkato all'ultimo nodo e il puntatore all'ultimo nodo linka b
    return a; //ritorno a 
}

//esercizio 1 FIFO concF(FIFO a, FIFO b){
    if(b){
        a=push_end(a, b.primo);
        a.ultimo=b.ultimo;
    }
    return a;
}
  


//esercizio 2
FIFO pickric_postfix(nodot*R, int &n, int k)
{
    FIFO lista; //definisco una lista FIFO vuota
    if(R == 0) //se il nodo R è 0
        return lista; //restituisco lista
    FIFO listaS = pickric_postfix(R->left, n, k); 
    FIFO listaD = pickrick_postfix(L->right, n, k);
    lista = concF(listaS, listaD); //unisco la lista sinistra e quella destra
    
    if(n == k){ //se n è uguale a k
        lista = push_end(lista, new nodo(R->info)); //unisco a lista un nuovo nodo con le info di k
        n = 1;
    } 
    else{ //se n non è uguale a k n viene incrementato
        n++; 
    }
    return lista;
}
//POST=(restituisce un valore FIFO f tale che f.primo sia una lista L tale che i nodi abbiano i campi info di valore uguale ai campi info dei nodi dell'albero Tree(R) che si trovano nelle seguenti posizioni: sia w=(kvn)+1, pe posizioni sono la w, w+k, w+2*k, eccetera rispetto all'ordine postfisso, inoltre n-1 è il numero di nodi presenti nell'albero che seguono, rispetto all'ordine postfisso, il nodo dell'albero in corrispondenza del quale si è creato il nodo di f.ultimo)

//esercizio 3
// PRE=(L(Q) è corretta,vL(Q)=L(Q))
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
// POST=(L(Q) è vL(Q) in cui sono stati eliminati i nodi che hanno un campo info
// tale che un nodo alla loro sinistra abbia lo stesso campo info. Quindi per
// ogni valore info resta solo il primo nodo con quel valore. La lista dei nodi
// eliminati va gestita da un valore FIFO restituito col return)

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
 FIFO x=pickric_postfix(R,n,k);
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
