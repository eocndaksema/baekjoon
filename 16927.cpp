#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
queue <int> q[150];
int a[300][300];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,r;
    cin>>n>>m>>r;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }
    int flag=0;
    int start_y=0;
    int start_x=0;
    int start_z=0;
    int y=start_y; int x=start_x; int z=start_z;
    for(int i=0; i<n*m; i++)
    {
        q[z].push(a[y][x]);
        if(y==z&&x==m-1-z)
        {
            flag=1;
        }
        else if(y==n-1-z&&x==m-1-z)
        {
            flag=2;
        }
        else if(y==n-1-z&&x==z)
        {
            flag=3;
        }
        else if(y==start_y+1&&x==start_x)
        {
            start_y++;
            start_x++;
            flag=0;
            z++;
        }
        if(flag==0)
        {
            x++;
        }
        else if(flag==1)
        {
            y++;
        }
        else if(flag==2)
        {
            x--;
        }
        else if(flag==3)
        {
            y--;
        }
    }
    for(int i=0; i<round(min(n,m)/2); i++)
    {
        int cnt=r%q[i].size();
        while(cnt--)
        {
            int tmp=q[i].front();
            q[i].pop();
            q[i].push(tmp);
        }
    }
    ///////
    ///////
    flag=0;
    start_y=0;
    start_x=0;
    start_z=0;
    y=start_y; x=start_x; z=start_z;
    for(int i=0; i<n*m; i++)
    {
        a[y][x]=q[z].front();
        q[z].pop();
        if(y==z&&x==m-1-z)
        {
            flag=1;
        }
        else if(y==n-1-z&&x==m-1-z)
        {
            flag=2;
        }
        else if(y==n-1-z&&x==z)
        {
            flag=3;
        }
        else if(y==start_y+1&&x==start_x)
        {
            start_y++;
            start_x++;
            flag=0;
            z++;
        }
        if(flag==0)
        {
            x++;
        }
        else if(flag==1)
        {
            y++;
        }
        else if(flag==2)
        {
            x--;
        }
        else if(flag==3)
        {
            y--;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}