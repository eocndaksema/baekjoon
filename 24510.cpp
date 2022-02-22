#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int cnt=0;
int ans=0;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int c;
    cin>>c;
    string s;
    for(int i=0; i<c; i++)
    {
        cin>>s;
        if(s.size()>=3)
        {
            for(int j=0; j<s.size()-2;)
            {
                if(s[j]=='f'&&s[j+1]=='o'&&s[j+2]=='r')
                {
                    cnt++;
                    j=j+3;
                }
                else
                {
                    j++;
                }
            }
        }
        if(s.size()>=5)
        {
            for(int j=0; j<s.size()-4;)
            {
                if(s[j]=='w'&&s[j+1]=='h'&&s[j+2]=='i'&&s[j+3]=='l'&&s[j+4]=='e')
                {
                    cnt++;
                    j=j+5;
                }
                else
                {
                    j++;
                }
            }
        }
        ans=max(ans,cnt);
        cnt=0;
    }
    cout<<ans;
}
