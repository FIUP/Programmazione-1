
//soluzione by: Leo M.

#include<iostream>
using namespace std;

int main()
{	//PRE
	int T[10][10], dimT;
	cin>>dimT;
	
	int rp=dimT/10, eur=dimT%10;	//rp=Righe Piene; eur=Elementi Ultima Riga
	int t_col=0, t_rig=0;			//indici per scorrere T
	while(t_rig<rp)					//riempio le righe complete (se ce ne sono) di T
	{
		t_col=0;					//reset indice per scorrere i singoli elementi di una riga
		while(t_col<10)
		{
			cin >> T[t_rig][t_col];
			t_col++;
		}
		t_rig++;
	}
	t_col=0;						//reset indice
	while(t_col<eur)				//riempio (se c'è) la riga incompleta
	{
		cin >> T[rp][t_col];
		t_col++;
	}
	
/*
//doppio ciclo che stampa la matrice T con la giusta formattazione, utile per il debug
	cout<<endl<<"Matrice T:"<<endl;
	t_col=0; t_rig=0;				//reset indici per scorrere la matrice T
	while(t_rig<rp)					//riempio le righe complete (se ce ne sono) di T
	{
		t_col=0;					//reset indice per scorrere i singoli elementi di una riga
		while(t_col<10)
		{
			cout << T[t_rig][t_col] << " ";
			t_col++;
		}
		cout << endl;
		t_rig++;
	}
	t_col=0;						//reset indice
	while(t_col<eur)				//riempio (se c'è) la riga incompleta
	{
		cout << T[rp][t_col] << " ";
		t_col++;
	}
	cout<<endl<<endl;
*/



	t_rig=0; t_col=0;				//reset indici per scorrere la matrice T
	int bestElem;					//miglior elemento
	int nBestElem=11;				//numero di occorrenze di bestElem, inizializ a 11 perchè il massimo può essere 10 (una riga intera dello stesso numero)
	int riga=-1;					//riga dove c'è bestElem
	
	while(t_rig<rp)					//gestisco (se ce ne sono) le righe piene
	{
		t_col=0;					//reset indice
		while(t_col<10)
		{
			int elem=T[t_rig][t_col]; 	//elemento di cui verificare in numero di occorrenze
			int nElem=0;				//numero di occorrenze di elem
			int k=0;					//indice ausiliario
			
			while(k<10)
			{
				if(elem==T[t_rig][k])
					nElem++;
				k++;
			}
			
			/*
			La tripla (m,n,k) rappresenta il fatto che nella riga m il valore n ripete k volte. La tripla (m,n,k) è minima tra quelle esistenti
			per T se per ogni altra tripla (j,q,p), vale che: o p>k oppure, se p=k, allora q>n oppure, se p=k e q=n, allora j<m.
			*/
			if(nElem<=nBestElem)							//p>k oppure p=k
			{
				if(nElem<nBestElem)							//p>K
				{
					nBestElem=nElem;
					bestElem=elem;
					riga=t_rig;
				}
				else	//cioè nElem=nBestElem				//p=k
				{
					if(elem<=bestElem)						//q>n (se q=n dovrei vedere le righe, ma dato che le righe sono progressive prenderò l'ultima che sarà la maggiore)
					{
						nBestElem=nElem;
						bestElem=elem;
						riga=t_rig;
					}
					//sarebbe meglio gestire bene anche i casi della riga.
				}
			}
			
			t_col++;
		}
		
		t_rig++;
	}
	
	/*
	NOTA:
	il seguente ciclo while gestisce solo l'ultima riga nel caso essa sia incompleta, pertanto si potrebbe accorpare al codice soprastante che gestisce le righe piene.
	- il ciclo while più esterno cambia la sua condizione in (t_rig<rp+1);
	- va aggiunta una variabile el (Elementi Riga) che ha sempre valore 10 (valore di stop dei cicli interni) per tutte le righe piene, e quando t_rig=rp -> el=eur;
	- tale var "el" và settata in un condizionale da inserire come prima istruzione del while più esterno;
	- PS: è evidente che anche se eur=0 verrà cominciato il while più esterno (a causa del "rp+1") ma poi nulla verrà fatto in quanto t_col<eur -> false.
	*/
	t_col=0;							//reset indice
	while(t_col<eur)					//gestisco (se c'è) la riga incompleta
	{
			int elem=T[rp][t_col]; 		//elemento di cui verificare in numero di occorrenze
			int nElem=0;				//numero di occorrenze di elem
			int k=0;					//indice ausiliario
			
			while(k<eur)
			{
				if(elem==T[rp][k])
					nElem++;
				k++;
			}
			
			//stessi controlli di prima
			if(nElem<=nBestElem)
			{
				if(nElem<nBestElem)
				{
					nBestElem=nElem;
					bestElem=elem;
					riga=t_rig;
				}
				else
				{
					if(elem<=bestElem)
					{
						nBestElem=nElem;
						bestElem=elem;
						riga=t_rig;
					}
				}
			}
			
			t_col++;
		}
	
	cout<<"Nella riga "<<riga<<", il valore "<<bestElem<<" si ripete "<<nBestElem<<" volte."<<endl;
	
	
}	//POST



/*
PRE=(cin contiene dimT (0<dimT<=100), seguito da dimT valori).

POST=(il programma stampa la tripla m n k che è la massima tra quelle esistenti per T).
*/
