/*Integrazione sei crediti*/ 
//Bantumi V2 implementa la cattura come prevista dalle regole del gioco http://mancala.wikia.com/wiki/Kalah
#include<iostream>
#include<fstream>
using namespace std;

void stampa(int B[][7], ofstream & OUT){
	cout<<"("<<B[0][6]<<")\t";
	OUT<<B[0][6]<<" ";
	for(int j=5; j>=0; j--){
		cout<<B[0][j]<<"\t";
		OUT<<B[0][j]<<" ";
		 }
	cout<<endl<<"\t"; 
	for(int j=0; j<6; j++){
		cout<<B[1][j]<<"\t";
		OUT<<B[1][j]<<" ";
	 }
	cout<<"("<<B[1][6]<<")"<<endl;
	cin.clear();
	cin.ignore(255, '\n');
	cin.get();
	OUT<<B[1][6] << endl;
 }
 
/*PRE=(B contiene 14 valori non negativi, player=0/1, buca in [0..5], fagioli>0.
Chiamiamo old_B il valore di B all'invocazione della funzione)*/

bool semina(int B[][7], int player, int buca, int fagioli){
	bool cambio = false, aggiungi = true;
	int p = player, add=0, k; //add fagioli da aggiungere
	B[player][buca] = 0; //svuoto la buca
while(fagioli >0){
	for(int i=player; i<2 && fagioli >0; i++)
		for(int j=buca+1; j<7 && fagioli >0; j++){
			
			if((i == p) || (cambio && j != 6 )){
				if(fagioli ==1 && B[i][j] ==0 && j !=6 && i == p){
					if(i)
						k=0;
					else k=1;
					add = B[k][j]+1;
					B[k][j] =0;
					B[i][6]=B[i][6]+add;
				}
				else (B[i][j])++;
				fagioli--;
				}
		}
		if(fagioli>0){
			if(player)			//non è player 0
				player =0;		//diventa player 0
			else				// è player 0
				player=1;		//cambia
			buca=-1;
			cambio = true;
		}
}
return cambio;
}

/*POST=(B è ottenuta da old_B eseguendo la mossa (player,buca) secondo le regole
del gioco descritte prima. Restituisce true se e solo se alla fine della semina si
verifica il caso (iii))*/

main(){
	ifstream IN("input");
	ofstream OUT("output");
	int p,b, fagioli =0;	
	bool cambio = false; //p = player b = buca
	if(IN && OUT){
		int B[2][7];
		for(int i=0; i<2; i++)
			for(int j=0; j<7; j++)
				IN>>B[i][j];
		stampa(B, OUT); //stampo configurazione iniziale
		IN >> p >> b;
		while(b !=-1){
			OUT << p << " " << b << " " << endl;
			if(B[p][b] !=0){
				fagioli = B[p][b];
				cambio = semina(B, p, b, fagioli);
				stampa(B, OUT);
				if(cambio)
					OUT << "il giocatore cambia" << endl;
				else OUT << "il giocatore non cambia" << endl;
			}
			IN >> p >> b;
		}
		OUT << "fine" << endl;
	 }
	else
		cout<<"Errore con i file"<<endl;
	IN.close();
	OUT.close();
 }
