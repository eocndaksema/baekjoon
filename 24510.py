import re
ans=0
cnt=0
c=int(input())
for i in range(0,c):
    text=input()
    cnt=text.count('for')+text.count('while')
    if cnt>ans:
        ans=cnt
    cnt=0
print(ans)