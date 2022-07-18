// 11779번
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#define INF 999999999999999999
typedef long long int ll;
using namespace std;
ll a[1001][1001];
ll d[1001];
priority_queue < tuple<ll, ll, vector <ll>> , vector< tuple<ll, ll, vector <ll>> > , greater< tuple<ll, ll, vector <ll>> > >pq;    //현재까지 이동거리, 현재 노드, 경로 벡터
vector < pair<ll,ll> > graph[1001];
vector <ll> route[1001];

void dijk(ll start)
{
    pq.push({0, start,{start}});
    
    while(!pq.empty())
    {
        ll curCost = get<0>(pq.top());
        ll curNode = get<1>(pq.top());
        vector <ll> curRoute = get<2>(pq.top());
        pq.pop();

        if(d[curNode] < curCost)
        {
            continue;
        }

        for(ll i = 0; i < graph[curNode].size(); i++)
        {
            ll nextNode = graph[curNode][i].first;
            ll cost = graph[curNode][i].second;

            if(cost + curCost < d[nextNode])
            {
                d[nextNode] = cost + curCost;
                route[nextNode].assign(curRoute.begin(),curRoute.end());
                route[nextNode].push_back(nextNode);
                pq.push({cost + curCost, nextNode, route[nextNode]});
            }
        }
    }
}

int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(ll i = 0; i < 1001; i++)
    {
        d[i] = INF;
    }

    ll n, m;
    cin>>n>>m;
    for(ll i = 0; i < m; i++)
    {
        ll city1, city2, cost;
        cin>>city1>>city2>>cost;
        graph[city1].push_back({city2, cost});
    }

    ll start, end;
    cin>>start>>end;

    dijk(start);

    cout<<d[end]<<"\n";
    cout<<route[end].size()<<"\n";
    for(ll i = 0; i < route[end].size(); i++)
    {
        cout<<route[end][i]<<" ";
    }
}