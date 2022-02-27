#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
void dfs(int start);
char a[2505];
bool dp[2505][2505];
int ans[2505];
int n;
int cnt=0;
int mn=9999;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string str;
    cin>>str;
    n=str.size();
    for(int i=1; i<=n; i++)
    {
        a[i]=str[i-1];
    }
    for(int i=1; i<=2500; i++)
    {
        dp[i][i]=1;
        if(a[i]==a[i+1])
        {
            dp[i][i+1]=1;
        }
    }
    for(int j=2498; j>=1; j--)
    {
        for(int i=1; i<=j; i++)
        {
            if((dp[i+1][i+2500-j-1]==1)&&(a[i]==a[i+2500-j]))
            {
                dp[i][i+2500-j]=1;
            }
        }
    }
    for(int i=n; i>=1; i--)
    {
        dfs(i);
        ans[i]=mn;
        cnt=0;
        mn=9999;
    }
    cout<<ans[1];
}
void dfs(int start){
    if(start>n)
    {
        mn=min(cnt,mn);
        return;
    }
    if(ans[start])
    {
        mn=min(mn,cnt+ans[start]);
        return;
    }
    else
    {
        for(int i=start; i<=n; i++)
        {
            if(dp[start][i]==1)
            {
                cnt++;
                dfs(i+1);
                cnt--;
            }
        }
    }
}
