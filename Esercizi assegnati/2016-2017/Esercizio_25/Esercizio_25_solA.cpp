// soluzione di B.Cosentino
#include<iostream>
using namespace std;

main()
{
	cout<<"start"<<endl;
	int A[3][4][5], *p=A[0][0],n_ele;
	cin>>n_ele;
	
	for(int i=0; i<n_ele; i=i+1)
		cin>>p[i];

	char c;
	int f;
	cin >> c >> f;
	
	if(c=='H'){
		if (n_ele <= f * 5){
			cout << "fetta richiesta vuota" << endl;
		} else {
			int pieni= n_ele/20; // numero strati pieni
			int N_rpiene= (n_ele%20)/5; // numero righe piene del primo strato non pieno
			int el_uriga= (n_ele%20)%5; // numero elementi dell'ultima riga da stampare 
			for (int i=0; i<pieni; i=i+1){ 
		    // R1 = (0<=i<=pieni) & (ho stampato gli strati pieni della H-fetta f da 0 a i-1)
				for (int j=0; j<5; j=j+1){
				// R2 = (0<=j<=5) & (ho stampato gli elementi dello strato (pieno) i della H-fetta da 0 a j-1)
					cout << A[i][f][j] << " ";
				}
				cout << endl;
			}
			if (f<=N_rpiene-1)
				el_uriga=5;
				
		    for (int i=0; i < el_uriga; i=i+1){
            // R3 = (0<=i<=el_uriga) & (ho stampato gli elementi dell'ultimo strato (non pieno) della H-fetta f da 0 a i-1)
				cout << A[pieni][f][i] << " ";
			}
			cout << endl;
			
		}
	} else {
		if (n_ele <= f*4){
			cout << "fetta richiesta vuota" << endl;
		} else {
			int pieni=n_ele/20; // numero strati pieni
			int N_rpiene=(n_ele%20)/5; // numero colonne piene
			int el_ucolonna=(n_ele%20)%5; // numero elementi dell'ultima colonna da stampare
			for (int i=0; i<pieni; i=i+1){
			// R4 = (0<=i<=pieni) & (ho stampato gli strati pieni della V-fetta f da 0 a i-1)
				for (int j=0; j<4; j=j+1)
				// R5 = (0<=j<=4) & (ho stampato gli elementi dello strato (pieno) i della V-fetta da 0 a j-1)
					cout << A[i][j][f] << " ";
				cout << endl;	
			}

			if (f < el_ucolonna)
			    N_rpiene = N_rpiene+1;

			for (int i=0; i<N_rpiene; i=i+1)
			// R6 = (0<=i<=el_ucolonna) & (ho stampato gli elementi dell'ultimo strato (non pieno) della V-fetta f da 0 a i-1)
				cout << A[pieni][i][f] << " ";
			cout << endl; 
		}
	}
	cout<<"endl"<<endl;
}
