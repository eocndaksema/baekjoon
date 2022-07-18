import math
def comb(a,b):
    return math.factorial(a)//(math.factorial(b)*math.factorial(a-b))

n, m = list(map(int, input().split()))
s = input()
print(comb(n, m) * (2 ** (m - 1)) % 1000000007)