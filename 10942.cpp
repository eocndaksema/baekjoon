#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[2005];
int dp[2005][2005];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,s,e;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=2000; i++)
    {
        dp[i][i]=1;
        if(a[i]==a[i+1])
        {
            dp[i][i+1]=1;
        }
    }
    for(int j=1998; j>=1; j--)
    {
        for(int i=1; i<=j; i++)
        {
            if((dp[i+1][i+2000-j-1]==1)&&(a[i]==a[i+2000-j]))
            {
                dp[i][i+2000-j]=1;
            }
        }
    }
    cin>>m;
    while(m--)
    {
        cin>>s>>e;
        cout<<dp[s][e]<<"\n";
    }
}
