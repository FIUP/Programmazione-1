
int main(){
	nodo * q1 = new nodo('a', 0, 0);
	nodo * q2 = new nodo('e', q1, 0);
	nodo * q3 = new nodo('c', 0, 0);
	nodo * q4 = new nodo('a', q2, q3);
	nodo * q5 = new nodo('a', 0, 0);
	nodo * q6 = new nodo('e', q4, q5);
	char P[2];
	P[0] = 'e';
	P[1] = 'a';
	int dim_P = 2;
	//nodoP * K, *p;
	//K = F(q6, P, dim_P);
	int ris = G(q6, P, dim_P);
	cout << ris <<endl;
	//p = K;
	//for (nodoP *q = p; q!= 0; q = q->next){
	//	cout << q->info->info<< endl;
	//}
	system("pause");
}
