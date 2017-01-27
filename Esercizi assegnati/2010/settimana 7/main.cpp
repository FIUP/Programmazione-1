 
int main(){
	nodo * p;
	nodo * quinto = new nodo(5, 0);
	nodo * quarto = new nodo(4, quinto), * terzo = new nodo(3, quarto);
	nodo * secondo = new nodo(2, terzo), * primo = new nodo(1, secondo);
	//p = R(primo).L2;
	nodo * L1, * L2;
	R(primo, L1, L2);
	//p = L2;
	p = L1;
	for (nodo *q = p; q!= 0; q = q->next){
		cout << q->info << endl;
	}
} 
