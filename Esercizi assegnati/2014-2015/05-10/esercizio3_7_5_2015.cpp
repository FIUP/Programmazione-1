/*Integrazione sei crediti*/
#include<iostream>
#include<fstream>
using namespace std;

int trad(int e){												
        int strato = e/(4*4);									//definisce lo strato in cui siamo
        e = e%(4*4);											//e = elemenenti rimanenti dell'ultimo strato
		//e = e - strato*4*4;								
        int riga = e/4;											//definisce la riga in cui siamo
        int colonna = e%4;										//e la colonna
		
        return strato*4*4 + colonna*4 + riga;					//ritorna la posizione dell'elemento
}
 
int compattaC(int* x, int dim, int z, int fino, int cur){		//compatta l'array
    if(cur >=dim)												//se l'elemento prossimo è maggiore di dim
		return fino;											//ritorniamo la posizione fino che è la nuova dimensione dell'array
	else{														//altrimenti
        if (x[trad(cur)] != z){									//se l'elemento considerato non coincide con l'elemento da eliminare
            x[trad(fino)] = x[trad(cur)];						//copiamo l'elemento in cur sulla posizione fino
            fino++;												//incrementiamo fino
        }														//altrimenti
        cur++;													//incrementiamo cur
        return compattaC(x, dim, z, fino, cur);					//e compattiamo l'array (eliminando di fatto l'elemento trovato)
    }
}

void stampaRiga(int* x, int dim, ofstream& OUT){				//stampa una riga, sia che sia piena, che no
	if(!dim){													//se finiamo la riga
		OUT << endl;											//andiamo a capo
		return;													//e ritorniamo
	}															//altrimenti
	
	OUT << x[0] << " "; 										//stampiamo l'elemento
	if((dim+3)%4 ==0) 											//consideriamo l'ordine in colonne se è l'ultimo elemento
		OUT << endl;											//andiamo a capo
	stampaRiga(x+1,dim-1,OUT);									//e invochiamo ricorsivamente aggiustando puntatore e dimensione
}
 
void stampaUltimo(int *x, int cp, int rim,int dim, ofstream &OUT){
    if (!dim)													//caso base:raggiunta la fine dello strato			
        return ;
 
    if (rim){													//se ci sono elementi rimanenti
        stampaRiga(x,cp+1,OUT);									//stampiamo la riga tramite stampaRiga (la riga ha un elemento in più)
		stampaUltimo(x+4,cp,rim-1,dim-(cp+1),OUT);				//invochiamo ricorsivamente stampaUltimo, aggiornando il puntatore alla riga
    }															//scaliamo rim di uno e la dimensione della riga (cp+1 uno è l'elemento extra)
    else{														//altrimenti se non ci sono elementi rimanenti
        stampaRiga(x,cp,OUT);									//stampaRiga stampa la riga normalmente
        stampaUltimo(x+4,cp,rim,dim-cp,OUT);					//stampaUltimo aggiorna solo il puntatore (rim è già a 0) e da dim scaliamo 
    }      														//la dimensione normale di una riga
}

 
void stampa(int *x, int dim, ofstream &OUT){
    if (!dim)													//caso base: raggiunto il limite dell'array
        return;
 
    int cp=dim/4;												//dimensione base delle righe, corrisponde alle colonne piene
    int rim=dim%4;												//elementi ultima colonna, righe con +1 elementi
 
    if (cp>=4){ 												//c'è almeno uno strato completo
		stampaRiga(x,(4*4),OUT);								//stampiamo le riga tramite l'invocazione di stampaRiga
        stampa(x+(4*4),dim-(4*4),OUT);							//invochiamo ricorsivamente stampa aggiornando il puntatore x e scalando 
    }															//gli elementi stampati da dim
 
    else 														//sono nell'ultimo strato, non completo!
       stampaUltimo(x,cp,rim,dim,OUT);							//lo stampiamo con una funzione apposita
}

main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT) 
  { 
   int T[3][4][4], dim,z, *x=**T;
   IN>>dim;
   int count=dim;
//riempie T per strati e colonne
   for(int i=0; i<3 && count>0;i++)
    for(int  j=0; j<4&&count>0;j++)
      for(int k=0;k<4&&count>0;k++){
		  IN>>T[i][k][j];count--;
	    }
   IN>>z;
   
   stampa(x,dim,OUT);//stampa ricorsiva per strati e per righe, considerando solo elementi definiti
   
   int ne=compattaC(x,dim,z,0,0);//da fare
   
   stampa(x,ne,OUT); //stampa dell'array dopo il compattamento
   OUT<<"fine"<<endl;
   IN.close(); OUT.close(); 
  }
  else
   cout<<"errore con i files";
}
