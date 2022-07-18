// 1562번
#define MOD 1000000000
#include <iostream>
#include <vector>
#include <algorithm>
typedef long long int ll;
using namespace std;
ll a[101][10][1024];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    a[1][1][2] = 1;
	a[1][2][4] = 1;
	a[1][3][8] = 1;
	a[1][4][16] = 1;
	a[1][5][32] = 1;
	a[1][6][64] = 1;
	a[1][7][128] = 1;
	a[1][8][256] = 1;
	a[1][9][512] = 1;

    for(ll i = 2; i <= 100; i++)
    {
        for(ll j = 0; j <= 9; j++)
        {
            for(ll k = 0; k < 1024; k++)
            {
                ll x = k | (1<<j);

                if(j == 0)
                {
                    a[i][j][x] = (a[i][j][x] + a[i - 1][j + 1][k]) % MOD;
                }
                else if(j == 9)
                {
                    a[i][j][x] = (a[i][j][x] + a[i - 1][j - 1][k]) % MOD;
                }
                else
                {
                    a[i][j][x] = (a[i][j][x] + a[i - 1][j - 1][k] + a[i - 1][j + 1][k]) % MOD;
                }
            }
        }
    }

    ll n;
    cin>>n;

    ll ans = 0;

    for(ll i = 0 ; i < 10; i++)
    {
        ans = (ans + a[n][i][1023]) % MOD;
    }

    cout<<ans;
}
