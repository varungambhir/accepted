#include <bits/stdc++.h>
using namespace std;
#define sn struct node
#define pb push_back

struct node
{
    char data;
    sn* left;
    sn* right;
};

class tree
{
public:
    sn* root;
    vector<sn*> v;
    tree()
    {
        root = NULL;
        v.clear();
    }

    sn *newnode(char val)
    {
        sn* ptr=  new sn;
        ptr->left = ptr->right = NULL;
        ptr->data = val;
    }

    sn *insertElement(sn* &r,char val,bool left = 0)//right  =1
    {
        if(this->root == NULL)
        {
            this->root = newnode(val);
            return this->root;
        }
        if(r == NULL)
        {
        r = newnode(val);
        return r;
        }

        if(left == 0)
        {
            r->left = newnode(val);
            return r->left;
        }
        else
        {
            r->right = newnode(val);
            return r->right;
        }

    }

    void inOrder(sn* r)
    {
        if(r == NULL) return;
        inOrder(r->left);
        cout << r->data << " ";
        inOrder(r->right);
    }

    void Diagnol(sn* r = NULL, bool check = 0)
    {
        if(check == 0 )
            r = this->root;
        if(r == NULL)
            return;
        
        sn* rcopy = r;
        queue<sn*> q;

        while( rcopy != NULL)
        {
            if(rcopy->left != NULL)
            q.push(rcopy->left);
            cout << rcopy->data << " ";
            rcopy = rcopy->right;
        }
        q.push(NULL);
        cout<<"\n";

        while(!q.empty())
        {
            sn* temp = q.front();
            q.pop();

            if(temp == NULL)
            {
                cout<<"\n";
                if(!q.empty())
                    q.push(NULL);
            }
            else
            {
                while(temp!=NULL)
                {
                    cout << temp->data << " ";
                    if(temp->left != NULL )
                        q.push(temp->left);
                    temp = temp->right;                    
                }
            }

        }
    }

};

int main()
{
    tree t;
    t.insertElement(t.root,'a');
    sn* a = t.insertElement(t.root->left,'d');
    sn* b = t.insertElement(a->right,'e');
    a = t.insertElement(a->left,'h');
    a = t.insertElement(a->right,'i');
    a = t.insertElement(t.root->right,'b');
    b = t.insertElement(t.root->right->left,'f');
    a = t.insertElement(a->right,'c');
    a = t.insertElement(a->left,'g');
    a = t.insertElement(a->left,'j');

    //t.inOrder(t.root);
    t.Diagnol();
    return 0;
}

