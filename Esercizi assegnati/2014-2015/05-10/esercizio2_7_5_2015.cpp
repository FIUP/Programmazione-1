#include<iostream>
#include<fstream>
using namespace std;

int compatta(int *x, int dim, int z, int fino, int cur){	//z è l'elemento da rimuovere, fino indica dove siamo arrivati
															//cur è l'indice del primo elemento diverso da z dopo la posizione fino
   if((fino+cur)>=dim)										//se fino + cur sfonda o arriva in fondo all'array
        return dim-cur;										//ritorniamo la dimensione del nuovo array (l'array viene modificato tramite puntatore)

    x[fino]=x[fino+cur];									//copiamo il primo elemento diverso da z in x[fino]
   
    if(x[fino]==z)											//se x in posizione fino è uguale a z va eliminato
        return compatta(x,dim,z,fino,cur+1);				//tramite un'invocazione ricorsiva di compatta, aggiornando cur (copiamo il prossimo in x[fino])
    return compatta(x,dim,z,fino+1,cur);					//altrimenti spostiamo fino per confrontare il prossimo elemento
   
}

void stampa(int* x, int dim, ofstream& OUT){				//stampa l'array
	if(!dim){												//se dim == 0
		OUT << endl;										//non abbiamo più roba da stampare, andiamo a capo
		return;												//e ritorniamo
	}														//altrimenti
	
	OUT << x[0] << " "; 									//stampiamo l'elemento di testa
		if(dim%4 ==0) 										//a gruppetti di 4 elementi 
			OUT << endl;									
	stampa(x+1,dim-1,OUT);									//stampiamo gli elementi rimanenti spostando il puntatore dell'array e calando la dimensione di uno
}

main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT) 
  { 
   int T[3][4][4], dim,z;
   IN>>dim;
   int* x=**T;
   for(int i=0; i<dim;i++)
    IN>>x[i];
   stampa(x,dim,OUT);//stampa ricorsiva per righe da fare
   OUT<<endl;
   IN>>z;
   
   int ne=compatta(x,dim,z,0,0);//da fare
   stampa(x,ne,OUT);//stampa quello che resta
   OUT<<"fine"<<endl;
   IN.close(); OUT.close(); 
  }
  else
   cout<<"errore con i files";
}
