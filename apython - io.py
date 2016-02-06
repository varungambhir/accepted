from sys import stdin, stdout
a = map(int,stdin.readline().rstrip().split())
b = map(int,stdin.readline().rstrip().split())
if a > b:
    stdout.write(">\n")
elif b > a:
    stdout.write("<\n")
else:
    stdout.write("=\n")
    

#List comprehension with stdin and stdout
from sys import stdin, stdout
a, b, c, d = [int(x) for x in stdin.readline().rstrip().split()]
stdout.write( str(a*b*c*d) + "\n" )


#Map with stdin and stdout
from sys import stdin, stdout
a, b, c, d = map( int, stdin.readline().rstrip().split() )
stdout.write( str(a*b*c*d) + "\n" )


"""
Method 1a: Using a list comprehension

1
2
a, b, c, d = [int(x) for x in input().split()]
print(a*b*c*d)


Method 1b: Using the map function

1
2
a, b, c, d = map(int, input().split())
print(a*b*c*d)

"""