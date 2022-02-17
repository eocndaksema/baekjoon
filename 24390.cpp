#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
using namespace std;
void bfs();
int a[4]={10,60,600,30};
queue < tuple<int,bool,int> > q; //flag 0 조리 시작안함 1 조리중
bool visited[3601];
int time_min;
int ans=99999999;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    time_min=((int)s[0]-(int)'0')*600+((int)s[1]-(int)'0')*60+((int)s[3]-(int)'0')*10+((int)s[4]-(int)'0');
    q.push({0,0,0});
    bfs();
    cout<<ans;
}
void bfs(){
    while(!q.empty())
    {
        int cur=get<0>(q.front());
        bool flag=get<1>(q.front());
        int cnt=get<2>(q.front());
        q.pop();
        if(cur==time_min)
        {
            if(flag==0)
            {
                ans=min(ans,cnt+1);
            }
            else
            {
                ans=min(ans,cnt);
            }
        }
        for(int i=0; i<4; i++)
        {
            int next=cur+a[i];
            if(i==3)
            {
                if((0<=next&&next<3601)&&visited[next]==0)
                {  
                    visited[next]=1;
                    q.push({next,1,cnt+1});
                }
            }
            else
            {
                if((0<=next&&next<3601)&&visited[next]==0)
                {  
                    visited[next]=1;
                    if(flag==0)
                    {
                        q.push({next,0,cnt+1});
                    }
                    else
                    {
                        q.push({next,1,cnt+1});
                    }
                }
            }
        }
    }
}