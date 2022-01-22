#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>
#include <climits>
using namespace std;
vector <int> acid;
vector <int> alkali;
vector < tuple<int,int,int> > ans;
void bs(int pivot,int start,int end);
int n;
int ans1=INT_MAX;
int ans2=INT_MAX;
int ans3=INT_MAX;
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int input;
        cin>>input;
        if(input>=0)
        {
            acid.push_back(input);
        }
        else
        {
            alkali.push_back(input);
        }
    }
    if(alkali.size()==0)
    {
        cout<<acid[0]<<" "<<acid[1]<<"\n";
    }
    else if(acid.size()==0)
    {
        cout<<alkali[alkali.size()-2]<<" "<<alkali[alkali.size()-1]<<"\n";
    }
    else
    {
        for(int i=0; i<alkali.size(); i++)
        {
            bs(-alkali[i],0,acid.size()-1);
        }
        sort(ans.begin(),ans.end());
        ans1=abs(get<1>(ans[0])+get<2>(ans[0]));
        if(alkali.size()>=2)
        {
            ans2=abs(alkali[alkali.size()-2]+alkali[alkali.size()-1]);
        }
        if(acid.size()>=2)
        {
            ans3=abs(acid[0]+acid[1]);
        }
        if(ans1<=ans2&&ans1<=ans3)
        {
            cout<<get<1>(ans[0])<<" "<<get<2>(ans[0])<<"\n";
        }
        else if(ans2<=ans1&&ans2<=ans1)
        {
            cout<<alkali[alkali.size()-2]<<" "<<alkali[alkali.size()-1]<<"\n";
        }
        else if(ans3<=ans1&&ans3<=ans2)
        {
            cout<<acid[0]<<" "<<acid[1]<<"\n";
        }
    }
}
void bs(int pivot,int start,int end){
    if(start>end)
    {
        if(0<=start&&start<acid.size())
        {
            ans.push_back({acid[start]-pivot,-pivot,acid[start]});
        }
        if(0<=end&&end<acid.size())
        {
            ans.push_back({pivot-acid[end],-pivot,acid[end]});
        }
        return;
    }
    int mid=(start+end)/2;
    if(acid[mid]==pivot)
    {
        ans.push_back({pivot-acid[mid],-pivot,acid[mid]});
        return;
    }
    else if(acid[mid]>pivot)
    {
        bs(pivot,start,mid-1);
    }
    else if(acid[mid]<pivot)
    {
        bs(pivot,mid+1,end);
    }
}
