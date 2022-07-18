//25305번
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int a[1000];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, k; cin>>n>>k;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(a, a + n, cmp);
    cout<<a[k-1];
}