#include<iostream>
using namespace std;

struct nodo
{
       int info; 
       nodo* next;
       nodo(int a=0, nodo* b=0){info=a;next=b;}
};


void stampa(nodo*L)
{if(L)
	{ cout<<L->info<<" ";
	  stampa(L->next);
	}
}

nodo*crea(int k)
{if(!k)
	return 0;
 int x;
 cin>>x;
 return new nodo(x,crea(k-1));	

}

void cambia(nodo*&L)
{ 
  nodo*temp=L;
  L=L->next;	
  delete temp;
}

nodo * G(int x, nodo *L)
{ 
  nodo*inizio=L;
	
  if(L)
   {  while(L->next)
       {  if(L->next->info==x)   
	        cambia(L->next);
	      else
		   L=L->next;
       }
	if(inizio->info==x)
	  cambia(inizio);
		
    }
return inizio;
}

main()
{   nodo*primo=crea(10);
	primo=G(3,primo);
	stampa(primo);
	system("PAUSE");
}
