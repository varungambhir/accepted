from sys import stdin, stdout
n = map(int,stdin.readline().rstrip().split())
a = map(int, stdin.readline().rstrip().split())
a = set(a)
sum = 0.0
for i in a:
    sum += i;
stdout.write(str(sum/len(a)) + "\n")