#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
#define NMAX 1000
int k;
 
int main() {
	
	int dp[NMAX+1][NMAX+1], wt[NMAX+1][NMAX+1];
	int len1,len2;
	char str1[NMAX+1], str2[NMAX+1];
	while(scanf("%d\n",&k) && k)
	{
		scanf("%s %s",str1,str2);
		len1 = strlen(str1);
		len2 = strlen(str2);
		for(int i=0; i<= len1; i++)
		{
			for(int j=0; j<= len2; j++)
			{
				if(!i || !j)
				{
					dp[i][j] = wt[i][j] = 0;
					continue;
				}
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				wt[i][j] = str1[i-1] == str2[j-1] ? wt[i-1][j-1]+1:0;
				if(wt[i][j] >= k)
				{
					for(int z=k; z<=wt[i][j]; z++)
					{
						dp[i][j] = max(dp[i][j],dp[i-z][j-z] + z);
					}
				}
			}
		}
		printf("%d\n",dp[len1][len2]);
	}
	return 0;
}
