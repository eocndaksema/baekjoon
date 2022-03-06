#include <iostream>
#include <vector>
#include <set>
#include <string>
typedef long long int ll;
using namespace std;
void case1(ll n);
void case2(ll n);
ll check(ll n);
set <ll> s;
vector <ll> v;
ll ftr[21];
ll a[21];
int main(){
	cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ftr[0]=1;
    for(ll i=1; i<21; i++)
    {
        ftr[i]=i*ftr[i-1];
    }
    ll n,input;
    cin>>n>>input;
    for(ll i=1; i<=n; i++)
    {
        s.insert(i);
    }
    if(input==1)
    {
        case1(n);
    }
    else if(input==2)
    {
        case2(n);
    }
}
void case1(ll n){
    ll k;
    cin>>k;
    k--;
    ll index=check(k);
    for(ll i=0; i<n-1-index; i++)
    {
        v.push_back(*s.begin());
        s.erase(s.begin());
    }
    while(k>0)
    {
        index=check(k);

        n=n-index;
        auto iter=s.begin();
        for(ll i=0; i<k/ftr[index]; i++)
        {
            iter++;
        }
        v.push_back(*iter);
        s.erase(iter);
        k=k-ftr[index]*(k/ftr[index]);
        ll after=check(k);
        for(ll i=index; i>1+after; i--)
        {
            v.push_back(*s.begin());
            s.erase(s.begin());
        }
    }
    for(auto iter=s.begin(); iter!=s.end(); iter++)
    {
        v.push_back(*iter);
    }
    for(ll i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
}
void case2(ll n){
    for(ll i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    ll ans=0;
    for(ll i=1; i<=n; i++)
    {
        auto iter2=s.find(a[i]);
        ll cnt=0;
        for(auto iter=s.begin(); iter!=s.end(); iter++)
        {
            if(*iter==*iter2)
            {
                s.erase(iter);
                break;
            }
            else
            {
                cnt++;
            }
        }
        ans=ans+cnt*ftr[s.size()];
    }
    ans++;
    cout<<ans;
}
ll check(ll n){
    for(ll i=1; i<21; i++)
    {
        if(ftr[i]<=n&&n<ftr[i+1])
        {
            return i;
        }
    }
}