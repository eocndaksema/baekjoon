#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
set <string> s;
int main(){
	cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    int ans=0;
    string str;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>str;
        s.insert(str);
    }
    for(int i=0; i<m; i++)
    {
        cin>>str;
        if(s.find(str)!=s.end())
        {
            ans++;
        }
    }
    cout<<ans;
}