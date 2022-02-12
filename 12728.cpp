#include <iostream>
using namespace std;
int a[1005];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    a[0]=0;
    a[1]=6;
    a[2]=28;
    for(int i=3; i<1005; i++)
    {
        a[i]=((6*a[i-1])%1000-(4*a[i-2])%1000)%1000;
        if(a[i]<0)
        {
            a[i]=a[i]+1000;
        }
    }
    int t;
    cin>>t;
    for(int i=1; i<t+1; i++)
    {
        int n;
        cin>>n;
        if(n==2)
        {
            cout<<"Case #"<<i<<": 027"<<"\n";
        }
        else
        {
            if(n%1000==0)
            {
                cout<<"Case #"<<i<<": 751"<<"\n";
            }
            else if(n%1000==1)
            {
                cout<<"Case #"<<i<<": 255"<<"\n";
            }
            else if(n%1000==2)
            {
                cout<<"Case #"<<i<<": 527"<<"\n";
            }
            else
            {
                if(10<=a[n%1000]-1&&a[n%1000]-1<100)
                {
                    cout<<"Case #"<<i<<": 0"<<a[n%1000]-1<<"\n";
                }
                else if(1<=a[n%1000]-1&&a[n%1000]-1<10)
                {
                    cout<<"Case #"<<i<<": 00"<<a[n%1000]-1<<"\n";
                }
                else
                {
                    cout<<"Case #"<<i<<": "<<a[n%1000]-1<<"\n";
                }
            }
        }
    }
}