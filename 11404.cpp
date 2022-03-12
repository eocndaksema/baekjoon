#define INF 99999999
#include <iostream>
#include <algorithm>
#include <vector>
typedef long long int ll;
using namespace std;
void floyd(ll n);
ll a[101][101];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(ll i=0; i<101; i++)
    {
        for(ll j=0; j<101; j++)
        {
            if(i==j)
            {
                a[i][j]=0;
            }
            else
            {
                a[i][j]=INF;
            }
        }
    }
    ll n,m; cin>>n>>m;
    for(ll i=0; i<m; i++)
    {
        ll x,y,z; cin>>x>>y>>z;
        a[x][y]=min(a[x][y],z);
    }
    floyd(n);
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            if(a[i][j]==INF)
            {
                cout<<"0 ";
            }
            else
            {
                cout<<a[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
}
void floyd(ll n){
    for(ll k=1; k<=n; k++)
    {
        for(ll s=1; s<=n; s++)
        {
            for(ll e=1; e<=n; e++)
            {
                if(a[s][e]>a[s][k]+a[k][e])
                {
                    a[s][e]=a[s][k]+a[k][e];
                }
            }
        }
    }
}