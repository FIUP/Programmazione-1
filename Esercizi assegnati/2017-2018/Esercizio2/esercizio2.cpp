#include<iostream>

using namespace std;

int main()
{
    // delimitatore iniziale output del programma (stringa "start")
    // ATTENZIONE! Non cancellare l'istruzione sottostante
    cout << "start" << endl;
    
    // inserire qui il codice del programma
    char  a,b;

	cin>>a>>b; //mosse dei giocatori

	if((a=='s'|| a=='f'||a=='c')&&(b=='s'|| b=='f'||b=='c'))
		{if ((a=='s' && b=='f')|| (a=='f' && b=='c') || (a=='c' && b=='s') )
			{cout<<"vince il giocatore 1"<<endl;}
		else if ((b=='s' && a=='f')|| (b=='f' && a=='c') || (b=='c' && a=='s')) 
			{cout<<"vince il giocatore 2"<<endl;}
		else if ((a=='s' && b=='s')|| (a=='f' && b=='f') || (a=='c' && b=='c')) 
			{cout<<"pareggio"<<endl;}
	}
	else {cout<<"mossa non valida"<<endl;}

    // delimitatore finale output del programma (stringa "end")
    // ATTENZIONE! Non cancellare l'istruzione sottostante
    cout << "end" << endl;
}
