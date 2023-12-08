
s = [1]*205

for i in range(205):

    line = input().split(": ")[1]
    win, inv = line.split(" | ")
    win = win.split()
    inv = inv.split()

    c = 0

    for num in inv:
        if num in win:
            c += 1

    num = s[i]

    for j in range(1,c+1):
        s[i+j] +=  num

print(sum(s))
