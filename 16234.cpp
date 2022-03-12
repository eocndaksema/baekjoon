#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
void dfs(int x);
void setting();
bool inside(int ny,int nx);
vector <int> v[2500];
vector <pair<int,int>> u;
bool visited[2500];
int a[50][50];
int before[50][50];
int n,l,r,sum,depth;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>l>>r;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>a[i][j];
        }
    }
    int ans=0;
    while(1)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                before[i][j]=a[i][j];
            }
        }
        setting();
        for(int i=0; i<n*n; i++)
        {
            sum=0; depth=0; u.clear();
            dfs(i);
            for(int j=0; j<u.size(); j++)
            {
                int row=u[j].first;
                int col=u[j].second;
                a[row][col]=sum/depth;
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(before[i][j]!=a[i][j])
                {
                    goto Label;
                }
            }
        }
        break;

        Label: 
        ans++;
    }
    cout<<ans;
}
void dfs(int x){
    if(visited[x]==1)
    {
        return;
    }
    visited[x]=1;
    depth++;
    int row=x/n;
    int col=x%n;
    sum=sum+a[row][col];
    u.push_back({row,col});
    for(int i=0; i<v[x].size(); i++)
    {
        dfs(v[x][i]);
    }
}
void setting(){
    sum=0; depth=0;
    u.clear();
    for(int i=0; i<2500; i++)
    {
        visited[i]=0;
        v[i].clear();
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int d;
            if(inside(i,j+1))
            {
                d=abs(a[i][j]-a[i][j+1]);
                if(l<=d&&d<=r)
                {
                    v[i*n+j].push_back(i*n+j+1);
                    v[i*n+j+1].push_back(i*n+j);
                }
            }
            if(inside(i+1,j))
            {
                d=abs(a[i][j]-a[i+1][j]);
                if(l<=d&&d<=r)
                {
                    v[i*n+j].push_back((i+1)*n+j);
                    v[(i+1)*n+j].push_back(i*n+j);
                }
            }
        }
    }
}
bool inside(int ny,int nx){
    if(0<=ny&&ny<n&&0<=nx&&nx<n)
    {
        return true;
    }
    else
    {
        return false;
    }
}