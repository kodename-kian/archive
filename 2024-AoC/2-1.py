###
# Advent of Code 2024
# Day 2 - Part 1
#
# Answer: 686
#
# @author Kian Chua
#
##

def check():
    a = [int(x) for x in input().split()]
    hasDec = False
    hasInc = False

    for i in range(1, len(a)):
        difference = abs(a[i] - a[i-1])
        if 1 > difference or difference > 3:
            return False
        elif difference == a[i] - a[i-1]:
            hasInc = True
        else:
            hasDec = True
    
    return hasInc ^ hasDec
        

def main():
    n = 1000
    ans = 0

    for _ in range(n):
        ans += check()

    print(ans)

if __name__ == "__main__":
    main()