///dp풀이///
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[1005][1005];
int n,m;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            char c; cin>>c;
            if(c=='1')
            {
                a[i][j]=min({a[i][j-1],a[i-1][j-1],a[i-1][j]})+1;
            }
            ans=max(ans,a[i][j]);
        }
    }
    cout<<ans*ans;
}
/////누적합 풀이//////

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
bool inside(int ny,int nx);
int a[1005][1005];
int sum[1005][1005];
int n,m;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            char c; cin>>c;
            if(c=='1')
            {
                a[i][j]=1;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
        }
    }
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            for(int k=0; ; k++)
            {
                if(inside(i+k,j+k))
                {
                    if(sum[i+k][j+k]-sum[i-1][j+k]-sum[i+k][j-1]+sum[i-1][j-1]==(k+1)*(k+1))
                    {
                        ans=max(ans,k+1);
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }

            }
        }
    }
    cout<<ans*ans;
    
}
bool inside(int ny,int nx)
{
    if(1<=ny&&ny<=n&&1<=nx&&nx<=m)
    {
        return true;
    }
    else
    {
        return false;
    }
}