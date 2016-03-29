Calculate nCr with out having overflow when it is guaranteed that the final result will not overflow:


From pascals triangular relation, we get,
nCr = n-1Cr + n-1Cr-1

Using this recursive formula directly will lead the program to exceed the time limit, as this may calculate the same value for many times which is un-necessary and we can remove this part by saving the states which means by using dynamic programming concepts.

In this formulation, one thing is to be noted that n and r keep decreasing, and sometimes is is possible that n becomes smaller than r. So considering these cases we get our base conditions for the recursive formula.


We know,
nCn = 1
nC1 = n
nC0 = 1
and
nCr = n-1Cr + n-1Cr-1

//So, we can build the recursive function as follows:

function nCr(n, r):
    if n == r:
        return 1
    if r == 1:
        return n
    if r == 0:
        return 1
    return nCr(n-1, r) + nCr(n-1, r-1)

Now, to reduce recursive steps, we maintain a table for saving the values of nCr of intermediate steps. So, when we face a sub-problem which is already solved, we can look up its value from the pre-calculation table.

table dp[N][R]

function nCr(n, r):
    if n == r:
        dp[n][r] = 1
    if r == 1:
        dp[n][r] = n
    if r == 0:
        dp[n][r] = 1
    if dp[n][r] is not yet calculated:
        dp[n][r] = nCr(n-1,r) + nCr(n-1,r-1)
    return dp[n][r]


Here is a sample code written in C++ which demonstrates the idea. (It is assumed that MAX N is 65 and N >= R).


#include <stdio.h>

#define i64 unsigned long long

i64 dp[66][33];

i64 nCr(int n, int r)
{
    if(n==r) return dp[n][r] = 1;
    if(r==0) return dp[n][r] = 1;
    if(r==1) return dp[n][r] = (i64)n;
    if(dp[n][r]) return dp[n][r];
    return dp[n][r] = nCr(n-1,r) + nCr(n-1,r-1);
}

int main()
{
    int n, r;
    while(scanf("%d %d",&n,&r)==2)
    {
        r = (r<n-r)? r : n-r;
        printf("%llu\n",nCr(n,r));
    }
    return 0;
}