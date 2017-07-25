/* Il programma dichiara un array C di 10 char, e in seguito legge 10 caratteri
   dall'input standard, inserendoli in C. Il programma deve determinare se C
   contiene 'b' e, in una successiva posizione (non per forza contigua), anche
   il carattere '2'. */

#include<iostream>
using namespace std;

main()
{
  char C[10];

  for (int i=0; i<10; i++)
    cin >> C[i];

  // PRE
  int i=0;
  bool b=false;

  while ((i<10) && !b) {     // R1
    if (C[i]=='b') b=true;
    i++;
  }
  // POST1

  bool due=false;

  while ((i<10) && !due) {     // R2
    if (C[i]=='2') due=true;
    i++;
  }
  // POST2

  if (due) cout << "L'array contiene una 'b' e successivamente un '2'" << endl;
  else cout << "L'array non contiene una 'b' e successivamente un '2'" << endl;
  // POST
}
