#define INF 999999999
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b);
int solution(int s,int e);
vector < pair <int,int> > v;
vector < pair <int,int> > w;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    for(int i=0; i<n; i++)
    {
        int x_input,y_input;
        cin>>x_input>>y_input;
        v.push_back({x_input,y_input});
    }
    sort(v.begin(),v.end());
    cout<<solution(0,n-1);
}
int solution(int s,int e){
    if(e-s==1)
    {
        int x1=v[e].first; int y1=v[e].second;
        int x2=v[s].first; int y2=v[s].second;
        return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    }
    else if(e-s==0)
    {
        return INF;
    }
    
    int mid=(s+e)/2;

    int left=solution(s,mid);
    int right=solution(mid+1,e);
    int d=min(left,right);

    w.clear();
    for(int i=s; i<=e; i++)
    {
        int band=(v[i].first-v[mid].first)*(v[i].first-v[mid].first);
        if(band<d)
        {
            w.push_back(v[i]);
        }
    }

    sort(w.begin(),w.end(),cmp);

    for(int i=0; i<w.size(); i++)
    {
        for(int j=i+1; j<w.size(); j++)
        {
            int xx1=w[i].first; int yy1=w[i].second;
            int xx2=w[j].first; int yy2=w[j].second;
            int dd=(xx1-xx2)*(xx1-xx2)+(yy1-yy2)*(yy1-yy2);
            if((yy1-yy2)*(yy1-yy2)<d)
            {
                d=min(d,dd);
            }
            else
            {
                break;
            }
        }
    }

    return d;
}
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}