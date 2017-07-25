// soluzione di B.Cosentino
#include<iostream>
using namespace std;

//PRE: cin contiene carattere
int main() {
	
	int count=0;	//Contatore
	char c='a';	//Carattere diverso da '0'
	
									//PRE while: count=0 && c='a' --> count>=-1 && c=carattere : R while
	while (c!='0' && count>=0) {			//R while: count>=-1 && c=carattere
									//INVARIANZA: R while && (c!='0' && count>=0) --> (count>=-1 && c=carattere) && 
									// && (c!='0' && count>=0) --> count>=0 && c!=0
		cin >> c;                   // 2 casi: se c='(' allora count++ -> count >=0
		if (c=='(') {		        //         se c=')' allora count-- -> count>=-1
			count++;                // In ogni caso R while vale ancora.
		}
		if (c==')') {					//R while && !(c!='0' && count>=0) --> count>=-1 && c=carattere && (c='0' || count<0)
			count--;					// --> count>=-1 && (c='0' || (c=carattere && count<=-1)) --> (count>=-1 && c='0')||
		}							// || (c=carattere && count=-1) --> count=-1 || c='0'
	}	
									//POST while: count=-1 || c='0'
	if (count==0) {	//c='0'
		//Bilanciate
		cout << "la sequenza e' bilanciata"<<endl;
	
	} else {	//count!=0
		//Sbilanciate
		cout << "la sequenza NON e' bilanciata,";
		
		if (count < 0 ) {	//count=-1
			//Parentesi chiuse > parentesi aperte
			cout << " ci sono parentesi chiuse senza match" <<endl;
		} else {			//count>0 && c='0'
		
			//Parentesi aperte > parentesi chiuse
			cout << " ci sono parentesi aperte senza match"<< endl;
		}
	}
	cout << "end" <<endl;
}
//POST: conta le parentesi e stampa se sono bilanciate o meno
