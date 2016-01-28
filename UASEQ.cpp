#include<iostream>
#include<cstdio>
#define MAX 100002
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define gc getchar_unlocked
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int main()
{
    int i,n,k,maxk,a[MAX],diff[MAX];
        scanint(n);
        scanint(k);
        maxk=MIN((n-2),10);
        for(i=0;i<n;i++)
        scanint(a[i]);
        if(maxk==k && k==(n-2))
        {   int ind=0;//ind&ind+1
            diff[0]=a[1]-a[0];
            int max=diff[0];
            for(i=1;i<n-1;i++)
            {
                diff[i]=a[i+1]-a[i];
                if(diff[i]>max)
                {
                    max=diff[i];
                    ind=i;
                }
            }
        for(i=ind+2;i<n;i++)
            {
                a[i]=a[i-1]+max;
            }
        for(i=ind-1;i>=0;i--)
            {
                a[i]=a[i+1]-max;
            }
        }
        else//k<maxk
        {
            for(i=0;i<n-1;i++)
                diff[i]=a[i+1]-a[i];
            int count=1;
            int max_count =1;
            int max_value = diff[0];
        for(i=1; i<n-1; i++)
        {
         if(diff[i-1] == diff[i])
        {
            count++;
            if(count>max_count)
            {
                max_count = count;
                max_value = diff[i];//max count of d
            }
        }
        else
                count = 1;
        }
        int minval,index;
        for(i=0;i<n-1;i++)
        {if(max_value==diff[i])
                {
                    minval=a[i];
                    index=i;
                    i++;
                    break;
                }
        }
        for(;i<n-1;i++)
        {
            if(max_value==diff[i] && a[i] < minval)
            {
                minval=a[i];
                index=i;
            }
        }
        for(i=index+1;i<n;i++)
        {
            a[i]=a[i-1]+max_value;
        }
        for(i=index-1;i>=0;i--)
            {
                a[i]=a[i+1]-max_value;
            }
 
        }
 
for(i=0;i<n;i++)
printf("%d ",a[i]);
 
    return 0;
}