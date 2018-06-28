#include<iostream>
using namespace std;

struct nodo{int info; nodo*next; nodo(int a=0, nodo*b=0){info=a; next=b;}};
struct FIFO {nodo* primo, *ultimo; int dim; FIFO(nodo*a=0,nodo*b=0,int c=0){primo=a; ultimo=b; dim=c;}};
struct nodoFIFO{FIFO info; nodoFIFO* next; nodoFIFO(FIFO a=FIFO(), nodoFIFO*b=0){info=a; next=b;}};

  
  void stampa(nodoFIFO*Q,int i)
  {
    if(Q)
      {
	cout<<"nella FIFO n."<< i<<" ci sono "<<Q->info.dim<<" valori, il primo e l'ultimo seguono:"<<endl;
        cout<<"primo="<<Q->info.primo->info<<", ultimo="<<Q->info.ultimo->info<<endl;
        stampa(Q->next,i+1);
      }

    //cout<<endl;
  }

  main()
    {
      int n, m,a;
      cin>>n>>m;
      nodoFIFO* Q=0;
      for(int i=0; i<n; i++)
	{
	  cin >>a;
	  nodo*N=new nodo(a);
	  Q=addtolist(Q,N,m);//da fare
	}
      cout<<"start"<<endl;
      stampa(Q,0);
      cout<<"end"<<endl;
    }
