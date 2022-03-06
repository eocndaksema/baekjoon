#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#define INF 999999999
using namespace std;
int getsmall();
void dijk(int start);
void reset();
priority_queue < pair<int,int> , vector< pair<int,int> > , greater< pair<int,int> > >pq;
vector < pair<int,int> > v[1001];
int d[1001][1001];
bool visited[1001];
int n,m,x;
int main(){
	cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>x;
    for(int i=0; i<m; i++)
    {
        int s,e,t;
        cin>>s>>e>>t;
        v[s].push_back({t,e});
    }
    for(int i=1; i<=n; i++)
    {
        reset();
        dijk(i);
    }
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        ans=max(d[i][x]+d[x][i],ans);
    }
    cout<<ans;
}
void dijk(int start){
    for(int i=1; i<=n; i++)
    {
        d[start][i]=INF;
    }
    d[start][start]=0;
    for(int i=0; i<v[start].size(); i++)
    {
        d[start][v[start][i].second]=v[start][i].first;
        pq.push({v[start][i].first,v[start][i].second});
    }
    visited[start]=1;
    for(int j=0; j<n; j++)
    {
        int cur=getsmall();
        visited[cur]=1;
        for(int i=0; i<v[cur].size(); i++)
        {
            if(visited[v[cur][i].second]==0&&d[start][cur]+v[cur][i].first<d[start][v[cur][i].second])
            {
                d[start][v[cur][i].second]=d[start][cur]+v[cur][i].first;
                pq.push({d[start][v[cur][i].second],v[cur][i].second});
            }
        }
    }
}
int getsmall(){
    int index=0;
    while(!pq.empty())
    {
        index=pq.top().second;
        pq.pop();
        if(visited[index]==0)
        {
            return index;
        }
    }
    return index;
}
void reset(){
    pq=priority_queue < pair<int,int> , vector< pair<int,int> > , greater< pair<int,int> > >();
    memset(visited,0,sizeof(visited));
}