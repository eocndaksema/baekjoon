#define MOD 1000000000
#include <iostream>
#include <algorithm>
#include <vector>
typedef long long int ll;
using namespace std;
ll dp[1000001];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    dp[2]=1;
    dp[3]=2;
    for(ll i=4; i<1000001; i++)
    {
        dp[i]=((i-1)*(dp[i-1]+dp[i-2])%MOD)%MOD;
    }
    ll n; cin>>n;
    cout<<dp[n];
}