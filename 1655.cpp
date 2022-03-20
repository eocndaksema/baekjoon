#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue <int> pq1;
priority_queue < int, vector<int>, greater<int> > pq2;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,input,mid; cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>input;
        if(i==1)
        {
            mid=input;
        }
        else if(i==2)
        {
            if(mid<input)
            {
                pq2.push(input);
            }
            else
            {
                pq2.push(mid);
                mid=input;
            }
        }
        else
        {
            if(mid<input)
            {
                pq2.push(input);
            }
            else
            {
                pq1.push(input);
            }
            if(i&1)
            {
                if(pq1.size()<pq2.size())
                {
                    while(pq1.size()!=pq2.size())
                    {
                        pq1.push(mid);
                        mid=pq2.top();
                        pq2.pop();
                    }
                }
            }
            else
            {
                if(pq1.size()==pq2.size()+1)
                {
                    pq2.push(mid);
                    mid=pq1.top();
                    pq1.pop();
                }
            }
        }
        cout<<mid<<"\n";
    }
}