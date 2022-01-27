#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
vector < pair<int,int> > v[100001];
void dfs(int n,int d);
bool check(int n);
void reset();
bool visited [100001];
int dist=-1;
int node;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int V;
    cin>>V;
    for(int i=0; i<V; i++)
    {
        int node1,node2,edge;
        cin>>node1;
        while(1)
        {
            cin>>node2;
            if(node2==-1)
            {
                break;
            }
            cin>>edge;
            v[node1].push_back({node2,edge});
        }
    }
    visited[1]=1;
    dfs(1,0);
    reset();
    visited[node]=1;
    dfs(node,0);
    cout<<dist;
}
void dfs(int n,int d){
    if(check(n)==false)
    {
        if(d>dist)
        {
            dist=d;
            node=n;
        }
        return;
    }
    for(int i=0; i<v[n].size(); i++)
    {
        if(visited[v[n][i].first]==0)
        {
            visited[v[n][i].first]=1;
            dfs(v[n][i].first,d+v[n][i].second);
        }
    }
}
bool check(int n){
    for(int i=0; i<v[n].size(); i++)
    {
        if(visited[v[n][i].first]==0)
        {
            return true;
        }
    }
    return false;
}
void reset(){
    memset(visited,0,sizeof(visited));
    dist=-1;
}