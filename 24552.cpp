#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int a[100001];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    int open=0;
    int close=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(')
        {
            open++;
        }
        else
        {
            close++;
        }
    }
    if(close-open==1)
    {
        reverse(s.begin(),s.end());
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(')
            {
                s[i]=')';
            }
            else
            {
                s[i]='(';
            }
        }
    }
    int index=-1;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(')
        {
            a[i+1]=a[i]+1;
        }
        else
        {
            a[i+1]=a[i]-1;
        }
        if(a[i+1]==0)
        {
            index=i;
        }
    }
    int ans=0;
    for(int i=index+1; i<s.size(); i++)
    {
        if(s[i]=='(')
        {
            ans++;
        }
    }
    cout<<ans;
}