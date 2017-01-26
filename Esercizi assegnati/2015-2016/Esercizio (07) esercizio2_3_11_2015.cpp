#include<iostream>
using namespace std;

main()	//PRE=(cin contiene dimT interi e dimP interi, seguite da 0<dimT<=100 e 0<dimP<=10).
{
	int T[100], P[10], dimT, dimP, nMatch=0;
	cin >> dimT >> dimP;

	int t=0;
	while(t<dimT)	//R - riempe T[0..dimT-1]
	{
		cin >> T[t];
		t++;
	}

	int p=0;
	while(p<dimP)	//R - riempio P[0..dimP-1]
	{
		cin >> P[p];
		p++;
	}

	t=0;	//reset indice t per scorrere T
	bool stopP;     //stopP lo uso per bloccare while di controllo elementi
	while(t<dimT && (dimT-t>=dimP))		//R - cicla fino a quando ho elementi in T[0..dimT-1] && (dimP<=dimT-t<=dimT)
	{
		stopP=false;
		p=0;	//reset indice p per scorrere P
		while(p<dimP && !stopP)		//R - cicla fino a quando ho elementi in P[0..dimP-1] && stopP è falsa
		{
			if(T[t+p]!=P[p])
				stopP=true;
			p++;
		}
		if(stopP==false)
			nMatch++;
		t++;
	}

	cout<<"n. match = "<<nMatch<<endl;

}   //POST=(il programma stampa su cout il numero di match di P in T)
