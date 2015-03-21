/*Dato un array int X[3][4][5][10], nel seguito dovete rappresentare
l'R-valore di X con X. Si chiede di:
i) Specificare il tipo di X e la dimensione dell'oggetto puntato
ii) Specificare il valore e il tipo di (*X)+2 e di *(X+2)
iii) Specificare il valore e il tipo di *(X[-8])+8

i) tipo di X = int (*)[4][5][10] 
dim oggetto puntato = 4*5*10*sizeof(int) = 4*5*10*4 
 
ii) tipo di (*X)+2 = tipo di *X = int(*)[5][10]
valore di (*X) + 2 = X + 2*(5*10)*4
tipo di *(X+2) = lo stesso di prima = int(*)[5][10]
valore di *(X+2) = X[2] = X + 2*(4*5*10)*4

iii) tipo di *(X[-8])+8 = int(*)[10]
valore di *(X[-8])+8 = *(*(X-8))+8 = X -8*(4*5*10)*4 + 8*(5*10)*4*5*10

 */
 