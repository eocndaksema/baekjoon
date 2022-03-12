#include <iostream>
#include <algorithm>
typedef long long int ll;
using namespace std;
ll ccw(ll x1,ll x2,ll x3,ll y1,ll y2,ll y3);
ll a[50];
ll cnt[50];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n; cin>>n;
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(ll i=0; i<n; i++)
    {
        for(ll j=i+1; j<n; j++)
        {
            for(ll k=i+1; k<j; k++)
            {
                if(ccw(i,j,k,a[i],a[j],a[k])==-1)
                {
                    continue;
                }
                else
                {
                    goto Label;
                }
            }
            cnt[i]++;
            cnt[j]++;
            Label: continue;
        }
    }
    ll ans=0;
    for(ll i=0; i<n; i++)
    {
        ans=max(ans,cnt[i]);
    }
    cout<<ans;
}
ll ccw(ll x1,ll x2,ll x3,ll y1,ll y2,ll y3){
    if(x1==x2)
    {
        if(x3>x1)
        {
            return -1;
        }
        else if(x3<x1)
        {
            return 1;
        }
    }
    else if(x1==x3)
    {
        if(y3<y1)
        {
            return -1;
        }
        else if(y3>y1)
        {
            return 1;
        }
    }
    else
    {
        ll a=(x1-x3)*(y1-y2);
        ll b=(x1-x2)*(y1-y3);
        if(a<b)
        {
            return 1;
        }
        else if(a>b)
        {
            return -1;
        }
    }
    return 0;
}