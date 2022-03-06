#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector <string> v;
int main(){
	cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        v.clear();
        for(int i=0; i<n; i++)
        {
            string s;
            cin>>s;
            v.push_back(s);
        }
        sort(v.begin(),v.end());
        for(int i=0; i<v.size()-1; i++)
        {
            if(v[i].size()<v[i+1].size())
            {
                if(v[i]==v[i+1].substr(0,v[i].size()))
                {
                    cout<<"NO\n";
                    goto Label;
                }
            }
        }
        cout<<"YES\n";
        Label: continue;
    }
    
}