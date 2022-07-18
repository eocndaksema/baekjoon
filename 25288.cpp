//25288번
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin>>n>>s;

    string ans = "";
    for(int i = 0; i < n; i++)
    {
        ans = ans + s;
    }
    cout<<ans;
}