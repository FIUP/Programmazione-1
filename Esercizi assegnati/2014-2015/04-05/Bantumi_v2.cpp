/*Integrazione sei crediti Funzionante secondo le regole del pdf*/ 
#include<iostream>
#include<fstream>
using namespace std;

void stampa(int B[][7], ofstream & OUT){							//funzione di stampa su output standard e file 
	cout<<"("<<B[0][6]<<")\t";										//gia vista in bantumi 1
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
	cin.clear();													//istruzioni per bloccare la schermata del prompt in windows
	cin.ignore(255, '\n');											//istruzioni per bloccare la schermata del prompt in windows
	cin.get();														//istruzioni per bloccare la schermata del prompt in windows
	OUT<<B[1][6] << endl;
 }
 
/*PRE=(B contiene 14 valori non negativi, player=0/1, buca in [0..5], fagioli>0.
Chiamiamo old_B il valore di B all'invocazione della funzione)*/

bool semina(int B[][7], int player, int buca, int fagioli){			//B è la tavola, player il giocatore corrente
	bool cambio = true, inverti = false;							//cambio ci dice se occorre cambiare, inverti inverte il giro
	int p = player, add=0, k; 										//add fagioli da aggiungere
	B[player][buca] = 0; 											//svuoto la buca scelta da player
while(fagioli >0){													//se ci sono fagioli
	for(int i=player; i<2 && fagioli >0; i++)						//partiamo con la semina finchè ne abbiamo
		for(int j=buca+1; j<7 && fagioli >0; j++)					//a partire dalla buca successiva
			if(j !=6){												//se non siamo su una buca grande (granaio)
				if(fagioli ==1 && B[i][j]==0){						//se l'ultimo fagiolo cade in una buca vuota
					if(!inverti){									//se siamo sul nostro lato della tavola
						if(i)										//giriamo la tavola
							k=0;									//invertendo il giocatore
						else k=1;									
						add = B[k][j]+1;							//prendiamo i fagioli della buca opposta
						B[k][j] =0;									//la svuotiamo
						B[i][6]=B[i][6]+add;						//e aggiungiamo il tutto al granaio del giocatore
						fagioli--;									//scaliamo poi il fagiolo che abbiamo seminato
					}
					else{											//se invece siamo nel lato opposto della tavola
						B[p][6]=B[p][6]+1;							//seminiamo normalmente un fagiolo
						fagioli--;									//e lo scaliamo dai rimanenti
					}
				}
				else{												//abbiamo più di un fagiolo o la buca non è vuota
					(B[i][j])++;									//aumentiamo i fagioli in buca di uno
					fagioli--;										//e scaliamo uno da quelli ancora da seminare
				}
			}														
			else{													//altrimenti j = 6 siamo su una buca grande
				if(fagioli ==1 && i==p)								//se è l'ultimo fagiolo e siamo nella buca del giocatore	
					cambio = false;									//non cambiamo
				if(i==p){											//ma 
					(B[i][j])++;									//aggiungiamo un fagiolo al granaio del giocatore
					fagioli--;										//e scaliamo dai rimamenti
				}
				if(player)											//non è player 0
					player =0;										//diventa player 0
				else												// è player 0
					player=1;										//cambia
				buca=-1;											
				inverti = true;
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
			cout << "Mossa player " << p << " buca "<< b << endl; 
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
