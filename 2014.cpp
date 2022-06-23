//2014번
#define MAX 2147483647
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
typedef long long int ll;
using namespace std;
ll check(ll x);
map <ll,ll> m;
ll a[100];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll k,n,ans; cin>>k>>n;
    for(ll i=0; i<k; i++)
    {
        cin>>a[i];
        m[a[i]]=i;
    }
    for(ll i=0; i<n; i++)
    {
        ll x=(*m.begin()).first;
        ll y=(*m.begin()).second;
        m.erase(m.begin());
        for(ll j=0; j<=y; j++)
        {
            if(check(x*a[j])==1)
            {
                m[x*a[j]]=j;
            }
            else if(check(x*a[j])==-1)
            {
                break;
            }
        }
        ans=x;
    }
    cout<<ans<<"\n";
}
ll check(ll x){
    if(x<=MAX)
    {
        if(m[x]==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return -1;
    }
}