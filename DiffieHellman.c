#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long int root(long long int p,long long int k,long long int a[])
{
 long long int i,s,h;
 for(i=1;i<p;i++)
 {
  h=pow(k,i);
  s=h%p;
  a[s-1]=s;
 }
 for(i=0;i<p-2;i++)
 {
  
  if(a[i]==0)
   return 0;
 }
 return 1;
}
long long int prime(long long int p)
{
 long long int c=0,i;
 for(i=2;i<p;i++)
 {
  if(p%i==0)
   c++;
 }
 return c;
}
void main()
{
 long long int p;
 printf("enter prime number\n");
 scanf("%lld",&p);
 long long int ch=prime(p);
 while(ch>0)
  ch=prime(++p);
 printf("\nprime number is %lld\n",p);
 long long int ar[p-1],i;
 for(i=0;i<p-2;i++)
  ar[i]=0;
 long long int k=2,k1,k2;
 long long int c=root(p,k,ar);
 while(c==0)
 {
  c=root(p,++k,ar);
 }
 printf("prime number and primitive root are %lld %lld\n",p,k);
 printf("enter public key 1 \n");
 scanf("%lld",&k1);
 printf("enter public key 2 \n");
 scanf("%lld",&k2);
 long long int a,b,A,B;
 a=fmod(pow(k,k1),p);
 b=fmod(pow(k,k2),p);
 printf("private keys are %lld %lld\n",a,b);
 A=fmod(pow(b,k1),p);
 B=fmod(pow(a,k2),p);
 printf("shared values are %lld %lld\n",A,B);
}