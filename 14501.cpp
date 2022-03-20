#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int T[15];
int P[15];
int dp[15];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    int ans=0;
    for(int i=0; i<n; i++)
    {
        cin>>T[i]>>P[i];
    }
    for(int i=n-1; i>=0; i--)
    {
        for(int j=i+T[i]; j<=n; j++)
        {
            dp[i]=max(dp[i],P[i]+dp[j]);
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}