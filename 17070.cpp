#include <iostream>
#include <algorithm>
using namespace std;
int ans=0;
void solve(int flag,int cy,int cx);
bool inside(int ny,int nx);
int a[16][16];
int n;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>a[i][j];
        }
    }
    solve(0,0,1);
    cout<<ans;
}
bool inside(int ny,int nx)
{
    if(0<=ny&&ny<n&&0<=nx&&nx<n)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void solve(int flag,int cy,int cx){
    if(cy==n-1&&cx==n-1)
    {
        ans++;
        return;
    }
    if(flag==0)
    {
        if(inside(cy,cx+1)&&a[cy][cx+1]!=1)
        {
            solve(0,cy,cx+1);
        }
        if(inside(cy,cx+1)&&a[cy][cx+1]!=1&&inside(cy+1,cx+1)&&a[cy+1][cx+1]!=1&&inside(cy+1,cx)&&a[cy+1][cx]!=1)
        {
            solve(2,cy+1,cx+1);
        }  
    }
    else if(flag==1)
    {
        if(inside(cy+1,cx)&&a[cy+1][cx]!=1)
        {
            solve(1,cy+1,cx);
        }
        if(inside(cy+1,cx)&&a[cy+1][cx]!=1&&inside(cy+1,cx+1)&&a[cy+1][cx+1]!=1&&inside(cy,cx+1)&&a[cy][cx+1]!=1)
        {
            solve(2,cy+1,cx+1);
        }
    }
    else if(flag==2)
    {
        if(inside(cy,cx+1)&&a[cy][cx+1]!=1)
        {
            solve(0,cy,cx+1);
        }
        if(inside(cy+1,cx)&&a[cy+1][cx]!=1)
        {
            solve(1,cy+1,cx);
        }
        if(inside(cy,cx+1)&&a[cy][cx+1]!=1&&inside(cy+1,cx)&&a[cy+1][cx]!=1&&inside(cy+1,cx+1)&&a[cy+1][cx+1]!=1)
        {
            solve(2,cy+1,cx+1);
        }
    }
}