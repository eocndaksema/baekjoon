#include <iostream>
#include <string>
using namespace std;
string s="111011100110101100101000000101";
unsigned long long int a[4000001];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    a[0]=1;
    for(long long int i=1; i<4000001; i++)
    {
        a[i]=i*a[i-1]%1000000007;
    }
    long long int n,k;
    cin>>n>>k;
    long long int A=a[n];
    long long int B=(a[k]*a[n-k])%1000000007;
    long long int tmp=B;
    for(int i=1; i<s.size(); i++)
    {
        if(s[i]=='1')
        {
            tmp=(tmp*tmp)%1000000007;
            tmp=(tmp*B)%1000000007;
        }
        else
        {
            tmp=(tmp*tmp)%1000000007;
        }
    }
    cout<<(A*tmp)%1000000007;
}