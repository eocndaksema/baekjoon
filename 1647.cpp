#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
int find_parent(int vertex);
bool cycle(int vertex1, int vertex2);
void Union(int vertex1, int vertex2);
vector < tuple<int, int, int> > v;
int parent[100001];
int city,m;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=0; i<100001; i++)
    {
        parent[i]=i;
    }

    cin>>city>>m;

    for(int i=0; i<m; i++)
    {
        int a,b,c; cin>>a>>b>>c;
        v.push_back({c,a,b});
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0; i<v.size(); i++)
    {
        if(city==2)
        {
            break;
        }
        int w=get<0>(v[i]);
        int vertex1=get<1>(v[i]);
        int vertex2=get<2>(v[i]);
        if(!cycle(vertex1,vertex2))
        {
            Union(vertex1,vertex2);
            ans=ans+w;
            city--;
        }
    }
    cout<<ans;
}
int find_parent(int vertex){
    if(parent[vertex]==vertex)
    {
        return vertex;
    }
    return parent[vertex]=find_parent(parent[vertex]);;
}
bool cycle(int vertex1, int vertex2){
    int x=find_parent(vertex1);
    int y=find_parent(vertex2);
    if(x==y)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Union(int vertex1, int vertex2){
    int x=find_parent(vertex1);
    int y=find_parent(vertex2);
    if(x<y)
    {
        parent[y]=x;
    }
    else
    {
        parent[x]=y;
    }
}
