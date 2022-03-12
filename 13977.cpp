#define MAX 1000000007
#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll;
using namespace std;
ll ftr[4000001];
string s="111011100110101100101000000101";
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ftr[0]=1;
    for(int i=1; i<4000001; i++)
    {
        ftr[i]=((i%MAX)*(ftr[i-1]%MAX))%MAX;
    }
    ll m; cin>>m;
    while(m--)
    {
        ll n,k; cin>>n>>k;
        ll A=ftr[n];
        ll base=((ftr[n-k]%MAX)*(ftr[k]%MAX))%MAX;
        ll B=base;
        for(ll i=1; i<s.size(); i++)
        {
            B=((B%MAX)*(B%MAX))%MAX;
            if(s[i]=='1')
            {
                B=((B%MAX)*(base%MAX)%MAX);
            }
        }
        cout<<((A%MAX)*(B%MAX))%MAX<<"\n";
    }
}