#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector <int> v;
int n,k;
int main(){
	cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    v.push_back(10);
    for(int i=0; i<n; i++)
    {
        char c;
        cin>>c;
        int x=(int)c-(int)'0';
        if(k>0)
        {
            if(v.back()>x)
            {
                v.push_back(x);
            }
            else
            {
                while(v.back()<x)
                {
                    v.pop_back();
                    k--;
                    if(k==0)
                    {
                        break;
                    }
                }
                v.push_back(x);
            }
        }
        else
        {
            v.push_back(x);
        }
    }
    for(int i=0; i<k; i++)
    {
        v.pop_back();
    }
    for(int i=1; i<v.size(); i++)
    {
        cout<<v[i];
    }
}
    