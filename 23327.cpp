#include <iostream>
using namespace std;
long long int popular[100005];
long long int sum[100005];
long long int length[100005];
long long int width[100005];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q,l,r;
    cin>>n>>q;
    for(int i=1; i<=n; i++)
    {
        cin>>popular[i];
        sum[i]=sum[i-1]+popular[i];
    }
    for(int i=n; i>=2; i--)
    {
        length[i-1]=length[i]+popular[i]*(sum[i-1]);
    }
    for(int i=1; i<=n-1; i++)
    {
        width[i]=width[i-1]+popular[i]*(sum[n]-sum[i]);
    }
    for(int i=0; i<q; i++)
    {
        cin>>l>>r;
        sum[l-1]*(sum[n]-sum[r]);
        cout<<width[n-1]-width[l-1]-length[r]+sum[l-1]*(sum[n]-sum[r])<<"\n";
    }
}