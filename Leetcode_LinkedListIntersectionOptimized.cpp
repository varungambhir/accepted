#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) <= (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define repstl(v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(c.begin(),c.end(),x) != (c).end())
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
  template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << endl;
}
  template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
  #define trace(...)
#endif

ll MOD = 1000000007LL;


// https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define ln ListNode
 struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    
    ln *head = headA;
    int n1 = 0;
    while(NULL != head) {
      n1++;
      head = head->next;
    }
    
    int n2 = 0;
    head = headB;
    while(NULL != head) {
      n2++;
      head = head->next;
    }
    
    while(n1 >0 && n2 > 0) {
      while(n1 > n2) {
        n1--;
        headA = headA->next;
      }
      while(n2 > n1) {
        n2--;
        headB = headB->next;
      }
      if(headB == headA)
        return headA;
      else {
        n1--;
        n2--;
        headA = headA->next;
        headB = (*headB).next;
      }
    }
    return NULL;
  }
};


// https://leetcode.com/problems/intersection-of-two-linked-lists/
int main(int argc, char const *argv[])
{
  BOOST;
  return 0;
} 