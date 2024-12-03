
T = int(input())
L = int(input())

c = 0

for t in range(0, T+1):
    if t*(T-t) > L:
        c += 1

print(c)
