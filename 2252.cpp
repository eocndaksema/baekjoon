// dfs

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void dfs(int n);
vector <int> v[32001];
vector <int> u;
bool visited[32001];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        v[0].push_back(i);
    }
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    dfs(0);
    for(int i=u.size()-2; i>=0; i--)
    {
        cout<<u[i]<<" ";
    }
}
void dfs(int n){
    if(v[n].size()==0)
    {
        u.push_back(n);
        return;
    }
    for(int i=0; i<v[n].size(); i++)
    {
        if(visited[v[n][i]]==0)
        {
            visited[v[n][i]]=1;
            dfs(v[n][i]);
        }
    }
    u.push_back(n);
}

/////////////////

//bfs

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
priority_queue < int , vector<int> , greater<int> > pq;
int indegree[32001];
vector <int> v[32001];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        indegree[b]++;
    }
    for(int i=1; i<=n; i++)
    {
        if(indegree[i]==0)
        {
            pq.push(i);
        }
    }
    while(!pq.empty())
    {
        int x=pq.top();
        pq.pop();
        for(int i=0; i<v[x].size(); i++)
        {
            indegree[v[x][i]]--;
            if(indegree[v[x][i]]==0)
            {
                pq.push(v[x][i]);
            }
        }
        cout<<x<<" ";
    }
}