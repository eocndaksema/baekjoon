#include <iostream>
typedef long long int ll;
using namespace std; 
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    if(n%7==0||n%7==2)
    {
        cout<<"CY";
    }
    else
    {
        cout<<"SK";
    }
}