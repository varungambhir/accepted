#include<iostream>
#include<cstdio>
#include<cstdlib>
#define MAX 2010
#define gc getchar_unlocked
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
int main()
{	int t,j,n,maxe,i,a[MAX],count[MAX]={0};
	scanint(t);
	while(t--)
	{
		scanint(n);
		for (i = 0; i < n; ++i)
		{	scanint(a[i]);
			count[a[i]+1000]++;
		}
		maxe=count[0];
		j=-1000;
		for (int i = 0; i < MAX; ++i)
		{
			if(maxe<count[i])
			{
				maxe=count[i];
				j=i-1000;
			}
		count[i]=0;
		}

	if(maxe>n/2)
	printf("YES %d\n",j);
	else printf("NO\n");
	}

	return 0;
}
