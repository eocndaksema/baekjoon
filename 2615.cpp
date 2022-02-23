#include <iostream>
#include <algorithm>
using namespace std;
int a[50][50];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(int i=10; i<29; i++)
    {
        for(int j=10; j<29; j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=10; i<29; i++)
    {
        for(int j=10; j<29; j++)
        {
            if(a[i][j-1]!=1&&a[i][j]==1&&a[i][j+1]==1&&a[i][j+2]==1&&a[i][j+3]==1&&a[i][j+4]==1&&a[i][j+5]!=1)
            {
                cout<<1<<"\n";
                cout<<i-9<<" "<<j-9;
                return 0;
            }
            else if(a[i][j-1]!=2&&a[i][j]==2&&a[i][j+1]==2&&a[i][j+2]==2&&a[i][j+3]==2&&a[i][j+4]==2&&a[i][j+5]!=2)
            {
                cout<<2<<"\n";
                cout<<i-9<<" "<<j-9;
                return 0;
            }
            else if(a[i-1][j]!=1&&a[i][j]==1&&a[i+1][j]==1&&a[i+2][j]==1&&a[i+3][j]==1&&a[i+4][j]==1&&a[i+5][j]!=1)
            {
                cout<<1<<"\n";
                cout<<i-9<<" "<<j-9;
                return 0;
            }
            else if(a[i-1][j]!=2&&a[i][j]==2&&a[i+1][j]==2&&a[i+2][j]==2&&a[i+3][j]==2&&a[i+4][j]==2&&a[i+5][j]!=2)
            {
                cout<<2<<"\n";
                cout<<i-9<<" "<<j-9;
                return 0;
            }
            else if(a[i-1][j-1]!=1&&a[i][j]==1&&a[i+1][j+1]==1&&a[i+2][j+2]==1&&a[i+3][j+3]==1&&a[i+4][j+4]==1&&a[i+5][j+5]!=1)
            {
                cout<<1<<"\n";
                cout<<i-9<<" "<<j-9;
                return 0;
            }
            else if(a[i-1][j-1]!=2&&a[i][j]==2&&a[i+1][j+1]==2&&a[i+2][j+2]==2&&a[i+3][j+3]==2&&a[i+4][j+4]==2&&a[i+5][j+5]!=2)
            {
                cout<<2<<"\n";
                cout<<i-9<<" "<<j-9;
                return 0;
            }
            else if(a[i-1][j+1]!=1&&a[i][j]==1&&a[i+1][j-1]==1&&a[i+2][j-2]==1&&a[i+3][j-3]==1&&a[i+4][j-4]==1&&a[i+5][j-5]!=1)
            {
                cout<<1<<"\n";
                cout<<i-5<<" "<<j-13;
                return 0;
            }
            else if(a[i-1][j+1]!=2&&a[i][j]==2&&a[i+1][j-1]==2&&a[i+2][j-2]==2&&a[i+3][j-3]==2&&a[i+4][j-4]==2&&a[i+5][j-5]!=2)
            {
                cout<<2<<"\n";
                cout<<i-5<<" "<<j-13;
                return 0;
            }
        }
    }
    cout<<0<<"\n";
    return 0;
}