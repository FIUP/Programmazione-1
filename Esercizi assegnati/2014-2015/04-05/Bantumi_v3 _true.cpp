/*Integrazione sei crediti implementa le regole del gioco come descritto su http://mancala.wikia.com/wiki/Kalah */ 
#include<iostream>
#include<fstream>
using namespace std;

int reversePlayer(int player){
	if(player)			//non è player 0
		player =0;		//diventa player 0
	else				// è player 0
		player=1;		//cambia
	return player;
}

bool checkFine(int B[][7], int p){
	bool vuoto =true;
	for(int j=0; j<6; j++){
		if(B[p][j] != 0)
			vuoto = false;
	}
	return vuoto;
}

void win(int B[][7], ofstream& out){
	if(B[0][6] > B[1][6])
		out << "vince il giocatore 0 con " << B[0][6] << " fagioli, mentre il giocatore 1 ne ha " << B[1][6]<<endl;
	else if(B[1][6] > B[0][6])
		out << "vince il giocatore 1 con " << B[1][6] << " fagioli, mentre il giocatore 0 ne ha " << B[0][6]<<endl;
	else out << "entrambi i giocatori hanno " <<B[0][6] << " fagioli, la partita finisce in parità"<<endl;
	
}

void steal(int B[][7], int p, int b){
	int pos = reversePlayer(p);
	int add = B[pos][6-(b+1)]+1;
	B[pos][6-(b+1)] =0;
	B[p][6] += add;
}

bool checkMossa(int B[][7], int p, int b, ofstream& OUT){
	bool corretta = true;
	if(p !=0 && p !=1)
		corretta=false;
	else
		if(b >5 || b <0)
			corretta = false;
			
	if(B[p][b] == 0)
		corretta = false;
	
	return corretta;
}

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
	bool cambio = true;
	int p = player; 
	B[player][buca] = 0; //svuoto la buca
while(fagioli >0){
	for(int i=player; i<2 && fagioli >0; i++)
		for(int j=buca+1; j<7 && fagioli >0; j++)
			if(j !=6){
				if(fagioli ==1 && B[i][j]==0 && i==p){
					steal(B,p,j);
					fagioli--;
				}
				else{
					(B[i][j])++;
					fagioli--;
				}
			}
			else{
				if(fagioli ==1 && i==p)
					cambio = false;
				if(i==p){
					(B[i][j])++;
					fagioli--;
				}
				player=reversePlayer(player);
				buca=-1;
			}
			
}
return cambio;
}

/*POST=(B è ottenuta da old_B eseguendo la mossa (player,buca) secondo le regole
del gioco descritte prima. Restituisce true se e solo se alla fine della semina si
verifica il caso (iii))*/

main(){
	ifstream IN("input.txt");
	ofstream OUT("output");
	int p,b, fagioli =0;   //p = player b = buca 
	bool cambio = false, termina = false;  
	if(IN && OUT){
		int B[2][7];
		for(int i=0; i<2; i++)
			for(int j=0; j<7; j++)
				IN>>B[i][j];
		stampa(B, OUT); //stampo configurazione iniziale
		IN >> p >> b;
		while(b !=-1 && !termina){
			OUT << "il giocatore " << p << " fa la mossa " << b  << endl;
			cout << "Mossa player " << p << " buca "<< b << endl; 
			if(checkMossa(B,p,b, OUT)){
				if(B[p][b] !=0){
					fagioli = B[p][b];
					cambio = semina(B, p, b, fagioli);
					termina = checkFine(B,p);
					stampa(B, OUT);
					if(termina)
						win(B,OUT);

					if(cambio){
						//OUT << "il giocatore cambia" << endl;
						p=reversePlayer(p);
					}
							
					//else OUT << "il giocatore non cambia" << endl;
				}
			}
			else {
				p = reversePlayer(p);
				OUT << "mossa sbagliata, il turno passa al giocatore " << p<<endl;
			}
				
			IN >> b;
		}
		OUT << "fine" << endl;
	 }
	else
		cout<<"Errore con i file"<<endl;
	IN.close();
	OUT.close();
 }
