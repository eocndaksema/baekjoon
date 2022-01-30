#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long int ans=0;
long long int parent[10001];
struct state
{
    long long int vertex1;
    long long int vertex2;
    long long int weight;
};
bool CompareWeight(const state& x, const state& y);
int Find_parent(int vertex);
bool cycle(int vertex1, int vertex2);
void Union(int vertex1, int vertex2);
vector <state> v;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(long long int i=0; i<10001; i++)
    {
        parent[i]=i;
    }
    long long int V,E;
    cin>>V>>E;
    for(long long int i=0; i<E; i++)
    {
        long long int a,b,c;
        cin>>a>>b>>c;
        v.push_back({a,b,c});
    }
    sort(v.begin(),v.end(),CompareWeight);
    for(long long int i=0; i<v.size(); i++)
    {
        int vertex1=v[i].vertex1;
        int vertex2=v[i].vertex2;
        if(!cycle(vertex1,vertex2))
        {
            ans=ans+v[i].weight;
            Union(vertex1,vertex2);
        }
    }
    cout<<ans;
}
bool cycle(int vertex1, int vertex2){
    int a=Find_parent(vertex1);
    int b=Find_parent(vertex2);
    if(a==b)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
void Union(int vertex1, int vertex2){
    int a=Find_parent(vertex1);
    int b=Find_parent(vertex2);
    if(a<b)
    {
        parent[b]=a;
    }
    else if(a>b)
    {
        parent[a]=b;
    }
}
int Find_parent(int vertex){
    if(parent[vertex]==vertex)
    {
        return vertex;
    }
    else
    {
        parent[vertex]=Find_parent(parent[vertex]);
        return parent[vertex];
    }
}
bool CompareWeight(const state& x, const state& y)
{
    return x.weight < y.weight;
}