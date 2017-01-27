//PRE: cin=v1..vn -1 ..., n>=0, v1..vn != -1
main(){
	int somma = 0, x, i=0; double media=0;
 	cin >> x;

	while ( x != -1){//R: somma è = alla somma dei primi i elementi di cin somma = somma + x;
		i++;       
	 	cin >> x;
	}//POST: somma è la somma dei primi n elementi di cin
 	if (i > 0)
  		media = (double) somma / i;
}
//POST: somma=v1+..+vn, media=somma/n, se n=0 somma=0 e media=0


/*
CONDIZIONE D'ENTRATA: i=0 => somma è uguale a 0 che rispetta l'invariante dato che non ci sono 
		     		  elementi da sommare

INVARIANZA: somma è la somma dei primi i elementi che sappiamo essere diversi da -1 poichè non si è 
	    	ancora usciti dal ciclo

CONDIZIONE D'USCITA: se x=-1 significa che sono finiti gli elementi di cin da considerare, quindi 
		    		 somma è la somma dei primi n elementi di cin
*/
