#include <stdio.h>

int ex_gcd(int a,int b,int n) //computes the GCD using the Extended Euclid method
{
int x=0,y=1,lastx=1,lasty=0;
int temp,q;
while(b!=0)
{
temp =b;
q = a/b;
b = a%b;
a = temp;

temp=x;
x = lastx - q*x;
lastx = temp;

temp =y;
y = lasty - q*y;
lasty = temp;
}
if(n==1) return a;
else return lasty;
}

long en_de(int base, int exp,int n)
{
int b[30],i,c=0;
long d=1;
for(i=0;exp!=0;exp/=2,i++)
b[i]=exp%2;

i--;
for(;i>=0;i--)
{
c = 2*c;
d = (d*d) %n;
if(b[i]==1)
{
c = c+1;
d = (d*base)%n;
}
}
return d;
}

void main()
{

int p,q,i;
int pt,ct;
int e,d,et,n,temp;

printf("Enter prime No.s p,q :");
scanf("%d %d",&p,&q);

n = p*q;
et=(p-1)*(q-1);

for(i=2;i<et;i++)
if(ex_gcd(et,i,1) == 1)
printf("%d\t",i);

printf("\nSelect e value:");
scanf("%d",&e);

temp = ex_gcd(et,e,2);
d = et+temp;

printf("\nPublic Key KU = {%d,%d}\n",e,n);
d=d%et;
printf("Private Key KR = {%d,%d}\n",d,n);

printf("Enter Plain text M Integer (0<M<%d):",n);
scanf("%d",&pt);

ct = en_de(pt,e,n);

printf("\nCipher Text = %d",ct);
printf("\n\nPlan Text After decrtion :%d\n",en_de(ct,d,n));
}
