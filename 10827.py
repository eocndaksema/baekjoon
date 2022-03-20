l=input()
l=l.split()
n=len(l[0])-1-l[0].find('.')
x=l[0].split('.')
x=int(x[0]+x[1])
y=int(l[1])
z=bin(y)[2:]
sum=x
for i in range(1,len(z)):
    sum=sum*sum
    if z[i]=='1':
        sum=sum*x

sum=str(sum)
while len(sum)<n*y+1:
    sum='0'+sum
front=sum[:len(sum)-n*y]
back=sum[len(sum)-n*y:]
print(front+'.'+back)
