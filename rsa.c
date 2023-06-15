#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int gcd(int m,int n)
{
 int temp=m%n;
 if(temp==0)
  return n;
 m=n;
 n=temp;
 gcd(m,n);
}
void main()
{
 int p,q;
 printf("enter the prime numbers  ");
 scanf("%d%d",&p,&q);
 int m,n=p*q;
 printf("enter the message  ");
 scanf("%d",&m);
 int x=(p-1)*(q-1);
 int e=2;
 while(e<x)
 {
  //printf("s");
  if(gcd(e,x)==1)
   break;
  e++;
 }//public key
 int d=2;
 while(d<x)
 {
  if((e*d)%x==1)
  break;
  d++;
 }//private key
  int enc=fmod(pow(m,e),n);
  //encrypt
  int dec=fmod(pow(enc,d),n);
  //decrypt
  printf("encryption: %d\n",enc);
  printf("decryption: %d\n",dec);
}