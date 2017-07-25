#include<fstream>
#include<iostream>
using namespace std;
void shift(int *A, int next, int &top)
{
 if(next<top)
 {
  A[next]=A[next+1];
  shift(A, next+1, top-1);
 }
}
void compact(int *A, int start, &top, int y)
{
 if(start<top)
 {
  if(A[start]==y)
  {
   shift(A, start, top);
   compact(A, start+1, top, y);
  }
 }

}
main()

{}
