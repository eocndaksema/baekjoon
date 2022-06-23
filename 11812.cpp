//11812번
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
typedef long long int ll;
using namespace std;
ll solution(ll k,ll node_x,ll node_y);
ll getlevel(ll k,ll node);
ll k_squared(ll k, ll n);
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n,k,q,node_x,node_y; cin>>n>>k>>q;
    for(ll i=0; i<q; i++)
    {
        cin>>node_x>>node_y;
        if(k==1)
        {
            cout<<abs(node_x-node_y)<<"\n";
        }
        else
        {
            cout<<solution(k,node_x,node_y)<<"\n";
        }
    }
}
ll solution(ll k,ll node_x,ll node_y){
    if(node_x==node_y)
    {
        return 0;
    }
    else
    {
        ll x=getlevel(k,node_x);
        ll y=getlevel(k,node_y);
        if(x>y)
        {
            return 1+solution(k,(node_x+k-2)/k,node_y);
        }
        else if(x<y)
        {
            return 1+solution(k,node_x,(node_y+k-2)/k);
        }
        else
        {
            return 2+solution(k,(node_x+k-2)/k,(node_y+k-2)/k);
        }
    }
}
ll getlevel(ll k,ll node){
    ll front=1;
    ll back=1;
    for(ll i=0; ; i++)
    {
        if(front<=node&&node<=back)
        {
            return i;
        }
        front=front+k_squared(k,i);
        back=back+k_squared(k,i+1);
    }
}
ll k_squared(ll k, ll n){
    if(n==0)
    {
        return 1;
    }
    else
    {
        return k*k_squared(k,n-1);
    }
}