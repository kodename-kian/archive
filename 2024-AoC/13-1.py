###
# Advent of Code 2024
# Day 13 - Part 1
#
# Answer: 31552
#
# @author Kian Chua
#
##

def parseLine():
    return  [ int(k[2:]) for k in (input().split(": ")[1]).split(", ") ]

def solve():
    a = parseLine()
    b = parseLine()
    t = parseLine()
    blank = input()

    best = 10000

    for i in range(0, 101):
        if (t[0] - i*a[0]) % b[0] != 0:
            continue
        if (t[1] - i*a[1]) % b[1] != 0:
            continue
        if (t[0] - i*a[0]) // b[0] != (t[1] - i*a[1]) // b[1]:
            continue

        val = 3*i + (t[0] - i*a[0]) // b[0]
        best = min(best, val)

    if best == 10000:
        return 0
    else:
        return best

    
    
def main():
    n = 1280 // 4
    ans = 0
    for _ in range(n):
        ans += solve()
    print(ans)


if __name__ == "__main__":
    main()