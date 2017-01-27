#include<iostream>
using namespace std;

struct nodo{char info; nodo* next;
nodo(char a='0', nodo*b=0){info=a;next=b;}};

nodo *riempi(int k)
{ if(!k)
	return NULL;
  char x;
  cin>>x;
  return new nodo(x,riempi(k-1));

}

void stampa(nodo*L)
{if(L)
  {cout<<L->info<<" ";
   stampa(L->next);
  }
}
//PRE: L è una lista eventualmente vuota, pos è la posizione del nodo all'interno della lista, y è definito, k è definito, boh è definito
//in seguito chiamerò il numero di nodi che hanno campo info uguale a y della lista L come yL
bool F(nodo*L, int pos, char y, int k,bool boh)
{if(!x)
	{if(k<=0)
	   return true;
     return false;
	}
  if(L->info==y)
	{
	 if(F(L->next,pos+1,y,k-1,!boh))
	   {if(boh)
			cout<<pos<<" ";
	    return true;
	   }
	 else return false;
	}
  return F(L->next,pos+1,y,k,boh);
}
//POST: se yL>=k, stampa 1 si e 1 no i nodi con campo info uguale a y e restituisce true
//	    se yL<k non stampa niente e restituisce false


main()
{nodo* inizio;
inizio=riempi(10);
stampa(inizio);
cout<<endl;
F(inizio,0, 'a', 3,true);
cout<<endl;
}

/* caso base: x=0 quindi la lista è vuota, se k<=0 ritorna true altrimenti ritorna false, in entrambi i casi non stampa nulla, poichè
			  la lista non ha nodi, quindi soddisfa entrambi i casi della POST
  passo induttivo: L= a @ L', se il campo info di a è diverso da y l'invocazione ricorsiva soddisfa la PRE_ric poichè L->next=L' è una
				   lista eventualmente vuota.
				   se il campo info è uguale a y l'invocazione ricorsiva soddisfa la PRE_ric poichè L-next=L' è una lista
				   eventualmente vuota, se la chiamata ricorsiva restituisce true verrà restituito a sua volta true e se boh=true stampa
				   pos, se la chiamata ricorsiva restituisce false, non stampa nulla e viene restituito a sua volta false.


*/
