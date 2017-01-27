int main(){
	nodo * p;
	nodo * ottavo = new nodo(8, 0), * settimo = new nodo(7, ottavo);	
	nodo * sesto = new nodo(6, settimo), * quinto = new nodo(5, sesto);
	nodo * quarto = new nodo(4, quinto), * terzo = new nodo(3, quarto);
	nodo * secondo = new nodo(2, terzo), * primo = new nodo(1, secondo);
	p = slice(primo, 3, 1);
	//p = primo;
	for (nodo *q = p; q!= 0; q = q->next){
		cout << q->info << endl;
	}
	system("pause");
}
