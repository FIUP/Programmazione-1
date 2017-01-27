#include<iostream>
using namespace std;

bool H(int *A, int d3)
{	bool esci=true;
	for(int i=0; i<d3 &&esci; i++)
		for(int j=i+1; j<d3 && esci; j++)
			if(A[i]==A[j]) esci=false;
	return esci;
}

bool G(int*A,int d3,int ele)
{ bool resta=true; 
	int rig=ele/d3, ult=ele%d3;
	for(int i=0;i<rig && resta;i++)
		resta=H(A+i*d3, d3);
	if(resta&&ult>0)
	 resta=H(A+rig*d3,ult);
	return resta;
}
//PRE: A[n_ele] definito, d1,d2,d3 interi definiti
void F(int*A, int d1, int d2, int d3, int n_ele)
{int sp=n_ele/(d2*d3), ele_u=n_ele%(d2*d3), conta=0;
for(int i=0; i<sp; i++)
	if(G(A+i*d2*d3,d3, d2*d3))
		conta++;
if(ele_u>0)
if(G(A+sp*d2*d3, d3, ele_u))conta++;
cout<< conta<<endl;
}
//POST: 

main()
{
int d1, d2, d3;
cin >> d1 >> d2 >> d3;
int A[d1*d2*d3];
int zero=0, n_ele=0; bool duezero=false;
for(int i=0; i<d1*d2*d3 && !duezero; i++)
{
	cin >> A[i];
	if(A[i]==0) zero++;
	else zero=0;
	if(zero==2) duezero=true;
	n_ele++;
}
if(duezero) n_ele=n_ele-2;
 F(A,d1,d2,d3,n_ele);
}
