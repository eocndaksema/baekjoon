//25286번
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int tc; cin>>tc;
    while(tc--)
    {
        int y, m;
        cin>>y>>m;
        if(m == 1)
        {
            cout<<y - 1<<" "<<12<<" "<<31;
        }
        else if(m == 3)
        {
            if((y % 100 != 0 && y % 4 == 0) || y % 400 == 0)
            {
                cout<<y<<" "<<2<<" "<<29;
            }
            else
            {
                cout<<y<<" "<<2<<" "<<28;
            }
        }
        else
        {
            cout<<y<<" "<<m-1<<" "<<a[m-1];
        }
        cout<<"\n";
    }
}