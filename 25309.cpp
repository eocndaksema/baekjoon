//25309번
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> v;
bool isPrimeNumber(int num)
{
    if(num == 0 || num == 1)
    {
        return false;
    }
    for(int i = 2; i * i <= num; i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}

void solve(int n, int k)
{
    if(k > (n / 2))
    {
        return;
    }

    if(k == 2)
    {
        if(n & 1)   // n이 홀수일때
        {
            if(isPrimeNumber(n-2))
            {
                for(int i = 0; i < v.size(); i++)
                {
                    cout<<v[i]<<" ";
                }
                cout<<2<<" "<<n-2;
                exit(0);
            }
        }
        else    // n이 짝수일때
        {
            for(int i = 1; i <= n / 2; i++)
            {
                if(isPrimeNumber(i) && isPrimeNumber(n - i))
                {
                    for(int j = 0; j < v.size(); j++)
                    {
                        cout<<v[j]<<" ";
                    }
                    cout<<i<<" "<<n - i;
                    exit(0);
                }
            }
        }
        return;
    }

    if(k == 1)
    {
        if(isPrimeNumber(n))
        {
            for(int i = 0; i < v.size(); i++)
            {
                cout<<v[i]<<" ";
            }
            cout<<n;
            exit(0);
        }
        return;
    }
    
    for(int i = n + 2 - 2 * k; i >= 2; i--)
    {
        if(isPrimeNumber(i))
        {
            v.push_back(i);
            solve(n - i, k - 1);
            v.pop_back();
        }
    }
}

int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, k; cin>>n>>k;
    solve(n, k);
    cout<<-1;
}