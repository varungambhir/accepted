#include<iostream>
#include<cstdio>
#include<cstdlib>
#define gc getchar_unlocked
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int main()
{
	int i,n,t,m[1001],w[1001],sum;
	scanint(t);
	while(t--)
	{	sum=0;
        scanint(n);
		for (i = 0; i < n; ++i)
			scanint(m[i]);
		for (i = 0; i < n; ++i)
			scanint(w[i]);
		qsort (m, n, sizeof(int), compare);
		qsort (w, n, sizeof(int), compare);
	for (i = 0; i < n; ++i)
		{
			sum+=(m[i]*w[i]);
		}
	printf("%d\n",sum );
	}

	return 0;
}
