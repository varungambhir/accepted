#include<iostream>
#include<cstdio>
#define MOD 1000000007
#define MIN(a,b) ((a) < (b) ? (a) : (b))
typedef unsigned long long int ull;
#define gc getchar_unlocked
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
ull modPow(ull a, ull x, ull p) {
    //calculates a^x mod p in logarithmic time.
    ull res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}

ull modInverse(ull a,ull p) {
    //calculates the modular multiplicative of a mod m.
    //(assuming p is prime)
    return modPow(a, p-2, p);
}
ull modBinomial(ull n, ull k, ull p) {
// calculates C(n,k) mod p (assuming p is prime)
	int i;
    ull numerator = 1; // n * (n-1) * ... * (n-k+1)
    for (i=0; i<k; i++) {
        numerator = (numerator * (n-i) ) % p;
    }

    ull denominator = 1; // k!
    for (i=1; i<=k; i++) {
        denominator = (denominator * i) % p;
    }

    // numerator / denominator mod p.
    return ( numerator* modInverse(denominator,p) ) % p;
}
int main()
{
	int n,r;
	scanint(n);
	unsigned long long ans;
	if(n<13)
	ans=0;
	else
	{n=(n-1)/2;
	r=MIN(6,n-6);
	ans=modBinomial(n,r,MOD);}
	printf("%llu\n",ans);
	return 0;
}
