#include<iostream>
using namespace std;

int main(){                                                 //PRE=("input" contiene un intero n_el che soddisfa la condizione 0<n_el<=40, seguito da n_el interi, seguiti a loro volta o dalla coppia "H" x o dalla coppia 'V' y dove x sarà tra 0 e 3 e y tra 0 e 4)
    int X[2][4][5];
    int num_ele, supporto=0;
    char indiceL;
    int indiceN;

    //leggo numero elementi
   do{                                                      //leggi num_ele e ripeti fino a quando non sono compresi tra 0 e 40
   cin >> num_ele;
   }while(num_ele<0 || num_ele>=40);

   //popolo X di num_ele elementi
    for(int z=0; z<2; z++)                                  //R1=(0 <= z < 2) && (letti i primi 0..z-1 strati)
        for(int i=0; i<4; i++)                              //R2=(0 <= i < 4) && (lette le prime 0..i-1 righe dello strato z)
            for(int j=0; j<5 && num_ele!=supporto; j++){    //R3=(0 <= j < 5) && (letti i primi 0..j-1 elementi della riga i) && (supporto e' diverso da num_ele)
                cin >> X[z][i][j];
                supporto++;
            }                                               //POST=(X è riempito di num_ele elementi prima per strato poi per riga e in fine per colonna)

    //input indice lettera, indice numero con controlli
    do{                                                     //ripeti se indiceL non è H o V
        cin >> indiceL;
    }while(indiceL!='H' && indiceL!='V');
    do{                                                     //ripeti (se indiceL è H e indiceN non è compreso tra 0 e 3) || (se indiceL è V e indiceN non é compreso tra 0 e 4)
        cin >> indiceN;
    }while(indiceN<0 && ((indiceL=='H' && indiceN>3) || (indiceL=='V' && indiceN>4)));

    //esecuzione esercizio
    if(indiceL=='H')                                        //se indiceL è H setto supporto in base all'indiceN
        supporto=(indiceN*5)+1;
    if(indiceL=='V')                                        //se indiceL è V setto supporto in base all'indiceN
    supporto=indiceN+1;
    
    bool continua=true;

    for(int z=0; z<2 && continua; z++){                     //R4=(0 <= z < 2) && (letti i primi 0..z-1 strati) && continua
        //controllo se ci sono fette vuote
        if((indiceL=='H' && num_ele<(indiceN+1)*5) || (indiceL=='V' && num_ele<indiceN+1)){
            cout << indiceL << " fetta " << indiceN << " vuota" << endl;
            continua=false;
        }                                                   //POST=(H/V fette 0..3/0..4 vuota)
        //se orizontali
        else if(indiceL=='H'){
                for(int j=0; j<5 && supporto<=num_ele+1; j++){      //R5=(0 <= j < 5) && (letti i primi 0..j-1 elementi della riga indice)
                    cout << X[z][indiceN][j] << " ";
                    supporto++;
                }cout << endl;
                supporto=supporto+(3*5)+1;
            }
            //se verticali
            else if(indiceL=='V'){
                for(int i=0; i<4 && supporto<=num_ele+1; i++){      //R6=(0 <= i < 4) && (letti i primi indiceN elementi delle 0..i-1 righe)
                    cout << X[z][i][indiceN] << " ";
                    supporto=supporto+5;
                }
            }cout << endl;
    }
    cout << "end";
}                                                           //POST=("output" deve contenere gli elementi definiti della fetta specificata dalla coppia letta e nel caso la fetta non abbia elementi definiti, deve scrivere la frase spiegata prima)
