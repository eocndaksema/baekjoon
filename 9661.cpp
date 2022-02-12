#include <iostream>
typedef long long int ll;
using namespace std;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    if(n==1||n==3)
    {
        cout<<"SK\n";
    }
    else if(n==2)
    {
        cout<<"CY\n";
    }
    else
    {
        if((n-3)%5==1||(n-3)%5==3||(n-3)%5==0)
        {
            cout<<"SK\n";
        }
        else
        {
            cout<<"CY\n";
        }
    }

}