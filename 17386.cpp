#include <iostream>
#include <algorithm>
typedef long long int ll;
using namespace std;
ll ccw(ll x1,ll x2,ll x3,ll y1,ll y2,ll y3);
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll x[4];
    ll y[4];
    for(ll i=0; i<4; i++)
    {
        cin>>x[i]>>y[i];
    }
    ll a=ccw(x[0],x[1],x[2],y[0],y[1],y[2]);
    ll b=ccw(x[0],x[1],x[3],y[0],y[1],y[3]);
    ll c=ccw(x[2],x[3],x[0],y[2],y[3],y[0]);
    ll d=ccw(x[2],x[3],x[1],y[2],y[3],y[1]);
    if((a==1&&b==-1)||(a==-1&&b==1))
    {
        if((c==1&&d==-1||(c==-1&&d==1)))
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    else
    {
        cout<<0;
    }

}
ll ccw(ll x1,ll x2,ll x3,ll y1,ll y2,ll y3){
    if(x1==x2)
    {
        if(x3>x1)
        {
            return -1;
        }
        else if(x3<x1)
        {
            return 1;
        }
    }
    else if(x1==x3)
    {
        if(y3<y1)
        {
            return -1;
        }
        else if(y3>y1)
        {
            return 1;
        }
    }
    else
    {
        ll a=(x1-x3)*(y1-y2);
        ll b=(x1-x2)*(y1-y3);
        if(a<b)
        {
            return 1;
        }
        else if(a>b)
        {
            return -1;
        }
    }
    return 0;
}