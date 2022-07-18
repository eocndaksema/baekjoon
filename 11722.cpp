// 11722번
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector < pair<int,int> > v; //길이,끝수

int a[1001] = {999999999, };
int n;

void solve()
{
    v.push_back({0, a[0]});
    for(int i = 1; i <= n; i++)
    {
        int mx = 0;
        for(int j = 0; j <= i - 1; j++)
        {
            if(a[j] > a[i])
            {
                mx = max(mx, 1 + v[j].first);
            }
        }
        v.push_back({mx, a[i]});
    }

    sort(v.begin(), v.end());
    cout<<v.back().first;
}

int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    solve();
}