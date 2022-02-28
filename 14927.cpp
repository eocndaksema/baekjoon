#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void setting();
void copy();
void dfs(int index,int size,int depth);
bool check();
bool inside(int ny,int nx);
vector <int> v;
bool visited[18];
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
bool base[18][18];
bool a[18][18];
int N;
int ans=9999;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    setting();
    for(int i=0; i<=N; i++)
    {
        dfs(0,i,0);
    }
    if(ans==9999)
    {
        cout<<-1;
    }
    else
    {
        cout<<ans;
    }
}
void setting(){
    cin>>N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>base[i][j];
        }
    }
}
void copy(){
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            a[i][j]=base[i][j];
        }
    }
}
void dfs(int index,int size,int depth){
    if(depth==size)
    {
        copy();
        int ny;
        int nx;
        int cnt=0;
        for(int i=0; i<v.size(); i++)
        {
            a[0][v[i]]=!a[0][v[i]];
            cnt++;
            for(int j=0; j<4; j++)
            {
                ny=dy[j];
                nx=v[i]+dx[j];
                if(inside(ny,nx))
                {
                    a[ny][nx]=!a[ny][nx];
                }
            }
        }
        
        for(int i=1; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(a[i-1][j]==1)
                {
                    a[i][j]=!a[i][j];
                    cnt++;
                    for(int k=0; k<4; k++)
                    {
                        ny=i+dy[k];
                        nx=j+dx[k];
                        if(inside(ny,nx))
                        {
                            a[ny][nx]=!a[ny][nx];
                        }
                    }
                }
            }
        }
        if(check())
        {
            ans=min(ans,cnt);
        }
        return;
    }
    for(int i=index; i<N; i++)
    {
        if(visited[i]==0)
        {
            visited[i]=1;
            v.push_back(i);
            dfs(i,size,depth+1);
            v.pop_back();
            visited[i]=0;
        }
    }
}
bool check(){
    for(int i=0; i<N; i++)
    {
        if(a[N-1][i]==1)
        {
            return false;
        }
    }
    return true;
}
bool inside(int ny,int nx){
    if(0<=ny&&ny<N&&0<=nx&&nx<N)
    {
        return true;
    }
    else
    {
        return false;
    }
}