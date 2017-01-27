struct tasse{int a, b;};
//PRE: tass definito, l>=0
void bubble(int*tass,const int l)
{	int temp;
	for(int i=l;i>0;i--)//R1: tass[0..l-1] è permutazione di vtass[0..l-1] e tass[i..l-1] è ordinato e
		    			//tass[i..l-1] >=tass[0..i-1]
	for(int j=0;j<i-1;j++)//R2: 0<=j<=i-1, tass[j] è il max tra gli elem 0 .. j 
		if(tass[j]>tass[j+1])
			{ temp=tass[j];
			  tass[j]=tass[j+1];
			  tass[j+1]=temp;
			}

}
//POST2: tass[i-1] è il massimo tra gli elementi 0...i-1
//POST1: tass è ordinato decrescente

void F(int *X,const int lim1,const int lim2,const int lim3,int n_ele, tasse T){
	int mult=lim2*lim3, st_p=n_ele/mult, rig_u=(n_ele%mult)/lim3, ele_rig_u=(n_ele%mult)%lim3;
	int coordinatedito= T.a*lim3+T.b;

 if(rig_u*lim3+ele_rig_u>coordinatedito)
	st_p++;
 const int l=st_p;
 int tass[l];

 for(int i=0; i<l;i++)//R: 0<=i<=l, a in [0...l] tass[a]=*(X+a*mult+coordinatedito)
   tass[i]=*(X+i*mult+coordinatedito);

 bubble(tass, l);

 for(int i=0; i<l;i++) //R: 0<=i<=l, a in [0...l] *(X+a*mult+coordinatedito)=tass[a]
	*(X+i*mult+coordinatedito)=tass[i];

}
main()
{
}
/* R2
CONDIZIONE D'ENTRATA: j=0 => tass[0] è necessariamente il massimo tra 0..0

INVARIANZA: ad ogni iterazione del ciclo tass[j] è il massimo tra 0..j, quindi confrontando j con j+1 
			e in caso j+1 sia minore si scambiano gli elementi, di conseguenza ad ogni ciclo T[j] 
			è il massimo tra 0..j

CONDIZIONE DI USCITA: quando la condizione di uscita è soddisfatta siamo nel caso j=i-1, quindi tass[i-1] 
					  è il massimo tra 0..i-1, che è esattamente il POST

R1 
CONDIZIONE D'ENTRATA: i=l => tass[l..l-1] è un array vuoto poichè l'elemento tass[l] non esiste

INVARIANZA: ad ogni ciclo sappiamo per il POST2 che l'elemento i-1 è il massimo tra [0..i-1], quindi 
			dopo i-- sarà l'elemento i ad essere il maggiore, quindi al primo ciclo l'elemento maggiore 
			di tutto l'array sarà nell'ultima posizione, al secondo non si considera più quell'elemento
			e di conseguenza l'elemento maggiore di tutto l'array meno l'ultima posizione sarà in ultima
			posizione del nuovo array e così via finchè i>0

CONDIZIONE D'USCITA: quando i=0, si esce dal ciclo e poichè sappiamo che ogni elemento, escludendo 
					 l'elemento 0, è maggiore di tutti gli elementi precedenti, abbiamo soddisfatto
					 la POST
*/
