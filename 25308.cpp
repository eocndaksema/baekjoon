//25308번
#define MAX 8
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
double a[8];
vector <double> v;
bool visited[8];
int ans = 0;
double ccw(double x1, double x2, double x3, double y1, double y2, double y3)
{
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

bool isConvexity()
{
    vector < pair<double, double> > coordinates; //x좌표 y좌표순
    coordinates.push_back({0, v[0]});
    coordinates.push_back({v[1] / sqrt(2), v[1] / sqrt(2)});
    coordinates.push_back({v[2], 0});
    coordinates.push_back({v[3] / sqrt(2), -v[3] / sqrt(2)});
    coordinates.push_back({0, -v[4]});
    coordinates.push_back({-v[5] / sqrt(2), -v[5] / sqrt(2)});
    coordinates.push_back({-v[6], 0});
    coordinates.push_back({-v[7] / sqrt(2), v[7] / sqrt(2)});
    coordinates.push_back({0, v[0]});
    coordinates.push_back({v[1] / sqrt(2), v[1] / sqrt(2)});

    for(int i = 0; i < MAX; i++)
    {
        double x1 = coordinates[i].first;
        double y1 = coordinates[i].second;

        double x2 = coordinates[i + 1].first;
        double y2 = coordinates[i + 1].second;

        double x3 = coordinates[i + 2].first;
        double y3 = coordinates[i + 2].second;

        if(ccw(x1, x2, x3, y1 ,y2, y3) > 0)
        {
            return false;
        }
    }
    return true;
}

void dfs()
{
    if(v.size() == MAX)
    {
        if(isConvexity())
        {
            ans++;
        }
        return;
    }

    for(int i = 0; i < MAX; i++)
    {
        if(visited[i] == false)
        {
            visited[i] = true;
            v.push_back(a[i]);
            dfs();
            v.pop_back();
            visited[i] = false;
        }
    }
}
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i = 0; i < MAX; i++)
    {
        cin>>a[i];
    }

    for(int i = 0; i < MAX; i++)
    {
        visited[i] = true;
        v.push_back(a[i]);
        dfs();
        v.pop_back();
        visited[i] = false;
    }

    cout<<ans;
}