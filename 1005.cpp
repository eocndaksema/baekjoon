#include <iostream>
#include <algorithm>
#include <vector>
typedef long long int ll;
using namespace std;
void reset();
ll dfs(ll n);
ll ans[1001];
ll delay[1001];
vector <ll> v[1001];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll t,n,k,x,y,w;
    cin>>t;
    while(t--)
    {
        reset();
        cin>>n>>k;
        for(ll i=1; i<=n; i++)
        {
            cin>>delay[i];
        }
        for(ll i=1; i<=k; i++)
        {
            cin>>x>>y;
            v[y].push_back(x);
        }
        cin>>w;
        cout<<dfs(w)<<"\n";
    }
}
void reset(){
    for(ll i=0; i<1001; i++)
    {
        ans[i]=-1;
        delay[i]=0;
        v[i].clear();
    }
}
ll dfs(ll n){
    if(v[n].size()==0)
    {
        ans[n]=delay[n];
        return ans[n];
    }
    if(ans[n]!=-1)
    {
        return ans[n];
    }
    else
    {
        for(ll i=0; i<v[n].size(); i++)
        {
            ans[n]=max(ans[n],delay[n]+dfs(v[n][i]));
        }
        return ans[n];
    }
}