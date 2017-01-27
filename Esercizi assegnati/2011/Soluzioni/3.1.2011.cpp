clear all
close all

% (M+N)x^k+1=-Dx^k+b
% P=(M+N)'*D
% q=(M+N)'*b

n=10;
a=linspace(0.5,1.5,200);

tol=1.e-9;
kmax=100;

M=pentadiag([-1,-1,1,0,0],n);

for k=1 : length(a)
    v=pentadiag([-1,-1,a(k), -1,-1],n);
    A=pentadiag(v,n);
    d=(a(k)-1)*ones(n,1);
    D=diag(d);
    N=A-D-M;
    
    P= -inv(M+N)*D;
    %calcolo  il raggio spettrale
    r(k)= max(abs(eig(P)));
end

semilogy(r,'r');



% seconda parte

%cerco la matrice con minor raggio spettrale, e ne salvo la posizione in aMin aMin
[r_star,aMin]=min(r);

b=(1:n)';
m=5;
x0=[ones(m,1);zeros(n-m,1)];

v=pentadiag([-1,-1,a(aMin), -1,-1],n);
A=pentadiag(v,n);
M=pentadiag([-1,-1,1,0,0],n);

d=(a(aMin)-1)*ones(n,1);
D=diag(d);

N=A-D-M;
    
P= -inv(M+N)*D;
q=inv(M+N)*b;
x1=P*x0+q;
k=1;
err(k)=norm(x1-x0)/norm(x1);


while(err(k)>tol & k<=kmax)
    x0=x1;
    x1=P*x0+q;
    k=k+1;
    err(k)=norm(x1-x0)/norm(x1);
    
end

x1
k-1
sol=inv(A)*b
figure(2)
semilogy(err,'b-o');
