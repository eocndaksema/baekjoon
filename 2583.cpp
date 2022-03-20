#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue < int, vector<int>, greater<int> > pq;
void dfs(int cy,int cx);
bool inside(int ny,int nx);
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
int a[101][101];
int m,n,k,cnt;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>m>>n>>k;
    for(int i=0; i<k; i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int j=y1; j<y2; j++)
        {
            for(int k=x1; k<x2; k++)
            {
                a[j][k]=1;
            }
        }
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(a[i][j]==0)
            {
                cnt=0;
                dfs(i,j);
                pq.push(cnt);
            }
        }
    }
    cout<<pq.size()<<"\n";
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
void dfs(int cy,int cx){
    a[cy][cx]=1;
    cnt++;
    for(int i=0; i<4; i++)
    {
        int ny=cy+dy[i];
        int nx=cx+dx[i];
        if(inside(ny,nx)&&a[ny][nx]==0)
        {
            dfs(ny,nx);
        }
    }
}

bool inside(int ny,int nx){
    if(0<=ny&&ny<m&&0<=nx&&nx<n)
    {
        return true;
    }
    else
    {
        return false;
    }
}