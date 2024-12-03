###
# Advent of Code 2024
# Day 2 - Part 2
#
# Answer: 717
#
# @author Kian Chua
#
##

def works(a):
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


def check():
    a = [int(x) for x in input().split()]

    if works(a):
        return True
    
    for i in range(len(a)):
        b = []
        for j in range(len(a)):
            if i != j:
                b.append(a[j])
        if works(b):
            return True

    return False


def main():
    n = 1000
    ans = 0

    for _ in range(n):
        ans += check()

    print(ans)


if __name__ == "__main__":
    main()