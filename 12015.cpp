// 12015번
#define MAX 1000000
#define INF 9999999

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[MAX];
int c[MAX + 1];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    for(int i = 0 ; i < n; i++)
    {
        cin>>a[i];
    }

    c[0] = -INF;
    for(int i = 1 ; i < n + 1; i++)
    {
        c[i] = INF;
    }

    for(int i = 0 ; i < n; i++)
    {
        int index = lower_bound(c, c + n + 1, a[i]) - c;
        c[index] = min(c[index], a[i]);
    }

    for(int i = n; i >= 0; i--)
    {
        if(c[i] != INF)
        {
            cout<<i;
            return 0;
        }
    }
}