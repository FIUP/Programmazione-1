/*Integrazione sei crediti*/
#include<iostream>
#include<fstream>
using namespace std;

int trad(int e){
        int strato = e/(4*4);
        e = e%(4*4);
		//e = e - strato*4*4;
        int riga = e/4;
        int colonna = e%4;
       
        return strato*4*4 + colonna*4 + riga;
}
 
int compattaC(int* x, int dim, int z, int fino, int cur){
    if(cur >=dim)
		return fino;
	else{
        if (x[trad(cur)] != z){
            x[trad(fino)] = x[trad(cur)];
            fino++;
        }
        cur++;
        return compattaC(x, dim, z, fino, cur);
    }
}

void stampaRiga(int* x, int dim, ofstream& OUT){
	if(!dim){
		OUT << endl;
		return;
	}
	
	OUT << x[0] << " "; 
	if((dim+3)%4 ==0) 
		OUT << endl;
	stampaRiga(x+1,dim-1,OUT);
}
 
void stampaUltimo(int *x, int cp, int rim,int dim, ofstream &OUT){
    if (!dim)//caso base:raggiunta la fine dello strato
        return ;
 
    if (rim){
        stampaRiga(x,cp+1,OUT);
        stampaUltimo(x+4,cp,rim-1,dim-(cp+1),OUT);
    }
    else{
        stampaRiga(x,cp,OUT);
        stampaUltimo(x+4,cp,rim,dim-cp,OUT);
    }      
}

 
void stampa(int *x, int dim, ofstream &OUT){
    if (!dim)//caso base: raggiunto il limite dell'array
        return;
 
    int cp=dim/4;	//dimensione base delle righe, dimensione base delle righe
    int rim=dim%4;	//elementi ultima colonna, righe con +1 elementi
 
    if (cp>=4){ //c'è almeno uno strato completo
		stampaRiga(x,(4*4),OUT);
        stampa(x+(4*4),dim-(4*4),OUT);
    }
 
    else //sono nell'ultimo strato, non completo!
       stampaUltimo(x,cp,rim,dim,OUT);
}

main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT) 
  { 
   int T[3][4][4], dim,z, *x=**T;
   IN>>dim;
   int count=dim;
//riempie T per strati e colonne
   for(int i=0; i<3 && count>0;i++)
    for(int  j=0; j<4&&count>0;j++)
      for(int k=0;k<4&&count>0;k++){
		  IN>>T[i][k][j];count--;
	    }
   IN>>z;
   
   stampa(x,dim,OUT);//stampa ricorsiva per strati e per righe, considerando solo elementi definiti
   
   int ne=compattaC(x,dim,z,0,0);//da fare
   
   stampa(x,ne,OUT); //stampa dell'array dopo il compattamento
   OUT<<"fine"<<endl;
   IN.close(); OUT.close(); 
  }
  else
   cout<<"errore con i files";
}
