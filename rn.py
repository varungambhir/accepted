
from random import randint

m = -10000
n =  10000
seen = set()

x, y = randint(m, n), randint(m, n)
seen.add((x, y))
i = 0
while i<=2000:
    seen.add((x,y))
    i = i + 1
    x, y = randint(m, n), randint(m, n)
    while (x, y) in seen:
        x, y = randint(m, n), randint(m, n)

import pickle
f = open("output.in","w+")
for item in seen:
    print>>f , item