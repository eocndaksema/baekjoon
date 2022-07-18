//  21757번
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

typedef long long int ll;

using namespace std;

ll a[100001];

map <ll ,ll> m;

int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll n; cin>>n;
    ll ans = 0;
    for(ll i = 1; i <= n; i++)
    {
        cin>>a[i];

        a[i] = a[i] + a[i - 1];
    }

    if(a[n] == 0)
    {
        ll cnt = 0;
        for(ll i = 1; i <= n; i++)
        {
            if(a[i] == 0)
            {
                cnt++;
            }
        }
        ans = (cnt - 1) * (cnt - 2) * (cnt - 3) / 6;
    }
    else
    {
        if(abs(a[n]) % 4 == 0)
        {
            ll g = a[n] / 4;
            m[0] = 1;
            
            for(ll i = 1; i < n; i++)
            {
                m[a[i]] = m[a[i]] + m[a[i] - g];
            }

            ans = m[a[n] - g];
        }
    }

    cout<<ans;
}