#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
bool inside(int ny,int nx);
void bfs();
void machine_work();
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
vector <int> machine;
int a[50][50];
int tmp[50][50];
int r,c,t;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>r>>c>>t;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>>a[i][j];
            if(a[i][j]==-1)
            {
                machine.push_back(i);
            }
        }
    }
    for(int i=0; i<t; i++)
    {
        bfs();
        machine_work();
    }
    int ans=0;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            ans=ans+a[i][j];
        }
    }
    cout<<ans+2;
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
void bfs(){
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(a[i][j]>=5)
            {
                int b=a[i][j]/5;
                for(int k=0; k<4; k++)
                {
                    int ny=i+dy[k];
                    int nx=j+dx[k];
                    if(inside(ny,nx)&&a[ny][nx]!=-1)
                    {
                        a[i][j]=a[i][j]-b;
                        tmp[ny][nx]=tmp[ny][nx]+b;
                    }
                }
            }
            tmp[i][j]=tmp[i][j]+a[i][j];
        }
    }
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            a[i][j]=tmp[i][j];
            tmp[i][j]=0;
        }
    }
}
void machine_work(){
    for(int i=machine[0]-1; i>=0; i--)
    {
        a[i+1][0]=a[i][0];
    }
    for(int i=1; i<c; i++)
    {
        a[0][i-1]=a[0][i];
    }
    for(int i=1; i<=machine[0]; i++)
    {
        a[i-1][c-1]=a[i][c-1];
    }
    for(int i=c-2; i>=1; i--)
    {
        a[machine[0]][i+1]=a[machine[0]][i];
    }
    a[machine[0]][0]=-1;
    a[machine[0]][1]=0;
    for(int i=machine[1]+1; i<r; i++)
    {
        a[i-1][0]=a[i][0];
    }
    for(int i=1; i<c; i++)
    {
        a[r-1][i-1]=a[r-1][i];
    }
    for(int i=r-1; i>=machine[1]; i--)
    {
        a[i+1][c-1]=a[i][c-1];
    }
    for(int i=c-2; i>=1; i--)
    {
        a[machine[1]][i+1]=a[machine[1]][i];
    }
    a[machine[1]][0]=-1;
    a[machine[1]][1]=0;
}