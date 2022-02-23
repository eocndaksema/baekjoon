#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int p1_x,p1_y,p2_x,p2_y,p3_x,p3_y;
    cin>>p1_x>>p1_y>>p2_x>>p2_y>>p3_x>>p3_y;
    if(p1_x==p2_x)
    {
        if(p1_x==p3_x)
        {
            cout<<0;
        }
        else if(p1_x<p3_x)
        {
            cout<<-1;
        }
        else
        {
            cout<<1;
        }
    }
    else if(p1_x==p3_x)
    {
        if(p3_y==p1_y)
        {
            cout<<0;
        }
        else if(p3_y>p1_y)
        {
            cout<<1;
        }
        else
        {
            cout<<-1;
        }
    }
    else
    {
        int a=(p1_x-p3_x)*(p1_y-p2_y);
        int b=(p1_x-p2_x)*(p1_y-p3_y);
        if(a==b)
        {
            cout<<0;
        }
        else if(a>b)
        {
            cout<<-1;
        }
        else
        {
            cout<<1;
        }
    }
}