#include <iostream>
#include <algorithm>
#include <queue>
typedef long long int ll;
using namespace std;
priority_queue < ll, vector<ll>, greater<ll> > pq;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n,input,sum; cin>>n;
    for(ll i=0; i<n; i++)
    {
        cin>>input;
        pq.push(input);
    }
    ll ans=0;
    while(pq.size()>1)
    {
        sum=0;
        ll x=pq.top();
        pq.pop();
        ll y=pq.top();
        pq.pop();
        sum=sum+x+y;
        ans=ans+sum;
        pq.push(sum);
    }
    cout<<ans;
}