/* Teoria TURNO II by Leo*/
//Es1:
 
int ** F(int * & x)     //tipo ritorno: int**, passaggio di un puntatore per riferimento (x ora è un alias del puntatore d'invocazione)
{ (*x)++;               //deref, ottengo l'ogg puntato ("a" del main) e ne aumento l'R-val di 1
  int **p=&x;           //dichiaro un puntatore locale al puntatore x (inutile!)
  return x; }           //ritorno il puntatore "x" per valore (cioè ne ritorno l'R-val), ma ha tipo int* (anche se è un alias)
main()
{ int a=2, *q=&a;       //"q" è un puntatore ad "a"
  **F(q)=4;             //"q" matcha con "int *x", OK; il tipo di ritorno è "int **" quindi lo posso deref 2 volte (-> occhio!)
  cout<<a<<endl;        //stampo "a"
}
/* ERRATO:
F ha tipo di ritorno int**, ma ritorna x che ha tipo int*.
(il compilatore dice: "[Error] cannot convert 'int*' to 'int**' in return").
Inoltre il main dereferenzia 2 volte quanto tornato da F: prima ottiene "a" e poi cerca di deref un intero!
(rendendo int* il tipo di ritorno di F, all'invocazione nel main, il compilatore dice: "[Error] invalid type argument of unary '*' (have 'int')").
Nota (?): se F avesse restituito "p" ci sarebbe stata concordanza con il tipo di ritorno (int**), ed "x" sarebbe diventato un alias del puntatore d'invocazione "q"; una volta restituito "p", lo deref, ottengo "x" (che in realtà è "q", e quindi non è dangling), poi deref ulteriormente ed ottengo "a", ci metto dentro il valore "4" e lo stampo. */
 
 
//Es2:
/*
dato int T[3][4][5];
che tipo ha ((*T)+8)[-2]?
((*T)+8)[-2] equivale a: *(((*T)+8)-2), inoltre l'aritmetica NON cambia il tipo (ma solo il valore), pertanto il tipo richiesto è lo stesso di **T che è: int*.
*/
 
 
//Es3:
 
//cosa stampa?
main()
{ int x=1;
  for(int i=0; i<10; i++)
  { cout<<x;
    if(x>0)
      continue;
    else
      break;
    x=0;
  }
}
 
/* stampa 1, poi entrerà sempre nel ramo "then" ed il "continue" lo forzerà a saltare sempre tutto ciò che segue (compreso "x=0;")
pertanto stamperà 10 volte 1 (fino a che l'indice non interromperà il ciclo). */