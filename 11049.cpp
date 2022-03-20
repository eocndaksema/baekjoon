#include <iostream>
#include <algorithm>
#include <vector>
typedef long long int ll;
using namespace std;
ll dp[505][505];
pair <ll,ll> p[505];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(ll i=1; i<505; i++)
    {
        for(ll j=1; j<505; j++)
        {
            if(i<j)
            {
                dp[i][j]=9999999999;
            }
        }
    }
    ll n; cin>>n;
    for(ll i=1; i<=n; i++)
    {
        cin>>p[i].first>>p[i].second;
    }
    for(ll m=2; m<=n ; m++)
    {
        ll i=1;
        for(ll j=m; j<=n; j++)
        {
            for(ll k=1; k<j; k++)
            {
                ll a=p[i].first;
                ll b=p[k].second;
                ll c=p[j].second;
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+a*b*c);
            }
            i++;
        }
        i=1;
    }
    cout<<dp[1][n];
}