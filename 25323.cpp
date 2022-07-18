//25323번
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

typedef long long int ll;
using namespace std;

ll a[500000];
ll b[500000];

ll gcd(ll a, ll b) {
    if (b == 0)
    	return a;
    else
    	return gcd(b, a % b);
}

bool isSquare(ll num)
{
    double x = sqrt(num);
    return (ll)x * (ll)x == num;
}

bool check(ll n)
{
    for(ll i = 0; i < n; i++)
    {
        if(a[i] == b[i])
        {
            continue;
        }
        else
        {
            ll g = gcd(a[i], b[i]);
            ll aa = a[i] / g;
            ll bb = b[i] / g;

            if(isSquare(aa) && isSquare(bb))
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll n; cin>>n;

    for(ll i = 0; i < n; i++)
    {
        cin>>a[i];

        b[i] = a[i];
    }

    sort(a, a + n);

    if(check(n))
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
}