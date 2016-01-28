#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
#include<iostream>
#include<cstdio>
#define gc getchar_unlocked

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int main()
{	int n,m,no,i;
	scanint(n);
	scanint(m);
	int a[n+1];
	long long change;
	char in;
	for(i=0;i<n;i++)
	cin>>a[i];
		change=0;
		for(i=0;i<m;i++)
		{cin>>in;
			if(in=='R')
			{
				cin>>no;
				if(change<0)
				{
					if(no+abs(change)<=n)
						cout<<a[no+abs(change)-1]<<endl;
					else
                cout<<a[no+(abs(change)%n)-1]<<endl;
				}
				else
				cout<<a[(no+change+n-1)%n]<<endl;
			}
			else if(in=='A')
			{cin>>no;
			change-=no;
			if(change<0)
				change+=n;
			}
			else if(in=='C')
			{
				cin>>no;
				change+=no;
				change=change%n;
			}
		}
	return 0;
}
