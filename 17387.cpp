#include <iostream>
#include <algorithm>
#include <cmath>
typedef long long int ll;
using namespace std;
ll ccw(ll x1,ll x2,ll x3,ll y1,ll y2,ll y3);
ll gcd(ll n,ll m);
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
    if(x[0]==x[1]&&x[0]==x[2]&&x[0]==x[3])
    {
        if((min(y[0],y[1])<=y[2]&&y[2]<=max(y[0],y[1]))||(min(y[0],y[1])<=y[3]&&y[3]<=max(y[0],y[1])))
        {
            cout<<1;
            return 0;
        }
        else
        {
            cout<<0;
            return 0;
        }
    }
    ll a=ccw(x[0],x[1],x[2],y[0],y[1],y[2]);
    ll b=ccw(x[0],x[1],x[3],y[0],y[1],y[3]);
    ll c=ccw(x[2],x[3],x[0],y[2],y[3],y[0]);
    ll d=ccw(x[2],x[3],x[1],y[2],y[3],y[1]);
    if(a==0&&b==0&&c==0&&d==0)
    {
        ll delta_x;
        ll delta_y;
        if(min(x[0],x[1])<min(x[2],x[3]))
        {
            if(x[0]>x[1])
            {
                delta_x=x[0]-x[1];
                delta_y=y[0]-y[1];
                ll g=gcd(abs(delta_x),abs(delta_y));
                delta_x=delta_x/g;
                delta_y=delta_y/g;
                ll cx=x[1];
                ll cy=y[1];
                while(1)
                {
                    if((cx==x[2]&&cy==y[2])||(cx==x[3]&&cy==y[3]))
                    {
                        cout<<1;
                        return 0;
                    }
                    if(cx==x[0]&&cy==y[0])
                    {
                        cout<<0;
                        return 0;
                    }
                    cx=cx+delta_x;
                    cy=cy+delta_y;
                }
            }
            else if(x[1]>x[0])
            {
                delta_x=x[1]-x[0];
                delta_y=y[1]-y[0];
                ll g=gcd(abs(delta_x),abs(delta_y));
                delta_x=delta_x/g;
                delta_y=delta_y/g;
                ll cx=x[0];
                ll cy=y[0];
                while(1)
                {
                    if((cx==x[2]&&cy==y[2])||(cx==x[3]&&cy==y[3]))
                    {
                        cout<<1;
                        return 0;
                    }
                    if(cx==x[1]&&cy==y[1])
                    {
                        cout<<0;
                        return 0;
                    }
                    cx=cx+delta_x;
                    cy=cy+delta_y;
                }
            }
        }
        else
        {
            if(x[2]>x[3])
            {
                delta_x=x[2]-x[3];
                delta_y=y[2]-y[3];
                ll g=gcd(abs(delta_x),abs(delta_y));
                delta_x=delta_x/g;
                delta_y=delta_y/g;
                ll cx=x[3];
                ll cy=y[3];
                while(1)
                {
                    if((cx==x[0]&&cy==y[0])||(cx==x[1]&&cy==y[1]))
                    {
                        cout<<1;
                        return 0;
                    }
                    if(cx==x[2]&&cy==y[2])
                    {
                        cout<<0;
                        return 0;
                    }
                    cx=cx+delta_x;
                    cy=cy+delta_y;
                }
            }
            else if(x[3]>x[2])
            {
                delta_x=x[3]-x[2];
                delta_y=y[3]-y[2];
                ll g=gcd(abs(delta_x),abs(delta_y));
                delta_x=delta_x/g;
                delta_y=delta_y/g;
                ll cx=x[2];
                ll cy=y[2];
                while(1)
                {
                    if((cx==x[0]&&cy==y[0])||(cx==x[1]&&cy==y[1]))
                    {
                        cout<<1;
                        return 0;
                    }
                    if(cx==x[3]&&cy==y[3])
                    {
                        cout<<0;
                        return 0;
                    }
                    cx=cx+delta_x;
                    cy=cy+delta_y;
                }
            }
        }
    }
    else
    {
        if(a!=b)
        {
            if(c!=d)
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
        return 0;
    }
    return 0;
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
ll gcd(ll n,ll m){
    if(n>m)
    {
        ll tmp=m;
        m=n;
        n=tmp;
    }
    if(n==0)
    {
        return m;
    }
    else
    {
        return gcd(m%n,n);
    }
}