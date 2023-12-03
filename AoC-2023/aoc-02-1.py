
s = 0

ref = dict()
ref["red"] = 12
ref["green"] = 13
ref["blue"] = 14

for i in range(100):

    flag = False
    
    game = input().split(": ")
    waves = game[1].split("; ")

    for wave in waves:
        colors = wave.split(", ")

        for color in colors:
            if int( color.split(" ")[0] ) > ref[ color.split(" ")[1] ]:
                flag = True

            if flag:
                break
        if flag:
            break

    if not flag:
        s += i+1

print(s)
