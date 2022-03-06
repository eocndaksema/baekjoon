#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
void dfs(int cx,int cy,int depth,long double csum);
bool visited[30][30];
long double percentage[4];
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
int n;
long double ans=0;
int main(){
	cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout<<fixed;
    cout.precision(9);
    cin>>n;
    for(int i=0; i<4; i++)
    {
        cin>>percentage[i];
        percentage[i]=percentage[i]/100;
    }
    visited[14][14]=1;
    dfs(14,14,0,1);
    cout<<ans;
}
void dfs(int cx,int cy,int depth,long double csum){
    if(depth==n)
    {
        ans=ans+csum;
        return;
    }
    for(int i=0; i<4; i++)
    {
        int nx=cx+dx[i];
        int ny=cy+dy[i];
        long double nsum=csum*percentage[i];
        if(visited[nx][ny]==0)
        {
            visited[nx][ny]=1;
            dfs(nx,ny,depth+1,nsum);
            visited[nx][ny]=0;
        }
    }
}