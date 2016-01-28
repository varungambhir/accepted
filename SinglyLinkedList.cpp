#include <bits/stdc++.h>
using namespace std;

#define sn struct node

struct node
{
    int val;
    sn *next;
};

class Slist
{
public:
    sn *front;
    sn *rear;

    Slist()
    {
        front = rear = NULL;
    }

    void insertAtfront(int val)
    {
        sn *ptr = new node;
        ptr->val = val;
        ptr->next = NULL;

        if(front == NULL)
        {
            front = rear = ptr;
        }
        else
        {
            ptr->next = front;
            front = ptr;
        }
    }

    void insertAtRear(int val)
    {
        sn *ptr = new node;
        ptr->val = val;
        ptr->next = NULL;

        if(rear == NULL)
        {
            front = rear = NULL;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
        }
    }

    void del(int val)
    {
        for( sn *it = front; it!=NULL ; it = it->next)
        {
            if( it-> val == val)
            {
                sn *temp = front;
                if(it == front)
                    front = front->next;
                else
                    for(; temp->next != it; temp = temp->next);
                    // previous to it
                temp->next = it->next;

                if( it->next == NULL)
                    rear = temp;
                delete it;
                return;
            }
        }
        cout << " No node of " << val << "\n";

    }

    void insertBefore(int pos,int val)
    {
        for(sn *it = front;it != NULL; it = it->next)
        {
            if(it->val == pos)
            {
                if(it == front)
                {
                    insertAtfront(val);
                    return;
                }
                sn *temp = front;

                for(; temp->next != it; temp = temp->next);

                sn *ptr = new sn;
                ptr->val = val;
                temp->next = ptr;
                ptr->next = it;
                break;
            }
        }
    }

    void display()
    {
       for( node *it = front; it != NULL; it = it->next )
         cout << it->val << "  ";
        cout << endl;
    }

    void reverse(sn* p)
    {
        if(p->next == NULL)
            front = p;
        else
        {
        reverse(p->next);
        sn *q = p->next;
        q->next = p;
        p->next = NULL;
        rear = p;
        }
    }

    void reverse(sn *current, sn *prev, bool check = 0)
    {
        if(check)
        {
            rear = front;
        }
        if( current->next == NULL)
        {
            front = current;

            current ->next = prev;
            return;
        }

        sn *next = current->next;

        current->next = prev;

        reverse(next,current, 1);
    }

    void reverse(sn *p, int c)
    {
        sn * current , *prev, *next;

        rear = front;
        current = front;
        prev = NULL;
        while(current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        front = prev;
    }

    sn *begin()
    {
        return front;
    }

    void display(int c)
    {
        cout<< front->val << " " << rear->val << "\n";
    }



};

int main() {
    Slist adj;
    adj.insertAtfront(10);
    adj.insertAtfront(20);
    adj.insertAtfront(30);
    adj.insertAtRear(50);
    adj.insertAtRear(60);
    adj.insertBefore(20, 100);
    adj.display();
    adj.del(100);
    adj.del(120);
    adj.reverse(  adj.begin(),NULL,0 );
    adj.display( );
    adj.display( 2);

}
