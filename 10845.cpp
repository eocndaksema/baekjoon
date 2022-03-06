#include <iostream>
#include <vector>
using namespace std;
vector <int> v;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,input;
    string s;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>s;
        if(s=="push")
        {
            cin>>input;
            v.push_back(input);
        }
        else if(s=="pop")
        {
            if(v.size()==0)
            {
                cout<<-1<<"\n";
            }
            else
            {
                cout<<*v.begin()<<"\n";
                v.erase(v.begin());
            }
        }
        else if(s=="size")
        {
            cout<<v.size()<<"\n";
        }
        else if(s=="empty")
        {
            if(v.size()==0)
            {
                cout<<1<<"\n";
            }
            else
            {
                cout<<0<<"\n";
            }
        }
        else if(s=="front")
        {
            if(v.size()==0)
            {
                cout<<-1<<"\n";
            }
            else
            {
                cout<<*v.begin()<<"\n";
            }
        }
        else if(s=="back")
        {
            if(v.size()==0)
            {
                cout<<-1<<"\n";
            }
            else
            {
                cout<<*--v.end()<<"\n";
            }
        }
    }
}