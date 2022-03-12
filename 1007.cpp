#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
typedef long long int ll;
using namespace std;
void dfs(ll index,ll n,ll depth);
vector< pair<ll,ll> > v;
bool visited[20];
double ans=99999999;
int main(){
	cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout<<fixed;
    cout.precision(6);
    ll t,n,x,y;
    cin>>t;
    while(t--)
    {
        v.clear();
        ans=99999999;
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            cin>>x>>y;
            v.push_back({x,y});
        }
        dfs(0,n/2,0);
        cout<<ans<<"\n";
    }
}
void dfs(ll index,ll n,ll depth){
    if(n==depth)
    {
        ll sum_x_end=0;
        ll sum_y_end=0;
        ll sum_x_start=0;
        ll sum_y_start=0;
        for(ll i=0; i<2*n; i++)
        {
            if(visited[i]==0)
            {
                sum_x_start=sum_x_start+v[i].first;
                sum_y_start=sum_y_start+v[i].second;
            }
            else
            {
                sum_x_end=sum_x_end+v[i].first;
                sum_y_end=sum_y_end+v[i].second;
            }
        }
        double sum=sqrt((sum_x_end-sum_x_start)*(sum_x_end-sum_x_start)+(sum_y_end-sum_y_start)*(sum_y_end-sum_y_start));
        ans=min(ans,sum);
        return;
    }
    for(ll i=index; i<v.size(); i++)
    {
        if(visited[i]==0)
        {
            visited[i]=1;
            dfs(i,n,depth+1);
            visited[i]=0;
        }
    }
}