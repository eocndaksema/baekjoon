#define MAX 1000001
#include <iostream>
#include <algorithm>
#include <vector>
typedef long long int ll;
using namespace std;
ll f[MAX];
ll g[MAX];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(ll i=1; i<MAX; i++)
    {
        for(ll j=i; j<MAX; j=j+i)
        {
            f[j]=f[j]+i;
        }
    }
    for(ll i=1; i<MAX; i++)
    {
        g[i]=g[i-1]+f[i];
    }
    ll t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        cout<<g[n]<<"\n";
    }
}