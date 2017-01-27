#include<iostream>
using namespace std;

//è sbagliata...
bool MR(char*T,int dimT,char*P,int dimP,int inizio,int &fine)
{
if(inizio>=fine)
	return false;
if(T[inizio]==P[0])
	{
	if(dimP==1)
		{
		fine=inizio;
		return true;
		}

	else
		{
		P++;
		dimP--;
		}
	return MR(T,dimT,P,dimP,inizio+1,fine);
	}
}
// MR corretta
bool MR(char* T, int dim_T, char* P, int dim_P, int inizio, int& fine){
	if(T[inizio]==*P){
		if(dim_P!=1) {
			return MR(T,dim_T,P+1,dim_P-1,inizio+1,fine);
		}
		else {
			fine=inizio;
			return true;	
		}
	}
	else return MR(T,dim_T,P,dim_P,inizio+1,fine);
}

int matchR(char*T,int dimT,char*P,int dimP,int inizio)
{
if(inizio>dimT-dimP)
	return false;
int fine;
bool b=false;
if(T[inizio]==P[0])
	b=MR(T,dimT,P,dimP,inizio,fine);
int x=matchR(T,dimT,P,dimP,inizio+1);
if(b)
	{
	int y=fine-inizio+-dimP;
	if(x==-1)
		return y;
	else
		if(x>y)	
			return y;
		else
			return x;
	}
return x;
}
main()
{
}
