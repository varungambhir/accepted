import sys
def bishops(N):
	if N == 1:
		return 1
	else :
		return 2*N-2

while  True:
	v=int(sys.stdin.readline())
	if v=='':
		break
	else:
		ans=bishops(v)
		print(ans)
	