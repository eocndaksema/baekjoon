#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
typedef long long int ll;
using namespace std;
void dfs(ll depth,ll sum);
bool visited[10005];
ll p[10005];
ll m[10005];
ll a[10005];
ll n;
ll ans=0;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]>=0)
        {
            p[a[i]]++;
        }
        else
        {
            m[-a[i]]++;
        }
    }
    if(n<3)
    {
        cout<<"0\n";
    }
    else
    {
        dfs(0,0);
        cout<<ans/6<<"\n";
    }
}
void dfs(ll depth,ll sum){
    if(depth==2)
    {
        if(0<=abs(sum)&&abs(sum)<=10000)
        {
            if(sum>0)
            {
                ans=ans+m[sum];
            }
            else if(sum<0)
            {
                ans=ans+p[-sum];
            }
            else
            {
                ans=ans+p[0];
            }
        }
        return;
    }
    for(ll i=0; i<n; i++)
    {
        if(visited[i]==0)
        {
            if(a[i]>=0)
            {
                visited[i]=1;
                p[a[i]]--;
                dfs(depth+1,sum+a[i]);
                p[a[i]]++;
                visited[i]=0;
            }
            else
            {
                visited[i]=1;
                m[-a[i]]--;
                dfs(depth+1,sum+a[i]);
                m[-a[i]]++;
                visited[i]=0;
            }
        }
    }
}