/*Integrazione 6 crediti - Correttezza non richiesta*/
#include<iostream>
#include<fstream>
using namespace std;
 
main(){
  int X[400], *p=X, n_el;
  int dimt, dims, dimr, dimc, r, c, pos=0;	//valori convenzionalmente impostati a -1
  bool continua = true, vuoto = true;
  ifstream IN("input");
  ofstream OUT("output");
  
if(IN && OUT){
  IN >>n_el;
  if(n_el >0 && n_el < 401){
	  for (int i=0;i<n_el;i++)
		IN>>X[i];											//All'uscita X ha n_el elementi definiti
  IN >> dimt >> dims >> dimr >> dimc;						//vedo un array P[dimt][dims][dimr][dimc]
  IN >> r >> c; 											//specifica la posizione del tassello da considerare
  IN.close();
  int tassello[dimt*dims];									//il tassello avrà al massimo dims*dimt elementi

  if (r > dimr-1 || c > dimc-1)
	  continua = false;
  
  for(int t=0; t<dimt && t*dims*dimr*dimc <=n_el && continua; t++)
	  for(int s =0; s<dims && (t*dims*dimr*dimc + s*dimr*dimc)<=n_el && continua; s++){
		  if((t*dims*dimr*dimc + s*dimr*dimc + r*dimc + c) <n_el){
			if(vuoto)
				vuoto = false;
			tassello[pos] = p[t*dims*dimr*dimc + s*dimr*dimc + r*dimc + c];
			pos++;
			}		
		  else continua = false;
	  }
	if(vuoto)
		OUT << "Il tassello " << r << " " << c << " e' vuoto" << endl;
	else{
		OUT << "Il tassello " << r << " " << c << " contiene ";
		for(int i =0; i<pos; i++){
			OUT << tassello[i] << " ";
		}
	}
  OUT.close();
  } else OUT << "Errore n_el non valido"; 
  } else cout << "Errore con i file";
}