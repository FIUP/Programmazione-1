/*Integrazione sei crediti*/
#include<iostream>
#include<fstream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};
struct nodoT{int info; nodoT* left,* right; nodoT(int a=0, nodoT* b=0, nodoT* c=0){info=a; left=b;right=c;}};

//PRE = L lista corretta, eventualmente vuota
int contaZero(nodo*L){
	if(!L)
		return 0;
	
	if(L->info ==0)
		return 1 + contaZero(L->next);
	return 0;

}//POST = restituisce il numero di zeri contenuti nella lista L

//PRE=(alt>=0)
nodo* costruisci_L(int alt)
{
  nodo* r=0;
  while(alt)
   {
    r=new nodo(0,r);
    alt--;
   }
  return r;

}
//POST=(restituisce una lista con alt nodi con info=0)

nodoT*buildt()
{
  nodoT* f1=new nodoT(10);
  nodoT* f2=new nodoT(20);
  nodoT*I=new nodoT(15,f1,f2);
  nodoT*R=new nodoT(2,I, new nodoT(23));
  return R;
}
//restituisce un albero per provare la vostra F1
//stampa gli alberi in forma lineare
void stampa_l(nodoT *r, ofstream & OUT)
{
  if(r)
    {
      OUT<<r->info<<'(';
      stampa_l(r->left,OUT);
      OUT<<',';
      stampa_l(r->right, OUT);
      OUT<<')';
    }
  else
    OUT<< '_';
}

//stampa lista 
void stampa_L(nodo* x,ofstream& OUT)
{
  if(x)
  {OUT<<x->info<<' '; stampa_L(x->next,OUT);}
  else
   OUT<<endl;
}

void setZero(nodo* L){										//PRE = L lista corretta, eventualmente vuota
	if(!L)													//se la lista è vuota ritorniamo
		return;												//altrimenti

	L->info = 0;											//Mettiamo il campo info del nodo considerato a zero
	setZero(L->next);										//e scorriamo la lista in avanti
	return;												
}

//PRE=(list(L) corretta, L=vL)
void F0(nodo*L, bool & b){
	if(!L){													//se la lista è vuota
		b= 0;												//la trasformazione non avviene
		return;												//e stop
	}
                
	F0(L->next,b);                          				//altrimenti, scorriamo la lista

	if(L->info ==0 & !b){                            		//se L->info == 0  e non c'è stata trasformazione è l'ultimo zero
		L->info = 1;                              			//lo settiamo a 1
		setZero(L->next);                         			//e poniamo i campi info dei successivi nodi a 0
		b = true;											//la trasformazione è avvenuta
		return;                                   			//e stop
	}                                                               
}
/*POST=( b => lista(L) è ottenuta da lista(vL) facendo la trasformazione richiesta) &&( !b => lista(vL) è tale che
ogni nodo ha campo info=1 e lista(L)=lista(vL))

PRE=(R albero corretto, vuoto)*/
nodoT* aggiungi_nodo(ifstream &INP){   						//Aggiunge un nodo	
    int x;             							 			//Creiamo una variabile intera dove poter salvare il valore letto da INP
    INP>>x;             									//Leggiamo il valore da file di input
    nodoT* R=new nodoT(x);     								//Creiamo un nuovo nodo usando il valore letto
    return R;           									//Restituiamo l'indirizzo del nodo appena creato
}
/*POST=(restituisce l'indirizzo di un nuovo nodo R creato leggendo da INP il valore del campo info)


PRE=( albero(R)corretto, 0<prof, INP ifstream definito, R=vR, INP contiene (almeno) 2(alt+1) -1 valori )*/
nodoT * F1(nodoT* R, int alt, ifstream & INP){
	if(!R)           										//Se non c'è la radice, la creiamo
		R = aggiungi_nodo(INP);
 
    nodo* L=costruisci_L(alt);  							//Costruisci la prima lista vuota
    nodo* currL =L;            								//Puntatore di riferimento all'interno di L
    nodoT* currT =R;            							//Puntatore di riferimento all'interno dell'albero R
    bool b = true;              							//Booleana per F0
 
    while(b){                  								//Finché la lista L non è composta tutta da 1 e non vi si puo' aggiungere più nulla
															// R = (b == true => la lista L presenta almeno uno 0 al suo interno)
        currL = L;             								//Imposta il puntatore all'interno di L all'inizio di L
        currT = R;             								//Imposta il puntatore all'interno dell'albero alla sua radice
		
        while(currL){                               		//Finché ci sono nodi in lista
															//R=(currL non e' vuota)&&(mi trovo al nodo di R che si trova seguendo
															//il percorso scritto dal primo nodo a quello attuale di L)
 
            if(currL->info==0){                           	//Se leggo 0
                if(!currT->left)                        	//e non ho il ramo di sinistra
                    currT->left = aggiungi_nodo(INP);   	//Lo creo
                currT = currT->left;                    	//Mi sposto a sinistra
            }
 
            else{                                      		//Altrimenti, se leggo 1
                if(!currT->right)                     		//e non ho il ramo di destra
                    currT->right = aggiungi_nodo(INP);    	//Lo creo
                currT = currT->right;                    	//Mi sposto a destra
            }
            currL = currL->next;							//scorro la lista in avanti
        }
 
        F0(L, b);                                 			//Creo il prossimo cammino
    }
        return R;
}

/*POST=(albero(R) è ottenuto da albero(vR) aggiungendo tutti i nodi non già presenti in albero(vR) di tutti i
cammini di lunghezza alt, i campi info dei nodi sono letti da INP. I cammini vanno considerati partendo dal
cammino con soli 0, poi applicando F0 ripetutamente )*/
 
main(){
	bool b = true;
	ifstream IN("input");
	ofstream OUT("output");
	if(IN && OUT) { 
		int alt;
   
		IN>>alt;
		nodo*L=costruisci_L(alt);//data
		while(b){
			stampa_L(L,OUT); 
			F0(L,b); //da fare   
		}	
		nodoT*R=F1(0,alt,IN); //da fare
		stampa_l(R,OUT);
		OUT<<endl;
		nodoT*K=buildt();//data
		stampa_l(K,OUT);//data
		OUT<<endl;
		K=F1(K,alt,IN);
		stampa_l(K,OUT);
		IN.close(); OUT.close(); 
	}
	else
		cout<<"errore con i files";
}