//20500번
#define MOD 1000000007
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
typedef long long int ll;
using namespace std;
void solution(ll n);
ll rem[15];
ll tmp[15];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n; cin>>n;
    solution(n);
}
void solution(ll n){
    if(n==1)
    {
        cout<<"0\n";
        return;
    }
    else
    {
        rem[11]=1;
        rem[0]=1;
        rem[6]=1;
        rem[10]=1;
        for(ll i=0; i<n-2; i++)
        {
            for(ll j=0; j<15; j++)
            {
                if(rem[j])
                {
                    tmp[(j+5)%15]=tmp[(j+5)%15]+rem[j];
                    tmp[(j+10)%15]=tmp[(j+10)%15]+rem[j];
                }
            }
            for(ll j=0; j<15; j++)
            {
                rem[j]=tmp[j];
                tmp[j]=0;
                if(rem[j]>=MOD)
                {
                    rem[j]=rem[j]-MOD;
                }
            }
        }
    }
    cout<<rem[0];
    return;
}