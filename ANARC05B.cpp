#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define gc getchar_unlocked

using namespace std;

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
#define MAX 10009


int main() {
	int na, nb, i, j, A[MAX], B[MAX];
	while(scanf("%d", &na)==1 && na)
	{
		for(i=1; i<=na; i++)
			scanf("%d", &A[i]);
		scanf("%d", &nb);
		for(j=1; j<=nb; j++)
			scanf("%d", &B[j]);
		for(i=j=1; i<=na || j<=nb; )
		{
			if(i<=na && j<=nb && A[i]==B[j])
			{
				A[i] += A[i-1];
				B[j] += B[j-1];
				A[i] = B[j] = max(A[i], B[j]);
				i++, j++;
			}
			else if(i>na) {
				B[j] += B[j-1];
				j++;
			}
			else if(j>nb) {
				A[i] += A[i-1];
				i++;
			}
			else if(A[i] < B[j]) {
				A[i] += A[i-1];
				i++;
			}
			else if(A[i] > B[j]) {
				B[j] += B[j-1];
				j++;
			}
		}
		printf("%d\n", max(A[na], B[nb]));
	}
	return 0;
}
