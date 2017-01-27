
//soluzione by: Leo M.

// Parte di Teoria
/*

Es1:

int ** F(int * & x)	//tipo ritorno: int**, passaggio di un puntatore per riferimento (x ora è un alias del puntatore d'invocazione)
{ (*x)++;			//deref, ottengo l'ogg puntato ("a" del main) e ne aumento l'R-val di 1
  int **p=&x;		//dichiaro un puntatore locale al puntatore x (inutile!)
  return x; }		//ritorno il puntatore "x" per valore (cioè ne ritorno l'R-val), ma ha tipo int* (anche se è un alias)
main()
{ int a=2, *q=&a;	//"q" è un puntatore ad "a"
  **F(q)=4;		//"q" matcha con "int *x", OK; il tipo di ritorno è "int **" quindi lo posso deref 2 volte (-> occhio!)
  cout<<a<<endl;	//stampo "a"
}
ERRATO:
F ha tipo di ritorno int**, ma ritorna x che ha tipo int*.
(il compilatore dice: "[Error] cannot convert 'int*' to 'int**' in return").
Inoltre il main dereferenzia 2 volte quanto tornato da F: prima ottiene "a" e poi cerca di deref un intero!
(rendendo int* il tipo di ritorno di F, all'invocazione nel main, il compilatore dice: "[Error] invalid type argument of unary '*' (have 'int')").
Nota (?): se F avesse restituito "p" ci sarebbe stata concordanza con il tipo di ritorno (int**), ed "x" sarebbe diventato un alias del puntatore d'invocazione "q";
una volta restituito "p", lo deref, ottengo "x" (che in realtà è "q", e quindi non è dangling), poi deref ulteriormente ed ottengo "a", ci metto dentro il valore "4" e lo stampo.


Es2:

dato int T[3][4][5];
che tipo ha ((*T)+8)[-2]?
((*T)+8)[-2] equivale a: *(((*T)+8)-2), inoltre l'aritmetica NON cambia il tipo (ma solo il valore), pertanto il tipo richiesto è lo stesso di **T che è: int*


Es3:

cosa stampa?
main()
{ int x=1;
  for(int i=0; i<10; i++)
  { cout<<x;
    if(x>0)
      continue;
    else
      break;
    x=0;
  }
}

stampa 1, poi entrerà sempre nel ramo "then" ed il "continue" lo forzerà a saltare sempre tutto ciò che segue (compreso "x=0;")
pertanto stamperà 10 volte 1 (fino a che l'indice non interromperà il ciclo).

*/





// Parte di Programmazione

//Versione 1
#include<iostream>
#include<fstream>
using namespace std;
struct tripla{int prof, riga, colonna; tripla(int a=0, int b=0, int c=0){prof=a; riga=b; colonna=c;}}; //per modellare posizione in sotto-array
bool match(int* X, int r, int c,int H, int L, int lim1, int lim2, int lim3,int * P, int dimP, int el);
int *posiz(int* X, int m, int el, int r, int c, int H, int L, int lim2, int lim3);

main()
{
  ifstream IN("input");

  ofstream OUT("output");
  if(IN && OUT) 
  { 
   
   int X[400],P[50], n_el, dimP, lim1,lim2,lim3;
   
   IN>>lim1>>lim2>>lim3;
   IN>>n_el;
   for(int i=0; i<n_el; i++)
     IN >> X[i];
   int r,c,h,l;
   IN>>r>>c>>h>>l; //definisce sotto-array
   
   IN>>dimP;
   for(int i=0; i<dimP; i++)
    IN>>P[i];

//pattern match sul sotto-array pieno con ordinamento per Strati

   //inizializzazione
   
 int count=0;
 for(int e=0; e<(h*l*lim1-dimP+1); e++)	//garantisco che a partire da e ci siano ancora almeno dimP elementi per poter fare matching
  {
    if(match(X,r,c,h,l,lim1,lim2,lim3,P,dimP,e))
    {
       OUT<<"trovato match a partire dall'elemento "<<e<<endl;
       count++;		//conta quanti match non sovrapposti ho trovato
       e=e+dimP-1;	//evita match sovrapposti
    }
    else
    {
       OUT<<"a partire dall'elemento "<<e<<" non c'e' match"<<endl;
    }
  }
  
   OUT<<"n. totale match="<<count<<endl;

     
   IN.close(); OUT.close(); 
  }
  else
   cout<<"errore con i files";
}

 
int *posiz(int* X, int m, int el, int r, int c, int H, int L, int lim2, int lim3)
{ //PRE&POST: dato un "el" e dato un "m", "posiz" restituisce un punt all'elem "el+m"-esimo, che di certo esiste dato che gli elem sono h*l*lim1, e<=h*l*lim1-dimP ed m<dimP
  int *q=X+r*lim3+c;	//inizializzo il punt all'inizio del sotto-array di interesse
  int str, rig, col;	//variabili ausiliari
  
  rig=r + (((el+m)/L)%H);		//indice della RIGa dove si trova l'elem d'interesse (rispetto a X)
  str=0 + ((el+m)/(H*L));		//indice dello STRato dove si trova l'elem d'interesse (rispetto a X)
  col=c + ((el+m)%L);			//indice della COLonna dove si trova l'elem d'interesse (rispetto a X)
  
  q= X + str*lim2*lim3 + rig*lim3 + col;	//imposto il puntatore q alla corretta posizione da ritornare
  
  return q;
}



