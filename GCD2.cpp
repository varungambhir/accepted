#include<iostream>
#include<cstdio>
#define gc getchar_unlocked
#include<cstring>
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
char b[300];
int mod(int a){
	int i,r=0;
	for(i=0;b[i]!='\0';i++)
	{
		r=( (b[i]-'0') + r*10 ) % a;
	}
	return r;
}
int gcd(int a,int b) {
        if(b==0) 
        return a;
        else 
        return gcd(b,a%b);
}
int main() {
	int r,t,a,i;
	scanint(t);
	while(t--){
	scanint(a);
	gets(b);
	if(a==0)
	puts(b);
	else 
	{	r=mod(a);
		printf("%d\n",gcd(a,r));
					}
	
	}
	return 0;
}
