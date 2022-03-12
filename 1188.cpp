#include <iostream>
#include <algorithm>
using namespace std;
int a[101][101];
int main(){
	cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(int i=1; i<101; i++)
    {
        a[1][i]=i-1;
    }
    for(int i=2; i<101; i++)
    {
        for(int j=1; j<101; j++)
        {
            if(j<=i)
            {
                a[i][j]=a[i-j][j];
            }
            else
            {
                a[i][j]=i+a[i][j-i];
            }
        }
    }
    int n,m;
    cin>>n>>m;
    cout<<a[n][m];
}