bool match(int* X, int r, int c,int H, int L, int lim1, int lim2, int lim3,int * P, int dimP, int el)
{	//PRE=(a partire dall'elem puntato da X seguono almeno dimP elem definiti).
  bool trovato=true;
  for(int m=0; m<dimP && trovato; m++)
  {
    if(*(posiz(X, m, el, r, c, H, L, lim2, lim3))!=*(P+m))
      trovato=false;
  }
  return trovato;
}	//POST=().



/* Versione 2
#include<iostream>
#include<fstream>
using namespace std;

bool match(int* X, int r, int c, int H, int L, int lim2, int lim3, int *P, int dimP, int el);
int *posiz(int* X, int elem, int r, int c, int H, int L, int lim2, int lim3);

main()
{
  ifstream INP("input");	//inizializzazione stream di INPut
  ofstream OUT("output");	//inizializzazione stream di OUTput
  if(INP && OUT)	//check streams status
  { 
   
//inizializzazioni e caricamenti
   
    //inizializzazione variabili array X
    int X[400], n_el, lim1, lim2, lim3;
    INP >> lim1 >> lim2 >> lim3;
    INP >> n_el;

    //caricamento array X
    for(int i=0; i<n_el; i++)
      INP >> X[i];
     
    //inizializzazione variabili del sotto-array
    int r, c, h, l;
    INP >> r >> c >> h >> l; //definisce sotto-array

    //inizializzazione variabili array P
    int P[50], dimP;
    INP>>dimP;

    //caricamento array P
    for(int i=0; i<dimP; i++)
      INP >> P[i];


//pattern match sul sotto-array pieno con ordinamento per: Strati, Righe, Colonne
   
    int count=0;
    for(int e=0; e<(h*l*lim1-dimP+1); e++)	//garantisco che a partire da "e" ci siano ancora almeno dimP elementi per poter fare match
    {
      if(match(X,r,c,h,l,lim2,lim3,P,dimP,e))
      {
        OUT<<"trovato match a partire dall'elemento "<<e<<endl;
        count++;		//conta quanti match non sovrapposti ho trovato
        e=e+dimP-1;	//evita match sovrapposti
      }
      else
      {
        OUT<<"a partire dall'elemento "<<e<<" non c'e' match"<<endl;
      }
    }
  
    OUT<<"n. totale match="<<count<<endl;


    //chiusura streams
    INP.close(); OUT.close(); 
  }
  else
    cout<<"errore con i files";
}



int *posiz(int* X, int elem, int r, int c, int H, int L, int lim2, int lim3)
{ //PRE&POST: data la somma elem=el+m, "posiz" restituisce un punt all'elem "elem-esimo", che di certo esiste dato che gli elementi sono h*l*lim1, e<=h*l*lim1-dimP ed m<dimP
  int *q=X+r*lim3+c;	//inizializzo il punt all'inizio del sotto-array di interesse
  int str, rig, col;	//variabili ausiliari
  
  rig= (elem/L)%H;		//indice della RIGa dove si trova l'elem d'interesse (all'interno del sotto-array di interesse)
  str= elem/(H*L);		//indice dello STRato dove si trova l'elem d'interesse (all'interno del sotto-array di interesse)
  col= elem%L;			//indice della COLonna dove si trova l'elem d'interesse (all'interno del sotto-array di interesse)
  
  q = q + str*lim2*lim3 + rig*lim3 + col;	//imposto il puntatore q alla corretta posizione assoluta da ritornare
  
  return q;
}
 
 
bool match(int* X, int r, int c, int H, int L, int lim2, int lim3, int *P, int dimP, int el)
{	//PRE=(a partire dall'elem puntato da X seguono almeno dimP elem definiti).
  bool trovato=true;
	
  for(int m=0; m<dimP && trovato; m++)
  {
    if(*(posiz(X, el+m, r, c, H, L, lim2, lim3))!=*(P+m))
      trovato=false;
  }
   	
  return trovato;
}	//POST=().
*/
