#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long int ll;
using namespace std;
bool cmp(string s1,string s2);
vector <string> v;
int main(){
	cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n;
    string input;
    cin>>n;
    for(ll i=0; i<n; i++)
    {
        cin>>input;
        v.push_back(input);
    }
    sort(v.begin(),v.end(),cmp);
    if(v[0]=="0")
    {
        cout<<0;
        return 0;
    }
    for(ll i=0; i<v.size(); i++)
    {
        cout<<v[i];
    }
    return 0;
}
bool cmp(string s1,string s2){
    return (s1+s2>s2+s1);
}
