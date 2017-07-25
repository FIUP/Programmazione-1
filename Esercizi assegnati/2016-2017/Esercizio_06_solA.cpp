// soluzione di B.Cosentino
#include<iostream>
using namespace std;

//PRE: cin contiene un intero positivo n>0 e 2*n char corrispondenti alle mosse della morra cinese dei due giocatori 

int main()
{
	int n, count1=0, count2=0;			//count1 e count2 sono dei contatori di vittorie di pl1 e pl2
	
	cin >> n;   //n=vn (vn significa "vecchio n", cioe' quello iniziale), vcount1=0, vcount2=0  
	
	while (n>0){ //R=(n>=0 && count1+count2=somma punteggi vn-n partite && cin contiene 2*n char)		k è R-valore di n prima dell'esecuzione del corpo del while
	
		
	char pl1, pl2;
	cin>>pl1;
	cin>>pl2;
	// cin contiene adesso 2*n-2 = 2*(n-1) char
		//pl1='f','c' or 's'  e pl2='f','c' or 's'
		if (pl1==pl2) {
			//pl1=pl2
		} else {
			//pl1!=pl2
			//pl1='f' o pl1='c' o pl1='s'					
			if (pl1=='f') {
				//pl2=='c' o pl2=='s'					
				if (pl2=='c') {						
					count1=count1+1;		//Vittoria di pl1			
				} else {
					//pl2='s'						
					count2=count2+1;		//Vittoria di pl2
				}
			}
			
			if (pl1=='c') {
				//pl2='f' o pl2='s'
				if (pl2=='s') {
					count1=count1+1;		//Vittoria di pl1
				} else {
					//pl2='f'
					count2=count2+1;		//Vittoria di pl2
				}
			}							
			if (pl1=='s') {
				//pl2='f' o pl2='c'
				if (pl2=='f') {
					count1=count1+1;		//Vittoria di pl1. 
				} else {
					//pl2='c'
					count2=count2+1;		//Vittoria di pl2
				}
			}
					
		}
	n=n-1;  // Decremento di uno.
	// All'inizio dell'esecuzione del corpo del while n > 0 -> n = n-1 > -1 -> n > -1 -> n>=0
	// Dal momento che n=n-1 e cin contiene 2*(n-1) char, segue che cin contiene 2*n char.
	//Dopo l'esecuzione del corpo del while, n>=0 && count1+count2=(somma punteggi vn-n partite && cin contiene 2*n char) 
	}
	//R && n<=0  =>  post: n=0 e count1+count2=somma vn partite e cin contiene 0 char  (vn-n=vn-0=vn)


	if (count1==count2){  //Confronto il numero di volte in cui pl1 e pl2 hanno vinto o perso
	
	cout << "Pareggio" <<endl;		
	} else {			
		if(count1>count2){
			cout << "Vince il Giocatore 1" <<endl;			
		} else {			
			cout << "Vince il Giocatore 2" <<endl;			
		}
	}
	cout<<"end"<<endl;
}
