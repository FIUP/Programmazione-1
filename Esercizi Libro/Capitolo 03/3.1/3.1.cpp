#include<iostream>
using namespace std;
#include<fstream>
main()
{
  ofstream YY("file_scrittura");
  YY<<11;
  YY<<' ';
  YY<<32;
  YY<<' '; 
  YY<<455;
  YY<<' ';  
  YY<<6;
  YY.close();
  ifstream XX("file_scrittura");
  int y; 
while(!XX.eof())
    {
      XX>>y;           //le freccie mi permettono di leggere direttamente
                       //gli interi saltando automaticamente gli spazi
      cout<<y<<endl;
    }
 }
