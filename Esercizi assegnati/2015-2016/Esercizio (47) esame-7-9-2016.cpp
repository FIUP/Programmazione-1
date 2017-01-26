#include <iostream>
using namespace std;

struct nodo {
    int info;
    nodo* next;
    nodo(int a = 0, nodo* b = 0)
    {
        info = a;
        next = b;
    }
}; // nodo di lista
struct FIFO {
    nodo *primo, *ultimo;
    FIFO(nodo* a = 0)
    {
        primo = a;
        ultimo = a;
    }
};

FIFO push_end(FIFO a, nodo* b)
{
    if (!a.primo) {
        a.primo = a.ultimo = b;
    }
    else {
        a.ultimo->next = b;
        a.ultimo = b;
    }
    return a;
}

struct nodoF {
    FIFO fi;
    nodoF* next;
    nodoF(FIFO a = FIFO(), nodoF* b = 0)
    {
        fi = a;
        next = b;
    }
};

//PRE=(W è una lista corretta di nodoF, a è un nodo con campo next=0, vW=W)
nodoF* inserisci(nodoF* W, nodo* a)
{
    if(!W)
    {
        FIFO fi1 =0;
        fi1=push_end(fi1,a);
        return new nodoF(fi1,0);
    }
    if(W->fi.primo->info == a->info)
    {
        W->fi=push_end(W->fi,a);
        return W;
    }
    if(W->next)
    {
        if(W->fi.primo->info > a->info && W->next->fi.primo->info < a->info)
        {
            FIFO fi2=push_end(fi2,a);
            nodoF* nuovo =new nodoF(fi2);
            nuovo->next= W->next;
            W->next=nuovo;
            return W;
        }
    }
    if(W->fi.primo->info > a->info)
    {
        FIFO fi3=0;
        fi3=push_end(fi3,a);
        nodoF* x= new nodoF(fi3,0);
        x->next=W;
        W=x;
        return W;
    }
    W->next= inserisci(W->next,a);
    return W;
}
/*POST=(restituisce una lista di nodoF ottenuta da vW aggiungendo ad esso il nodo a)
questa asserzione richiede maggiori spiegazioni. Dobbiamo distinguere 2 casi:
i) se in vW c'è già un nodoF che gestisce una sottolista con nodi con campo info=a->info, allora a andrà
aggiunto in fondo a questa sottolista.
ii) se (i) non si applica allora sarà necessario aggiungere un nuovo nodoF a vW che gestisca la sottolista
composta solo dal nodo a e questo nuovo nodoF andrà inserito nel posto di vW tale che prima di lui ci siano
le sottoliste con campo info minori di a->info e dopo di lui quelle con info maggiore di a->info*/

//PRE=(Q è lista corretta di nodo)
nodoF* smembra(nodo* Q)
{
    nodoF* W = 0;
    while(Q)
    {
        nodo* a=new nodo(Q->info, NULL);
        Q=Q->next;
        W= inserisci(W,a);
    }
    return W;
}
//POST=(restituisce una lista concatenata di nodoF che contiene le sottoliste di Q come mostrato nell'esempio 2, cioè in ordine di campo info crescenti)

nodo* LO(nodoF* W)
{
    if(!W) return 0;
    FIFO f=W->fi;
    nodoF* e=W;
    W=W->next;
    delete e;
    f.ultimo->next=LO(W);
    return f.primo;
} 


//funzioni ausiliarie
void stampa_L(nodo* L)
{
    if (L) {
        cout << L->info << ' ';
        stampa_L(L->next);
    }
    else
        cout << endl;
}
void stampa_F(nodoF* a)
{
    if (a) {
        stampa_L(a->fi.primo);
        cout << endl;
        stampa_F(a->next);
    }
    else
        cout << endl;
}

nodo* costruisci(int dim)
{
    if (dim) {
        int x;
        cin >> x;
        return new nodo(x, costruisci(dim - 1));
    }
    return 0;
}

main()
{
    int dim;

    cin >> dim;
    nodo* C = costruisci(dim);

    cout << "Lista costruita" << endl;
    stampa_L(C);
    nodoF* a = smembra(C);
    cout << "Liste uniformi:" << endl;
    stampa_F(a);

    nodo* b = LO(a);
    cout << "Lista ordinata" << endl;
    stampa_L(b);
    cout << "end";
}
