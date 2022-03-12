#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
queue < pair<int,int> > q;
vector < pair<int,int> > enter;
void reset();
bool cmp1();
void copy1();
void bfs();
bool inside(int ny,int nx);
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
bool key[26];
char c[100][100];
char before[100][100];
bool visited[100][100];
int t,h,w;
int ans;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        reset();
        cin>>h>>w;
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                cin>>c[i][j];
                if(i==0||i==h-1||j==0||j==w-1)
                {
                    if(c[i][j]!='*')
                    {
                        enter.push_back({i,j});
                    }
                }
            }
        }

        string s; cin>>s;
        if(s!="0")
        {
            for(int i=0; i<s.size(); i++)
            {
                key[(int)s[i]-(int)'a']=1;
            }
        }

        while(1)
        {
            bfs();
            if(cmp1()==false)
            {
                copy1();
                for(int i=0; i<h; i++)
                {
                    for(int j=0; j<w; j++)
                    {
                        visited[i][j]=0;
                    }
                }
            }
            else
            {
                break;
            }
        }
        cout<<ans<<"\n";
    }
}
void reset(){
    q=queue < pair<int,int> >();
    enter.clear();
    ans=0;
    for(int i=0; i<101; i++)
    {
        if(0<=i&&i<26)
        {
            key[i]=0;
        }
        for(int j=0; j<101; j++)
        {
            visited[i][j]=0;
        }
    }
}
bool cmp1(){
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            if(before[i][j]!=c[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
void copy1(){
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            before[i][j]=c[i][j];
        }
    }
}
void bfs(){
    for(int i=0; i<enter.size(); i++)
    {
        if(c[enter[i].first][enter[i].second]=='.')
        {
            q.push(enter[i]);
            visited[enter[i].first][enter[i].second]=1;
        }
        else if('a'<=c[enter[i].first][enter[i].second]&&c[enter[i].first][enter[i].second]<='z')
        {
            q.push(enter[i]);
            visited[enter[i].first][enter[i].second]=1;
            key[(int)c[enter[i].first][enter[i].second]-(int)'a']=1;
            c[enter[i].first][enter[i].second]='.';
        }
        else if('A'<=c[enter[i].first][enter[i].second]&&c[enter[i].first][enter[i].second]<='Z')
        {
            if(key[(int)c[enter[i].first][enter[i].second]-(int)'A'])
            {
                q.push(enter[i]);
                visited[enter[i].first][enter[i].second]=1;
                c[enter[i].first][enter[i].second]='.';
            }
        }
        else if(c[enter[i].first][enter[i].second]=='$')
        {
            ans++;
            q.push(enter[i]);
            visited[enter[i].first][enter[i].second]=1;
            c[enter[i].first][enter[i].second]='.';
        }
    }
    while(!q.empty())
    {
        int cy=q.front().first;
        int cx=q.front().second;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int ny=cy+dy[i];
            int nx=cx+dx[i];
            if(inside(ny,nx)&&visited[ny][nx]==0)
            {
                if(c[ny][nx]=='.')
                {
                    q.push({ny,nx});
                    visited[ny][nx]=1;
                }
                else if('a'<=c[ny][nx]&&c[ny][nx]<='z')
                {
                    q.push({ny,nx});
                    visited[ny][nx]=1;
                    key[(int)c[ny][nx]-(int)'a']=1;
                    c[ny][nx]='.';
                }
                else if('A'<=c[ny][nx]&&c[ny][nx]<='Z')
                {
                    if(key[(int)c[ny][nx]-(int)'A'])
                    {
                        q.push({ny,nx});
                        visited[ny][nx]=1;
                        c[ny][nx]='.';
                    }
                }
                else if(c[ny][nx]=='$')
                {
                    ans++;
                    q.push({ny,nx});
                    visited[ny][nx]=1;
                    c[ny][nx]='.';
                }
            }
        }
    }
}
bool inside(int ny,int nx){
    if(0<=ny&&ny<h&&0<=nx&&nx<w)
    {
        return true;
    }
    else
    {
        return false;
    }
}