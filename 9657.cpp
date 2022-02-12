#include <iostream>
#include <algorithm>
using namespace std;
bool a[1001];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    a[1]=0;
    a[2]=1;
    a[3]=0;
    a[4]=0;
    a[5]=0;
    for(int i=6; i<1001; i++)
    {
        if(a[i-1]==a[i-3]&&a[i-1]==a[i-4])
        {
            if(a[i-1]==0)
            {
                a[i]=1;
            }
            else
            {
                a[i]=0;
            }
        }
        else
        {
            a[i]=0;
        }
    }
    int n;
    cin>>n;
    if(a[n]==0)
    {
        cout<<"SK";
    }
    else
    {
        cout<<"CY";
    }
}