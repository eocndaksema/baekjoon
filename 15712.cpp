#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
ll f(ll r,ll n,ll mod);
ll solve(ll r,ll n,ll mod);
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll a,r,n,mod;
    cin>>a>>r>>n>>mod;
    if(mod==1)
    {
        cout<<0;
    }
    else
    {
        if(r==1)
        {
            cout<<(a%mod*n%mod)%mod;
        }
        else
        {
            cout<<(a%mod*solve(r,n,mod)%mod)%mod;
        }
    }
}
ll f(ll r,ll n,ll mod){
    if(n==1)
    {
        return r%mod;
    }
    ll b=f(r,n/2,mod);
    if(n&1)
    {
        return (r%mod*b%mod*b%mod)%mod;
    }
    else
    {
        return (b%mod*b%mod)%mod;
    }
}
ll solve(ll r,ll n,ll mod){
    if(n==1)
    {
        return 1;
    }
    else
    {
        int x=(1%mod+f(r,n/2,mod)%mod)%mod;
        int y=solve(r,n/2,mod)%mod;
        int z=f(r,2*(n/2),mod)%mod;
        if(n&1) //홀수일때
        {
            return (z%mod+(x%mod*y%mod))%mod;
        }
        else //짝수일때
        {
            return (x%mod*y%mod)%mod;
        }
    }
}