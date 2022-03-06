#define MAX 1000002
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>
typedef long long int ll;
using namespace std;
void setting();
ll a[MAX];
ll n,m;
int main(){
	cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(ll i=0; i<m-n+1; i++)
    {
        a[i]=i+n;
    }
    setting();
    ll ans=0;
    for(ll i=0; i<m-n+1; i++)
    {
        if(a[i]!=0)
        {
            ans++;
        }
    }
    cout<<ans;
}
void setting(){
    for(ll i=2; i*i<=m; i++)
    {
        ll x=(n/(i*i))*i*i;
        if(x==n)
        {
            for(ll j=0; ; j=j+i*i)
            {
                if(x-n+j>m-n)
                {
                    break;
                }
                a[x-n+j]=0;
            }
        }
        else
        {
            x=x+i*i;
            for(ll j=0; ; j=j+i*i)
            {
                if(x-n+j>m-n)
                {
                    break;
                }
                a[x-n+j]=0;
            }
        }
    }
}
