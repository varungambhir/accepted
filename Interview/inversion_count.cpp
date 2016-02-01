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
//#define L 2*index
//#define R 2*index+1
#define repstl(v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
//#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << "\n"
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
- Time, Pink Floyd*/
#define MAXN 100010
#define MOD 1000000007

int merge(int arr[],int temp[],int l,int mid,int r);
int mergesort(int arr[],int temp[],int l,int r);

int arr[100];
int temp[100];

int main(int argc, char const *argv[])
{
    arr[0] = 1;
    arr[1] = 20;
    arr[2] = 6;
    arr[3] = 4;
    arr[4] = 5;
    arr[5] = 14;
    
    cout << "Inversions : " <<mergesort(arr,temp,0,4) << endl;

    cout << endl;
    return 0;
}

int mergesort(int arr[],int temp[],int left,int right)
{
    if(left < right)
    {
        int mid = (left+right)/2;
        int inv_count = 0;
        inv_count+=mergesort(arr,temp,left,mid);
        inv_count+=mergesort(arr,temp,mid+1,right);
        inv_count+=merge(arr,temp,left,mid,right);
        return inv_count;
    }
    return 0;
}

int merge(int arr[],int temp[],int left,int mid,int right)
{
    int i,j,k;
    int n1 = mid - left +1;
    int n2 = right -(mid+1) +1;

    int inv_count  = 0;
    int L[n1] , R[n2];

    for(i=0; i < n1; i++)
        L[i] = arr[left + i];
    for(j = 0; j< n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2 )
    {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            {
                arr[k++] = R[j++];
                inv_count += (mid+1 - i);
            }
    }

    while(i < n1)
    {
        arr[k++] = L[i++];
    }

    while(j < n2)
    {
        arr[k++] = R[j++];
    }

    return inv_count;
}

