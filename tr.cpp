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
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define MAXN 100005
#define MOD 1000000007
#define sn struct node

struct node
{
  int data;
  struct node* left;
  struct node* right;
};

struct node* NewNode(int data)
{
  struct node* node = (struct node*) malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return (node);
}

void PreorderIterative(sn* root)
{
  sn *node  = root;
  stack<sn*> parentstack;

  while(!parentstack.empty() || node != NULL)
  {
    if(node != NULL)
    {
      cout << node->data << " ";
      if(node->right != NULL);
        parentstack.push(node->right);
      node = node->left;
    }
    else
    {
      node = parentstack.top();
      parentstack.pop();
    }
  }
}

void InorderIterative(sn* root)
{
  sn *node = root;
  stack<sn*> parentstack;
  while(!parentstack.empty() || node != NULL)
  {
    if(node != NULL)
    {
      parentstack.push(node);
      node = node->left;
    }
    else
    {
      node = parentstack.top();
      parentstack.pop();
      cout << node->data << " ";
      node = node->right;
    }
  }
}

void PostOrderIterative(sn* root)
{
  sn* node = root;
  stack<sn*> parentstack;
  sn* lastvisited = NULL;
  sn* topnode = NULL;
  int cnt =0;
  while(!parentstack.empty() || node != NULL) 
  {
    if(node != NULL)
    {
      parentstack.push(node);
      node = node->left;
    }
    else
    {
      if(parentstack.top()->right != NULL && parentstack.top()->right != lastvisited)
        node = parentstack.top()->right;
      else
      {
        cout << parentstack.top()->data << " ";
        lastvisited = parentstack.top();
        parentstack.pop();
      }
    }
  }
}


void printPreorder(struct node* node)
{
  if(node==NULL)
    return;


  printf("%d ",node->data);

  printPreorder(node->left);

  printPreorder(node->right);

  return;
}

void printPostorder(struct node* node)
{
  if(node==NULL)
    return;

  printPostorder(node->left);

  printPostorder(node->right);

  printf("%d ",node->data);

  return;
}

void printInorder(struct node* node)
{
  if(node==NULL)
    return;

  printInorder(node->left);

  printf("%d ",node->data);

  printInorder(node->right);

  return;
}



int main(int argc, char const *argv[])
{
  struct node* root = NewNode(1);
  root->left = NewNode(2);
  root->right = NewNode(3);
  root->left->left = NewNode(4);
  root->left->right = NewNode(5);

  printf("\n Preorder traversal of binary tree is \n");
  PreorderIterative(root);

  printf("\n Inorder traversal of binary tree is \n");
  InorderIterative(root);

  printf("\n Postorder traversal of binary tree is \n");
  PostOrderIterative(root);

  return 0;
}

