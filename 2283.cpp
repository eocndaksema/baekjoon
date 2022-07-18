//2283번
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cnt[1000001];
int prefixSum[1000001];
int n, k;

void solve()
{
    int left = 0; int right = 0;

    int lengthSum = 0;
    
    while(1)
    {
        if(left == 1000001 || right == 1000001)
        {
            cout<<"0 0";
            break;
        }

        if(lengthSum == k)
        {
            cout<<left<<" "<<right;
            break;
        }
        else if(lengthSum < k)
        {
            right++;
            lengthSum = lengthSum + prefixSum[right - 1];
        }
        else if(lengthSum > k)
        {
            left++;
            lengthSum = lengthSum - prefixSum[left - 1];
        }
    }
}

int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int i = 0; i < n; i++)
    {
        int left, right;

        cin>>left>>right;
        cnt[left]++;
        cnt[right]--;
    }

    for(int i = 0; i < 1000001; i++)
    {
        if(i == 0)
        {
            prefixSum[i] = cnt[i];
        }
        else
        {
            prefixSum[i] = prefixSum[i - 1] + cnt[i];
        }
    }

    solve();
}