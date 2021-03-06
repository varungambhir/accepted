#include <bits/stdc++.h>
#define mod 1000000007;
#define ll long long int
#define pb(x) push_back(x)
#define MP(x,y) make_pair(x,y)
using namespace std;
 
vector <int> primes[1024];
 
void prime_factorisation(){
    ll i,j,x,product;
    for(i=2;i<=1024;i++){
        if(primes[i].size() == 0){
            for(j=i;j<=1024;j=j+i){
                x=j;
                product=1;
                while(x%i==0){
                    x=x/i;
                    product=product*i;
                }
                primes[j].pb(product);
            }
        }
    }
}
 
ll pow(ll a, ll b){
    ll ret=1;
    while(b)
    {
        if(b%2==1)
            ret=(ret*a)%mod;
        b/=2;
        a=(a*a)%mod;
    }
    return ret;
}
 
void solve(){
    ll n,m,l,r,i,j,len,k;
    scanf("%lld %lld %lld %lld",&n,&m,&l,&r);
    vector <ll>missing;
    vector <ll>load;
    missing.pb(0);
    missing.pb(0);
    load.pb(0);
    load.pb(0);
    for(i=2;i<=r;i++){
        missing.pb(0);
        load.pb(0);
        if(primes[i].size()<=1){
            missing[i]=pow(m-m/i,n);
            load[i]=missing[i];
        }
        else{
            int si=primes[i].size();
            long long int times=0;
            load[i]=0;
            for(j=1;j<(1<<si);j++){
                ll products=1;
                ll counts=0;
                for(k=0;k<si;k++){
                    if((j&(1<<k))){
                        products*=primes[i][k];
                        counts++;
                    }
                }
                if(counts%2==0){
                    times=times-m/products;
                }
                else{
                    times=times+m/products;
                }
            }
            times=m-times;
            for(j=1;j<(1<<si);j++){
                ll products=1;
                ll counts=0;
                for(k=0;k<si;k++){
                    if((j&(1<<k))){
                        products*=primes[i][k];
                        counts++;
                    }
                }
                if(counts%2==0){
                    if(products==i){
                        missing[i]-=pow(times,n);
                        load[i]+=pow(times,n);
                    }
                    else{
                        missing[i]-=load[products];
                    }
                }
                else{
                    if(products==i){
                        missing[i]+=pow(times,n);
                        load[i]+=pow(times,n);
                    }
                    else{
                        missing[i]+=load[products];
                    }
                }
                if(missing[i]<0){
                    missing[i]+=mod;
                }
                missing[i]=missing[i]%mod;
            }
        }
    }
    ll sol=0;
    ll all=pow(m,n);
 
    for(i=l;i<=r;i++){
        ll local_sol=all-missing[i];
        if(local_sol<0)
            local_sol=local_sol+mod;
        sol=(sol+local_sol)%mod;
    }
    printf("%lld\n",sol);
}
 
int main(){
    prime_factorisation(); //precomputation.
    int t;
    scanf("%d",&t);
    while(t--){
            solve();
    }
    return(0);
}