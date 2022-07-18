// 25188번
#include <iostream>
#include <algorithm>
#include <vector>

typedef long long int ll;
using namespace std;

ll a[2001];
ll dp[7][2001];

int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll n; cin>>n;

    for(ll i = 1; i <= n; i++)
    {
        cin>>a[i];
    }

    for(ll i = 1; i <= 6; i++)
    {
        for(ll j = 1; j <= n; j++)
        {
            if(i == 1)
            {
                dp[i][j] = dp[i][j - 1] + a[j];
            }
            else if(i == 3 || i == 5)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1] + a[j]);
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout<<dp[6][n];
}