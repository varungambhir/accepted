import sys
t=int(sys.stdin.readline())
for c in xrange(0,t):
 
	n=int(sys.stdin.readline())
	m=0
 
	primfac = []
 
	d = 2
 
	while (n % d) == 0:
		primfac.append(d)
		m+=1
		n /= d
 
	d+=1
 
	while d <= 17000:
		while (n % d) == 0:
			primfac.append(d)
			n /= d
			m+=1
		d += 2
 
 
	if n > 1:
		primfac.append(n)
		m+=1
	print m
 
	for x in xrange(0, m):
		print primfac[x] 
