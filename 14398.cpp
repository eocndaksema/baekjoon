#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string.h>
typedef long long int ll;
using namespace std;
bool check(ll n, ll m);
ll gcd(ll n,ll m);
bool dfs(ll x);
vector <ll> v;
//vector <ll> odd;
//vector <ll> even;
ll matching[201];
bool visited[201];
bool adj[201][201];
ll ans=0;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    v.push_back(-1);
    for(ll i=0; i<n; i++)
    {
        ll input;
        cin>>input;
        v.push_back(input);
    }
    for(ll i=1; i<v.size(); i++)
    {
        if(v[i]&1)
        {
            continue;
        }
        for(ll j=1; j<v.size(); j++)
        {
            if(!(v[j]&1))
            {
                continue;
            }
            if(gcd(v[i],v[j])==1&&check(v[i],v[j]))
            {
                adj[i][j]=1;
            }
        }
    }
    for(ll i=1; i<v.size(); i++)
    {
        memset(visited, 0, sizeof(visited));
        if(dfs(i))
        {
            ans++;
        }
    }
    cout<<ans;
}
bool dfs(ll x){
    if(visited[x]==1)
    {
        return 0;
    }
    visited[x]=1;
    for(ll i=1; i<v.size(); i++)
    {
        if(adj[x][i])
        {
            if(!matching[i]||dfs(matching[i]))
            {
                matching[i]=x;
                return 1;
            }
        }
    }
    return 0;
}
ll gcd(ll n,ll m){
    if(n>m)
    {
        ll tmp=m;
        m=n;
        n=tmp;
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
bool check(ll n, ll m){
    ll k=(ll)sqrt(n*n+m*m);
    if(n*n+m*m==k*k)
    {
        return true;
    }
    else
    {
        return false;
    }
}