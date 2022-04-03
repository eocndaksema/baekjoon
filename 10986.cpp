#include <iostream>
#include <algorithm>
#include <vector>
typedef long long int ll;
using namespace std;
ll set[1001];
ll a[1000001];
ll sum[1000001];
ll ans[2];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n,m; cin>>n>>m;
    for(ll i=1; i<=n; i++)
    {
        cin>>a[i];
        a[i]=a[i]%m;
        sum[i]=(sum[i-1]+a[i])%m;
    }
    for(ll i=1; i<=n; i++)
    {
        if(sum[i]==0)
        {
            ans[0]++;
        }
        ans[1]=ans[1]+set[sum[i]];
        set[sum[i]]++;
    }
    cout<<ans[0]+ans[1]<<"\n";
}