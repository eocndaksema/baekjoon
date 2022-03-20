#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void turn(int d);
void move(int cy, int cx, int d);
bool inside(int ny,int nx);
int dice[6]={0,0,0,0,0,0};//앞 위 뒤 바닥 왼 오
int dy[5]={0,0,0,-1,1};
int dx[5]={0,1,-1,0,0};
int a[20][20];
int n,m,x,y,k;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>y>>x>>k;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0; i<k; i++)
    {
        int d;
        cin>>d;
        move(y,x,d);
    }
}
void turn(int d){
    int tmp[6];
    if(d==1)
    {
        tmp[3]=dice[5];
        tmp[5]=dice[1];
        tmp[1]=dice[4];
        tmp[4]=dice[3];
        tmp[0]=dice[0];
        tmp[2]=dice[2];
    }
    else if(d==2)
    {
        tmp[1]=dice[5];
        tmp[4]=dice[1];
        tmp[3]=dice[4];
        tmp[5]=dice[3];
        tmp[0]=dice[0];
        tmp[2]=dice[2];
    }
    else if(d==3)
    {
        tmp[1]=dice[0];
        tmp[2]=dice[1];
        tmp[3]=dice[2];
        tmp[0]=dice[3];
        tmp[4]=dice[4];
        tmp[5]=dice[5];
    }
    else if(d==4)
    {
        tmp[3]=dice[0];
        tmp[0]=dice[1];
        tmp[1]=dice[2];
        tmp[2]=dice[3];
        tmp[4]=dice[4];
        tmp[5]=dice[5];
    }

    for(int i=0; i<6; i++)
    {
        dice[i]=tmp[i];
    }
}
void move(int cy, int cx, int d){
    for(int i=1; i<=4; i++)
    {
        if(d==i)
        {
            int ny=cy+dy[i];
            int nx=cx+dx[i];
            if(inside(ny,nx))
            {
                turn(d);
                if(a[ny][nx]==0)
                {
                    a[ny][nx]=dice[3];
                }
                else
                {
                    dice[3]=a[ny][nx];
                    a[ny][nx]=0;
                }
                y=ny; x=nx;
                cout<<dice[1]<<"\n";
            }
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