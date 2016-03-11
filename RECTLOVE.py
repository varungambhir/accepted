from sys import stdin,stdout

t1= map(int , stdin.readline().rstrip().split())
t = t1[0]
while t > 0:
    t -=1
    n,m,k = map(int , stdin.readline().rstrip().split())
    i = 0
    ans = 0.0
    den =  n*(n+1)*m*(m+1)*0.25
    r = map(int , stdin.readline().rstrip().split())
    while i < k:
        temp = r[i]
        if temp%m == 0:
            x = temp//m
            y = m
        else:
            x = temp//m  + 1
            y = temp%m    
        ans = ans + x*(n+1-x)*y*(m+1-y)*1.0
        i = i + 1
    ans = (ans*1.0)/den
    print "%.12f" %ans

