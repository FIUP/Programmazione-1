#include<iostream>
using namespace std;

struct nodo{ int info; nodo*left; nodo* right;
	nodo(int a=0, nodo*b=0, nodo*c=0){info=a; left=b; right=c;}
};

void prefix(nodo *n){
if(n){
	cout << n->info << " ";
	prefix(n->left);
	prefix(n->right);
}
}

int AAA_nodocercasi(nodo *L, int prof){
	if(!L)
	 return -1;	
	if((L->left && !L->right) || (!L->left && L->right))
		return prof;
	int a=AAA_nodocercasi(L->left, prof+1);
	int b=AAA_nodocercasi(L->right, prof+1);
	if(a==-1 || b==-1)
		{if(a==-1)
			return b;
		else
			return a;
		}
	if(a<b)
		return a;
	else
		return b;
}

main()
{
nodo *quinto= new nodo(5,0,0);
nodo *quarto= new nodo(2,0,quinto);
nodo *terzo= new nodo(6,0,0);
nodo *secondo= new nodo(10,quarto,0);
nodo *primo= new nodo(34,secondo,terzo);
prefix(primo);
cout<<endl<<AAA_nodocercasi(primo,0)<<endl;
}



//34(10(2(_,5(_,_)),_),6(_,_))

