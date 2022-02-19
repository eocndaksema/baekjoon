#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue <int> pq;
int gcd(int n,int m);
int a[100];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=n-1; i>=0; i--)
    {
        a[i]=a[i]-a[0];
    }
    int x;
    for(int i=0; i<n-1; i++)
    {
        if(i==0)
        {
            x=gcd(a[i],a[i+1]);
        }
        else
        {
            x=gcd(x,a[i+1]);
        }
    }
    for(int i=2; i*i<=x; i++)
    {
        if(x%i==0)
        {
            if(i==x/i)
            {
                pq.push(-i);
            }
            else
            {
                pq.push(-i);
                pq.push(-(x/i));
            }
        }
    }
    pq.push(-x);
    while(!pq.empty())
    {
        cout<<-pq.top()<<" ";
        pq.pop();
    }
}
int gcd(int n,int m){
    if(n>m)
    {
        int tmp;
        tmp=m;
        m=n;
        n=tmp;
    }
    if(n==0)
    {
        return m;
    }
    else
    {
        return gcd(m%n,n);
    }
}