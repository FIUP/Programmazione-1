#include<iostream>
using namespace std;

struct nodo{int info;nodo* next;
nodo(int a=0, nodo*b=0){info=a; next=b;}};

nodo*crea(int k)
{if(!k)
	return 0;
 return new nodo(k,crea(k-1));
}

void stampa(nodo*L)
{ if(L)
	{cout<<L->info<< " "; stampa(L->next);}

}

void F(nodo*&L, nodo*& E, int k)
{ nodo*L1=L, *E1;
  int conta =2;
  if(!L1)
	return;
  else
   { while(L1->next)
	  { if(conta==k)
		  {conta=1;
			if(!E)
				{E=L1->next;
				  E1=E;
				}
			else
			 { E1->next=L1->next;
				E1=E1->next;
				}
			L1->next=L1->next->next;
			  	  
			}
		 else
			{ L1=L1->next;
			  conta++;
			}
	 }
 	E1->next=0;

  }

}


main()
{ nodo*L=crea(10);
  nodo*E=0;
 F(L,E,3);
 stampa(L);
cout<<endl;
 stampa(E);
cout<<endl;
 

}
