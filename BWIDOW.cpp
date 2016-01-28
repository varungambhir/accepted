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
int main()
{
	int t,in[1001],out[1001],n,i,j,r,R;
	scanint(t);
	while(t--)
	{
		scanint(n);
		for (i = 0; i < n; ++i)
			{
				scanint(in[i]);//inner r
				scanint(out[i]);//outer R
			}
	r=in[0];//rmax
	j=0;
	for(i=1;i<n;i++)
		{
		if(in[i]>r)
			{
				j=i;
				r=in[i];
			}
		}
	R=1;//judge
	for (i = 0; i < n; ++i)
		{
			if(r<=out[i] && i!=j)
			{
				R=0;
				break;
			}
		}
	if(R)
	printf("%d\n",j+1);
	else
	printf("-1\n");
	}
	return 0;
}
