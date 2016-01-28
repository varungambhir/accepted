#include<iostream>
#include<cstdio>
#include<cmath>
#define gc getchar_unlocked
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int main()
{
	int t,R1,R2,R3;
	double r1,r2,r3,r;
	scanint(t);
	while(t--)
	{
		scanint(R1);
		scanint(R2);
		scanint(R3);
		r1=(double)R1;
		r2=(double)R2;
		r3=(double)R3;
		r= (r1*r2*r3)/(r1*r2+r1*r3+r2*r3+2*pow(r1*r2*r3*(r1+r2+r3),0.5));
		printf("%.6lf\n",r);
    }
	return 0;
}
