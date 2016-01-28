#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define SL(x) scanf("%lld",&x)
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
    sn *left;
    sn *right;
};

sn* newNode(int data)
{
  sn* ptr = new sn;
  ptr->data = data;
  ptr->left = ptr->right = NULL;
  return ptr;
}

int height(sn* node)
{
  if(node == NULL)
    return 0;
  return 1 + max( height(node->left),height(node->right));
}

int diameter(sn* node)
{
  int lheight = 0;
  int rheight = 0;
  if( node == 0)
  {
    return 0;
  }

  lheight = height(node->left);
  rheight = height(node->right);

  int ldiameter = diameter(node->left);
  int rdiameter = diameter(node->right);

  return max( 1 + lheight + rheight , max(ldiameter,rdiameter) );

}

int diameter(sn* node,int &height)
{
  int lh = 0 , rh = 0;
  if(node == NULL)
  {
    height = 0;
    return 0;
  }
  int ldiameter = diameter(node->left,lh);
  int rdiameter = diameter(node->right, rh);

  height = max(lh,rh) + 1;

  return max( 1 + lh + rh, max(ldiameter,rdiameter));

}

int main(int argc, char const *argv[])
{
  sn* root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  int height = 0; 
  printf("Diameter of the given binary tree is %d\n", diameter(root,height));
  
  return 0;
}