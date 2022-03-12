#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool all_melt();
void dfs(int cy,int cx);
bool inside(int ny,int nx);
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
int a[300][300];
int cnt[300][300];
bool visited[300][300];
int n,m;
int t=0;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }
    while(!all_melt())
    {
        int island=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(a[i][j]!=0)
                {
                    if(visited[i][j]==0)
                    {
                        dfs(i,j);
                        island++;
                        if(island>1)
                        {
                            cout<<t;
                            return 0;
                        }
                    }
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                for(int k=0; k<4; k++)
                {
                    int ny=i+dy[k];
                    int nx=j+dx[k];
                    if(inside(ny,nx)&&a[ny][nx]==0)
                    {
                        cnt[i][j]++;
                    }
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                a[i][j]=max(0,a[i][j]-cnt[i][j]);
                cnt[i][j]=0;
                visited[i][j]=0;
            }
        }
        t++;
    }
    cout<<0;
}
bool all_melt(){
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(a[i][j]!=0)
            {
                return false;
            }
        }
    }
    return true;
}
void dfs(int cy,int cx){
    visited[cy][cx]=1;
    for(int i=0; i<4; i++)
    {
        int ny=cy+dy[i];
        int nx=cx+dx[i];
        if(a[ny][nx]!=0&&visited[ny][nx]==0)
        {
            dfs(ny,nx);
        }
    }
}
bool inside(int ny,int nx){
    if(0<=ny&&ny<n&&0<=nx&&nx<m)
    {
        return true;
    }
    else
    {
        return false;
    }
}