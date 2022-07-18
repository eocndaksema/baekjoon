//17143번
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
tuple<int, int, int> shark[100][100]; //속력, 이동방향, 크기
int R, C, M;

int fishing(int col)
{
    int sharkSize = 0;
    for(int i = 0; i < R; i++)
    {
        if(get<2>(shark[i][col]))
        {
            sharkSize = get<2>(shark[i][col]);
            shark[i][col] = {0, 0, 0};

            return sharkSize;
        }
    }
    return sharkSize;
}

void sharkMove()
{
    tuple<int, int, int> tmp[100][100] = {{{0, 0, 0}},};

    for(int i = 0 ; i < R; i++)
    {
        for(int j = 0 ; j < C; j++)
        {
            int r = i;
            int c = j;

            int s = get<0>(shark[i][j]);
            int d = get<1>(shark[i][j]);
            int z = get<2>(shark[i][j]);

            bool flag = true;

            if(d == 0)
            {
                continue;
            }
            else if(d == 1)    // 위일때
            {
                if(R != 1)
                {
                    if(s % ((R - 1) * 2) == 0)
                    {
                        for(int k = 0; k < (R - 1) * 2; k++)
                        {
                            if(flag)
                            {
                                r--;
                                if(r == -1)
                                {
                                    r = 1;
                                    flag = !flag;
                                }
                            }
                            else
                            {
                                r++;
                                if(r == R)
                                {
                                    r = R - 2;
                                    flag = !flag;
                                }
                            }
                        }
                    }
                    else
                    {
                        for(int k = 0; k < s % ((R - 1) * 2); k++)
                        {
                            if(flag)
                            {
                                r--;
                                if(r == -1)
                                {
                                    r = 1;
                                    flag = !flag;
                                }
                            }
                            else
                            {
                                r++;
                                if(r == R)
                                {
                                    r = R - 2;
                                    flag = !flag;
                                }
                            }
                        }
                    }
                }

                if(get<2>(tmp[r][c]))   //다른 상어 있는경우
                {
                    if(flag)
                    {
                        if(z > get<2>(tmp[r][c]))
                        {
                            tmp[r][c] = {s, d, z};
                        }
                    }
                    else
                    {
                        if(z > get<2>(tmp[r][c]))
                        {
                            tmp[r][c] = {s, 2, z};
                        }
                    }
                }
                else    //다른 상어 없는 경우
                {
                    if(flag)
                    {
                        tmp[r][c] = {s, d, z};
                    }
                    else
                    {
                        tmp[r][c] = {s, 2, z};
                    }
                }
            }
            else if(d == 2)   // 아래일때
            {
                if(R != 1)
                {
                    if(s % ((R - 1) * 2) == 0)
                    {
                        for(int k = 0; k < (R - 1) * 2; k++)
                        {
                            if(flag)
                            {
                                r++;
                                if(r == R)
                                {
                                    r = R - 2;
                                    flag = !flag;
                                }
                            }
                            else
                            {
                                r--;
                                if(r == -1)
                                {
                                    r = 1;
                                    flag = !flag;
                                }
                            }
                        }
                    }
                    else
                    {
                        for(int k = 0; k < s % ((R - 1) * 2); k++)
                        {
                            if(flag)
                            {
                                r++;
                                if(r == R)
                                {
                                    r = R - 2;
                                    flag = !flag;
                                }
                            }
                            else
                            {
                                r--;
                                if(r == -1)
                                {
                                    r = 1;
                                    flag = !flag;
                                }
                            }
                        }
                    }
                }

                if(get<2>(tmp[r][c]))   //다른 상어 있는경우
                {
                    if(flag)
                    {
                        if(z > get<2>(tmp[r][c]))
                        {
                            tmp[r][c] = {s, d, z};
                        }
                    }
                    else
                    {
                        if(z > get<2>(tmp[r][c]))
                        {
                            tmp[r][c] = {s, 1, z};
                        }
                    }
                }
                else    //다른 상어 없는 경우
                {
                    if(flag)
                    {
                        tmp[r][c] = {s, d, z};
                    }
                    else
                    {
                        tmp[r][c] = {s, 1, z};
                    }
                }
            }
            else if(d == 3)   // 오른쪽일때
            {
                if(s % ((C - 1) * 2) == 0)
                {
                    for(int k = 0; k < (C - 1) * 2; k++)
                    {
                        if(flag)
                        {
                            c++;
                            if(c == C)
                            {
                                c = C - 2;
                                flag = !flag;
                            }
                        }
                        else
                        {
                            c--;
                            if(c == -1)
                            {
                                c = 1;
                                flag = !flag;
                            }
                        }
                    }
                }
                else
                {
                    for(int k = 0; k < s % ((C - 1) * 2); k++)
                    {
                        if(flag)
                        {
                            c++;
                            if(c == C)
                            {
                                c = C - 2;
                                flag = !flag;
                            }
                        }
                        else
                        {
                            c--;
                            if(c == -1)
                            {
                                c = 1;
                                flag = !flag;
                            }
                        }
                    }
                }

                if(get<2>(tmp[r][c]))   //다른 상어 있는경우
                {
                    if(flag)
                    {
                        if(z > get<2>(tmp[r][c]))
                        {
                            tmp[r][c] = {s, d, z};
                        }
                    }
                    else
                    {
                        if(z > get<2>(tmp[r][c]))
                        {
                            tmp[r][c] = {s, 4, z};
                        }
                    }
                }
                else    //다른 상어 없는 경우
                {
                    if(flag)
                    {
                        tmp[r][c] = {s, d, z};
                    }
                    else
                    {
                        tmp[r][c] = {s, 4, z};
                    }
                }
            }
            else if(d == 4)   // 왼쪽일때
            {
                if(s % ((C - 1) * 2) == 0)
                {
                    for(int k = 0; k < (C - 1) * 2; k++)
                    {
                        if(flag)
                        {
                            c--;
                            if(c == -1)
                            {
                                c = 1;
                                flag = !flag;
                            }
                        }
                        else
                        {
                            c++;
                            if(c == C)
                            {
                                c = C - 2;
                                flag = !flag;
                            }
                        }
                    }
                }
                else
                {
                    for(int k = 0; k < s % ((C - 1) * 2); k++)
                    {
                        if(flag)
                        {
                            c--;
                            if(c == -1)
                            {
                                c = 1;
                                flag = !flag;
                            }
                        }
                        else
                        {
                            c++;
                            if(c == C)
                            {
                                c = C - 2;
                                flag = !flag;
                            }
                        }
                    }
                }

                if(get<2>(tmp[r][c]))   //다른 상어 있는경우
                {
                    if(flag)
                    {
                        if(z > get<2>(tmp[r][c]))
                        {
                            tmp[r][c] = {s, d, z};
                        }
                    }
                    else
                    {
                        if(z > get<2>(tmp[r][c]))
                        {
                            tmp[r][c] = {s, 3, z};
                        }
                    }
                }
                else    //다른 상어 없는 경우
                {
                    if(flag)
                    {
                        tmp[r][c] = {s, d, z};
                    }
                    else
                    {
                        tmp[r][c] = {s, 3, z};
                    }
                }
            }
        }
    }

    for(int i = 0 ; i < R; i++)
    {
        for(int j = 0 ; j < C; j++)
        {
            shark[i][j] = tmp[i][j];
        }
    }
}

int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>R>>C>>M;
    for(int i = 0; i < M; i++)
    {
        int r, c, s, d, z;
        cin>>r>>c>>s>>d>>z;
        get<0>(shark[r-1][c-1]) = s;
        get<1>(shark[r-1][c-1]) = d;
        get<2>(shark[r-1][c-1]) = z;
    }

    if(C == 1)
    {
        cout<<fishing(0);
        return 0;
    }

    int ans = 0;

    for(int i = 0; i < C; i++)
    {
        ans = ans + fishing(i);
        sharkMove();
    }

    cout<<ans;
}