#include <iostream>
#include <algorithm>
using namespace std;
int a[200002];
int sum[200002];
int ans=0;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=n; i++)
    {
        a[i+n]=a[i];
    }
    sum[1]=a[1];
    for(int i=2; i<=2*n; i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=k; i<=2*n; i++)
    {
        ans=max(ans,sum[i]-sum[i-k]);
    }
    cout<<ans;
}