#include<iostream>
#include<fstream>
using namespace std;

int compatta(int *x, int dim, int z, int fino, int cur){
   
   if((fino+cur)>=dim)
        return dim-cur;

    x[fino]=x[fino+cur];
   
    if(x[fino]==z)
        return compatta(x,dim,z,fino,cur+1);
    return compatta(x,dim,z,fino+1,cur);
   
}


void stampa(int* x, int dim, ofstream& OUT){
	if(!dim){
		OUT << endl;
		return;
	}
	
	OUT << x[0] << " "; 
		if(dim%4 ==0) 
			OUT << endl;
	stampa(x+1,dim-1,OUT);
}

main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT) 
  { 
   int T[3][4][4], dim,z;
   IN>>dim;
   int* x=**T;
   for(int i=0; i<dim;i++)
    IN>>x[i];
   stampa(x,dim,OUT);//stampa ricorsiva per righe da fare
   OUT<<endl;
   IN>>z;
   
   int ne=compatta(x,dim,z,0,0);//da fare
   stampa(x,ne,OUT);//stampa quello che resta
   OUT<<"fine"<<endl;
   IN.close(); OUT.close(); 
  }
  else
   cout<<"errore con i files";
}
