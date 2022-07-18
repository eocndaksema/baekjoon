//25306번
#include <iostream>
typedef long long int ll;
using namespace std;
ll XOR1ton(ll n)
{
    if(n % 4 == 0)
    {
        return n;
    }
    else if(n % 4 == 1)
    {
        return 1;
    }
    else if(n % 4 == 2)
    {
        return n + 1;
    }
    else if(n % 4 == 3)
    {
        return 0;
    }
}
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    ll a, b; cin>>a>>b;
    ll ans = XOR1ton(a-1) ^ XOR1ton(b);
    cout<<ans<<"\n";
}