//PRE: cin=v1..vn -1 ..., n>=0, v1..vn != -1 || cin=v1..vn.. t.c. v1..vn != -1 
//     e pos(v1+..+vn)<neg(v1..vn) e questo non succede per v1..vm, per ogni m<n
main(){
	int somma = 0, x, y=0, z=0, i=0;
	cin >> x;
	while ( x != -1 && y>=z){//R: somma = v1 + .. + v(i), y è il num di elementi positivi fino ad i, 
		somma = somma + x; i++; // x quello dei negativi 
		if (x>=0)
			y++;
		else
			z++;
    	cin >> x; 
    }
}
//POST: somma= v1+..+vn

/*
CONDIZIONE D'ENTRATA: i=0 => somma= v1 + .. + v(0) quindi non ci sono elementi da sommare allora 
						somma=0

INVARIANZA: somma= v1 + .. + v(i) poichè gli elementi v1.. v(i) sono diversi da -1 e fino all'elemento 
			i-1 y>=z poichè precedentemente si era entrati nel ciclo	

CONDIZIONE D'USCITA: se x = -1 quindi non ci sono più elementi da sommare e somma = v1 + .. +vn
					 se y < z => somma = v1 + .. + vn, con v1..vn diversi da -1
*/
