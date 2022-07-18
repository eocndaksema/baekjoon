//11402번
#define MAX 60
#include <iostream>
#include <algorithm>
#include <vector>
typedef unsigned long long int ull;
using namespace std;
ull memo[2001][2001] = {1,};

ull arrN[MAX];
ull arrK[MAX];

void setting(char c, ull depth, ull num, ull mod)
{
	if(num == 0)
	{
		return;
	}

	ull remainder = num % mod;

	if(c == 'N')
	{
		arrN[MAX - 1 - depth] = remainder;
	}
	else if(c == 'K')
	{
		arrK[MAX - 1 - depth] = remainder;
	}

	setting(c, depth + 1, num / mod, mod);
}

ull solve(ull m)
{
	ull ret = 1;
	for(int i = 0; i < MAX; i++)
	{
		ret = (ret * memo[arrN[i]][arrK[i]]) % m;
	}
	return ret;
}

int main() {
	cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	ull n, k, m; cin>>n>>k>>m;

	for(int i = 1; i < 2001; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			if(j == 0)
			{
				memo[i][j] = 1;
			}
			else
			{
				memo[i][j] = (memo[i - 1][j - 1] + memo[i - 1][j]) % m;
			}
		}
	}

	setting('N', 0, n, m);
	setting('K', 0, k, m);

	cout<<solve(m);
}