#include <iostream>
#include <algorithm>
#include <set>
typedef long long int ll;
using namespace std;
bool a[2000010];
bool ans[2000010];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n,input;
    cin>>n;
    for(ll i=0; i<n; i++)
    {
        cin>>input;
        a[input]=true;
    }
    for(ll i=0; i<2000010; i++)
    {
        if(a[i]==true)
        {
            for(ll j=i; j<2000010; j++)
            {
                if(a[j]==true)
                {
                    if(i*j>=2000010)
                    {
                        break;
                    }
                    ans[i*j]=true;
                }
            }
        }
    }
    for(ll i=0; i<2000010; i++)
    {
        if(ans[i]==false)
        {
            cout<<i;
            return 0;
        }
    }
}