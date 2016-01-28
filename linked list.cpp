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
  int val;
  node *next;
};

class Slist{
private:
  struct node *front;
  struct node *rear;

public:
    Slist()
    {
        front = rear = NULL;
    }

    void insertAtFront(int val)
    {
        node *ptr = new node;
        ptr->val = val;
        ptr->next = NULL;
        if(front == NULL)
        {
            front = ptr;
            rear = ptr;
        }
        else
        {
            ptr->next = front;
            front = ptr;
        }
    }

    void insertAtRear(int val)
    {
        node *ptr = new node;
        ptr->val = val;
        ptr->next = NULL;

        if(rear == NULL)
        {
            front = ptr;
            rear = ptr;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
        }
    }

    void del(int val)
    {
        for(sn* it = front; it!=NULL;it = it->next)
            if(it->val == val)
            {
                sn* tmp = front;

                if(it == front)
                    front = front->next;
                else
                    for(;tmp->next != it; tmp = tmp->next);

                tmp->next = it->next;

                if(it->next == NULL)//last
                rear = tmp;

                delete it;
                break;
            }
    }

    void insertBefore(int pos,int val)
    {
        for(sn* it = front; it != NULL; it = it->next)
            if(it->val == pos)
            {
                if(it == front)
                {
                    insertAtFront(val); return;
                }
                sn* t = front;
                for(;t->next != it; t = t->next);
                    sn* ptr = new node;
                ptr->val = val;
                ptr->next = it;
                t->next = ptr;
                break;
            }
    }

    void display()
    {
        for(sn* it = front; it != NULL; it = it->next)
            cout << it->val << " ";
        cout << "\n";
    }

    void reverse(sn* p)
    {
        if(p->next == NULL)
            front = p;
        else
        {
            reverse(p->next);
            sn* q = p->next;
            q->next = p;
            p->next = NULL;
            rear  = p;
        }
    }

    sn* begin()
    {
        return front;
    }


};

int main(int argc, char const *argv[])
{
    Slist adj;
    adj.insertAtFront(10);
    adj.insertAtFront(20);
    adj.insertAtFront(30);
    adj.insertAtRear(50);
    adj.insertAtRear(60);
    adj.insertBefore(20, 100);
    //adj.del(100);
    adj.display( );
    adj.reverse(  adj.begin() );
    adj.display( );

   //int n; cin >> n;

  return 0;
}
