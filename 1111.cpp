#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
vector <double> v;
int check();
bool check2();
double arr[50];
int n;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    if(n==1)
    {
        cout<<"A\n";
    }
    else if(n==2)
    {
        if(arr[0]==arr[1])
        {
            cout<<arr[0]<<"\n";
        }
        else
        {
            cout<<"A\n";
        }
    }
    else
    {
        for(int i=0; i<=n-2; i++)
        {
            v.push_back(arr[i+1]-arr[i]);
        }
        if(check()==1)
        {
            double a=v[1]/v[0];
            double b=arr[1]-a*arr[0];
            cout<<arr[n-1]*a+b<<"\n";
        }
        else if(check()==2)
        {
            if(check2()==true)
            {
                cout<<arr[0]<<"\n";
            }
            else
            {
                cout<<"B\n";
            }
        }
        else if(check()==0)
        {
            cout<<"B\n";
        }
    }
    return 0;
}
bool check2(){
    for(int i=0; i<=n-2; i++)
    {
        if(arr[i]==arr[i+1])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
int check(){
    if(v[0]==0&&v[1]==0)
    {
        return 2;
    }
    else if(v[0]==0&&v[1]!=0)
    {
        return 0;
    }
    else
    {
        double a=v[1]/v[0];
        if(a!=round(a))
        {
            return 0;
        }
        else
        {
            for(int i=1; i<=v.size()-2; i++)
            {
                if(a==v[i+1]/v[i]||(v[i+1]==0&&v[i]==0))
                {
                    continue;
                }
                else
                {
                    return 0;
                }
            }
        }
        return 1;
    }
}