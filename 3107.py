def f():
    for i in range(0,len(l)):
            if l[i]=='':
                return i


a=input()
if a[0]==':' and a[1]==':':
    a=a[1:]
elif a[-1]==':' and a[-2]==':':
    a=a[:-1]

l=a.split(':')
if len(l)<8:
    while len(l)<8:
        l.insert(f(),'')

a=""

for i in range(0,len(l)):
    while len(l[i])<4 :
        l[i]="0"+l[i]
    a=a+":"+l[i]

print(a[1:])