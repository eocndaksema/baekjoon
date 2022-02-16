#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool inside(int ny,int nx);
void bfs();
void dfs(int size,int index);
vector < pair<int,int> > virus;
queue < pair<int,int> > q;
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
int a[8][8];
int b[8][8];
bool visited[8][8];
bool visited2[8][8];
int n,m;
int ans=0;
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
            b[i][j]=a[i][j];
            if(a[i][j]==2)
            {
                virus.push_back({i,j});
            }
        }
    }
    dfs(0,0);
    cout<<ans;
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
    for(int i=0; i<virus.size(); i++)
    {
        q.push(virus[i]);
    }
    while(!q.empty())
    {
        int cy=q.front().first;
        int cx=q.front().second;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int ny=cy+dy[i];
            int nx=cx+dx[i];
            if(inside(ny,nx)&&a[ny][nx]==0&&visited[ny][nx]==0)
            {
                visited[ny][nx]=1;
                a[ny][nx]=a[cy][cx]+1;
                q.push({ny,nx});
            }
        }
    }
}
void dfs(int size,int index){
    if(size==3)
    {
        bfs();
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(a[i][j]==0)
                {
                    cnt++;
                }
                else if(a[i][j]>=3)
                {
                    a[i][j]=0;
                }
                visited[i][j]=0;
            }
        }
        ans=max(ans,cnt);
        return;
    }
    for(int i=index; i<n*m; i++)
    {
        if(a[i/m][i%m]==0&&visited2[i/m][i%m]==0)
        {
            visited2[i/m][i%m]=1;
            a[i/m][i%m]=-1;
            dfs(size+1,i);
            a[i/m][i%m]=0;
            visited2[i/m][i%m]=0;
        }
    }
}