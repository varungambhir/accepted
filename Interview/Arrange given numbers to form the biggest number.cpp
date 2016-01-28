#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define MAX 100000
#define MOD 1000000007
#define endl "\n"
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())

int compare(string X, string Y)
{
    string XY = X.append(Y);
    string YX = Y.append(X);

    return XY.compare(YX) > 0 ? 1 : 0 ;
}


int main(int argc, char const *argv[])
{
    std::vector<string> v;
    v.push_back("712");
    v.push_back("283");
    v.push_back("985");
    //v.push_back("914");

    string a = "9";
    string b = "98";
    cout<<a.compare(b)<<endl;

    sort(v.begin(),v.end(),compare);

    repstl(v)
    {
        cout<<*it;
    }
    cout<<endl;

    return 0;
}

