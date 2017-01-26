#include<iostream>
#include<fstream>
using namespace std;
struct nodo{int info; nodo* left,*right;nodo(int a=0, nodo* b=0, nodo* c=0){info=a; left=b; right=c;}};

int conta_n(nodo*r)
{
   if(!r) return 0;
     else
    return conta_n(r->left)+conta_n(r->right)+1;
}

nodo* insert(nodo*r, nodo* y)
{
  if(!r) return y;
   
  if(conta_n(r->left)<=conta_n(r->right))
    r->left=insert(r->left,y);
   else   
    r->right=insert(r->right,y); 
  return r;
}
void stampa_cam(int*C)
{
  cout<<*C<<' ';
  if(*C!=-1)
    stampa_cam(C+1);
  else
    cout<<endl;
}

nodo* build_tree(nodo*R,int n_el)
{
 if(!n_el) return R;
 int x;
 cin>>x;
 nodo* Q=insert(R,new nodo(x));
 return build_tree(Q,n_el-1);
}
void stampa(nodo *r)
{
  if(r)
    {
      cout<<r->info<<'(';
      stampa(r->left);
      cout<<',';
      stampa(r->right);
      cout<<')';
    }
  else
    cout<< '_';
}
/*PRE=(C e' un array con dimensione <= 50 elementi e contiene un -1 tra i suoi elementi*/
int conta_c(nodo*r)
{   
    if(!r || (!r->left&&!r->right))return 0;
	int a=0, b=0;
	if(r->left) a=conta_c(r->left);
	if(r->right)b=conta_c(r->right);
	
    if(a<=b&&a!=0)return a+1;
    return b+1;
}


nodo* CF(nodo* r, int*C)
{

    if(conta_c(r->left)<=conta_c(r->right)&&r->left) {
            *C = 0;
            return CF(r->left, C+1);
        } 
	if(conta_c(r->left)>conta_c(r->right)&&r->right) {
            *C = 1;
            return CF(r->right, C+1);
        }
    *C = -1;
    return r;
   
  }
  
  
 main()
{
 int n_el;
 cin>>n_el;
 
 nodo* R=build_tree(0,n_el);
 cout<<"albero:";
 stampa(R);
 int C[50];
 nodo* a=CF(R,C);
 cout<<endl<<"la foglia meno profonda ha info="<<a->info<<endl;
 stampa_cam(C);
 cout<<endl<<"end"<<endl;
}
