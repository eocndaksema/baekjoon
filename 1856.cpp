///1865번
#define INF 999999999
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
typedef long long int ll;
using namespace std;
bool floyd(ll n);
void reset();
ll a[501][501];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll tc,n,m,w,s,e,t; 
    cin>>tc;
    while(tc--)
    {
        reset();
        cin>>n>>m>>w;
        for(ll i=0; i<m; i++)
        {
            cin>>s>>e>>t;
            a[s][e]=min(a[s][e],t);
            a[e][s]=min(a[e][s],t);
        }
        for(ll i=0; i<w; i++)
        {
            cin>>s>>e>>t;
            a[s][e]=min(a[s][e],-t);
        }
        if(floyd(n))
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
}
bool floyd(ll n){
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
                if(s==e&&a[s][e]<0)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
void reset(){
    for(ll i=0; i<501; i++)
    {
        for(ll j=0; j<501; j++)
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
}