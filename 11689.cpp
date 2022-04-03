#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
typedef long long int ll;
using namespace std;
void dfs(ll x,ll index,ll cur_depth,ll depth);
set <ll> s;
vector <ll> v;
vector <bool> visited;
ll n,nn;
ll ans;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    nn=n;
    ans=nn;
    while(1)
    {
        ll x=1;
        for(ll i=2; i*i<=n; i++)
        {
            if(n%i==0)
            {
                s.insert(i);
                x=i;
                break;
            }
        }
        if(n==n/x)
        {
            break;
        }
        else
        {
            n=n/x;
        }
    }
    s.insert(n);
    for(auto it=s.begin(); it!=s.end(); it++)
    {
        v.push_back(*it);
        visited.push_back(0);
    }
    for(ll i=1; i<=v.size(); i++)
    {
        dfs(1,0,0,i);
    }
    cout<<ans;
}
void dfs(ll x,ll index,ll cur_depth,ll depth){
    if(cur_depth==depth)
    {
        ll sum=0;
        sum=sum+nn/x;
        if(depth&1)
        {
            ans=ans-sum;
        }
        else
        {
            ans=ans+sum;
        }
        return;
    }
    for(ll i=index; i<v.size(); i++)
    {
        if(visited[i]==0)
        {
            visited[i]=1;
            dfs(x*v[i],i,cur_depth+1,depth);
            visited[i]=0;
        }
    }
}