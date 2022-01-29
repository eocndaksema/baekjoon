#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int sum[100001];
int ans=999999;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    long long int input,n,s;
    cin>>n>>s;
    for(int i=1; i<=n; i++)
    {
        cin>>input;
        sum[i]=sum[i-1]+input;
    }
    int start=1;
    int end=1;
    while(1)
    {
        if(start>end||start>n||end>n)
        {
            break;
        }
        if(sum[end]-sum[start-1]>=s)
        {
            ans=min(ans,end-start+1);
            start++;
        }
        else if(sum[end]-sum[start-1]<s)
        {
            end++;
        }
    }
    if(ans==999999)
    {
        cout<<0;
    }
    else
    {
        cout<<ans;
    }
}

