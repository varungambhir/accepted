#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define L 2*node
#define R 2*node+1
#define repstl(v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(c.begin(),e.end(),x) != (c).end())
#define MAXN 100010
#define MOD 1000000007
 /*Tired of lying in the sunshine, Staying home to watch the rain
You are young and life is long, And there is time to kill today
And then one day you find, 10 years have got behind you
No one told you when to run, You missed the starting gun
- Time, Pink Floyd*/


#define sn struct node
struct node
{
  int data;
  struct node *l;
  struct node *r;
};  

sn* newnode(int data)
{
  sn* ptr = new sn;
  ptr->data = data;
  ptr->l = ptr->r = NULL; 
  return ptr;
}

bool findpath(sn* root, vector<int> &path, int k)
{
  if(root == NULL )
    return false;

  path.push_back(root->data);

  if(root->data == k)
    return true;

  if( (root->l!=NULL && findpath(root->l,path,k)) ||
      (root->r!=NULL && findpath(root->r,path,k))
    )
  return true;

  path.pop_back();
  return false;
}

int findLCA(sn* root, int n1, int n2 )
{

  vector<int> path1,path2;
  if( !findpath(root,path1,n1) || !findpath(root,path2,n2) )
    return -1;

  int i = 0;
  for(i = 0; i < path1.size() && i<path2.size() ; i++)
    if(path2[i] != path1[i])
      break;
  return path1[i-1];
}

int main(int argc, char const *argv[])
{
  sn* head = newnode(1);

  head->l = newnode(2);
  head->r = newnode(3);
  head->r->l = newnode(6);
  head->r->r = newnode(7);
  head->l->l = newnode(4);
  head->l->r = newnode(5);
  head->l->r->l = newnode(8);

  head->l->r->r = newnode(9);

  head->l->r->r->l = newnode(10);
  head->l->r->r->r = newnode(11);
  
  cout << " LCA  " << findLCA(head,4,10);
  {

  }

  return 0;
}