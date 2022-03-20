#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void dfs(int depth,int cnt);
bool check(int row,int col);
bool inside(int ny,int nx);
int dy[4]={-1,-1};
int dx[4]={-1,1};
int chess[10][10];
int n;
int ans=0;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>chess[i][j];
        }
    }
    dfs(0,0);
    int tmp=ans;
    ans=0;
    dfs(1,0);
    ans=ans+tmp;
    cout<<ans;
}
void dfs(int depth,int cnt){
    if(depth>=n*n)
    {
        ans=max(ans,cnt);
        return;
    }

    int row=depth/n;
    int col=depth%n;
    if(chess[row][col]==1)
    {
        if(check(row,col)==true)
        {
            chess[row][col]=2;
            if(n&1)
            {
                dfs(depth+2,cnt+1);
            }
            else
            {
                if(col==n-1)
                {
                    dfs(depth+1,cnt+1);
                }
                else if(col==n-2)
                {
                    dfs(depth+3,cnt+1);
                }
                else
                {
                    dfs(depth+2,cnt+1);
                }
            }
            chess[row][col]=1;
        }
    }
    if(n&1)
    {
        dfs(depth+2,cnt);
    }
    else
    {
        if(col==n-1)
        {
            dfs(depth+1,cnt);
        }
        else if(col==n-2)
        {
            dfs(depth+3,cnt);
        }
        else
        {
            dfs(depth+2,cnt);
        }
    }
}
bool check(int row,int col){
    for(int i=0; i<2; i++)
    {
        for(int j=1; ; j++)
        {
            int n_row=row+j*dy[i];
            int n_col=col+j*dx[i];
            if(inside(n_row,n_col))
            {
                if(chess[n_row][n_col]==2)
                {
                    return false;
                }
            }
            else
            {
                break;
            }
        }
    }
    return true;
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
///////////////////////////////
//45도 회전으로 입력받을시

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
void dfs(int row,int col,int cnt);
bool check(int row,int col);
int chess[19][19];
int n;
int ans=0;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x=i;
        for(int j=n-x-1; j<2*n-x-1; j++)
        {
            cin>>chess[i][j];
            i++;
        }
        i=x;
    }
    dfs(0,n-1,0);
    int tmp=ans;
    ans=0;
    dfs(1,n-2,0);
    ans=ans+tmp;
    cout<<ans;
}
void dfs(int row,int col,int cnt){
    if(row>=2*n-1)
    {
        ans=max(ans,cnt);
        return;
    }
    if(col>n-1+row)
    {
        dfs(row+2,abs(n-1-(row+2)),cnt);
        return;
    }
    if(chess[row][col]==1&&check(row,col)==true)
    {
        chess[row][col]=2;
        dfs(row+2,abs(n-1-(row+2)),cnt+1);
        chess[row][col]=1;
    }
    dfs(row,col+2,cnt);
}
bool check(int row,int col){
    for(int i=1; row-1*i>=0; i++)
    {
        if(chess[row-1*i][col]==2)
        {
            return false;
        }
    }
    return true;
}


