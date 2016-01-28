import operator as op
import sys
x,y=map(int,raw_input().split())
n=x+y
r=y
r = min(r, n-r)
if r == 0:
	print "1"
else:
	numer = reduce(op.mul, xrange(n, n-r, -1))
	denom = reduce(op.mul, xrange(1, r+1))
	print numer//denom