a, b, c = i=map(int, input().split())
if a != 0 and a != 1:
    besp = c // (a)
    c = c - besp
if b != 0:
    n = c // (b+1)
    c = c - n
print(c)


