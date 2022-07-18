//16563번
#define MAX 5000001
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[MAX];
vector <int> v;
void solution(int ki)
{
    int j = 0;
    for(int i = v[j]; ;)
    {
        if(a[ki] == 0)  //ki가 소수가 되면 리턴
        {
            cout<<ki;
            return;
        }
        else
        {
            if(ki % i == 0)
            {
                ki = ki / i;
                cout<<i<<" ";
            }
            else
            {
                j++;
                i = v[j];
            }
        }
    }
}
int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    a[0] = 1;
    a[1] = 1;
    for(int i = 2; i < MAX; i++)
    {
        for(int j = i + i; j < MAX; j = j+i)
        {
            a[j] = 1;
        }

        if(a[i] == 0)
        {
            v.push_back(i);
        }
    }

    int n; cin>>n;
    for(int i = 0; i < n; i++)
    {
        int ki; cin>>ki;
        solution(ki);
        cout<<"\n";
    }
}