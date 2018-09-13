//Soluzione di S.Righetto
#include<iostream>
using namespace std; 

int main(){
    
    cout<<"start"<<endl;
    
	int x1, x2, y1, y2; //punti Q e P
	cin >> x1 >> y1 >> x2 >> y2 ;

	// |x1-x2| = |Y1-Y2|
	
	int d1,d2;
	d1= x2-x1;
	d2= y2-y1;
	
	//applico il modulo per i numeri negativi
	if (d1 < 0)
		d1= d1 * (-1);
	if (d2 < 0)
		d2= d2 * (-1);
	
	int nrighe, spazi;
	if (d1 == d2 ){
		nrighe = d1;
		if ( ((x2>x1) && (y2>y1)) || ((x2<x1) && (y2<y1)) ){ //se la diagonale è inclunata verso destra
    		while ( nrighe > 0 ){
    			spazi = nrighe-1;
    			while(spazi>0 )	{
    				cout << "b";
    		    	spazi --;
    			}
    			cout << "s" << endl;
    			nrighe--;
    		}
		}	
		else if ( ((x2<x1) && (y2>y1)) || ((x2>x1) && (y2<y1)) ){ //se è inclinata verso sinistra
			int i=0;
			while ( nrighe > 0 ){
				spazi=0;
				while(spazi<i){
					cout << "b";
			    	spazi ++;
				    }
				i++;
				
				cout << "s" << endl;
				nrighe--;
		    	}
	    	}
	    	
	}
	else cout<<"Le coordinate immesse non formano la diagonale di un quadrato"<<endl;	
	
	cout<< "end";
}


