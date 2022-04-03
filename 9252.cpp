#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;
void LCS(string x,string y);
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string x,y; cin>>x>>y;
    LCS(x,y);
}
void LCS(string x,string y){
    int dp[1005][1005]={0,};
    int dp2[1005][1005]={0,};
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
                dp2[i][j]=1;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                {
                    dp[i][j]=dp[i-1][j];
                    dp2[i][j]=2;
                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                    dp2[i][j]=3;
                }
            }
        }
    }
    int ans=dp[n-1][m-1];
    cout<<ans<<"\n";

    stack <char> st;
    int row=n-1;
    int col=m-1;
    while(ans>0)
    {
        if(dp2[row][col]==1)
        {
            st.push(x[row]);
            row--;
            col--;
            ans--;
        }
        else if(dp2[row][col]==2)
        {
            row--;
        }
        else if(dp2[row][col]==3)
        {
            col--;
        }
    }
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
}