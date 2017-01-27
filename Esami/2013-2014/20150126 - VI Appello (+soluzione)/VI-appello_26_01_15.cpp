#include<iostream>
using namespace std;
struct nodo{int info; nodo*left,*right; nodo(int a=0, nodo* b=0, nodo*c=0){info=a; left=b;right=c;}};

bool conf(nodo * a, nodo * b){
  if (!a && !b) // non ho la radice su entrambi => hanno la stessa struttura (vuota)
    return true;
  if ((a && !b) || (!a && b)) return false;
  else{
    bool l =conf(a->left,b->left);
    bool r =conf(a->right,b->right);
    if (l && r)
      return true;
    else 
      return false;
  }
}

void stampa_l(nodo *r)
{
  if(r)
    {
      cout<<r->info<<'(';
      stampa_l(r->left);
      cout<<',';
      stampa_l(r->right);
      cout<<')';
    }
  else
    cout<< '_';
}

bool foglia(nodo *r){
  return !r->left && !r->right;
}

void ricopia(int * &T, int * S, int indS){
  if(!indS) return;
  else{
    *T=*S;
    T=T+1;
    ricopia(T, S+1, indS-1);
  }
}

void c_cam(nodo * A, int *&T, int * S, int indS){
  if(foglia(A)){
    S=S-indS;
    ricopia(T, S, indS);
    *T=-1;
    T=T+1;
  }
  else{
    if(A->left){
      *S=0;
      c_cam(A->left, T, S+1, indS+1);
    }
    if(A->right){
      *S=1;
      c_cam(A->right, T, S+1, indS+1);
    
    }
  }
}

void percorri_albero(nodo * & r, int * T, int & i){
  nodo* scorri_r=r;
  while(T[i]!=-1){
    if(T[i]==0){
      if(!scorri_r->left){
	scorri_r->left=new nodo(0);
	scorri_r=scorri_r->left;
      }
      else
	scorri_r=scorri_r->left;
    }
    else{//1
      if(!scorri_r->right){
        scorri_r->right=new nodo(1);
        scorri_r=scorri_r->right;
      }
      else
        scorri_r=scorri_r->right;  
    }
    i++;
  }
}

nodo * c_alb(int * T){
  nodo * r=0;
  nodo* inizio=0;
  int i=0;
  if (!r){
        r = new nodo(5);
        inizio=r;
      }
  while(T[i]!= -2){
    if(T[i]==-1){
      r=inizio;
      i++;
    }
    else{
      percorri_albero(r,T,i);
      r=inizio;
    }
  }
  return r;
}

nodo* costruz()
{
 nodo*x2=new nodo(2);
 nodo* x3=new nodo(3);
 nodo* x4=new nodo(4);
 nodo*x1=new nodo(1,x2,x3);
 x2->right=x4;
 x2->left=new nodo(0);
 x3->right=new nodo();
 return x1;
}


int main()
{
  nodo*a=costruz(),*b=0;
    
  int T[100],S[20], is=0, *B=T; 
  c_cam(a,B,S,is);  // da fare ricorsiva
  *B=-2;
  int i;
  for(i=0; T[i]!=-2; i++)
   cout<<T[i]<<' ';
  cout<<T[i]<<endl;
  stampa_l(a);
  cout<<endl;

  b=c_alb(T); //da fare iterativa
  stampa_l(b);  
  
  if(conf(a,b))  //da fare ricorsiva
    cout<<"uguali"<<endl;
  else
    cout<<"non uguali"<<endl;
}
