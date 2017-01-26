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

int conta_n(nodot* r)
{
    if (!r)
        return 0;
    else
        return conta_n(r->left) + conta_n(r->right) + 1;
}

nodot* insert(nodot* r, nodot* y)
{
    if (!r)
        return y;

    if (conta_n(r->left) <= conta_n(r->right))
        r->left = insert(r->left, y);
    else
        r->right = insert(r->right, y);
    return r;
}

void stampa_lista(nodo* C)
{
    if (C) {
        cout << C->info << ' ';
        stampa_lista(C->next);
    }
    else
        cout << endl;
}

nodot* build_tree(nodot* R, int n_el)
{
    if (!n_el)
        return R;
    int x;
    cin >> x;

    return build_tree(insert(R, new nodot(x)), n_el - 1);
}

void stampa(nodot* r)
{
    if (r) {
        cout << r->info << '(';
        stampa(r->left);
        cout << ',';
        stampa(r->right);
        cout << ')';
    }
    else
        cout << '_';
}

FIFO concF(FIFO a, FIFO b)
{
    if (!a.primo)
        return b;
    if (!b.primo)
        return a;
    a.ultimo->next = b.primo;
    a.ultimo = b.ultimo;
    return a;
}

FIFO pickric_postfix(nodot* R, int& n, int k)
{
    if (!R)
        return FIFO();
    FIFO sx = pickric_postfix(R->left, n, k);
    FIFO dx = pickric_postfix(R->right, n, k);
    if (!(n % k))
        dx = push_end(dx, new nodo(R->info));
    n++;
    return concF(sx, dx);
}

int lung(nodo* Q)
{
    if (!Q)
        return 0;
    else
        return 1 + lung(Q->next);
}

FIFO tieni_primo(nodo*& Q)
{
    FIFO f;
    int l = lung(Q);
    nodo** k = new nodo*[l];
    nodo* c = Q;
    for (int i = 0; i < l; i++) {
        k[i] = c;
        c = c->next;
    }

    for (int i = 0; i < l - 1; i++) { //R=(esaminati i nodi di vL[Q] partendo da vk[0..i-1] e per ciascuno di essi sono eliminati e messi in f i nodi sucessivi con campo info)
        if (k[i]) {
            for (int j = i + 1; j < l; j++) {
                if (k[j] && k[j]->info == k[i]->info) {
                    nodo* a = k[j];
                    int z = j - 1;
                    while (!k[z]) {
                        z--;
                    }
                    k[z]->next = k[j]->next;
                    a->next = 0;
                    f = push_end(f, a);
                    k[j] = 0;
                }
            }
        }
    }

    return f;
}

main()
{
    int test, n_el, k, n = 1;
    cin >> test >> n_el >> k;

    nodot* R = build_tree(0, n_el);
    cout << "albero:" << endl;
    stampa(R);

    FIFO x = pickric_postfix(R, n, k);
    cout << endl
         << "lista creata:" << endl;
    stampa_lista(x.primo);

    if (test > 0) {
        FIFO y = tieni_primo(x.primo);
        cout << "lista dei nodi tolti" << endl;
        stampa_lista(y.primo);
        cout << "lista dei nodi che restano" << endl;
        stampa_lista(x.primo);
    }

    cout << endl
         << "end" << endl;
}