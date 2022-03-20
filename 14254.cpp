#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int a[26];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s; int k; cin>>s>>k;
    if(k==s.size())
    {
        cout<<0;
        return 0;
    }
    int gap=s.size()-k;
    int ans=0;
    for(int i=0; i<gap; i++)
    {
        for(int j=i; j<s.size(); j=j+gap)
        {
            a[(int)s[j]-(int)'a']++;
        }
        int mx=0; int sum=0;
        for(int i=0; i<26; i++)
        {
            sum=sum+a[i];
            mx=max(a[i],mx);
        }
        ans=ans+sum-mx;
        memset(a,0,sizeof(a));
    }
    cout<<ans;
}