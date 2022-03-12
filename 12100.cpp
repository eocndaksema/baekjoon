#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
void dfs(int depth);
void move(int d);
stack <int> st[20];
vector <int> v;
int direction[4]={0,1,2,3}; //오 왼 위 아
pair<int,int> p[20][20];
pair<int,int> original[20][20];
int n;
int ans=0;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>original[i][j].first;
            original[i][j].second=0;
        }
    }
    dfs(0);
    cout<<ans;
}
void dfs(int depth){
    if(depth==5)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                p[i][j]=original[i][j];
            }
        }
        for(int i=0; i<v.size(); i++)
        {
            move(v[i]);
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                ans=max(ans,p[i][j].first);
            }
        }
        return;
    }
    for(int i=0; i<4; i++)
    {
        v.push_back(direction[i]);
        dfs(depth+1);
        v.pop_back();
    }
}

void move(int d){
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            p[i][j].second=0;
        }
    }
    int index;
    int x;
    if(d==0)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(p[i][j].first!=0)
                {
                    st[i].push(p[i][j].first);
                    p[i][j].first=0;
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            index=n-1;
            while(!st[i].empty())
            {
                x=st[i].top();
                st[i].pop();
                if(index==n-1)
                {
                    p[i][index].first=x;
                    index--;
                }
                else
                {
                    if(p[i][index+1].first==x)
                    {
                        if(p[i][index+1].second==0)
                        {
                            p[i][index+1].first=x+x;
                            p[i][index+1].second=1;
                        }
                        else
                        {
                            p[i][index].first=x;
                            index--;
                        }
                    }
                    else
                    {
                        p[i][index].first=x;
                        index--;
                    }
                }
            }
        }
    }
    else if(d==1)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=n-1; j>=0; j--)
            {
                if(p[i][j].first!=0)
                {
                    st[i].push(p[i][j].first);
                    p[i][j].first=0;
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            index=0;
            while(!st[i].empty())
            {
                x=st[i].top();
                st[i].pop();
                if(index==0)
                {
                    p[i][index].first=x;
                    index++;
                }
                else
                {
                    if(p[i][index-1].first==x)
                    {
                        if(p[i][index-1].second==0)
                        {
                            p[i][index-1].first=x+x;
                            p[i][index-1].second=1;
                        }
                        else
                        {
                            p[i][index].first=x;
                            index++;
                        }
                    }
                    else
                    {
                        p[i][index].first=x;
                        index++;
                    }
                }
            }
        }
    }
    else if(d==2)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=n-1; j>=0; j--)
            {
                if(p[j][i].first!=0)
                {
                    st[i].push(p[j][i].first);
                    p[j][i].first=0;
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            index=0;
            while(!st[i].empty())
            {
                x=st[i].top();
                st[i].pop();
                if(index==0)
                {
                    p[index][i].first=x;
                    index++;
                }
                else
                {
                    if(p[index-1][i].first==x)
                    {
                        if(p[index-1][i].second==0)
                        {
                            p[index-1][i].first=x+x;
                            p[index-1][i].second=1;
                        }
                        else
                        {
                            p[index][i].first=x;
                            index++;
                        }
                    }
                    else
                    {
                        p[index][i].first=x;
                        index++;
                    }
                }
            }
        }
    }
    else if(d==3)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(p[j][i].first!=0)
                {
                    st[i].push(p[j][i].first);
                    p[j][i].first=0;
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            index=n-1;
            while(!st[i].empty())
            {
                x=st[i].top();
                st[i].pop();
                if(index==n-1)
                {
                    p[index][i].first=x;
                    index--;
                }
                else
                {
                    if(p[index+1][i].first==x)
                    {
                        if(p[index+1][i].second==0)
                        {
                            p[index+1][i].first=x+x;
                            p[index+1][i].second=1;
                        }
                        else
                        {
                            p[index][i].first=x;
                            index--;
                        }
                    }
                    else
                    {
                        p[index][i].first=x;
                        index--;
                    }
                }
            }
        }
    }
}
