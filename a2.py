from sys import stdin,stdout
from math import factorial as fact
inp= map(int , stdin.readline().rstrip().split())
n = inp[0]
ans = (n*(n-1)*(n-2)*(n-3)*(n-4))*(n*(n-1)*(n-2)*(n-3)*(n-4))/120
stdout.write(str(ans) + "\n")   

