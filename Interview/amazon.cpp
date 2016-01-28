#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

typedef struct node
{
 struct node*left;
 struct node*right;
 int data;
} node;

void readInput(int *k,int *l, char arr[100],int arr1[100],int *treesize){
  char *ch = NULL,ch1;  
  int i = 0 ,mm,x;
  size_t size;
  getline(&ch,&size,stdin);
  char *token;
  token = strtok(ch, " ");
  while( token != NULL ) {
    if(i==0){
      *k = atoi(token);
        i++;
    }
    else if(i==1){
      *l = atoi(token);
        i++;
    }
    else{
      mm=atoi(token);
      arr[i-2] = mm;
      if(atoi(token)!='#' && atoi(token)!='\0')
      arr1[i-2]=mm;
        i++;
    }
    token = strtok(NULL," ");
  }
  arr[i-2] = '\0';
 *treesize=i-2;
}

node* insert(char c[],int a[],int n,int treesize)
{ node* tree=NULL;
 if(c[n]!='#' && c[n]!='\0' && n<treesize)
 {
  tree=(node*)malloc(sizeof(node));
  tree->left=insert(c,a,2*n+1,treesize);
  tree->data=a[n];
  tree->right=insert(c,a,2*n+2,treesize);
 }
 return tree;
}

void printarr(int path[] , int len)
{
  int i;
    for(i = 0; i < len; i++)
  {
    printf("%d ", path[i]);
  }
  printf("\n");
}


void printpathrec(node*tree, int path[] , int k,int sum, int pathlen)
{
  if(tree== NULL)
  {
    return;
  }
  if(sum > k)
  return;
  
  path[pathlen++] = tree->data;
  
  sum += tree->data;
  
    printarr(path,pathlen);

  
    
  printpathrec(tree->right, path, k , sum , pathlen);
  printpathrec(tree->left, path, k , sum , pathlen);
  

}

int printPath(int k,int l, node*tree){
  /*Write your logic here*/
  
  int path[100000];
  int sum = 0;
  printpathrec(tree,  path, k, 0,0);  
  
  return 0;
  
}

int main()
{
  node*tree=NULL;
  int k,l,x,treesize=0;
  char arr[100];
  int arr1[100];
  readInput(&k,&l,arr,arr1,&treesize);
  tree=insert(arr,arr1,0,treesize);
  printPath(k,l,tree);
  return 0;
}