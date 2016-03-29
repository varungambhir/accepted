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

inline void inputfile()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
}

 /*Tired of lying in the sunshine, Staying home to watch the rain
You are young and life is long, And there is time to kill today
And then one day you find, 10 years have got behind you
No one told you when to run, You missed the starting gun

And you run and you run to catch up with the sun
But it's Sinking
Racing around to come up behind you again
The Sun is the same in a relative way, but you're older
Shorter of breath and one day closer to death

Every year is getting shorter, never seem to find the time
Plans that either come to naught or half a page of scribbled lines
- Time, Pink Floyd*/
bool table[100][100] = {0};

void printsubstr(char *str,int low, int high)
{
    FOR(i,low,high)
    cout << str[i];
}

int longestPalSubstr(char *str)
{
    int n = strlen(str);
    //str[i..j] is not a palin ; false
    //


    int maxlength = 1;
    for(int i=0; i < n ; i++)
        table[i][i] = true;

    int start = 0;
    //lengths greater than 2
    for(int i=0; i <n-1 ; i++)
    {
        if(str[i] == str[i+1])
        {
            table[i][i+1] = true;
            start = i;
            maxlength = 2;
        }
    }

    //check for lengths greater than 2. k is length of substring
    for(int k  =3; k <= n; k++)
    {
        for(int i = 0; i < n-k+1; i++)
        {
            //get the ending index of substring from
            // starting index i and length k
            int  j = i + k  -1;

            //checking for sub-string from ith index to
            //jth index iff str[i+1] to str[j-1] is a palindrome

            if(table[i+1][j-1] && str[i] == str[j] )
            {
                table[i][j] = true;

                if(k > maxlength)
                {
                    start = i;
                    maxlength = k;
                }
            }
        }
    }

    cout << "Longest Palindrome Substring is  : ";
    printsubstr(str,start,start+maxlength-1);
    cout << endl;
    return maxlength;
}
int main(int argc, char const *argv[])
{
    BOOST;
    char str[] = "forgeeksskeegfor";
    cout << "len  : " << longestPalSubstr(str) << endl;
    return 0;
}
