#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map<int,int> m;
int sum[200001];
int ans=0;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int input,n,k;
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>input;
        sum[i]=sum[i-1]+input;
        if(sum[i]==k)
        {
            ans++;
        }
    }
    for(int i=1; i<=n; i++)
    {
        ans=ans+m[sum[i] - k];
        m[sum[i]]++;
    }
    cout<<ans;
}

