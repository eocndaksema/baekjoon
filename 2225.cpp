#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int a[405][405];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=0; i<405; i++)
    {
        a[i][0]=1;
    }
    for(int i=1; i<405; i++)
    {
        for(int j=1; j<=i; j++)
        {
            a[i][j]=(a[i-1][j-1]+a[i-1][j])%1000000000;
        }
    }
    cout<<a[n+k-1][n];
}