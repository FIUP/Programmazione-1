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
	int somma = 0;
    for (int i = 0; i < 8 && i < lung; ++i)
		somma += *(X+i);
    return somma;
    }
   
main(){
    ifstream IN("input");
    ofstream OUT("output");
  
    if(IN && OUT){
        int X[10][5][8], n_el, *p = **X, somma_max = INT_MIN, somma, index;
  
    IN >> n_el;
    for (int i = 0; i < n_el; ++i)
        IN >> p[i];
	
	IN.close();
 
    for (int i = 0; i < 5; ++i){
        somma = 0;
        for (int s = 0; s < 10; ++s)
            somma += sommaRighe(p+s*5*8+i*8, n_el-s*5*8-i*8);
		if(somma >= somma_max){
            index = i;
            somma_max = somma;
        }
    }
  
    OUT << "H fetta massima=" << index;
            
    OUT.close();
     }
     else cout << "errore con i file" << endl;}