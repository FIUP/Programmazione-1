//PRE=("input" contiene 2 interi dimT e dimP (tali che 0<dimT<=100 e 0<dimP<=20) seguiti da (almeno) dimT*dimP caratteri)

#include<iostream>
#include<fstream>
using namespace std;

main(){
 	ifstream IN("input");
 	ofstream OUT("output");
 	if(IN){
		int dimT, dimP;
		IN>>dimT>>dimP;
 		char T[dimT], P[dimP];
 		for(int i=0; i<dimT; i++)
//R1=(0<=i<=dimT)&&(T[0..dimT-1 è definito)
 			IN>>T[i];
 		for(int i=0; i<dimP; i++)
//R2=(0<=i<=dimP)&&(P[0..dimP-1 è definito)
 			IN>>P[i];
 		int inizio=-1;
		bool trovato=false;
		for(int i=0; i<dimT-dimP && !trovato; i++){
////R3=(0<=i<=dimT-dimP)&&(se trovato allora T[inizio..inizio+indice]==P[0..dimP-1] e inizio è l'indice più piccolo; se !trovato allora non esistono match di P[0..dimP-1] e T[0..indice-1])
			bool match=true;
			int indice=i;
			for(int j=0; j<dimP && match; j++){
//R4=(0<=j<=dimP)&&(se match allora c'è match tra P[0..j-1] e T[inizio..indice-1]; se !match allora non c'è match completo tra P[0..dimP-1] e T[0..indice-1]
				if(T[indice]==P[j])
					indice++;
				else
					match=false;
			 }
//POST=(match se c'è match tra P[0..dimP-1] e T[inizio..indice]; !match altrimenti)
			if(match)
				inizio=i;
		 }
//POST=(inizio=i se c'è match tra P[0..dimP-1] e T[0..dimT-1]; -1 altrimenti)
		OUT<<inizio;
	 }
	else
 		cout<<"Errore nell'apertura del file"<<endl;
  }
 
//POST=("output" contiene un intero i tale che: se T[0..dimT-1] contiene un match di T[0..dimP-1] allora i sarà il minimo indice a partire dal quale T contiene un match di P, altrimenti i=-1)
