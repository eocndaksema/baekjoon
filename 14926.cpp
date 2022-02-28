#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void dfs(int start,int depth);
bool graph[500][500];
int cnt[500];
int n;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i!=j)
            {
                graph[i][j]=1;
            }
        }
    }
    dfs(0,0);
    cout<<"a1";
}
void dfs(int start,int depth){
    cout<<"a"<<start+1<<" ";
    if(depth==n*(n-1)/2)
    {
        return;
    }
    for(int i=0; i<n; i++)
    {
        if(graph[start][i]==1&&cnt[i]<n-2)
        {
            cnt[start]++;
            cnt[i]++;
            graph[start][i]=0;
            graph[i][start]=0;
            dfs(i,depth+1);
        }
    }
}