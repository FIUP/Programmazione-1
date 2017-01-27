#include<iostream>
using namespace std;

void stampa(int inizio, int*A,int lim)
{ for(int i=inizio;i<lim;i++)
	 cout<< A[i];
}

//k >0, cin contiene una sequenza a (eventualmente vuota) di n interi + '-2'
void G(int k)
{int I, conta=0,*A=new int[k];
 bool ok=false;
 cin >>I;
 while(I !=-2)					//R: !ok -> A[0..conta-1] contiene i primi conta elementi di cin
  { if(conta==k)				//	 ok -> A[0..k-1] contiene gli ultimi k-1 elementi di cin, conta-1 è la posizione di A in cui è stato inserito 										    l'ultimo elemento
	 { conta=0;
		ok=true;
	  }
	A[conta]=I;
	conta++;
	cin>>I;
  }
if(ok)
 stampa(conta,A,k);
 
 stampa(0,A,conta);
}
// POST: se n > k, stampa gli interi a(n-k+1)...a(n)
// 		 se n < k  stampa gli interi a(0)...a(n)

main()
{ G(6);

}
