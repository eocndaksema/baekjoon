#15824번
n = int(input())
inputString = input()
scoville = inputString.split()
two = [1]
for i in range(0, len(scoville)):
    scoville[i] = int(scoville[i])
    if i != 0:
        two.append((two[-1] * 2) % 1000000007)

scoville.sort()

sum1 = 0
sum2 = 0
for i in range(n-1, 0, -1):
    sum1 = (sum1 + (two[i] - 1) % 1000000007 * scoville[i] % 1000000007) % 1000000007
    sum2 = (sum2 + (two[i] - 1) % 1000000007 * scoville[n - 1 - i] % 1000000007) % 1000000007

print((sum1 - sum2) % 1000000007)