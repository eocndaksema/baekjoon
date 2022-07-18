//25307번
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int a[2000][2000];
bool pillar[2000][2000];
bool mannequin[2000][2000];
bool visited[2000][2000];
vector < pair<int, int> > mannequinLocation;
queue < tuple<int, int, int> > q;
vector < pair<int, int> > endVector;
int n, m, k;
int startY, startX, endY, endX;
int ans = 999999999;

bool isInside(int ny, int nx)
{
    if(0 <= ny && ny < n && 0 <= nx && nx < m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void mannequinBFS()
{
    while(!q.empty())
    {
        int cy = get<0>(q.front());
        int cx = get<1>(q.front());
        int cd = get<2>(q.front());
        q.pop();

        if(cd > 0)
        {
            for(int i = 0; i < 4; i++)
            {
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                if(isInside(ny, nx) && visited[ny][nx] == false)
                {
                    visited[ny][nx] = true;
                    mannequin[ny][nx] = true;
                    q.push({ny, nx, cd - 1});
                }
            }
        }
    }
}

void SiruBFS()
{
    while(!q.empty())
    {
        int cy = get<0>(q.front());
        int cx = get<1>(q.front());
        int dummy = get<2>(q.front());
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(isInside(ny, nx) && visited[ny][nx] == false && mannequin[ny][nx] == false && pillar[ny][nx] == false)
            {
                visited[ny][nx] = true;
                a[ny][nx] = a[cy][cx] + 1;
                q.push({ny, nx, dummy});
            }
        }
    }
}

void solve()
{
    for(int i = 0; i < mannequinLocation.size(); i++)
    {
        int y = mannequinLocation[i].first;
        int x = mannequinLocation[i].second;

        visited[y][x] = true;
        q.push({y, x , k});
        mannequinBFS();
    }

    memset(visited, false, sizeof(visited));

    int dummy = 0;
    visited[startY][startX] = true;
    q.push({startY, startX, dummy});
    SiruBFS();

    for(int i = 0; i < endVector.size(); i++)
    {
        endY = endVector[i].first;
        endX = endVector[i].second;
        if(!(mannequin[endY][endX] == true || pillar[endY][endX] == true) && a[endY][endX] != 0)
        {
            ans = min(ans, a[endY][endX]);
        }
    }

    if(ans != 999999999)
    {
        cout<<ans;
    }
    else
    {
        cout<<-1;
    }
}
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int input; cin>>input;
            if(input == 0)
            {
                a[i][j] = input;
            }
            else if(input == 1)
            {
                pillar[i][j] = true;
            }
            else if(input == 2)
            {
                endVector.push_back({i, j});
            }
            else if(input == 3)
            {
                mannequin[i][j] = true;
                mannequinLocation.push_back({i, j});
            }
            else if(input == 4)
            {
                startY = i;
                startX = j;
            }
        }
    }

    solve();
}