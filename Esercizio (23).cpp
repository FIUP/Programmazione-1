#include<iostream>
#include<fstream>
using namespace std;
struct E{char T; int fetta, indice; const char* tipo;
E(char a=0, int b=0, int c=0, const char* d=0){T=a; fetta=b; indice=c; tipo=d;}
};

int& FH (int*X, int lim1, int lim2, int lim3, int n_el, int f, int i);
int& FV (int*X, int lim1, int lim2, int lim3, int n_el, int f, int i);

main()
{
 int X[400], lim1, lim2, lim3, n_el, f,indice;
 cin>>lim1>>lim2>>lim3>>n_el;
 for(int i=0; i<n_el; i++)
  cin>>X[i];
 if(n_el > lim1*lim2*lim3)
   n_el=lim1*lim2*lim3;
 for(int i=0; i<4; i++)
 {
 try{
  cin>> f>>indice;
  int&a=FH(X,lim1,lim2,lim3,n_el, f, indice);// da fare
  a=100+f;
  int& b=FV(X,lim1,lim2,lim3,n_el, f, indice); //da fare
  b=100+f;
}
  catch(E e)
   {cout<<e.T<<"-fetta "<<e.fetta<<" indice="<<e.indice<<' '<<e.tipo<<endl;}


 }
  for (int i=0; i<n_el; i++)
  {
    if(!(i%lim3))
     cout<< endl;
    cout<<X[i]<<' ';

  }
   cout<<endl<<"end";
}

int& FH (int*X, int lim1, int lim2, int lim3, int n_el, int f, int i) {
    //una H-fetta contiene lim3 elementi moltiplicato il numero di strati,
    //quindi i varia fra 0 <= i <= lim3*lim1
    int indice = i % lim3, strato = i / lim3; //separo indice dell-elemento nella H-fetta dallo strato della H-fetta
    //trovo in che strato si trova i, trovo la posizione dell,elemento richiesto nello strato e la chiamo indice (0 <= indice <= lim3)

    //puo' succedere che: sono fuori indice (caso 2), sono in un elemento non riempito (caso 3) o sono in un elemento valido (utilizzando un indice valido, caso 1)
    if (((strato < lim1) && (f < lim2) && (indice < lim3)) && (((strato * lim2 * lim3) + (f * lim3) + indice) < n_el)) {
        return *(X+((strato * lim2 * lim3) + (f * lim3) + indice));
    } else if ((strato >= lim1) || (f >= lim2) || (indice >= lim3)) {
        throw E('H', f, i, "elemento non esiste");
    } else {
        throw E('H', f, i, "elemento indefinito");
    }
}

//funziona con la stessa logica di FH
int& FV (int*X, int lim1, int lim2, int lim3, int n_el, int f, int i) {
    int strato = i / lim2, indice = i % lim2;

    if (((strato < lim1) && (indice < lim2) && (f < lim3)) && (((strato * lim2 * lim3) + (indice * lim3) + f) < n_el)) {
        return *(X+((strato * lim2 * lim3) + (indice * lim3) + f));
    } else if ((strato >= lim1) || (indice >= lim2) || (f >= lim3)) {
        throw E('V', f, i, "elemento non esiste");
    } else {
        throw E('V', f, i, "elemento indefinito");
    }
}
