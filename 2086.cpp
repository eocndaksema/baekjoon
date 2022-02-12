#include <iostream>
#include <stack>
#include <vector>
typedef long long int ll;
using namespace std;
void reset();
void ans_ans();
void ans_base();
vector <ll> v;
stack <bool> st;
ll base[2][2]={1,1,1,0};
ll ans[2][2]={1,1,1,0};
ll tmp[2][2];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(int i=0; i<2; i++)
    {
        ll n;
        cin>>n;
        if(i==0)
        {
            n=n+1;
        }
        else
        {
            n=n+2;
        }
        n=n-1;
        while(n!=0)
        {
            st.push(n&1);
            n=n>>1;
        }
        st.pop();
        while(!st.empty())
        {
            if(st.top()==1)
            {
                ans_ans();
                ans_base();
                //ans=ans*ans*base
            }
            else
            {

                ans_ans();
                //ans=ans*ans
            }
            st.pop();
        }
        v.push_back(ans[0][0]);
        reset();
    }
    if(v[1]-v[0]<0)
    {
        cout<<1000000000+v[1]-v[0];
    }
    else
    {
        cout<<v[1]-v[0];
    }
}
void reset(){
    ans[0][0]=base[0][0];
    ans[0][1]=base[0][1];
    ans[1][0]=base[1][0];
    ans[1][1]=base[1][1];
}
void ans_base(){
    //ans=ans*ans*base
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            for(int k=0; k<2; k++)
            {
                tmp[i][j]=((tmp[i][j]%1000000000)+(ans[i][k]%1000000000)*(base[k][j]%1000000000))%1000000000;
            }
        }
    }
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            ans[i][j]=tmp[i][j];
            tmp[i][j]=0;
        }
    }
}
void ans_ans(){
    //ans=ans*ans
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            for(int k=0; k<2; k++)
            {
                tmp[i][j]=((tmp[i][j]%1000000000)+(ans[i][k]%1000000000)*(ans[k][j]%1000000000))%1000000000;
            }
        }
    }
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            ans[i][j]=tmp[i][j];
            tmp[i][j]=0;
        }
    }
}