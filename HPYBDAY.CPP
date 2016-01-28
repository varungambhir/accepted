#include<iostream>
#include<cstdio>
#define gc getchar_unlocked
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int arr[10000000];
int sumofdigits(int n)
{
    int sum=0;
 while(n!=0)
 {sum+=n%10;n=n/10;}

    return sum;
}
int noofdigits(int n)
{

    int sum=0;
    while(n!=0)
    {sum++;n=n/10;}
    return sum;
}
int main()
{

   int t;
   scanint(t);
   int count=0;
   for(int i=0;count<=59000;i++)
   if(sumofdigits(i)==13)
   {arr[count]=i;count++;}
   while(t--)
   {
       int count=0;
    int n;
   scanint(n);

   if(n<58000)
  printf("%d\n",noofdigits(arr[n]));
  else
  printf("8\n");
   }
   return 0;
}
