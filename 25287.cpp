//25287번
#define MAX 50000

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[MAX];

bool check(int n)
{
    for(int i = 0; i < n ; i++)
    {
        if(i == 0)
        {
            a[i] = min(a[i], n + 1 - a[i]);
        }
        else
        {
            if(a[i - 1] <= a[i] && a[i - 1] <= n + 1 - a[i])
            {
                a[i] = min(a[i], n + 1 - a[i]);
            }
            else if(a[i - 1] <= a[i] && !(a[i - 1] <= n + 1 - a[i]))
            {
                a[i] = a[i];
            }
            else if(!(a[i - 1] <= a[i]) && a[i - 1] <= n + 1 - a[i])
            {
                a[i] = n + 1 - a[i];
            }
            else if(!(a[i - 1] <= a[i]) && !(a[i - 1] <= n + 1 - a[i]))
            {
                return false;
            }
        }
    }
    return true;
}

int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int tc; cin>>tc;

    while(tc--)
    {
        int n; cin>>n;
        for(int i = 0; i < n ; i++)
        {
            cin>>a[i];
        }

        if(check(n))
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
}