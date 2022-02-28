#include <iostream>
#include <cmath>
using namespace std;
int a[100000];
int ans=999999999;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int start=0;
    int end=n-1;
    while(start<end)
    {
        if(abs(a[start]+a[end])<abs(ans))
        {
            ans=a[start]+a[end];
        }
        if(abs(a[start])<abs(a[end]))
        {
            end=end-1;
        }
        else
        {
            start=start+1;
        }
    }
    cout<<ans;
}