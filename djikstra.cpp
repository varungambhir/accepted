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
#define endl "\n"
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define MAX 100000
#define MOD 1000000007

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

priority_queue<ii , vector<ii> , greater<ii> > Q1;//ascending

void Djikstra()
{
      vector<int> D(N, 987654321); 
      // distance from start vertex to each vertex

      priority_queue<ii,vector<ii>, greater<ii> > Q; 
      // priority_queue with reverse comparison operator, 
      // so top() will return the least distance
      // initialize the start vertex, suppose it’s zero
      D[0] = 0;
      Q.push(ii(0,0));

      // iterate while queue is not empty
      while(!Q.empty()) {

            // fetch the nearest element
            ii top = Q.top();
            Q.pop();
                        
            // v is vertex index, d is the distance
            int v = top.second, d = top.first;

            // this check is very important
            // we analyze each vertex only once
            // the other occurrences of it on queue (added earlier) 
            // will have greater distance
            if(d <= D[v]) {
                  // iterate through all outcoming edges from v
                  repstl(G[v]) {
                        int v2 = it->first, cost = it->second;
                        if(D[v2] > D[v] + cost) {
                              // update distance if possible
                              D[v2] = D[v] + cost;
                              // add the vertex to queue
                              Q.push(ii(D[v2], v2));

                        }
                  }
            }
      }
}


void djikstras()
{
    std::vector<int> D(N,987654321);

    set<ii> Q;
    D[0] = 0;
    Q.insert(ii(0,0));

    while(!Q.empty())
    {
        //fetch closset to start element
        ii top = *Q.begin();
        Q.erase(Q.begin());
        int v =  top.second , d = top.first;
        // d <= D[v]
        //no need to check whether distance is prefect, 
        //because new vertices will always add up
        // in proper way in this implementaion

        repstl(G[v])
        {
            int v2 = it->first , cost = it->second;
            if(D[v2] > D[v] + cost)
            {
                //not possible with priority_queue
                if(D[v2] != 987654321)
                {
                    Q.erase(Q.find(ii(D[v2],v2)));
                }
                D[v2] = D[v] + cost;
                Q.insert(ii(D[v2],v2));
            }
        }
    }
       
}

int main(int argc, char const *argv[])
{

    return 0;
}