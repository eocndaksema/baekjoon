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