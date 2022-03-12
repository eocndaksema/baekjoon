#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
bool inside(int ny,int nx);
bool check(int row,int col,int flag);
int a[100][100];
bool b[100];
int n,l;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>l;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>a[i][j];
        }
    }
    int ans=0;

    for(int i=0; i<n; i++)
    {
        memset(b,0,sizeof(b));
        for(int j=1; j<n; )
        {
            if(a[i][j]==a[i][j-1])
            {
                j++;
            }
            else
            {
                if(a[i][j]-a[i][j-1]==1)
                {
                    if(check(i,j,0)==true)
                    {
                        j++;
                    }
                    else
                    {
                        goto Label1;
                    }
                }
                else if(a[i][j]-a[i][j-1]==-1)
                {
                    if(check(i,j-1,1)==true)
                    {
                        j++;
                        //j=j+1+l;
                    }
                    else
                    {
                        goto Label1;
                    }
                }
                else
                {
                    goto Label1;
                }
            }
        }
        ans++;
        continue;

        Label1:
        memset(b,0,sizeof(b));
        for(int j=n-2; j>=0; )
        {
            if(a[i][j]==a[i][j+1])
            {
                j--;
            }
            else
            {
                if(a[i][j]-a[i][j+1]==1)
                {
                    if(check(i,j,1)==true)
                    {
                        j--;
                    }
                    else
                    {
                        goto Label2;
                    }
                }
                else if(a[i][j]-a[i][j+1]==-1)
                {
                    if(check(i,j+1,0)==true)
                    {
                        j--;
                        //j=j-1-l;
                    }
                    else
                    {
                        goto Label2;
                    }
                }
                else
                {
                    goto Label2;
                }
            }
        }
        ans++;
        Label2:
        continue;
    }

    ////
    for(int i=0; i<n; i++)
    {
        memset(b,0,sizeof(b));
        for(int j=1; j<n;)
        {
            if(a[j][i]==a[j-1][i])
            {
                j++;
            }
            else
            {
                if(a[j][i]-a[j-1][i]==1)
                {
                    if(check(j,i,2)==true)
                    {
                        j++;
                    }
                    else
                    {
                        goto Label3;
                    }
                }
                else if(a[j][i]-a[j-1][i]==-1)
                {
                    if(check(j-1,i,3)==true)
                    {
                        j++;
                        //j=j+1+l;
                    }
                    else
                    {
                        goto Label3;
                    }
                }
                else
                {
                    goto Label3;
                }
            }
        }
        ans++;
        continue;

        Label3:
        memset(b,0,sizeof(b));
        for(int j=n-2; j>=0; )
        {
            if(a[j][i]==a[j+1][i])
            {
                j--;
            }
            else
            {
                if(a[j][i]-a[j+1][i]==1)
                {
                    if(check(j,i,3)==true)
                    {
                        j--;
                    }
                    else
                    {
                        goto Label4;
                    }
                }
                else if(a[j][i]-a[j+1][i]==-1)
                {
                    if(check(j+1,i,2)==true)
                    {
                        j--;
                        //j=j-1-l;
                    }
                    else
                    {
                        goto Label4;
                    }
                }
                else
                {
                    goto Label4;
                }
            }
        }
        ans++;

        Label4:
        continue;
    }
    cout<<ans;
}
bool inside(int ny,int nx){
    if(0<=ny&&ny<n&&0<=nx&&nx<n)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool check(int row,int col,int flag){
    int x;
    if(flag==0)
    {
        for(int i=1; i<=l; i++)
        {
            if(inside(row,col-i))
            {
                x=a[row][col-1];
                if(x!=a[row][col-i])
                {
                    return false;
                }
                else
                {
                    if(b[col-i]==1)
                    {
                        return false;
                    }
                }
            }
            else
            {
                return false;
            }
        }
        for(int i=1; i<=l; i++)
        {
            b[col-i]=1;
        }
        return true;
    }
    else if(flag==1)
    {
        for(int i=1; i<=l; i++)
        {
            if(inside(row,col+i))
            {
                x=a[row][col+1];
                if(x!=a[row][col+i])
                {
                    return false;
                }
                else
                {
                    if(b[col+i]==1)
                    {
                        return false;
                    }
                }
            }
            else
            {
                return false;
            }
        }
        for(int i=1; i<=l; i++)
        {
            b[col+i]=1;
        }
        return true;
    }
    else if(flag==2)
    {
        for(int i=1; i<=l; i++)
        {
            if(inside(row-i,col))
            {
                x=a[row-1][col];
                if(x!=a[row-i][col])
                {
                    return false;
                }
                else
                {
                    if(b[row-i]==1)
                    {
                        return false;
                    }
                }
            }
            else
            {
                return false;
            }
        }
        for(int i=1; i<=l; i++)
        {
            b[row-i]=1;
        }
        return true;
    }
    else if(flag==3)
    {
        for(int i=1; i<=l; i++)
        {
            if(inside(row+i,col))
            {
                x=a[row+1][col];
                if(x!=a[row+i][col])
                {
                    return false;
                }
                else
                {
                    if(b[row+i]==1)
                    {
                        return false;
                    }
                }
            }
            else
            {
                return false;
            }
        }
        for(int i=1; i<=l; i++)
        {
            b[row+i]=1;
        }
        return true;
    }
}