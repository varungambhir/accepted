#include <stdio.h>
#include<math.h>
int main()
{
	int t;
	double p,s,S,V;
	scanf("%d",&t);
	while(t--)
	{
    scanf("%lf%lf",&p,&s);
		S=(p-sqrt(p*p-24*s))/12;
		V=-2*S*S*S+S*S*p/4.0;
		printf("%0.2lf\n",V);
	}
	return 0;
}
