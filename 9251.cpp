#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int LCS(string x,string y);
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string x,y; cin>>x>>y;
    cout<<LCS(x,y);
}
int LCS(string x,string y){
    int dp[1005][1005]={0,};
    x=" "+x;
    y=" "+y;
    int n=x.size();
    int m=y.size();
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            if(x[i]==y[j])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n-1][m-1];
}