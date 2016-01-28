#python 3
import sys
data=sys.stdin.read().strip().split()
#split splits into different lists sperated by space
#strips of white spaces
x=int(data[0])
y=int(data[2])
if data[1]=="+":
	print(x+y)
elif data[1]=='-':
	print(x-y)
elif data[1]=="*":
	print(x*y)
elif data[1]=='/':
	print(int(x/y))
else:
	print('Invalid Operator') 