#include <iostream>
#include <vector>
#include <string>
typedef long long int ll;
using namespace std;
void solve(ll n,ll m,ll k);
ll dp[27][27];
int main(){
	cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    n=n/2; k++;
    for(int i=0; i<27; i++)
    {
        dp[i][1]=1;
    }
    for(ll i=1; i<27; i++)
    {
        for(ll j=2; j<=i+1; j++)
        {
            dp[i][j]=dp[i][j-1]+dp[i-1][j];
        }
    }
    solve(n,n,k);
}
void solve(ll n,ll m,ll k){
    if(dp[n][m]<k)
    {
        cout<<"-1";
        return;
    }
    while(n>0)
    {
        if(dp[n][m]>=k)
        {
            cout<<"(";
            m--;
        }
        else
        {
            cout<<")";
            k=k-dp[n][m];
            n--;
        }
    }
}