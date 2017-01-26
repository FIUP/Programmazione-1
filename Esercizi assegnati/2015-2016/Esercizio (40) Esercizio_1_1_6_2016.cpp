#include<iostream>
#include<fstream>
using namespace std;
struct nodo{int info; nodo*left,*right; nodo(int a=0, nodo*b=0, nodo*c=0){info=a; left=b; right=c;}};


void stampa(nodo *r){
  if(r){
      cout<<r->info<<'(';
      stampa(r->left);
      cout<<',';
      stampa(r->right);
      cout<<')';
    }else
        cout<< '_';
}

int S(int* X, int n){
    int i, conta=0;
    for(i=0; (X[i]!=-2) && (conta<n);i++){            //R=(in X[0..i-1] non c'e' -2, conta= # -1 incontrati in X[0..i-1]
        if(X[i]==-1)                                //se conta=n allora X[i-1]=-1 quindi X[i]=inizio prossimo sottoseq se c'e'
            conta++;
    }                                                   //POST=(se conta=n allora (se X[i]!-2  allora i e' l'indice della sottoseq. di indice n)&& (se conta <n allora X[i]=-2 e in X[0..i-1]
    if(conta==n && X[i]!=-2)                            // ci sono conta < n sottoseq
        return i;
    else
        return -2;
}

nodo* build1(){
    nodo* left=new nodo(1);
    nodo* right=new nodo(3);
    return new nodo(2,left,right);
}
nodo* build2(){
    nodo* a=new nodo(1);
    nodo* b=new nodo(3,a);
    return new nodo(2,0,b);
}

nodo *cam_iter(nodo *r, int *X) {
    int i, info;
    nodo *curNode = r;
    nodo **parentBranch = NULL;

    for(i=0; curNode != NULL && X[i] != -1; i++){
        parentBranch = (X[i] == 0 ? &curNode->left : &curNode->right);
    curNode = *parentBranch;
    }

    cin >> info;

    if(curNode == NULL && X[i] != -1) {
        cout << "cammino troppo lungo, non usato:" << info << endl;
    }else if(curNode != NULL) { // && X[i] == -1
        cout << "cammino troppo corto, non usato:" << info << endl;
    }else { // curNode == NULL && X[i] == -1
        curNode = new nodo(info, NULL, NULL);
    
        if(parentBranch != NULL) {
            *parentBranch = curNode;
        }else { // if(r == NULL)
            r = curNode;
        }
    }

    return r;
}

nodo *lavora_iter(nodo *r, int *X){
    int i, pathIdx;
    
    for(i=0; (pathIdx = S(X, i)) != -2; i++) {
        r = cam_iter(r, X + pathIdx);
    }
    return r;

}

main(){
    int X[400];
    cin>>X[0];
    
    for(int i=1; i<400 && X[i-1]!=-2; i++)
       cin>>X[i];
    
    nodo* r0=0;
    nodo* r1=build1();
    nodo* r2=build2();
    
    cout<<endl<<"albero=";
    stampa(r0);
    cout<<endl;
    nodo* a=lavora_iter(r0,X);
    stampa(a);
    
    cout<<endl<<"albero=";
    stampa(r1);
    cout<<endl;
    a=lavora_iter(r1,X);
    stampa(a);
    
    cout<<endl<<"albero=";
    stampa(r2);
    cout<<endl;
    a=lavora_iter(r2,X);
    stampa(a);
    
    cout<<endl<<"end"<<endl;
}
