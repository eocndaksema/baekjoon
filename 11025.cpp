#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int ans;
    for(int i=1; i<=n; i++)
    {
        if(i==1)
        {
            ans=1;
        }
        else
        {
            ans=(ans+k)%i;
            if(ans==0)
            {
                ans=ans+i;
            }
        }
    }
    cout<<ans;
}