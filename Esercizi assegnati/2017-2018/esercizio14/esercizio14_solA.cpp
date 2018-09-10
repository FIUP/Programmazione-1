//Soluzione di S.Righetto
#include<iostream>
using namespace std;

int main(){
    cout << "start"<<endl;
    int n; //numero di elementi
    cin >> n;
    if((n<=100)&&(n>0)){
        int array[n];
        for(int i=0; i<n; i++) //riempio l'array
            cin >> array[i];
        bool ok=true;
        int dup[n],index=0; //array dei dulicati
        for(int i=0;i<n-1;i++){ //scorro dal primo elemento al penultimo
            for(int k=i+1; k<n;k++){ //scorro dall'elemento successivo fino all'ultimo
                if (array[i]==array[k]){ //se due elementi sono uguali
			    	bool trovato = false;
			    	for(int j=0; j < index && !trovato; j++) {
				    	if (dup[j] == array[i])
						trovato = true;
				    }
					if (!trovato) {
					 	dup[index]=array[i];
					 	index++;
					 	if(ok)
						ok = false;
					}
                }
            }
        }
        if(ok==true)
	    	cout << "Tutto regolare";
    	else {
    	    for (int i=0; i<index; i++){
				for (int j=0; j<index-1-i; j++){ //sort degli elementi
					if(dup[j]>dup[j+1]){ 
						int temp=dup[j];
						dup[j]=dup[j+1];
						dup[j+1]=temp;
					}
				}
			}
		}
	for(int i=0; i<index; i++) //stampa duplicati
		cout << dup[i] << endl;
    }
    cout<< endl <<"end";
};
