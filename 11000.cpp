#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
priority_queue <int, vector<int>, greater<int>> pq;
pair <int,int> p[200000];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>p[i].first>>p[i].second;
    }
    sort(p,p+n);
    pq.push(-1);
    for(int i=0; i<n; i++)
    {
        if(pq.top()<=p[i].first)
        {
            pq.pop();
            pq.push(p[i].second);
        }
        else
        {
            pq.push(p[i].second);
        }
    }
    cout<<pq.size();
}