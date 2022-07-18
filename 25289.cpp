//25289번
#define MAX 100000

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[MAX];
int dp[199][101];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 199; j++)
        {
            if(0 <= a[i] - (j - 99) && a[i] - (j - 99) <= 100)
            {
                dp[j][a[i]] = dp[j][a[i] - (j - 99)] + 1;
            }
            else
            {
                dp[j][a[i]] = 1;
            }
        }
    }

    int ans = -1;
    
    for(int i = 0; i < 199; i++)
    {
        for(int j = 0; j < 101; j++)
        {
            ans = max(ans, dp[i][j]);
        }
    }
    cout<<ans;
}