//1253번
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[2000];
int n;
vector < pair< int, pair<int, int> > > v;
vector < int > x;
vector < pair<int, int> > y;

bool isGOOD(int index, int num)
{
    int upper = upper_bound(x.begin(), x.end(), num) - x.begin();
    int lower = lower_bound(x.begin(), x.end(), num) - x.begin();

    for(int i = lower; i < upper; i++)
    {
        if(y[i].first == index || y[i].second == index)
        {
            continue;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    sort(a, a + n);

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            v.push_back({a[i] + a[j], {i, j}});
        }        
    }

    sort(v.begin(), v.end());
    
    for(int i = 0; i < v.size(); i++)
    {
        x.push_back(v[i].first);
        y.push_back(v[i].second);
    }

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        if(isGOOD(i, a[i]))
        {
            ans++;
        }
    }

    cout<<ans;
}