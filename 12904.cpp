#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s,t;
    cin>>s>>t;
    
    while(t.size()>s.size())
    {
        if(t.back()=='A')
        {
            t.pop_back();
        }
        else if(t.back()=='B')
        {
            t.pop_back();
            reverse(t.begin(),t.end());
        }
        else
        {
            cout<<"0\n";
            return 0;
        }
    }
    
    if(t==s)
    {
        cout<<"1\n";
    }
    else
    {
        cout<<"0\n";
    }
}