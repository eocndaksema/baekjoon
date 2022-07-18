// 5525번
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int dp[1000005];

int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m; cin>>n>>m;
    string s; cin>>s;

    for(int i = 0; i < m; i++)
    {
        if(i == 0)
        {
            if(s[i] == 'O')
            {
                dp[i] = 0;
            }
            else if(s[i] == 'I')
            {
                dp[i] = 1;
            }
        }
        else
        {
            if(s[i] == 'O')
            {
                if(s[i - 1] == 'O')
                {
                    dp[i] = 0;
                }
                else if(s[i - 1] == 'I')
                {
                    dp[i] = dp[i - 1] + 1;
                }
            }
            else if(s[i] == 'I')
            {
                if(s[i - 1] == 'O')
                {
                    dp[i] = dp[i - 1] + 1;
                }
                else if(s[i - 1] == 'I')
                {
                    dp[i] = 1;
                }
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < m; i++)
    {
        if(2 * n + 1 <= dp[i] && s[i] == 'I')
        {
            ans++;
        }
    }

    cout<<ans;
}