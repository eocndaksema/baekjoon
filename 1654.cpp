#include <iostream>
#include <algorithm>
#include <vector>
typedef long long int ll;
using namespace std;
ll f(ll x);
ll lan[10001];
ll k,n;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>k>>n;
    for(ll i=0; i<k; i++)
    {
        cin>>lan[i];
    }
    sort(lan,lan+k);
    
    ll j=k-1;
    while(j>-1)
    {
        ll i=lan[j];
        if(n<=f(i))
        {
            if(i==lan[k-1])
            {
                cout<<lan[k-1]<<"\n";
                return 0;
            }
            ll s=lan[j];
            ll e=lan[j+1];
            ll mid;
            while(e!=s+1)
            {
                mid=(s+e)/2;
                if(n<=f(mid))
                {
                    s=mid;
                }
                else
                {
                    e=mid;
                }
            }
            if(f(e)==n)
            {
                cout<<e<<"\n";
            }
            else
            {
                if(f(mid)==n)
                {
                    cout<<mid<<"\n";
                }
                else
                {
                    cout<<s<<"\n";
                }
            }
            return 0;
        }
        else
        {
            j--;
        }
    }
    ll s=0;
    ll e=lan[0];
    ll mid;
    while(e!=s+1)
    {
        mid=(s+e)/2;
        if(n<=f(mid))
        {
            s=mid;
        }
        else
        {
            e=mid;
        }
    }
    if(f(e)==n)
    {
        cout<<e<<"\n";
    }
    else
    {
        if(f(mid)==n)
        {
            cout<<mid<<"\n";
        }
        else
        {
            cout<<s<<"\n";
        }
    }
    return 0;
}

ll f(ll x){
    ll ans=0;
    for(ll i=0; i<k; i++)
    {
        ans=ans+lan[i]/x;
    }
    return ans;
}