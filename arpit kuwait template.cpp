//arp95(aimwf) machake rahega ek din
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007ll
#define E 1e-9
#define ll long long
#define LSOne(S) (S & (-S))
//power of two
bool poftwo(ll num)
{
	return ((num&(num-1))==0);
}
//number is odd or even
bool oddeven(ll num)
{
	if((num&1)==0)
		return 1;
	else
		return 0;
}
//fastexpo
ll fastexpo(ll a, ll n) 
{
	ll ret=1;
	ll b=a;
	while(n) 
	{
		if(n&1) 
		ret=(ret*b)%MOD;
		b=(b*b)%MOD;
		n>>=1;
	}
	return ret%MOD;
}
//to find gcd of two numbers (Eulers Theoram)
ll gcd(ll a ,ll b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
//to find lcm of two numbers
ll lcm(ll num1,ll num2)
{
	return (num1*num2)/gcd(num1,num2);
}
//to check existence of element in a sorted array
ll b1(ll arr[],ll low,ll high,ll item)
{
	ll mid;
	while((high-low)>1)
	{
		mid=low+(high-low)/2;
		if(arr[mid]>item)
			high=mid;
		else
			low=mid;
	}
	if(arr[low]==item)
		return low;
	else if(arr[high]==item)
		return high;
	return -1;
}
// to find an element strictly less than the item
ll b2(ll arr[],ll low,ll high,ll item)
{
	ll mid;
	while((high-low)>1)
	{
		mid=low+(high-low)/2;
		if(arr[mid]>=item)
			high=mid;
		else
			low=mid;
	}
	if(arr[high]<item)
		return high;
	else if(arr[low]<item)
		return low;
	return -1;
}
// to find the element strictly greater than the item
ll b3(ll arr[],ll low,ll high,ll item)
{
	ll mid;
	while((high-low)>1)
	{
		mid=low+(high-low)/2;
		if(arr[mid]>item)
			high=mid;
		else
			low=mid;
	}
	if(arr[low]>item)
		return low;
	else if(arr[high]>item)
		return high;
	return -1;
}
vector<int>v[100005];
int i,j,k,l,n,m,t,ans1=INT_MAX,ans2=0,x,type,vis[1005],s[1000005],q[1000005];
void rec(int num,ll sum)
{
	if(num>=n)
	{
		if(sum>ans2)
			ans2=sum;
		else if(sum<ans1)
			ans1=sum;
		return;
	}
	for(int yu=0;yu<v[num].size();yu++)
	{
		if(vis[v[num][yu]]==0)
		{
			vis[v[num][yu]]=1;
			rec(num+1,sum+(s[num]*q[v[num][yu]]));
			vis[v[num][yu]]=0;
		}
	}
	return;
}
int main() 
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	//sieve();
	//primesieve();
	//gcd(num1,num2);
	//lcm(num1,num2);
	//b(array,low,high,item)
	//fastexpo(base,power)
	//issquare(num)
	char ch;
	cin>>n>>m;
	for(i=0;i<n;i++)
		cin>>s[i];
	for(i=0;i<m;i++)
		cin>>q[i];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>ch;
			if(ch=='Y')
				v[i].push_back(j);
		}
	}
	rec(0,0);
	cout<<ans1<<" "<<ans2;
	return 0;
} 