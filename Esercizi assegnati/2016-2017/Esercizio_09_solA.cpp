// soluzione di B.Cosentino
#include<iostream>
using namespace std;

//PRE: cin contiene carattere
int main() {
	
	int count=0;	//Contatore
	char c='a';	//Carattere diverso da '0'
	bool letto_e=false, letto_en=false, letto_end=false;
	
									//PRE while: count=0 && nessun carattere letto -->
									//--> count=0 && letto_end=false && letto_en=false && letto_e=false -->
									//--> count>=-1 && (letto_end=true <=> ultimi tre caratteri 'E','N','D') &&
									//&& (letto_en=true <=> ultimi due caratteri 'E','N') &&
									//&& (letto_e=true <=> ultimo carattere 'E'): R while
	while (letto_end==false && count>=0) {	//R while: count>=-1 && (letto_end=true <=> ultimi tre caratteri 'E','N','D') &&
									        //&& (letto_en=true<=>ultimi due caratteri 'E','N') && (letto_e=true <=>
									        // <=> ultimo carattere 'E')
									//INVARIANZA: R while && (letto_end=false && count>=0) --> 
									//--> (count>=-1 && (letto_end=true <=> ultimi tre caratteri 'E','N','D') && 
									//&& (letto_en=true <=> ultimi due caratteri 'E','N') &&
									//(letto_e=true <=> ultimo carattere 'E')) && 
									// && (letto_end=false && count>=0) -->  
									//--> count>=0 && (letto_end=true <=> ultimi tre caratteri 'E','N','D') &&
									// (letto_en=true <=> ultimi due caratteri 'E','N') && 
									//&& (letto_e=true <=> ultimi tre caratteri 'E')
									//2 casi: se c='(' allora count++ -> count >=0
                                    //        se c=')' allora count-- -> count>=-1
                                    // In ogni caso R while vale ancora, supponendo che valga ancora il resto dell'invariante
									//3 casi:
									//      - c='D' && letto_en==true e' vero sse c='D' && ultime due lettere lette 'E','N'. 
									//          Se questa condizione vale allora letto_end=true -> 
									//          le ultime tre lettere lette sono 'E','N','D' e letto_end=true -> 
									//          -> (letto_end=true <=> ultimi tre caratteri 'E','N','D') e' vero
									//          Altrimenti, letto_end resta false -> (letto_end=true <=> ultimi tre caratteri 'E','N','D') e' ancora vero
									//      - c='N' && letto_e==true e' vero sse c='E' && ultima lettera letta 'E'. 
									//          Se questa condizione vale allora letto_en=true -> 
									//          le ultime due lettere lette sono 'E','N' e letto_en=true -> 
									//          -> (letto_en=true <=> ultimi due caratteri 'E','N') e' vero
									//          Altrimenti, letto_en=false -> (letto_en=true <=> ultimi due caratteri 'E','N') e' ancora vero
									//      - se c='E' ì, allora letto_e=true -> (letto_e=true <=> ultimo carattere 'E') e' ancora vero
									//          Altrimenti, c!='E', allora letto_e=false -> (letto_e=true <=> ultimo carattere 'E') e' ancora vero
									//In ogni possibile caso, (letto_end=true <=> ultimi tre caratteri 'E','N','D') && (letto_en=true<=>ultimi due caratteri 'E','N')  &&
									//  && (letto_e=true <=> ultimo carattere 'E') vale ancora.
									// Quindi, R while vale.
		cin >> c;
		if (c=='(') {		
			count++;
		}
		if (c==')') {					
			count--;					
		}							
		if (c=='D' && letto_en) {	//c='D' && ultime due lettere lette 'E','N'
			letto_end=true;
		}
		if (c=='N' && letto_e) { //c='N' && ultima lettera letta 'E'
			letto_en=true;
		} else {
			//c!='N' || letto_e=false --> c!='N' || ultima lettura diversa da 'E'
			letto_en=false;
		}
		if (c=='E') {			//c='E'
			letto_e=true;
		} else {		//c!='E'
			letto_e=false;
		}							//R while && !(letto_end=false && count>=0) --> 
									// --> count>=-1 && (letto_end=true <=> ultimi tre caratteri 'E','N','D') &&
									//&& (letto_en=true<=>ultimi due caratteri 'E','N') && (letto_e=true <=>
									// <=> ultimo carattere 'E') && (letto_end=true || count<=-1) -->
	}								// --> (letto_end=true <=> ultimi tre caratteri 'E','N','D') &&
									//&& (letto_en=true<=>ultimi due caratteri 'E','N') && (letto_e=true <=>
									// <=> ultimo carattere 'E') && (letto_end=true || count=-1) -->
									//--> ultimi tre caratteri 'E','N','D, || count=-1 : POST while
									//POST while: count=-1 || ultimi tre caratteri 'E','N','D'
	
	if (count==0) {	//c='0'
		//Bilanciate
		cout << "la sequenza e' bilanciata"<<endl;
	
	} else {	//count!=0
		//Sbilanciate
		cout << "la sequenza NON e' bilanciata,";
		
		if (count < 0 ) {	//count=-1
			//Parentesi chiuse > parentesi aperte
			cout << " ci sono parentesi chiuse senza match" <<endl;
		} else {			//count>0 && c='0'
		
			//Parentesi aperte > parentesi chiuse
			cout << " ci sono parentesi aperte senza match"<< endl;
		}
	}
	cout << "end" <<endl;
}
