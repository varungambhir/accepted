from sys import stdin, stdout
a = map(int,stdin.readline().rstrip().split())
b = map(int,stdin.readline().rstrip().split())
if a > b:
    stdout.write(">\n")
elif b > a:
    stdout.write("<\n")
else:
    stdout.write("=\n")
    