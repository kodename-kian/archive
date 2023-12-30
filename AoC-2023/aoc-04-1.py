
s = 0

for i in range(205):

    line = input().split(": ")[1]
    win, inv = line.split(" | ")
    win = win.split()
    inv = inv.split()

    c = 0

    for num in inv:
        if num in win:
            c += 1

    if c > 0:
        s += pow(2,c-1)

print(s)
