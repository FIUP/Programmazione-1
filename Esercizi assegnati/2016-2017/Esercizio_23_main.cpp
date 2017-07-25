#include<iostream>
using namespace std;
main()
{
 int A[8][6];
 bool B[8][6];
 int* p=*A;
 for (int i=0; i<48; i++)
  cin >> p[i];

 // da fare

   for(int i=0; i<8; i++)
   {
    for (int j=0; j<6; j++)
     cout<<B[i][j]<<' ';
    cout<<endl;
   }

}