from sys import stdin, stdout
"""n , m , a = map( int, stdin.readline().rstrip().split() )
h = n//a
if n%a != 0:
    h = h + 1

w = m //a
if m%a != 0:
    w = w + 1
stdout.write( str(h*w) + "\n")
"""

def countr(i):
    cnt = 0
    while(i%10 == 0):
        cnt += 1
        i = i / 10
    return cnt


from math import factorial as fact
for i in xrange(1,251):
    if(i%25 == 0 or i%25 == 24):
        print i , countr(fact(i))
    