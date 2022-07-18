// 2109번
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int a[10001];
priority_queue < pair <int, int> > pq;

int findParent(int n)
{
    if(a[n] == n)
    {
        return n;
    }
    
    return findParent(a[n]);
}

int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i = 0; i < 10001; i++)
    {
        a[i] = i;
    }

    int n; cin>>n;
    
    for(int i = 0; i < n; i++)
    {
        int p, d;
        cin>>p>>d;
        pq.push({p, d});
    }

    int ans = 0;
    while(!pq.empty())
    {
        int p = pq.top().first;
        int d = pq.top().second;
        pq.pop();

        int prt = findParent(d);
        if(prt != 0)
        {
            ans = ans + p;
            a[prt] = findParent(prt - 1);
        }
    }

    cout<<ans<<"\n";
}