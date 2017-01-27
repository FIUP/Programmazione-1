#include <iostream>
#include <fstream>
using namespace std;
 
struct coord{int s,r,c; coord(int a=0, int b=0, int d=0){s=a;r=b;c=d;}};

coord calc_coord(int lim1, int lim2, int lim3, int VF, int n){
  coord a(0,0,0);
  a.s=n%lim1;
  a.r=n/lim1;
  a.c=VF;
  return a;
}



int legge(int*A, int lim1, int lim2, int lim3, ifstream & IN){
  int x, count=0;
  bool stop=false;
  coord crd;
  while (!stop && count<(lim1*lim2*lim3)){
    for (int VF=0;VF<lim3 && !stop;VF++){
      for (int n=0;n<lim1*lim2 && !stop;n++){
        IN>>x;
        if(x==-2){
          stop=true;
        }
        else{
          crd=calc_coord(lim1,lim2,lim3,VF,n);
          A[lim2*lim3*crd.s+lim3*crd.r+crd.c]=x;
          count++;
        }
      }
    } 
  }
  return count;
}


int matchElement(int*A,int lim1,int lim2,int lim3,int element,int restoelem,int inizio, int VF){
        if(restoelem <= 0 || inizio> lim1*lim2-1)
                return -1;
        coord crd = calc_coord(lim1,lim2,lim3,VF,inizio); 
        if( A[lim2*lim3*crd.s+lim3*crd.r+crd.c] == element ){
                return inizio;
        }else{
                return matchElement(A,lim1,lim2,lim3,element,restoelem-1,inizio+1,VF);
        }
}        
 
void F1(int*A,int lim1,int lim2,int lim3,int*P,int dimP,int restoelem,int inizio,int VF,ofstream & OUT){
        if(restoelem <= 0 || dimP == 0){
				OUT<<"fine"<<endl;
                return;
			}
		int match = matchElement(A,lim1,lim2,lim3,*(P),restoelem,inizio,VF);
        OUT<<match<<endl;
        if (match>=lim1*lim2-1){
			OUT<<"fine"<<endl;
                return;
                }
        if(match != -1)
                F1(A,lim1,lim2,lim3,P+1,dimP-1,restoelem-(lim1*lim2)-(match+1-inizio),match+1,VF+1,OUT);
        else
                F1(A,lim1,lim2,lim3,P,dimP,restoelem-(lim1*lim2),inizio,VF+1,OUT);     
}//F1
 
main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT)
  {
   int A[400],P[30], dimP, lim1,lim2,lim3;
   
   IN>>dimP;
   for(int i=0; i<dimP;i++)
    IN>>P[i];
   IN>>lim1>>lim2>>lim3;
   int nel=legge(A, lim1, lim2, lim3, IN);//da fare
   
   OUT<<nel<<endl;
   F1(A,lim1,lim2,lim3,P,dimP,nel,0,0,OUT);//da fare
   
   IN.close(); OUT.close();
 
  }
  else
   cout<<"errore con i files";
 }
