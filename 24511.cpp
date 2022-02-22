#include <iostream>
#include <queue>
#include <stack>
using namespace std;
stack <int> st;
queue <int> q;
bool flag[100000];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,input,x;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>flag[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>input;
        if(flag[i]==0)
        {
            st.push(input);
        }
    }
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    cin>>m;
    for(int i=0; i<m; i++)
    {
        cin>>input;
        q.push(input);
    }
    for(int i=0; i<m; i++)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}