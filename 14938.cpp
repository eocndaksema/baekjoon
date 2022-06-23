//14938번
#define INF 9999
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
typedef long long int ll;
using namespace std;
void floyd(ll n);
ll d[101][101];
ll t[101];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(ll i=1; i<101; i++)
    {
        for(ll j=1; j<101; j++)
        {
            if(i!=j)
            {
                d[i][j]=INF;
            }
        }
    }

    ll n,m,r; cin>>n>>m>>r;
    for(ll i=1; i<=n; i++)
    {
        cin>>t[i];
    }
    for(ll i=0; i<r; i++)
    {
        ll a,b,l; cin>>a>>b>>l;
        d[a][b]=min(d[a][b],l);
        d[b][a]=min(d[b][a],l);
    }

    floyd(n);

    ll ans=0;
    for(ll i=1; i<=n; i++)
    {
        ll sum=0;
        for(ll j=1; j<=n; j++)
        {
            if(d[i][j]<=m)
            {
                sum=sum+t[j];
            }
        }
        ans=max(ans,sum);
    }
    cout<<ans;
}
void floyd(ll n){
    for(ll x=1; x<=n; x++)
    {
        for(ll s=1; s<=n; s++)
        {
            for(ll e=1; e<=n; e++)
            {
                d[s][e]=min(d[s][e],d[s][x]+d[x][e]);
            }
        }
    }
}