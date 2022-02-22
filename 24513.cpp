#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
void bfs();
bool inside(int ny,int nx);
queue < tuple<int,int,int> > q;
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
int a[1000][1000];
int level[1000][1000];
int ans[3];
int n,m;
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
            if(a[i][j]==1||a[i][j]==2)
            {
                q.push({i,j,-1});
                level[i][j]=-1;
            }
        }
    }
    bfs();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(a[i][j]==1)
            {
                ans[0]++;
            }
            else if(a[i][j]==2)
            {
                ans[1]++;
            }
            else if(a[i][j]==3)
            {
                ans[2]++;
            }
        }
    }
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2];
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
void bfs(){
    while(!q.empty())
    {
        int cy=get<0>(q.front());
        int cx=get<1>(q.front());
        int cl=get<2>(q.front());
        q.pop();
        if(a[cy][cx]==3)
        {
            continue;
        }
        for(int i=0; i<4; i++)
        {
            int ny=cy+dy[i];
            int nx=cx+dx[i];
            int nl=cl-1;
            if(inside(ny,nx))
            {
                if(level[ny][nx]==nl)
                {
                    if(a[ny][nx]!=0&&a[ny][nx]!=a[cy][cx])
                    {
                        a[ny][nx]=3;
                    }
                }
                else if(level[ny][nx]==0)
                {
                    if(a[ny][nx]==0)
                    {
                        q.push({ny,nx,nl});
                        level[ny][nx]=nl;
                        a[ny][nx]=a[cy][cx];
                    }
                }
            }
        }
    }
}