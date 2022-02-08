#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string solve(int n);
string dp[1000001];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    dp[1]="";
    dp[2]="()";
    dp[3]="(())";
    int n,t;
    cin>>t;
    while(t>0)
    {
        cin>>n;
        cout<<solve(n)<<"\n";
        t--;
    }
}
string solve(int n){
    string ans=dp[n];
    if(!dp[n].empty())
    {
        return ans;
    }
    if(n<=3)
    {
        return ans;
    }
    else
    {
        for(int j=2; j*j<=n; j++)
        {
            string s="";
            string p="";
            s.append(n-(j*(n/j)),'(');
            p.append(n-(j*(n/j)),'(');
            string a=solve(j);
            string b=solve(n/j);
            s=s+a+b;
            p=p+b+a;
            s.append(n-(j*(n/j)),')');
            p.append(n-(j*(n/j)),')');
            if(dp[n].empty())
            {
                dp[n]=min(s,p);
            }
            else
            {
                if(s.size()<dp[n].size())
                {
                    dp[n]=min(s,p);
                }
                else if(s.size()==dp[n].size())
                {
                    dp[n]=min({dp[n],s,p});
                }
            }
        }
        ans=dp[n];
        return ans;
    }
}