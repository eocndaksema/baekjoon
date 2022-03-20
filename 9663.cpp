#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
void dfs(int row,int col);
bool check(int row,int col);
int chess[14];
int n;
int ans=0;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    dfs(0,0);
    cout<<ans;
}
void dfs(int row,int col){
    if(row>=n)
    {
        ans++;
        return;
    }

    while(col!=n)
    {
        if(check(row,col)==true)
        {
            chess[row]=col;
            dfs(row+1,0);
            chess[row]=0;
        }
        col++;
    }
}
bool check(int row,int col){
    for(int i=0; i<row; i++)
    {
        if(chess[i]==col||abs(col-chess[i])==abs(row-i))
        {
            return false;
        }
    }
    return true;
}