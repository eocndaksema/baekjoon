#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
vector < pair<int,int> > v; //길이,끝수
void solve();
int a[1001];
int n;
int ans=0;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    solve();
}
void solve(){
    v.push_back({0,0});
    for(int i=1; i<=n; i++)
    {
        int mx=0;
        for(int j=0; j<i; j++)
        {
            if(a[j]<a[i])
            {
                mx=max(mx,1+v[j].first);
            }
        }
        v.push_back({mx,a[i]});
    }
    sort(v.begin(),v.end());
    cout<<v[v.size()-1].first;
}