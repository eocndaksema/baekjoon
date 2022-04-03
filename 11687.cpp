#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int f(int n);
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    int s=n*4;
    int e=n*5;
    while(s<e)
    {
        if(f(s)==n)
        {
            cout<<s<<"\n";
            return 0;
        }
        if(f(e)==n)
        {
            cout<<e<<"\n";
            return 0;
        }

        int mid=(s+e)/2;
        if(f(mid)==n)
        {
            cout<<5*(mid/5)<<"\n";
            return 0;
        }
        if(f(s)<n&&n<f(mid))
        {
            if(e==mid)
            {
                break;
            }
            e=mid;
        }
        else if(f(mid)<n&&n<f(e))
        {
            if(s==mid)
            {
                break;
            }
            s=mid;
        }
    }
    cout<<"-1\n";
    return 0;
}
int f(int n){
    int five[14]={1,};
    for(int i=1; i<14; i++)
    {
        five[i]=five[i-1]*5;
    }
    int sum=0;
    for(int i=1; i<14; i++)
    {
        sum=sum+n/five[i];
    }
    return sum;
}