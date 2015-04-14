#include<iostream>
#include<fstream>
using namespace std;
 
main(){
  int A[2][4][5], *p=**A, n_el;
  ifstream IN("input.txt");
  ofstream OUT("output");
  
if(IN && OUT){
  IN >>n_el;
  if(n_el >=0 && n_el < 41){
	  for (int i=0;i<n_el;i++)
		IN>>p[i];
  char value;
  int index;
  IN >> value >> index;
  IN.close();
 
  if (value=='V'){
    if (index>=n_el)
        OUT << "V fetta "<<index<<" vuota"<< endl;
    else{
        while (index<n_el){
           OUT << p[index]<< " ";
           index+=5;
        }
    }
    }
  else if (value == 'H')
    {
      if (index>(n_el/5))
        OUT << "H fetta "<<index<<" vuota"<< endl;
      else
        {
          int iterator=index*5;
          while(iterator<n_el)
            {
              if (iterator%5==4)
                {
                  OUT << p[iterator] << " ";
                  iterator+=16;
                }
              else
                {
                  OUT << p[iterator] << " ";
                  iterator++;
                }
            }
        }
    }
  OUT.close();
  } else OUT << "Errore n_el non valido"; 
  } else cout << "Errore con i file";
}