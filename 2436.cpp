#include <iostream>
typedef long long int ll;
#include <algorithm>
using namespace std;
ll gcd(ll n,ll m);
int main(){
	cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll sum=9223372036854775807;
    ll ans1,ans2;
    ll x,y,z;
    cin>>x>>y;
    z=y/x;
    for(ll i=1; i*i<=z; i++)
    {
        if((z%i)==0)
        {
            if(i+(z/i)<=sum&&gcd(i,z/i)==1)
            {
                sum=i+z/i;
                ans1=i;
                ans2=z/i;
            }
        }
    }
    cout<<x*ans1<<" "<<x*ans2;
}
ll gcd(ll n,ll m){
    if(n>m)
    {
        ll tmp=n;
        n=m;
        m=tmp;
    }
    if(n==0)
    {
        return m;
    }
    else
    {
        return gcd(m%n,n);
    }
}