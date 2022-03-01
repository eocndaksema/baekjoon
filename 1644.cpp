#define MAX 4000001
#include <iostream>
#include <vector>
using namespace std;
vector <int> v;
int a[MAX];
int cnt[MAX];
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    a[0]=1;
    a[1]=1;
    for(int i=2; i<MAX; i++)
    {
        for(int j=i+i; j<MAX; j=j+i)
        {
            a[j]=1;
        }
    }
    for(int i=1; i<MAX; i++)
    {
        if(a[i]==0)
        {
            v.push_back(i);
        }
    }
    for(int i=0; i<v.size(); i++)
    {
        int sum=0;
        for(int j=i; j<v.size(); j++)
        {
            sum=sum+v[j];
            if(sum>4000000)
            {
                break;
            }
            else
            {
                cnt[sum]++;
            }
        }
    }
    int n;
    cin>>n;
    cout<<cnt[n];
}