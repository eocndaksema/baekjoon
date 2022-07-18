//17371번
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cout<<fixed;
    cout.precision(6);

    pair < int, int > p[1000];
    vector < pair<int, pair<int, int> > > v;

    int n; cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>p[i].first>>p[i].second;
    }

    for(int i = 0; i < n; i++)
    {
        int mx = -1;

        for(int j = 0; j < n; j++)
        {
            int dist = (p[i].first - p[j].first) * (p[i].first - p[j].first) + (p[i].second - p[j].second) * (p[i].second - p[j].second);
            if(dist > mx)
            {
                mx = dist;
            }
        }

        if(mx != -1)
        {
            v.push_back({mx, p[i]});
        }
    }
    sort(v.begin(), v.end());

    cout<<(double)v[0].second.first<<" "<<(double)v[0].second.second;
}
