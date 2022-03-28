#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int solution();
int m[100];
int c[100];
int N,M;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        cin>>m[i];
    }
    for(int i=0; i<N; i++)
    {
        cin>>c[i];
    }
    cout<<solution();
}
int solution(){
    int csum=0;
    int dp[10005];
    memset(dp,0,sizeof(dp));
    for(int i=0; i<N; i++)
    {
        csum=csum+c[i];
    }
    for(int i=0; i<N; i++)
    {
        int cost=c[i];
        int mem=m[i];
        for(int j=csum; j>=cost; j--)
        {
            dp[j]=max(dp[j],mem+dp[j-cost]);
        }
    }
    for(int i=0; i<=csum; i++)
    {
        if(M<=dp[i])
        {
            return i;
        }
    }
    return -1;
}