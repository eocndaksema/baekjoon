#include <iostream>
#include <algorithm>
typedef long long int ll;
using namespace std;
ll ans=0;
ll a[1000005];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(ll i=1; i<n-1; i++)
    {
        ans=max(ans,a[i]+min(a[i-1],a[i+1]));
    }
    ans=max({a[0],a[n-1],ans});
    cout<<ans;
}