#include <iostream>
#include <string>
#include <vector>
using namespace std;
void dfs(int depth);
int n,input;
string s="";
int a[11];
bool visited[10];
int mx=-1000000001;
int mn=1000000001;
vector <char> v;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<4; i++)
    {
        cin>>input;
        for(int j=0; j<input; j++)
        {
            if(i==0)
            {
                s=s+"+";
            }
            else if(i==1)
            {
                s=s+"-";
            }
            else if(i==2)
            {
                s=s+"*";
            }
            else if(i==3)
            {
                s=s+"/";
            }
        }
    }
    dfs(0);
    cout<<mx<<"\n"<<mn;
}
void dfs(int depth){
    if(depth==n-1)
    {
        int result=a[0];
        for(int i=0; i<v.size(); i++)
        {
            if(v[i]=='+')
            {
                result=result+a[i+1];
            }
            else if(v[i]=='-')
            {
                result=result-a[i+1];
            }
            else if(v[i]=='*')
            {
                result=result*a[i+1];
            }
            else if(v[i]=='/')
            {
                result=result/a[i+1];
            }
        }
        mx=max(result,mx);
        mn=min(result,mn);
    }
    for(int i=0; i<s.size(); i++)
    {
        if(visited[i]==0)
        {
            visited[i]=1;
            v.push_back(s[i]);
            dfs(depth+1);
            v.pop_back();
            visited[i]=0;
        }
    }
}