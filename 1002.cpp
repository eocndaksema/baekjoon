#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t,x1,y1,r1,x2,y2,r2;
    cin>>t;
    while(t--)
    {
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        if(x1==x2&&y1==y2&&r1==r2)
        {
            cout<<-1<<"\n";
        }
        else
        {
            if((r1-r2)*(r1-r2)<(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)&&(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<(r1+r2)*(r1+r2))
            {
                cout<<2<<"\n";
            }
            else if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)==(r1+r2)*(r1+r2)||(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)==(r1-r2)*(r1-r2))
            {
                cout<<1<<"\n";
            }
            else
            {
                cout<<0<<"\n";
            }
        }
    }
}