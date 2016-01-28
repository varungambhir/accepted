#include <bits/stdc++.h>
using namespace std;
#define sn struct node

struct node
{
    int data;
    sn *left;
    sn *right;
};

class tree
{
public:
    node *root;
    tree()
    {
        root = NULL;
    }
    sn *newnode(int data)
    {
        sn *ptr = new sn;
        //sn *ptr = (sn *)malloc(sizeof(sn));
        ptr->data = data;
        ptr->left = ptr->right = NULL;
        return ptr;
    }

    void insert(int data, sn* &r)
    {
        if(this->root == NULL)
        {
            this->root = newnode(data);
            return;
        }
        if( r == NULL )
        {
            r = newnode(data);
            return;
        }

        if( data >= r->data)
            return insert(data, r->right);
        else
            return insert(data,r->left);
    }

    void display(queue<sn*> q = queue<sn*>(), bool check = 0)
    {
        if(check == 0)
            q.push(this->root);
        
        if(q.front() == NULL)
            return;

        queue<sn*> qq;
        while(!q.empty())
        {   
            cout << q.front()->data << " ";

            if( q.front()->left != NULL)
                qq.push(q.front()->left);

            if( q.front()->right != NULL)
                qq.push(q.front()->right);
            
            q.pop();
        }   

        if(!qq.empty())
            display(qq,1);
        return;
    }

    void inOrder(sn* r = NULL, bool check = 0)
    {
        if( check == 0)
            r = this->root;

        if( r == NULL )
            return;
        else
        {
            inOrder(r->left , 1);
            cout << r->data << " ";
            inOrder(r->right , 1);
        }
    }
    int findmin(sn* r)
    {
        if(r->left != NULL)
            return findmin(r->left);
        else
            return r->data;

    }
    //next inorder successor is minimum value in left subtree
    void deletes(sn* &r, int x)
    {
        if(root == NULL)
            return;
        //root null 
        if(r->data == x)
        {
            if(r->left == NULL && r->right == NULL)//leaf
            {
                delete r;
                r = NULL;
                return;
            }
            else if(r->left != NULL && r->right == NULL)//one child
            {
                sn* ptr = r;
                r = r->left;
                delete ptr;
                ptr = NULL;
            }
            else if(r->left == NULL && r->right != NULL)
            {
                sn* ptr = r;
                r = r->right;
                delete ptr;
                ptr = NULL;
            }
            else// 2 childs
            {
                int val = findmin(r->right);
                
                deletes(r->right,val);
                r->data = val;
            }
        }
        else if(r->data > x)
        {
            return deletes(r->left,x);
        }
        else
        {
            return deletes(r->right,x);
        }
    }

    int findmax(sn* r)
    {
        if(r->right != NULL)
            return findmax(r->right);
        else
            return r->data;
    }

    int findmax2(sn* r)
    {
        while(r->right != NULL)
            r = r->right;
            return r->data;
    }

    bool search(sn* r,int val)
    {
        if( r == NULL)
            return false;
        if( r->data == val)
            return true;
        else if(r->data > val)
            return search(r->left,val);
        else if(r->data < val)
            return search(r->right,val);
    }

};

// root = insert(root,10)

//*(arr + i*c + j)
int main(int argc, char const *argv[])
{
    tree t;
    t.insert(10,t.root);
    t.insert(20,t.root);
    t.insert(2,t.root);
    t.insert(40,t.root);
    t.insert(3,t.root);

    t.inOrder();
    cout << endl;
    t.display();
    cout<<"\n";
    t.deletes(t.root,10);
    //t.inOrder();
    t.display();
    cout<<endl;
    cout << t.findmax2(t.root);

    return 0;
}