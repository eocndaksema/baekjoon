//1821번
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
typedef long long int ll;
using namespace std;
void dfs(ll sum,string str,ll cur_depth,ll depth);
string a[10000];
ll dp[10][10];
bool visited[10];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(ll i=0; i<10; i++)
    {
        for(ll j=0; j<=i; j++)
        {
            if(j==0)
            {
                dp[i][j]=1;
            }
            else
            {
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
            }
        }
    }

    int n,f; cin>>n>>f;
    dfs(0,"",0,n);
    cout<<a[f]<<"\n";
}
void dfs(ll sum,string str,ll cur_depth,ll depth){
    if(cur_depth==depth)
    {
        if(a[sum]=="")
        {
            a[sum]=str;
        }
        return;
    }
    for(ll i=0; i<depth; i++)
    {
        if(visited[i]==0)
        {
            visited[i]=1;
            dfs(sum+dp[depth-1][cur_depth]*(i+1),str+to_string(i+1)+" ",cur_depth+1,depth);
            visited[i]=0;
        }
    }
}