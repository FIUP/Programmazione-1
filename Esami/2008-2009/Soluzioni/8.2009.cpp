#include <iostream>
using namespace std;

struct nodo{ char info; nodo* left; nodo*right;
	nodo(char a='\0', nodo*b=0, nodo*c=0){info=a; left=b; right=c;}
};

int F2(nodo* x, char y, int *C, int top){
	if(!x) return -1;
	if(x->info==y)	return top;
	else {
		C[0]=0; int acc=F2(x->left, y, C+1, top+1);
		  if(acc==-1)
			{ C[0]=1; top= F2(x->right, y, C+1, top+1);
				return top;
			}
		return acc;
	}
}

main(){
	nodo * ott=new nodo('l', 0, 0);
	nodo * sett=new nodo('h', 0, 0);
	nodo * ses=new nodo('f', ott, 0);
	nodo * qui=new nodo('d', 0, 0);
	nodo * qu=new nodo('c', 0, 0);
	nodo * ter=new nodo('e', ses, sett);
	nodo * sec=new nodo('b', qu, qui);
	nodo * ini=new nodo('a', sec, ter);
	//postfix(ini); cout << endl;
	//int k=3, conta=F(ini,k,k ); cout << endl;
	char y='l'; int top=0, P[5];
	top=F2(ini, y, P, top);
	for(int i=0; i<top; i++)
		cout << P[i] << " ";
	cout << endl;
}


void postfix(nodo*n){
	if(n){
		postfix(n->left);
		postfix(n->right);
		cout << n->info << " ";
	}
}


int F(nodo *x, int salta, int k){
	if(x){
		salta =F(x->left, salta, k);
		salta= F(x->right, salta, k);
		if(salta==1){
			cout << x->info << " "; 
			return k;	
		}
		return salta-1;
	}
	else
		return salta;
}	

