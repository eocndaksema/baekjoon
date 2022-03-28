#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
void bfs2();
void bfs();
bool inside(int ny,int nx);
queue< pair <int,int> > wq;
queue< pair <int,int> > sq;
vector <pair <int,int> > swan;
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
char a[1500][1500];
bool visited[1500][1500];
int r,c;
int ans=0;
bool flag=0;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>r>>c;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='L')
            {
                swan.push_back({i,j});
                wq.push({i,j});
            }
            else if(a[i][j]=='.')
            {
                wq.push({i,j});
            }
        }
    }
    visited[swan[0].first][swan[0].second]=1;
    sq.push({swan[0].first,swan[0].second});
    a[swan[0].first][swan[0].second]='.';
    while(1)
    {
        bfs2();
        if(flag==1)
        {
            cout<<ans<<"\n";
            return 0;
        }
        bfs();
        ans++;
    }
}
void bfs2(){
    queue< pair <int,int> > tmp;
    while(!sq.empty())
    {
        int cy=sq.front().first;
        int cx=sq.front().second;
        sq.pop();
        for(int j=0; j<4; j++)
        {
            int ny=cy+dy[j];
            int nx=cx+dx[j];
            if(inside(ny,nx))
            {
                if(visited[ny][nx]==0)
                {
                    visited[ny][nx]=1;
                    if(a[ny][nx]=='.')
                    {
                        sq.push({ny,nx});
                    }
                    else if(a[ny][nx]=='X')
                    {
                        tmp.push({ny,nx});
                    }
                    else if(a[ny][nx]=='L')
                    {
                        flag=1;
                        break;
                    }
                }
            }
        }
    }
    while(!tmp.empty())
    {
        sq.push(tmp.front());
        tmp.pop();
    }
}
void bfs(){
    int sz=wq.size();
    for(int i=0; i<sz; i++)
    {
        int cy=wq.front().first;
        int cx=wq.front().second;
        wq.pop();
        for(int j=0; j<4; j++)
        {
            int ny=cy+dy[j];
            int nx=cx+dx[j];
            if(inside(ny,nx))
            {
                if(a[ny][nx]=='X')
                {
                    wq.push({ny,nx});
                    a[ny][nx]='.';
                }
            }
        }
    }
}
bool inside(int ny,int nx){
    if(0<=ny&&ny<r&&0<=nx&&nx<c)
    {
        return true;
    }
    else
    {
        return false;
    }
}