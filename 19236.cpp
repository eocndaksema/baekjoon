#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void back_up(int depth);
void recover(int depth);
int eat(int ny,int nx);
void move(int shark_i,int shark_j);
void dfs(int cd,int cy,int cx,int depth);
bool check(int cd,int cy,int cx);
bool inside(int ny,int nx);
int dy[8]={-1,-1,0,1,1,1,0,-1};
int dx[8]={0,-1,-1,-1,0,1,1,1};
pair <int,int> location[17];
pair <int,int> p[4][4];
pair <int,int> before[20][4][4];
int sum=0; int ans=0;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cin>>p[i][j].first>>p[i][j].second;
            p[i][j].second=p[i][j].second-1;
            location[p[i][j].first].first=i;
            location[p[i][j].first].second=j;
        }
    }
    sum=sum+p[0][0].first;
    dfs(eat(0,0),0,0,0);
    cout<<ans;
}
void back_up(int depth){
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            before[depth][i][j]=p[i][j];
        }
    }
}
void recover(int depth){
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            p[i][j]=before[depth][i][j];
        }
    }
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            location[p[i][j].first].first=i;
            location[p[i][j].first].second=j;
        }
    }
}
int eat(int ny,int nx){
    location[p[ny][nx].first].first=-1;
    location[p[ny][nx].first].second=-1;
    p[ny][nx].first=0;
    return p[ny][nx].second;
}
void move(int shark_i,int shark_j){
    for(int i=1; i<=16; i++)
    {
        int cnt=0;
        if(location[i].first==-1&&location[i].second==-1)
        {
            continue;
        }
        else
        {
            int cy=location[i].first;
            int cx=location[i].second;
            for(int j=0; j<8; j++)
            {
                if(cnt==8)
                {
                    p[cy][cx].second=(p[cy][cx].second+1)%8;
                    break;
                }
                int ny=cy+dy[j];
                int nx=cx+dx[j];
                int direction=p[cy][cx].second;
                if(direction==j)
                {
                    if(inside(ny,nx))
                    {
                        if(ny==shark_i&&nx==shark_j)
                        {
                            p[cy][cx].second=(p[cy][cx].second+1)%8;
                            cnt++;
                            j=-1;
                        }
                        else
                        {
                            pair <int,int> tmp=p[cy][cx];
                            pair <int,int> tmp_l=location[i];

                            int x=p[ny][nx].first;

                            p[cy][cx]=p[ny][nx];
                            location[i].first=ny; location[i].second=nx;

                            p[ny][nx]=tmp;
                            location[x]=tmp_l;
                            break;
                        }
                    }
                    else
                    {
                        p[cy][cx].second=(p[cy][cx].second+1)%8;
                        cnt++;
                        j=-1;
                    }
                }
            }
        }
    }
}
void dfs(int cd,int cy,int cx,int depth){
    move(cy,cx);
    if(check(cd,cy,cx)==false)
    {
        ans=max(ans,sum);
        return;
    }
    back_up(depth);
    for(int i=1; i<=3; i++)
    {
        int ny=cy+i*dy[cd];
        int nx=cx+i*dx[cd];
        if(inside(ny,nx)&&p[ny][nx].first>0)
        {
            int x=p[ny][nx].first;
            sum=sum+x;
            dfs(eat(ny,nx),ny,nx,depth+1);
            sum=sum-x;
            recover(depth);
        }
    }
}
bool check(int cd,int cy,int cx){
    for(int i=1; i<=3; i++)
    {
        int ny=cy+i*dy[cd];
        int nx=cx+i*dx[cd];
        if(inside(ny,nx)&&p[ny][nx].first)
        {
            return true;
        }
    }
    return false;
}
bool inside(int ny,int nx){
    if(0<=ny&&ny<4&&0<=nx&&nx<4)
    {
        return true;
    }
    else
    {
        return false;
    }
}