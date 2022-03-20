#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    cout<<fixed;
    cout.precision(9);
    double ans=9999;
    double X,Y,D,T; cin>>X>>Y>>D>>T;
    double d=sqrt(X*X+Y*Y);
    ans=min(ans,d);
    for(int i=1; ; i++)
    {
        if(i==1)
        {
            d=abs(D-d);
            ans=min(ans,d+T*i);
        }
        else
        {
            d=d-D;
            if(d<=0)
            {
                ans=min(ans,T*i);
                break;
            }
            ans=min(ans,abs(d)+T*i);
        }
    }
    cout<<ans;
}