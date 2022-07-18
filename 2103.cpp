// 2109번
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map< int, vector<int> > mapX;
map< int, vector<int> > mapY;

int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n; cin>>n;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin>>x>>y;
        mapX[x].push_back(y);
        mapY[y].push_back(x);
    }

    for(auto it = mapX.begin(); it != mapX.end(); it++)
    {
        sort((*it).second.begin(), (*it).second.end());
    }

    for(auto it = mapY.begin(); it != mapY.end(); it++)
    {
        sort((*it).second.begin(), (*it).second.end());
    }

    int ans = 0;

    for(auto it = mapX.begin(); it != mapX.end(); it++)
    {
        for(int i = 0; i < (*it).second.size(); i = i + 2)
        {
            ans = ans + abs((*it).second[i] - (*it).second[i + 1]);
        }
    }

    for(auto it = mapY.begin(); it != mapY.end(); it++)
    {
        for(int i = 0; i < (*it).second.size(); i = i + 2)
        {
            ans = ans + abs((*it).second[i] - (*it).second[i + 1]);
        }
    }

    cout<<ans;
}