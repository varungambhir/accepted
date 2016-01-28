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

sn* findLCAUtil(sn* root, int n1, int n2,bool &v1, bool &v2)
{
  if(root == NULL)
    return NULL;

  if(root->data == n1)
  {
    v1 = true;
    return root;
  }

  if(root->data == n2)
  {
    v2 = true;
    return root;
  }

  sn* leftlca = findLCAUtil(root->l,n1,n2,v1,v2);
  sn* rightlca = findLCAUtil(root->r,n1,n2,v1,v2);

  if( leftlca!= NULL && rightlca!=NULL)
    return root;

  if(leftlca != NULL)
    return leftlca;
  else
    return rightlca;
}

bool find(sn* root,int k)
{
  if(root == NULL)
    return false;

  if(root->data == k || find(root->l,k) || find(root->r,k))
    return true;
  else
    return false;
}

sn* findLCA(sn* root,int n1,int n2)
{
  bool v1 = false;
  bool v2 = false;

  sn* lca = findLCAUtil(root,n1,n2,v1,v2);

  if(v1 && v2 || v1 && find(root,n2) || v2 && find(root,n1) )
    return lca;
  else
    return NULL;
}


int main(int argc, char const *argv[])
{
  /*
              1
        2             3
    4      5        6    7
        8     9
           10  11
  */


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
  
  sn* lca = findLCA(head,8,7);
  if(lca != NULL)
    cout << "LCA  " << lca->data;
  else
    cout<<"Keys not present";
  cout<<"\n";

  return 0;
}