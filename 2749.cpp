#include <iostream>
#include <algorithm>
using namespace std;
long long int a[1500000];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    a[0]=0;
    a[1]=1;
    long long int n;
    cin>>n;
    int n2=n%1500000;
    for(int i=2; i<=n2; i++)
    {
        a[i]=(a[i-2]+a[i-1])%1000000;
    }
    cout<<a[n2];
}