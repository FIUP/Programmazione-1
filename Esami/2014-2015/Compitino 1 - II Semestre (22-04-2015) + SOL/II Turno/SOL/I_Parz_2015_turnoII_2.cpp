
//soluzione by: Federico Silvio Busetto

/*Integrazione 6 crediti parte di correttezza non richiesta*/

/*
Parte di Teoria:

//Es1:
 
int ** F(int * & x)     //tipo ritorno: int**, passaggio di un puntatore per riferimento (x ora è un alias del puntatore d'invocazione)
{ (*x)++;               //deref, ottengo l'ogg puntato ("a" del main) e ne aumento l'R-val di 1
  int **p=&x;           //dichiaro un puntatore locale al puntatore x (inutile!)
  return x; }           //ritorno il puntatore "x" per valore (cioè ne ritorno l'R-val), ma ha tipo int* (anche se è un alias)
main()
{ int a=2, *q=&a;       //"q" è un puntatore ad "a"
  **F(q)=4;             //"q" matcha con "int *x", OK; il tipo di ritorno è "int **" quindi lo posso deref 2 volte (-> occhio!)
  cout<<a<<endl;        //stampo "a"
}
ERRATO:
F ha tipo di ritorno int**, ma ritorna x che ha tipo int*.
(il compilatore dice: "[Error] cannot convert 'int*' to 'int**' in return").
Inoltre il main dereferenzia 2 volte quanto tornato da F: prima ottiene "a" e poi cerca di deref un intero!
(rendendo int* il tipo di ritorno di F, all'invocazione nel main, il compilatore dice: "[Error] invalid type argument of unary '*' (have 'int')").
Nota (?): se F avesse restituito "p" ci sarebbe stata concordanza con il tipo di ritorno (int**), ed "x" sarebbe diventato un alias del puntatore d'invocazione "q";
una volta restituito "p", lo deref, ottengo "x" (che in realtà è "q", e quindi non è dangling), poi deref ulteriormente ed ottengo "a", ci metto dentro il valore "4" e lo stampo.
 
 
//Es2:

dato int T[3][4][5];
che tipo ha ((*T)+8)[-2]?
((*T)+8)[-2] equivale a: *(((*T)+8)-2), inoltre l'aritmetica NON cambia il tipo (ma solo il valore), pertanto il tipo richiesto è lo stesso di **T che è: int*.
 
 
//Es3:
 
//cosa stampa?
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
 
//stampa 1, poi entrerà sempre nel ramo "then" ed il "continue" lo forzerà a saltare sempre tutto ciò che segue (compreso "x=0;")
//pertanto stamperà 10 volte 1 (fino a che l'indice non interromperà il ciclo).
*/


//Parte di Programmazione
#include<iostream>
#include<fstream>
using namespace std;
struct tripla{int prof, riga, colonna; tripla(int a=0, int b=0, int c=0){prof=a; riga=b; colonna=c;}}; //per modellare posizione in sotto-array

tripla ritornaPos(int index, int l, int h, int lim1, int lim2, int lim3){
	int strato = index/(l*h);
	int rimus =index%(l*h);
	int riga = rimus/l; 	
	int colonna = index%l;

	tripla pos(strato, riga, colonna);
	return pos;
}

bool match (int*X, int r, int c, int h, int l, int lim1, int lim2, int lim3, int* P, int dimP, int e, ofstream& out){
    int inizio = r*lim3+c;	//distanza iniziale del primo elemento dell'array
	tripla pos = ritornaPos(e, l, h, lim1, lim2, lim3);
	int dist = inizio + pos.prof*(lim2*lim3)+pos.riga*(lim3)+pos.colonna;
	//out << e << " pos strato " << pos.prof << ", riga " << pos.riga << ", colonna " << pos.colonna << " distanza "<< dist << endl;
	int i=e;
	bool ok = true;
	for(int j = 0; j < dimP && ok; j++){
		if(X[dist] != P[j]){
			ok = false;
		}
		else{
			//out << " elemento trovato = " << X[dist] << " p " << P[j] << " distanza "<< dist << " "; 
			i++;;
			pos = ritornaPos(i,l,h,lim1,lim2,lim3);
			dist = inizio + pos.prof*(lim2*lim3)+pos.riga*(lim3)+pos.colonna;
			//out << i << " pos succ: " << pos.prof << " pos riga " << pos.riga << " pos colonna " << pos.colonna <<endl;
		}
    }
    return ok;
}


main(){
  ifstream IN("input");
  ofstream OUT("output");

  if(IN && OUT) { 
   
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

//pattern match sul sottoarray  pieno con ordinamento per V-fette 

   //inizializzazione
    int dimSA = lim1*h*l;
    int matchvf=0;
	int jump=1;
	
   //for(esame elementi del sotto-array in ordine per  V-fette da cui può iniziare un match con P)
	for(int e = 0; e < (dimSA-dimP)+1; e+=jump){
		if(match(X,r,c,h,l,lim1,lim2,lim3,P,dimP,e, OUT)){ 
			matchvf++;
			OUT<<"trovato match a partire dall'elemento "<<e<<endl;
			jump = dimP;
		}
		else{ 
			OUT<<"a partire dall'elemento "<<e<<" non c'e' match"<<endl;
			jump=1;
		}
	}
	OUT<<"n. totale match="<< matchvf <<endl;
    IN.close(); OUT.close(); 
  }
  else
   cout<<"errore con i files";
}
