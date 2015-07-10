/*Integrazione 6 crediti - Correttezza non richiesta*/
#include<iostream>
#include<fstream>
using namespace std;
 
main(){
  int X[400], *p=X, n_el;									
  int dimt, dims, dimr, dimc, r, c, pos=0;					//dimt torte, dims strati, dimr righe,dimc elementi delle righe 
  bool continua = true, vuoto = true;						//r e c indicano la posizione del tassello, impostati per convenzione
  ifstream IN("input");										//a -1, pos a 0, continua serve ad interrompere il ciclo e vuoto indica
  ofstream OUT("output");									//lo stato del tassello se è vuoto o meno
  
if(IN && OUT){
  IN >>n_el;
  if(n_el >0 && n_el < 401){
	  for (int i=0;i<n_el;i++)
		IN>>X[i];											//All'uscita X ha n_el elementi definiti
  IN >> dimt >> dims >> dimr >> dimc;						//vedo un array P[dimt][dims][dimr][dimc]
  IN >> r >> c; 											//specifica la posizione del tassello da considerare
  IN.close();
  int tassello[dimt*dims];									//il tassello avrà al massimo dims*dimt elementi se è grande come uno strato

  if (r > dimr-1 || c > dimc-1)								//se la posizione del tassello non è valida
	  continua = false;										//non si continua
  
  for(int t=0; t<dimt && t*dims*dimr*dimc <=n_el && continua; t++)							//navigo tra torte se si continua e se siamo in elementi definiti
	  for(int s =0; s<dims && (t*dims*dimr*dimc + s*dimr*dimc)<=n_el && continua; s++){		//navighiamo tra strati se si continua e se siamo in elementi definiti
		  if((t*dims*dimr*dimc + s*dimr*dimc + r*dimc + c) <n_el){							//se k'elemento è definito
			if(vuoto)																		//se vuoto = true
				vuoto = false;																//lo impostiamo a false (inseriremo un elemento nel tassello)
			tassello[pos] = p[t*dims*dimr*dimc + s*dimr*dimc + r*dimc + c];					//mettiamo l'elemento nella giusta posizione del tassello
			pos++;																			//e incrementiamo pos
			}		
		  else continua = false;															//se l'elemento non è definito, non continuiamo
	  }
	if(vuoto)																				//se il tassello è vuoto
		OUT << "Il tassello " << r << " " << c << " e' vuoto" << endl;						//stampiamo su output un messaggio apposito
	else{																					//altrimenti
		OUT << "Il tassello " << r << " " << c << " contiene ";								//stampiamo il tassello in posizione r c contiene
		for(int i =0; i<pos; i++){															//e i suoi elementi
			OUT << tassello[i] << " ";
		}
	}
  OUT.close();
  } else OUT << "Errore n_el non valido"; 
  } else cout << "Errore con i file";
}