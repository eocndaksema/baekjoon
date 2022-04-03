#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void dfs(int index,int sum,int mx,int mn,int cur_depth,int depth);
int a[15];
bool visited[15];
int n,l,r,x;
int ans=0;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>l>>r>>x;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i=2; i<=n; i++)
    {
        dfs(0,0,0,9999999,0,i);
    }
    cout<<ans;
}
void dfs(int index,int sum,int mx,int mn,int cur_depth,int depth){
    if(cur_depth==depth)
    {
        if(mx-mn>=x&&l<=sum&&sum<=r)
        {
            ans++;
        }
        return;
    }
    for(int i=index; i<n; i++)
    {
        if(visited[i]==0)
        {
            visited[i]=1;
            dfs(i,sum+a[i],max(mx,a[i]),min(mn,a[i]),cur_depth+1,depth);
            visited[i]=0;
        }
    }
}