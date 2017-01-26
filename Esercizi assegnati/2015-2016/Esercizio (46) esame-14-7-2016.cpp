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
    FIFO(nodo* a = 0, nodo* b = 0)
    {
        primo = a;
        ultimo = b;
    }
};
struct nodot {
    int info;
    nodot *left, *right;
    nodot(int a = 0, nodot* b = 0, nodot* c = 0)
    {
        info = a;
        left = b;
        right = c;
    }
}; //nodo di albero
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

FIFO push_begin(FIFO x, nodo* b)
{
    if (!x.primo) {
        x.primo = x.ultimo = b;
    }
    else {
        b->next = x.primo;
        x.primo = b;
    }
    return x;
}

bool cerca(nodo* n, int val)
{
    if (!n)
        return false;
    if (n->info == val)
        return true; //match = val trovato
    return cerca(n->next, val); // cerca nei nodi successivi
}

FIFO tieni_ultimo_ric(nodo*& Q)
{
    if (!Q)
        return FIFO();
    //scorro fino all'ultimo nodo
    FIFO temp = tieni_ultimo_ric(Q->next);

    //se Q attuale ha un next
    if (Q->next) {
        //se i prossimi nodi di Q attuale hanno campo info uguale a Q->info
        if (cerca(Q->next, Q->info)) {
            //salvo Q attuale
            nodo* salva = new nodo(Q->info, 0);
            //Tolgo Q attuale dalla lista
            Q = Q->next;
            //metto il Q salvato all'inizio di temp
            return push_begin(temp, salva);
        }
    }

    return temp;
}

// cerca iterativamente
bool seek(nodo* n, int v)
{
    while (n) //finche ho nodi
    {
        if (n->info == v) // ho ridondanza => ricerca riuscita
            return true;
        n = n->next; // sposta avanti ptr
    }

    return false; // ricerca fallita
}

FIFO tieni_ultimo_iter(nodo*& q)
{
    FIFO tenuti = FIFO();
    FIFO tolti = FIFO();

    if (!q)
        return FIFO();

    while (q) //finche ho nodi
    {

        if (seek(q->next, q->info)) // aggiungo a tolti
        {
            tolti = push_end(tolti, q);
        }

        else // aggiungo a tenuti
            tenuti = push_end(tenuti, q);

        q = q->next; //sfilo da lista iniziale
    }

    tenuti.ultimo->next = 0;
    tolti.ultimo->next = 0; // setto a null la fine delle fifo

    q = tenuti.primo; // reimposto q sulla lista non ridondante, furbetto

    return tolti; // ritorno la fifo dei tolti
}

void stampa_L(nodo* L)
{
    if (L) {
        cout << L->info << ' ';
        stampa_L(L->next);
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
nodo* clone(nodo* a)
{
    if (a) {
        return new nodo(a->info, clone(a->next));
    }
    return 0;
}
main()
{

    int dim;

    cin >> dim;
    nodo* C = costruisci(dim);
    nodo* D = clone(C);
    cout << "Lista costruita" << endl;
    stampa_L(C);
    FIFO a = tieni_ultimo_ric(C);
    cout << "soluzione ricorsiva" << endl
         << "nodi tolti:" << endl;

    stampa_L(a.primo);
    cout << "lista rimanente:" << endl;
    stampa_L(C);
    FIFO b = tieni_ultimo_iter(D);
    cout << "soluzione iterativa" << endl
         << "nodi tolti:" << endl;
    stampa_L(b.primo);
    cout << "lista rimanente:" << endl;
    stampa_L(D);
    cout << "end";
}
