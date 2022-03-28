#define MOD 10007
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
    ll n; cin>>n;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for(ll i=4; i<1000001; i++)
    {
        if(i%3==0)
        {
            dp[i]=(3*dp[i-3])%MOD;
        }
        else
        {
            dp[i]=(2*dp[i-2])%MOD;
        }
    }
    cout<<dp[n]<<"\n";
}