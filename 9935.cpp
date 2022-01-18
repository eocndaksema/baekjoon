#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
using namespace std;
vector <char> v;
string s1,s2;
void f(int n,int index);
void setting();
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>s1>>s2;
    setting();
    if(v.size()==0)
    {
        cout<<"FRULA";
    }
    else
    {
        for(int i=0; i<v.size(); i++)
        {
            cout<<v[i];
        }
    }
}
void setting(){
    for(int i=0; i<s1.size(); i++)
    {
        v.push_back(s1[i]);
        if(v[v.size()-1]==s2[s2.size()-1])
        {
            f(1,s2.size()-2);
        }
    }
}
void f(int n,int index){
    if(n==s2.size())
    {
        for(int i=0; i<s2.size(); i++)
        {
            v.pop_back();
        }
        return;
    }
    if(s2[index]==v[v.size()+index-s2.size()])
    {
        f(1+n,index-1);
    }
}