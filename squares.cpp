#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
#define pb push_back
#define si(x) scanf("%d", &x);
#define sdd(x,y) scanf("%lf%lf", &x, &y);
#define sll(x) scanf("%lld", &x);
#define pi(x) printf("%d\n", x);
#define pll(x) printf("%lld\n", x);
#define x first 
#define y second 
int main()
{
	int t, n, i, j;
	pair<double, double> pt[2001];
	si(n)
	for(i=0;i<n;i++)
	{
		sdd(pt[i].x, pt[i].y)
	}
	if(n == 0)
		printf("4\n");
	else if(n == 1)
		printf("3\n");
	else if(n == 2)
		printf("2\n");
	else {
		double dist;
		int min = 2;
		pair<double, double> midpt, p1, p2, half;
		double slope;
		sort(pt, pt+n);
		bool a, b;
		int anurag=0;
		int flag=0;
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				flag = 0;
		/*		if(pt[i].y != pt[j].y)
				{
					anurag = 0;
					slope = (double)(pt[j].x-pt[i].x)/(pt[i].y-pt[j].y);
				}
				else anurag = 1;
				dist = (double)sqrt(pow(pt[i].x-pt[j].x, 2)+pow(pt[i].y-pt[j].y, 2));
		*/		midpt.x = (pt[i].x+pt[j].x)/2;
				midpt.y = (pt[i].y+pt[j].y)/2;
				half.x = (pt[i].x-pt[j].x)/2;
				half.y = (pt[i].y-pt[j].y)/2;
		//		if(anurag == 0)
		//		{
				p1.x = midpt.x + half.y;
				p2.x = midpt.x - half.y;	
				p1.y = midpt.y - half.x;
				p2.y = midpt.y + half.x;
				//		}
		//		else {
		//			p1.x = p2.x = midpt.x;
		//			p1.y = midpt.y + (dist/2);
		//			p2.y = midpt.y - (dist/2);
		//		}
				//cout<<p1.x<<" "<<p1.y;
				a = binary_search(pt, pt+n, p1);
				b = binary_search(pt, pt+n, p2);
				if(a && b)
				{
					flag = 1;
					min = 0;
					break;
				}
				else if(a || b)
				{
					min = 1;
				}
			}
			if(flag)
				break;
		}
		printf("%d\n", min);
	}
	return 0;
}
