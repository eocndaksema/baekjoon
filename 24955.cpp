//24955번
#define MOD 1000000007
#include <iostream>
#include <algorithm>
#include <vector>
typedef unsigned long long int ll;
using namespace std;
ll houseNumber[1005];
vector <ll> v[1005];
vector <ll> houseNumberVector;
bool visited[1005];

ll calculateAns(ll ans, ll addNum)
{
    if(0 <= addNum && addNum <= 9)
    {
        return ((ans * 10) % MOD+ addNum % MOD) % MOD;
    }
    else if(10 <= addNum && addNum <= 99)
    {
        return ((ans * 100) % MOD+ addNum % MOD) % MOD;
    }
    else if(100 <= addNum && addNum <= 999)
    {
        return ((ans * 1000) % MOD+ addNum % MOD) % MOD;
    }
    else if(1000 <= addNum && addNum <= 9999)
    {
        return ((ans * 10000) % MOD+ addNum % MOD) % MOD;
    }
    else if(10000 <= addNum && addNum <= 99999)
    {
        return ((ans * 100000) % MOD+ addNum % MOD) % MOD;
    }
    else if(100000 <= addNum && addNum <= 999999)
    {
        return ((ans * 1000000) % MOD+ addNum % MOD) % MOD;
    }
    else if(1000000 <= addNum && addNum <= 9999999)
    {
        return ((ans * 10000000) % MOD+ addNum % MOD) % MOD;
    }
    else if(10000000 <= addNum && addNum <= 99999999)
    {
        return ((ans * 100000000) % MOD+ addNum % MOD) % MOD;
    }
    else if(100000000 <= addNum && addNum <= 999999999)
    {
        return ((ans * 1000000000) % MOD+ addNum % MOD) % MOD;
    }
    else if(addNum == 1000000000)
    {
        return ((ans * 10000000000) % MOD+ addNum % MOD) % MOD;
    }
}
void backtracking(ll start, ll end)
{
    if(start == end)
    {
        ll ans = 0;

        for(ll i = 0; i<houseNumberVector.size(); i++)
        {
            if(i == 0)
            {
                ans = ans + houseNumberVector[i];
            }
            else
            {
                ans = calculateAns(ans, houseNumberVector[i]);
            }
        }
        cout<<ans<<"\n";
        return;
    }

    if(v[start].empty())
    {
        return;
    }

    for(ll i = 0; i<v[start].size(); i++)
    {
        if(visited[v[start][i]] == false)
        {
            visited[v[start][i]] = true;
            houseNumberVector.push_back(houseNumber[v[start][i]]);

            backtracking(v[start][i], end);

            houseNumberVector.pop_back();
            visited[v[start][i]] = false;
        }
    }
}
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n, q; cin>>n>>q;
    for(ll i = 1; i <= n; i++)
    {
        cin>>houseNumber[i];
    }

    ll a, b, x, y;
    for(ll i = 0; i < n-1; i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(ll i = 0; i<q; i++)
    {
        cin>>x>>y;
        visited[x] = true;
        houseNumberVector.push_back(houseNumber[x]);

        backtracking(x, y);
        
        houseNumberVector.pop_back();
        visited[x] = false;
    }
}