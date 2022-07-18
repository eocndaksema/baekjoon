import math
def comb(a,b):
    return math.factorial(a)//(math.factorial(b)*math.factorial(a-b))

def solution(n):
    ans = 0
    for k in range(0, n//4):
        ans = ans + ((-1) ** k) * comb(13, k+1) * comb(52 - 4 * (k + 1), n - 4 *(k + 1)) 
    return ans
n = int(input())
print(solution(n)%10007)