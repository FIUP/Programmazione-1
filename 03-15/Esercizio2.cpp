#include<iostream>
#include<fstream>
using namespace std;
 
main(){
  int A[2][4][5], *p=**A, n_el;							//p punterà ad A
  ifstream IN("input");
  ofstream OUT("output");
  
if(IN && OUT){										
  IN >>n_el;
  if(n_el >=0 && n_el < 41){							//n_el dev'essere compreso tra 0 e 40
	  for (int i=0;i<n_el;i++)							//carichiamo l'array a, tramite p, di n_el elementi
		IN>>p[i];
  char value;											//varrà V o H
  int index;											//l'indice della fetta
  IN >> value >> index;
  IN.close();									
 
  if (value=='V'){										//se value vale V è una V-Fetta 
    if (index>=n_el)									//se l'indice è maggiore uguale a n_el la V-fetta è vuota
        OUT << "V fetta "<<index<<" vuota"<< endl;		//e scriviamo in output un errore
    else{												//altrimenti
        while (index<n_el){								//finché ci sono elementi
           OUT << p[index]<< " ";						//li stampiamo nel file
           index+=5;									//portiamo avanti l'indice di 5 (saltiamo una riga per arrivare al prossimo elemento)
        }
    }
   }
  else if (value == 'H'){								//se value vale H è un H-fetta
      if (index>(n_el/5))								//se index è maggiore di n_el/5, la riga (e quindi l'H fetta è vuota) 
        OUT << "H fetta "<<index<<" vuota"<< endl;		//e scriviamo in output un errore
      else{												//altrimenti
          int iterator=index*5;							//creiamo un iteratore intero che punta al primo elemento dell'H-Fetta
          while(iterator<n_el){							//finché l'iteratore è minore di n_el siamo nella parte definita dell'array
              if (iterator%5==4){						//se iterator%5 vale 4 vuol siamo a fine riga
                  OUT << p[iterator] << " ";			//stampiamo su output l'elemento
                  iterator+=16;							//incrementiamo l'iteratore per arrivare all'altro strato saltando (5*3 righe +1 elemento)
                }
              else{										//altrimenti
                  OUT << p[iterator] << " ";			//stampiamo l'elemento normalmente	
                  iterator++;							//e incrementiamo l'iteratore di uno a puntare all'elemento successivo
                }
            }
        }
    }
  OUT.close();
  } else OUT << "Errore n_el non valido"; 
  } else cout << "Errore con i file";
}