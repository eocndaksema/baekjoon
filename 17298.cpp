#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
stack < pair<int,int> > st;
int a[1000000];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,input;
    cin>>n;
    cin>>input;
    st.push({0,input});
    for(int i=1; i<n; i++)
    {
        cin>>input;
        while(!st.empty())
        {
            if(st.top().second<input)
            {
                int index=st.top().first;
                a[index]=input;
                st.pop();
            }
            else
            {
                break;
            }
        }
        st.push({i,input});
    }
    for(int i=0; i<n; i++)
    {
        if(a[i])
        {
            cout<<a[i]<<" ";
        }
        else
        {
            cout<<"-1 ";
        }
    }
}