#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dp[1001];
int p[1001];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>p[i];
    }
    for(int i=1; i<=n; i++)
    {
        int mx=0;
        for(int j=1; j<=i; j++)
        {
            mx=max(mx,dp[i-j]+p[j]);
        }
        dp[i]=mx;
    }
    cout<<dp[n];
}