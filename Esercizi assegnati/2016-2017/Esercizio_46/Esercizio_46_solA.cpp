// soluzione di B.Cosentino
#include<iostream>

using namespace std;

bool trova_lab(int L[], int dim, int i, int j,int P[]){
    
    if (*(L+i*dim+j)==0 || j<0 || j>=dim)
        return false;
    
    // L[i][j]==1 & 0<=i<=dim-1 & 0<=j<dim
    
    P[i]=j;
    
    if (i==dim-1){
        return true;
    }
    // L[i][j]==1 & 0<=i<dim-1 & 0<=j<dim
    
    return (trova_lab(L,dim,i+1,j-1,P) || trova_lab(L,dim,i+1,j,P) || trova_lab(L,dim,i+1,j+1,P));
} 

bool trova(int L[], int dim, int e, int P[]){
    
    if (e>=dim)		// se ho superato il limite della riga
    	return false;
    
    if (L[e]==1 && trova_lab(L, dim, 0, e, P))		// se trovo un cammino
    	return true;
    
    // L[e]==0 && !trova_lab(L, dim, 0, e) && e<=dim-1
    
    //	se non lo trovo ne cerco uno a partire dalla posizione successiva
    return trova(L, dim, e+1, P);
    
}

void stampa(int P[], int n, int c){
	
	if (c<n){
		cout << "(" << c << ',' << P[c] << ")";
		stampa(P, n, c+1);
	}

}


main()
{
  int n;
  cin>>n;
  int* L= new int [n*n], *P=new int[n];
  for(int i=0; i<n*n; i++)
          cin>>L[i];
  bool x=trova(L,n,0,P);//da fare
  cout<<"start"<<endl;
  if(x)
    { cout<<"il cammino e':"; stampa(P,n,0); cout << endl;}//da fare
    
  else
    cout<<"il cammino non esiste"<<endl;
  cout<<"end"<<endl;
      
}
