#include<iostream>
#include<fstream>
using namespace std;

void stampaSituazione(int (*B)[7], ofstream & OUT){

	//player 0 → B[0][6]
  cout<<"("<<B[0][6]<<")\t";
  OUT<<B[0][6]<<" ";

	//bucket player 0 → B[0][5..0]
  for(int j=5; j>=0; j--){
    cout<<B[0][j]<<"\t";
    OUT<<B[0][j]<<" ";
  }

  cout<<endl;

	//bucket player 1 → B[1][0..5]
  for(int j=0; j<6; j++){
    cout<<B[1][j]<<"\t";
    OUT<<B[1][j]<<" ";
  }

	//player 1 → B [1][6]
  cout<<"("<<B[1][6]<<")"<<endl<<endl;
  OUT<<B[1][6]<<endl;
}

//POST stampaSituazione=("output" contiene in ordine il contenuto della buca grande alla buca piccola 0 del player 0 e il contenuto della buca piccola 0 alla buca grande del player 1)


void semina(int (*B)[7], int player, int bucket){
	int contenuto=B[player][bucket];
	B[player][bucket]=0;
	
	int p=player;

	//distribuisco sulle buche successive
	for(int b=bucket+1; b<7 && contenuto!=0; b++){
		B[p][b]++;
		contenuto--;
	}
	
	while(contenuto!=0){
		p=(p+1)%2; //player successivo
		int b;
		for(b=0; b<6 && contenuto!=0; b++){ //salto la buca grande
			B[p][b]++;
			contenuto--;
		}
		//b è l'indice della buca grande del player
		if(p==player && contenuto!=0){ //se siamo sulle buche del player
			B[p][b]++;
			contenuto--;
		}
	}
	
}

//POST semina=(il contenuto di B[player][bucket] è stato distribuito in senso anti-orario sulle buche saltando quella grande del giocatore avversario)


main(){
  ifstream IN("input");
  ofstream OUT("output");
  if(IN){
    int B[2][7];
    for(int i=0; i<2; i++)
      for(int j=0; j<7; j++)
        IN>>B[i][j];
//le due parti sono rappresentate in B in modo uguale tra loro (come viste dai giocatori
    
		int mosse;
    IN>>mosse;
    for(int m=1; m<=mosse; m++){
      int p, b;
      IN>>p>>b;
      semina(B, p, b); //esegue la mossa
			OUT<<endl;
    }
		stampaSituazione(B, OUT); //stampa la situazione dopo tutte le mosse
		
  }else{
    cout<<"Errore nell'apertura del file"<<endl;
	}
  IN.close();
  OUT.close();
}
