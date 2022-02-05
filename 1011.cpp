#include <iostream>
using namespace std;
typedef long long int ll;
ll solve(ll n);
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int x,y,t;
    cin>>t;
    while(t>0)
    {
        cin>>x>>y;
        cout<<solve(y-x)<<"\n";
        t--;
    }
}
ll solve(ll n){
    for(ll i=1; i<=47000; i++)
    {
        ll a=i*(i-1);
        ll b=i*i;
        ll c=(i+1)*i;
        if(a<n&&n<=b)
        {
            return i*2-1;
        }
        else if(b<n&&n<=c)
        {
            return i*2;
        }
    }
}