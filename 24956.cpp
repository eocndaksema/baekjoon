//24956번
#define MOD 1000000007
#include <iostream>
#include <algorithm>
#include <vector>
typedef long long int ll;
using namespace std;
void setting(ll n, char m);
void solve();
vector <ll> v;
char c[200005];
ll dp[2][200005];
ll two[200005];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n; cin>>n;
    two[0] = 1;
    for(ll i = 1; i <= n; i++)
    {
        cin>>c[i];
        
        if(c[i] == 'W')
        {
        	dp[0][i] = dp[0][i-1] + 1;
        }
        else
        {
        	dp[0][i] = dp[0][i-1];
        }
        
        two[i] = (two[i-1]*2) % MOD;
    }
    
    setting(n, 'H');
    setting(n, 'E');
    setting(n, 'E');

    for(ll i = 1; i <= n; i++)
    {
        if(c[i] == 'E')
        {
            v.push_back(dp[0][i]);
        }
    }
    solve();
}
void setting(ll n, char m){
    for(ll i = 1; i <= n; i++)
    {
        if(c[i] == m)
        {
            dp[1][i] = (dp[1][i-1]+dp[0][i-1]) % MOD;
        }
        else
        {
            dp[1][i] = dp[1][i-1];
        }
    }
    for(ll i = 1; i <= n; i++)
    {
        dp[0][i] = dp[1][i];
    }
}
void solve(){
    ll ans;
    if(v.size() == 0)
    {
        ans = 0;
    }
    else
    {
        ans = v[v.size()-1];
        ll j = 0;
        for(ll i = v.size()-2; i >= 0; i--)
        {
            ans = (ans + (two[j] * v[i]) % MOD) % MOD;
            j++;
        }
    }
    cout<<ans;
}