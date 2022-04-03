import math
def comb(n,m):
    return math.factorial(n)//(math.factorial(m)*math.factorial(n-m))

n,k=map(int,input().split())
dp=[n]
p=[1]
for i in range(1,55):
    p.append(p[i-1]*n)

for i in range(1,k+1):
    sum=p[i+1]
    for j in range(2,i+2):
        x=comb(i+1,j)*dp[i+1-j]
        if j&1:
            sum=sum-x
        else:
            sum=sum+x
    dp.append(sum//(i+1))
print(dp[k]%1000000007)