#include <iostream>
using namespace std;
void G(int * A, int *B, int lim1, int lim2, int lim3, int lim4, int &i, int&j, int&k, int&h, int&lung){
	bool esci=false;
	int indice = i*lim2*lim3*lim4+j*lim3*lim4+k*lim4+h+lung+1;
	lung=0; cout <<"indice: "<<indice<<endl;
	if(indice<lim1*lim2*lim3*lim4)
	{for(int x=indice; x<lim1*lim2*lim3*lim4 && !esci  ; x++){
		if(A[x]!=B[x]) 
		{i=i+(x-lung)/(lim2*lim3*lim4);
		j=j+((x-lung)%(lim2*lim3*lim4))/(lim3*lim4);
		h=h+((x-lung)%(lim3*lim4))/(lim4);
		k=k+((x-lung)%lim4); cout << i << " " << j << " " << k << " " << h << " " << "lung: "<<lung;
		esci=true;}
		else 
		lung++;		
	}
	}	
	else
	i++;
}

main()
{
 int A[4][2][3][6], B[4][2][3][6], lim1=4, lim2=2, lim3=3, lim4=6, max=0;
  int i=0, j=0,k=0,h=0,posi=0,posj=0,posk=0,posh=0;
	int lung=0;
	while(i<lim1)
		{G(***A, ***B,lim1,lim2,lim3,lim4,i , j, k , h,lung);
		  if(lung>max)	
		{ max=lung;
			posi=i;
			posj=j;
			posk=k;
			posh=h;
 		};
		}
}
