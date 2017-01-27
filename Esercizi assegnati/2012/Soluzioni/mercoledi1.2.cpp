class C {
	private int i = 0;
	public void m() {
		synchronized(a){
			for (int k=0; k<1000000; k++) i++;
			for (int k=0; k<1000000; k++) i--;
	 		i++;
	 		notifyAll();
		}
	}

	public void n() throws InterruptedException {
		synchronized(b){
			if (i<9) wait();
			System.out.print(i+" ");
		}
	}
}

class T1 extends Thread {
	private C c;
	public T1(C c) {this.c =c;}
	public void run() {
		for (int i=0; i<1000; i++) c.m();
	}
}

class T2 extends Thread {
	private C c;
	public T2(C c) {this.c = c;}
	public void run() {
		try { c.n();}
		catch(InterruptedException e){}
	}
}

class TTest{
	public static void main(String[] args){
		C c=new C();
		T1 r=new T1(c); T2 s= new T2(c), t=new T2(c);
		t.start(); s.start(); r.start();
		
	}
}


