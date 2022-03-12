#define INF 999999999
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
typedef long long int ll;
using namespace std;
ll getsmall();
void dijk(ll start);
void reset();
ll arr[801][801];
ll d[801];
bool visited[801];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(ll i=0; i<801; i++)
    {
        for(ll j=0; j<801; j++)
        {
            if(i!=j)
            {
                arr[i][j]=INF;
            }
        }
    }
    ll n,e; cin>>n>>e;
    for(ll i=0; i<e; i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        arr[a][b]=c;
        arr[b][a]=c;
    }
    ll v1,v2; cin>>v1>>v2;
    ll ans[2]={0,0};

    dijk(1);
    ans[0]=ans[0]+d[v1];
    ans[1]=ans[1]+d[v2];
    reset();

    dijk(v1);
    ans[0]=ans[0]+d[v2];
    reset();

    dijk(v2);
    ans[0]=ans[0]+d[n];
    ans[1]=ans[1]+d[v1];
    reset();

    dijk(v1);
    ans[1]=ans[1]+d[n];

    if(min(ans[0],ans[1])>=INF)
    {
        cout<<-1;
    }
    else
    {
        cout<<min(ans[0],ans[1]);
    }
}
ll getsmall(){
    ll mn=INF;
    ll index=0;
    for(ll i=0; i<801; i++)
    {
        if(visited[i]==0&&mn>d[i])
        {
            mn=d[i];
            index=i;
        }
    }
    return index;
}
void dijk(ll start){
    visited[start]=1;
    for(ll i=0; i<801; i++)
    {
        d[i]=arr[start][i];
    }
    for(ll i=0; i<801; i++)
    {
        ll cur=getsmall();
        visited[cur]=1;
        for(ll j=0; j<801; j++)
        {
            if(visited[j]==0)
            {
                if(d[j]>d[cur]+arr[cur][j])
                {
                    d[j]=d[cur]+arr[cur][j];
                }
            }
        }
    }
}
void reset(){
    memset(d,0,sizeof(d));
    memset(visited,0,sizeof(visited));

}