#include <iostream>
using namespace std;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int x, n, a, b; cin>>x>>n;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>a>>b;
        sum = sum + a * b;
    }
    
    if(x == sum)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
}