/*
Written by : Ashish Sareen
*/
#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) <= (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define L 2*index
#define R 2*index+1
#define repstl(v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(c.begin(),e.end(),x) != (c).end())
#define TRACE
#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#else
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif

 /*Tired of lying in the sunshine, Staying home to watch the rain
You are young and life is long, And there is time to kill today
And then one day you find, 10 years have got behind you
No one told you when to run, You missed the starting gun

And you run and you run to catch up with the Sun but it's sinking
Racing around to come up behind you again
The Sun is the same in a relative way, but you're older
Shorter of breath and one day closer to death

Every year is getting shorter, never seem to find the time
Plans that either come to naught or half a page of scribbled lines
- Time, Pink Floyd*/

#define MAXN 100010
#define MOD 1000000007

int main(int argc, char const *argv[])
{
    BOOST;
    return 0;
}
/*
An O (N) algorithm:
In this section we present a linear time algorithm to compute the array B.

We define minPos(i, j) as smallest k, such that i <= k <= j, and A[k] is the minimum element of subarray A[i, j]. For a given k, there could be many pairs (i, j) such that minPos(i, j) = k.
Let us say that

1) k1 < k is the smallest integer such that all elements in the subarray A[k1, k - 1] are strictly greater than A[k], and
2) k2 > k is the largest integer that no element in the subarray A[k, k2] is strictly smaller than A[k].

Now, it is easy to see that minPos(i, j) = k if and only if k1 <= i <= k <= j <= k2. This means there are exactly (k - k1 + 1) * (k2 - k + 1) such pairs (i, j) whose minPos is k.

If we can compute the integer k1 and k2 for each k, then we can compute the array B easily. We just need to iterate through the values of k from 0 to N-1, for each k, compute k1, k2, and hence the number of subarrays whose minPos() is k using the above formula. The element B[A[k]] will then be incremented by this value.

Next, we discuss how to compute k1's in a single pass, the computation of k2 can be done in a similar way. We scan the array A from left to right and maintain a sequence {v1, v2, ...} such that:
1) vi < vi+1,
2) A[vi] <= A[vi+1], 
3) for each j in (vi, vi+1), A[j] > A[vi+1]
4) the last element of the sequence is the index of the last scanned element.

Or, in other words (vi + 1) is the k1 value for vi+1. The sequence can be maintained easily. Whenever, we scan a new value A[i] = x in the array A, we just need to look at the sequence from right to left, and remove all the values j such that A[j] > x.

V = {};
for (int i = 0; i < N; ++i) {
    while (!V.empty() && A[V.back()] > A[i])
        V.pop_back();

    // If V is empty, then k1 value for i is 0, otherwise
    // k1 value for i is (1 + V.back())

    V.push_back(i);
}
Since each integer is added to V exactly once, and removed at most once, the time complexity of above algorithm is linear.

TIME COMPLEXITY:
O (N + Q)

*/