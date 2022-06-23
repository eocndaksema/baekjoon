//14279번
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
typedef long long int ll;
using namespace std;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll a, b, c;
    ll ans = 9223372036854775807;

    cin>>a>>b>>c;

    for(ll A = 1; A <= 1000000; A++)
    {
        for(ll B = 1; B <= 1 + 1000000/A; B++)
        {
            ans = min(ans, abs(A - a) + abs(B - b) + abs(A * B - c));
        }
    }
    cout<<ans<<"\n";
}