// 10997번
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool a[400][400];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};

int y, x;

void f(int depth, int cnt, int d, int cy, int cx, int ey, int ex)
{
    a[cy][cx] = true;

    if(cy == ey && cx == ex)
    {
        return;
    }

    int ny = cy + dy[d];
    int nx = cx + dx[d];

    if(cnt - depth != 0)
    {
        f(depth + 1, cnt, d, ny, nx, ey, ex);
    }
    else
    {
        d = (d + 1) % 4;
        ny = cy + dy[d];
        nx = cx + dx[d];

        if(d == 0 || d == 2)
        {
            f(0, cnt - 2, d, ny, nx, ey, ex);
        }
        else
        {
            f(0, cnt, d, ny, nx, ey, ex);
        }
    }
}

int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n; cin>>n;

    if(n == 1)
    {
        cout<<'*';
        return 0;
    }

    x = 4 * n - 3;
    y = 4 * n - 1;

    for(int i = 0; i < x; i++)
    {
        a[0][i] = true;
    }

    f(0, y - 2, 1, 1, 0, 2 * n, 2 * n - 2);

    string ans[400];

    for(int i = 0; i < y; i++)
    {
        for(int j = 0; j < x; j++)
        {
            if(a[i][j])
            {
                ans[i].push_back('*');
            }
            else
            {
                ans[i].push_back(' ');
            }
        }
    }

    for(int i = 0; i < y; i++)
    {
        while(ans[i].back() == ' ')
        {
            ans[i].pop_back();
        }
        cout<<ans[i]<<"\n";
    }
}