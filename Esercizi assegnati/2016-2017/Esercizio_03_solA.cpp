// soluzione di B.Cosentino
#include<iostream>
using namespace std;


int main()
{
	char pl1, pl2;
	cin>>pl1;
	cin>>pl2;
	
	if ((pl1!='f' and pl1!='s' and pl1!='c') or (pl2!='f' and pl2!='s' and pl2!='c')){
		//pl1,pl2 diversi da f,c,s
		cout << "mossa non valida" << endl;
	
	} else {
		//pl1=f,c or s e pl2=f,c or s
		if (pl1==pl2) {
			//pl1=pl2
			cout << "pareggio" <<endl;
			
		} else {
			//pl1!=pl2
			//pl1=='f' o pl1=='c' o pl1=='s'
			
			if (pl1=='f') {
				//pl2=='c' o pl2=='s'
				
				if (pl2=='c') {
					
					cout << "vince il giocatore 1" <<endl;
				
				} else {
					//pl2=='s'
					
					cout << "vince il giocatore 2" <<endl;
				}
			}
			
			if (pl1=='c') {
				//pl2=='f' o pl2=='s'
					
				if (pl2=='s') {
					
					cout << "vince il giocatore 1" <<endl;	
				
				} else {
					//pl2=='f'
					
					cout << "vince il giocatore 2" <<endl;
					
				}
			}
					
			if (pl1=='s') {
				//pl2=='f' o pl2=='c'
				
				if (pl2=='f') {
				
				cout << "vince il giocatore 1" << endl;
				
				} else {
					//pl2=='c'
					
					cout << "vince il giocatore 2" << endl;
					
				}
			}
			
		}
					
	}
	cout << "end" <<endl;	
}				
