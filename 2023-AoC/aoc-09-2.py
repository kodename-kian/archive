
def allZero(a):
    for i in a:
        if i != 0:
            return False
    return True

def predict(a):
    l = len(a)
    b = []
    for i in range(0, l-1):
        b.append(a[i+1] - a[i])

    if allZero(b):
        return a[0]
    else:
        return a[0] - predict(b)
ans = 0

s = input()

while s != "STAHP":
    k = [int(c) for c in s.split()]
    ans += predict(k)
    s = input()

print(ans)
