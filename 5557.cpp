#include <iostream>
#include <algorithm>
#include <vector>
typedef long long int ll;
using namespace std;
void dfs(ll x,ll depth,ll index,ll sum);
ll a[100];
ll dp[105][21];
ll n;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
    }

    dfs(1,0,0,a[0]);
    for(ll i=1; i<n-2; i++)
    {
        for(ll j=0; j<21; j++)
        {
            if(dp[i][j])
            {
                dfs(dp[i][j],0,i,j);
            }
        }
    }
    cout<<dp[n-2][a[n-1]]<<"\n";
}
void dfs(ll x,ll depth,ll index,ll sum){
    if(sum<0||sum>20)
    {
        return;
    }
    if(depth==1)
    {
        dp[index][sum]=dp[index][sum]+x;
        return;
    }
    if(index>n-2)
    {
        return;
    }
    dfs(x,depth+1,index+1,sum+a[index+1]);
    dfs(x,depth+1,index+1,sum-a[index+1]);
}