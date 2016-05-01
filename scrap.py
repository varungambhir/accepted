from sys import stdin, stdout
i = 0
while i < 10001:
    n , a = map( int, stdin.readline().rstrip().split() )
    i += 1
    print "%d," % a,

