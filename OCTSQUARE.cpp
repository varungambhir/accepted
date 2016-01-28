// will this one get ac

#include <set>
#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	int x,y,best=2;
	scanf("%d",&n);
	if(n==0)
	{
		printf("4") ;
		return 0;
	}
	if(n==2)
	{
		printf("2") ;;
		return 0;
	}
	if(n==1)
	{
		printf("3") ;
		return 0;
	}
	set <pair<int,int> > points;

	vector<pair<int,int> > vec;
	

	
	for (int i = 0; i < n; ++i) {
    	cin >> x >> y ;
		points.insert (make_pair(x,y));
		vec.push_back(make_pair(x,y));
	}
	
	
	pair<int,int> one,two,p[4];
	int x1,y1,x2,y2;
	set<pair<int,int> >::iterator it1,it2,it3,it4;
	
	
	for (int i = 0; i < vec.size()-1; ++i)
	{
		one=vec[i];
		x1=vec[i].first;
		y1=vec[i].second;
		for (int j = i+1; j < vec.size(); ++j)
		{
			two=vec[j];
			x2=vec[j].first;
			y2=vec[j].second;
			
			p[0]=make_pair(x1+y1-y2,x2+y1-x1);
			p[1]=make_pair(x2+y1-y2,y2+x2-x1);
			p[2]=make_pair(x1+y2-y1,y1-x2+x1);
			p[3]=make_pair(x2+y2-y1,y2-x2+x1);
			
			
			
			it1=points.find(p[0]);
			it2=points.find(p[1]);
			it3=points.find(p[2]);
			it4=points.find(p[3]);
			if( (it1!=points.end() && it2!=points.end()) || (it3!=points.end() && it4!=points.end()) ) best=0;
			else if( (it1!=points.end() || it2!=points.end()) || (it3!=points.end() || it4!=points.end()) )
			{
				if(best>1) best=1;
			}
			else
			{
				if(best>2) best=2; 
			}
		}
	}
	printf("%d\n",best);
	
	return 0;
}