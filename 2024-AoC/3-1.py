###
# Advent of Code 2024
# Day 3 - Part 1
#
# Answer: 184576302
#
# @author Kian Chua
#
##

def check():
    # split by occurence of "mul(..."
    round1 = input().split("mul(")[1:]

    # trim at ")"
    round2 = []
    for i in round1:
        for j in range(len(i)):
            if i[j] == ')':
                round2.append(i[:j])
                break
    
    # split by ","
    round3 = []
    for i in round2:
        spt = i.split(",")
        if len(spt) == 2:
            round3.append(spt)

    # verify integer values
    round4 = []
    for i in round3:
        flag = True
        for s in i:
            for c in s:
                if c not in "0123456789":
                    flag = False
        if flag:
            round4.append(i)

    # multiply and add to result
    ans = 0
    for i in round4:
        ans += int(i[0]) * int(i[1])

    return ans

    
def main():
    n = 6
    ans = 0

    for _ in range(n):
        ans += check()

    print(ans)


if __name__ == "__main__":
    main()