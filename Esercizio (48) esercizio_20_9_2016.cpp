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

struct FIFOX {
    nodo *primo, *ultimo;
    int valp, valu, nele;
    FIFOX(nodo* a = 0, int b = 0, int c = 0, int d = 0)
    {
        primo = a;
        ultimo = a;
        valp = b;
        valu = c;
        nele = d;
    }
};

ostream& operator<<(ostream& OUT, FIFOX& a)
{
    OUT << '[' << "nele=" << a.nele << " valp=" << a.valp << " valu=" << a.valu << ']' << endl;
    int x = 0;
    nodo* z = a.primo;
    while (x < a.nele) {
        OUT << z->info << ' ';
        z = z->next;
        x++;
    }
    OUT << endl;
    return OUT;
}

FIFOX push_iter (FIFOX A, nodo* b)
{
    if(!A.primo) //se A è vuoto inserisco b
    {
        A.primo = A.ultimo = b;
        A.valp = A.valu = b->info;
        A.nele = 1;
        return A;
    }else{ //se A non è vuoto
        if(A.valp > b->info) //controllo se primo è maggiore (significa che b va davanti)
        {
            b->next=A.primo;
            A.primo=b;
            A.valp=b->info;
            A.nele++;
            return A;
        }
        else if(A.valu < b->info) //controllo se ultimo è minore (significa che b va in fondo)
        {
            A.ultimo->next=b;
            A.ultimo=b;
            A.valu=b->info;
            A.nele++;
            return A;
        }else{  //controllo con tutti se b non deve essere messo fuori dagli estremi
            FIFOX tempA = A;
            for(int i=0; i<A.nele; i++)
            {
                if(tempA.valp < b->info && (tempA.primo->next)->info > b->info){
                    b->next = tempA.primo->next;
                    tempA.primo->next = b;
                    A.nele++;
                    return A;
                }
                tempA.primo = tempA.primo->next;
                tempA.valp = tempA.primo->info;
            }
        }
    }
}

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

nodo*elimina (nodo*lista, int z, bool &presente)
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

FIFOX deleteX(FIFOX A, int z)
{
    if(!(!A.primo || A.valp > z || A.valu < z) )
    {
        A = modifica(A,z);
    }
    
    return A;
}

main()
{
    int dim1, dim2, x;

    cin >> dim1 >> dim2;
    FIFOX a;
    while (dim1) {
        cin >> x;
        a = push_iter(a, new nodo(x));
        dim1--;
    }
    cout << a;

    while (dim2) {
        cin >> x;
        a = deleteX(a, x);
        dim2--;
    }
    cout << a;

    cout << "end" << endl;
}
