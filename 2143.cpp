// 2143번
#include <iostream>
#include <vector>
#include <algorithm>
typedef long long int ll;
using namespace std;
ll prefixSumA[1001];
ll prefixSumB[1001];
vector <ll> sumAVector;

int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll t, n, m;

    ll ans = 0;

    cin>>t;
    cin>>n;
    for(ll i = 1; i <= n; i++)
    {
        cin>>prefixSumA[i];

        prefixSumA[i] = prefixSumA[i] + prefixSumA[i - 1];
    }

    cin>>m;
    for(ll i = 1; i <= m; i++)
    {
        cin>>prefixSumB[i];

        prefixSumB[i] = prefixSumB[i] + prefixSumB[i - 1];
    }

    for(ll i = 1; i <= n; i++)
    {
        for(ll j = i; j <= n; j++)
        {
            sumAVector.push_back(prefixSumA[j] - prefixSumA[i - 1]);
        }
    }

    sort(sumAVector.begin(), sumAVector.end());

    for(ll i = 1; i <= m; i++)
    {
        for(ll j = i; j <= m; j++)
        {
            ans = ans + upper_bound(sumAVector.begin(), sumAVector.end(), t - (prefixSumB[j] - prefixSumB[i - 1])) - lower_bound(sumAVector.begin(), sumAVector.end(), t - (prefixSumB[j] - prefixSumB[i - 1]));
        }
    }
    cout<<ans;
}