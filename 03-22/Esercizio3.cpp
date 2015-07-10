/*Integrazione 6 crediti
Dato un array int X[3][4][5][10], nel seguito dovete rappresentare
l'R-valore di X con X. Si chiede di:
i) Specificare il tipo di X e la dimensione dell'oggetto puntato
ii) Specificare il valore e il tipo di (*X)+2 e di *(X+2)
iii) Specificare il valore e il tipo di *(X[-8])+8

i) tipo di X = int (*)[4][5][10] 
dim oggetto puntato = 4*5*10*sizeof(int) = 4*5*10*4 
 
ii) tipo di (*X)+2 = tipo di *X = int(*)[5][10]
valore di (*X) + 2 = X + 2*(5*10)*4
tipo di *(X+2) = lo stesso di prima = int(*)[5][10]
valore di *(X+2) = X[2] = X + 2*(4*5*10)*4

iii) tipo di *(X[-8])+8 = int(*)[10]
valore di *(X[-8])+8 = *(*(X-8))+8 = X -8*(4*5*10)*4 + 8*(10)*4*/
#include <iostream>
#include <fstream>
#include <climits>
using namespace std;
    
int sommaRighe(int* X, int lung){
	int somma = 0;																//dichiarazione iniziale
    for (int i = 0;  i<8 && i < lung; ++i)										//8 sono gli elementi di una riga, tra i lung considerati
		somma += *(X+i);														//tramite l'aritmetica dei puntatori aggiungiamo l'elemento a somma
    return somma;																//e ritorniamo
    }
   
main(){
    ifstream IN("input");
    ofstream OUT("output");
  
    if(IN && OUT){
        int X[10][5][8], n_el, *p = **X, somma_max = INT_MIN, somma, index;		//p è un puntatore, necessita di dereferenziare X due volte
																				//inizializziamo somma_max al minimo possibile, occorre includere
																				//la classe climits
    IN >> n_el;
    for (int i = 0; i < n_el; ++i)												//carichiamo n_el elementi nell'array tramite p
        IN >> p[i];
	
	IN.close();
 
    for (int i = 0; i < 5; ++i){												//navighiamo tra le righe
        somma = 0;																//non abbiamo ancora sommato nulla
        for (int s = 0; s < 10; ++s)											//navighiamo tra strati
            somma += sommaRighe(p+s*5*8+i*8, n_el-s*5*8-i*8);					//assegniamo alla somma l'intero ritornato dall'invocazione di sommaRighe
																				//p+s*5*8+i*8 è l'elemento iniziale della riga che stiamo considerando
																				//togliamo gli elementi dei primi s strati e quelli delle righe dello strato
																				//che stiamo considerando
		if(somma >= somma_max){													//se la nuova somma è maggiore della massima trovata in precedenza
            index = i;															//teniamo memoria dell'indice 
            somma_max = somma;													//e la impostiamo come nuova somma_max
        }
    }
  
    OUT << "H fetta massima=" << index;
            
    OUT.close();
     }
     else cout << "errore con i file" << endl;}