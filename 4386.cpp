#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;
void setting();
int find_parent(int vertex);
bool cycle(int vertex1, int vertex2);
void Union(int vertex1, int vertex2);
double x[101];
double y[101];
int parent[101];
double ans=0;
vector< tuple<double,int,int> > v;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout<<fixed;
    cout.precision(2);
    setting();
    for(int i=0; i<v.size(); i++)
    {
        double dist=get<0>(v[i]);
        int vertex1=get<1>(v[i]);
        int vertex2=get<2>(v[i]);
        if(cycle(vertex1,vertex2)==false)
        {
            ans=ans+dist;
            Union(vertex1, vertex2);
        }
    }
    cout<<ans;
}
void setting(){
    for(int i=0; i<101; i++)
    {
        parent[i]=i;
    }
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>x[i]>>y[i];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            double dist=sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
            v.push_back({dist,i,j});
        }
    }
    sort(v.begin(),v.end());
}
int find_parent(int vertex){
    if(parent[vertex]==vertex)
    {
        return vertex;
    }
    else
    {
        parent[vertex]=find_parent(parent[vertex]);
        return find_parent(parent[vertex]);
    }
}
bool cycle(int vertex1, int vertex2){
    vertex1=find_parent(vertex1);
    vertex2=find_parent(vertex2);
    if(vertex1==vertex2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Union(int vertex1, int vertex2){
    vertex1=find_parent(vertex1);
    vertex2=find_parent(vertex2);
    if(vertex1<vertex2)
    {
        parent[vertex2]=vertex1;
    }
    else
    {
        parent[vertex1]=vertex2;
    }
}