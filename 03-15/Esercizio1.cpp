/*Integrazione 6 crediti*/
#include<fstream>
#include<iostream>
using namespace std;
main(){
	int A[2][4][5];
	ifstream IN("input");
	ofstream OUT("output");
/*PRE = input contiene 40 interi, seguiti o dalla coppia "H" x
	o dalla coppia "V" y dove x sarà tra 0 e 3 e y tra 0 e 4*/
	
if(IN && OUT){
	for(int i = 0; i < 2; i++)
		for(int j=0; j<4; j++)
			for(int z=0; z<5;z++)
				IN >> A[i][j][z]; 
	//fin qui ho letto i 40 interi
	char c;
	int n=-1;	//n è il nostro x o y impostato di defaul a -1 fuori dal range dei valori validi
	IN >> c;
	
	if(c == 'H'){
		IN >> n;
		if(n >=0 && n <=3){ //individuata h fetta valida
			for(int i = 0; i < 2; i++){
				for(int z=0; z<5;z++)
					OUT << A[i][n][z] << " ";
				OUT << endl;
			}					
		} 
		else OUT << "H-fetta non valida, controllare valore di x";	
	}
	if(c == 'V'){
		IN >> n;
		if(n >=0 && n <=4){ //individuata h fetta valida
			for(int i = 0; i < 2; i++){
				for(int j=0; j<4;j++)
					OUT << A[i][j][n] << " ";
				OUT << endl;
			}					
		} 
		else OUT << "V-fetta non valida, controllare valore di y";	
	}
	IN.close();
	OUT.close();
		//POST = ("output" contiene gli elementi della fetta specificata dalla coppia letta)
} else cout << "Errore con i file";
			

}