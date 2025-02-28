
symbols = ['_', '.', '?', '!', '-', ',']

def solve():
    m, x, y, z = [int(x) for x in input().split()]
    v = x ^ y ^ z

    s = ""

    for i in range(m):
        exc = v % 32
        v = v >> 5
 
        if exc < 26:
            s = chr(ord('a') + exc) + s
        else:
            s = symbols[exc - 26] + s
    
    print(s)


for _ in range(int(input())):
    solve()