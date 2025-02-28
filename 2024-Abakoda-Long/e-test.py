
n = 6
fail = 16

p = pow(2,n)

passed = []

def diff(x, y):
    ans = 0
    for j in range(n):
        ans += (x%2 != y%2)
        x //= 2
        y //= 2
    return ans

def findBest(val, choices):
    best = choices[0]
    for i in choices:
        if diff(val, i) < diff(val, best):
            best = i
    return diff(val, best)

def evaluate(tests):
    bad = []

    for i in range(p):
        score = n+1
        for test in tests:
            score = min(score, diff(i, test))
        if score > 1:
            bad.append(i)

        if len(bad) > fail:
            return
    
    passed.append([tests, bad])

print("RUNNING:")

for a in range(1,p-1):
    for b in range(a+1, p-1):
        for c in range(b+1, p-1):
            for d in range(c+1, p-1):
                tests = [0, 21, 42, 63, a, b, c, d]
                evaluate(tests)
    print("a pass")

print("Passing Tests:", len(passed))

best = []
bestScore = 9999 

for i in range(len(passed)):
    for j in range(i+1, len(passed)):
        count = 0
        for k in range(p):
            count += min(findBest(k, passed[i][0]), findBest(k, passed[j][0]))
        if count < bestScore:
            best = [passed[i][0], passed[j][0]]
            bestScore = count

print("BEST TEST COMBO:")
print(best)
print("TOTAL SCORE:", bestScore)

