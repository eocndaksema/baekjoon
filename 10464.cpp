//10464번
#include <iostream>
using namespace std;
int XOR1ton(int n)
{
    if(n % 4 == 0)
    {
        return n;
    }
    else if(n % 4 == 1)
    {
        return 1;
    }
    else if(n % 4 == 2)
    {
        return n + 1;
    }
    else if(n % 4 == 3)
    {
        return 0;
    }
}
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int tc; cin>>tc;
    while(tc--)
    {
        int s, f; cin>>s>>f;
        int ans = XOR1ton(s-1) ^ XOR1ton(f);
        cout<<ans<<"\n";
    }
}