#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
typedef long long int ll;
using namespace std;
vector <ll> v;
vector <ll> u;
ll A[4000];
ll B[4000];
ll C[4000];
ll D[4000];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n; cin>>n;
    ll sum=0;
    for(ll i=0; i<n; i++)
    {
        cin>>A[i]>>B[i]>>C[i]>>D[i];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            v.push_back(A[i]+B[j]);
            u.push_back(C[i]+D[j]);
        }
    }
    sort(u.begin(),u.end());
    for(int i=0; i<v.size(); i++)
    {
        ll x=upper_bound(u.begin(),u.end(),-v[i])-u.begin();
        ll y=lower_bound(u.begin(),u.end(),-v[i])-u.begin();
        if(u[y]==-v[i])
        {
            sum=sum+x-y;
        }
    }
    cout<<sum<<"\n";
}
