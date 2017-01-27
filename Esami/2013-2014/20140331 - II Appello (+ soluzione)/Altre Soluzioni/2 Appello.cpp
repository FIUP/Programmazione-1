#include <iostream>
#include <fstream>
using namespace std;
struct nodo{int info1,info2; nodo* next; nodo(int a=0, int c=0, nodo* b=0){info1=a;info2=c; next=b;}};

int SearchMach(nodo*&T, int*P,int f){
	int y=0;
	while(T){
    if(T->info1==*P) 
      return y;
    else T=T->next; 
    y++;
  }
return -1;
}

int ConsecutiveMatch(nodo*&T, int*&P, int &f,int dimP){
	int y=0; 
  bool stop=0;
	while(!stop && f<dimP && T){
    if(T->info1==*P){
      y++; 
      T=T->next; 
      f++; 
      P=P+1;
    }else stop=1;
  } 
	return y;
}

void build(nodo*Y,int inf1,int inf2){
	nodo*J=Y;
	while(J->next!=0){
    J=J->next;
  }
	J->next=new nodo(inf1,inf2);
return;
}
	
nodo* M1(nodo* T, int*P, int dimP){
	if(!dimP) 
    return 0;
	bool stop=0; 
  int f=0; 
  nodo*Y=0;
	while(T && f<dimP && !stop){
    int inf1=SearchMach(T,P,f); 	
    if(inf1==-1) 
      stop=1;
    else{
      int inf2=ConsecutiveMatch(T,P,f,dimP); 
      if(!Y) 
        Y=new nodo(inf1,inf2); 
      else build(Y,inf1,inf2);
    }
  }	
	return Y;
}
	
nodo*&Jump(nodo*&T,int x){
	if(T){
    if(x==0) 
      return T;
	 return Jump(T->next,x-1);
  }
	return T;
}

nodo*del(nodo*T,int x){
	if(T){
  	if(x==0) 
      return T;
    nodo*y=T;
    T=T->next;
    delete y;
    return del(T,x-1);
  } 
	return 0;
}
	
void TB(nodo*&T, nodo*X){
	if(T&&X){
		nodo*&Temp1=Jump(T,X->info1);
		nodo*Temp2=del(Temp1,X->info2);
		Temp1=Temp2; 
    TB(Temp1,X->next);
  }else return;
}
	
nodo* TC(nodo*&T, nodo*X){
	if(X&&T){
    if(X->info1){
      X->info1--; 
      return TC(T->next,X);
    }else if(X->info2){ 
        X->info2--; 
        nodo*temp=T; 
        T=T->next; 
        return new nodo(temp->info1,temp->info2,TC(T,X)); 
        delete temp;
      }else return TC(T,X->next);
  } 
	return 0;
}


nodo* copia(nodo* X)
{
  if(X)
    return new nodo(X->info1, X->info2, copia(X->next));
  return 0;

}

void crea(nodo*&L, int dim, ifstream & INP, int n)
{
  int x;
  if(n<dim)
    {
      INP>>x;
      L=new nodo(x,n,0);
      crea(L->next, dim,INP,n+1);
    }
  else
   L=0;
}
void crea1(nodo*&L, int dim, ifstream & INP, int n)
{
  int x,y;
  if(n<dim)
    {
      INP>>x>>y;
      //cout<<"x="<<x<<" y="<<y<<endl;
      L=new nodo(x,y,0);
      crea1(L->next, dim,INP,n+1);
    }
  else
   L=0;
}
void stampa(nodo* x, ofstream & OUT)
{
  if(x)
    {
      OUT<<'('<< x->info1<<','<<x->info2<<')';
      if(x->next)
      OUT<<"->";
      //cout<< x->info1<<' '<<x->info2<<' ';
      stampa(x->next, OUT);
    }
   else
   {OUT<<endl;
    //cout<<endl;
   }
}


main()
{
  try{
  ifstream INP("input");
  ofstream OUT("output");
  if(!INP) throw(0);
  if(!OUT) throw(1);
  int P[100],dimP,dim,dimX;
  INP>>dim>>dimP>>dimX;
  
  nodo*L=0;
  crea(L,dim,INP,0);//data
  
  for(int i=0;i<dimP ; i++)
   {INP>>P[i];}
  nodo*z=M1(L,P,dimP);    //da fare
  if(!z)
  OUT<<"nessun match"<<endl;
  else
  stampa(z,OUT);//data
  OUT<<endl;

  nodo* X=0;
  crea1(X,dimX,INP,0);//data  
	

  nodo*L1=copia(L);//data
  
  TB(L1,X);        //da fare
  stampa(L1,OUT);														
  //cout<<endl;
  nodo* z1=TC(L,X); //da fare 
  stampa(L,OUT); 									
  //cout<<endl;
  stampa(z1,OUT);									
  //cout<<endl;

 }
 catch(int x)
{
   switch(x)
  {
   case 0: cout<<"problemi con input"<<endl; break;
   case 1: cout<<"problemi con output"<<endl; break;
  }
}
}