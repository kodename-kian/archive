
n, a, b, c = [int(x) for x in input().split() ]
A = [int(x) for x in input().split()]

memo = []
for i in range(n+3):
    memo.append([])
    for j in range(2030):
        memo[i].append(-1)

# probability of surviving if we 'land' at square i with health h
def dp(i, h): 
    if h <= 0:
        return 0
    if i >= n:
        return 1
    if memo[i][h] != -1:
        return memo[i][h]
    
    nh = h - A[i]

    ans = 0
    ans += 1 * dp(i+2, nh)
    ans += 2 * dp(i+3, nh)
    ans += 3 * dp(i+4, nh)
    ans += 4 * dp(i+5, nh)
    ans += 5 * dp(i+6, nh)
    ans += 6 * dp(i+7, nh)
    ans += 5 * dp(i+8, nh)
    ans += 4 * dp(i+9, nh)
    ans += 3 * dp(i+10, nh)
    ans += 2 * dp(i+11, nh)
    ans += 1 * dp(i+12, nh)

    ans /= 36

    memo[i][h] = ans
    
    return ans
    
print(dp(0, a) * dp(0, b) * dp(0, c))
    

# 2                     -> 1/36 chance of 2
# 3 3                   -> 2/36 chance of 3
# 4 4 4                 -> 3/36 chance of 4
# 5 5 5 5               -> 4/36 chance of 5
# 6 6 6 6 6             -> 5/36 chance of 6
# 7 7 7 7 7  7          -> 6/36 chance of 7
#   8 8 8 8  8          -> 5/36 chance of 8
#     9 9 9  9          -> 4/36 chance of 9
#         10 10         -> 3/36 chance of 10
#         11 11         -> 2/36 chance of 11
#            12         -> 1/36 chance of 12

