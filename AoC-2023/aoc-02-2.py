
s = 0

ref = dict()
ref["red"] = 0
ref["green"] = 1
ref["blue"] = 2

for i in range(100):

    ans = [0,0,0]
    
    game = input().split(": ")
    waves = game[1].split("; ")

    for wave in waves:
        colors = wave.split(", ")

        for color in colors:
            ans[ref[color.split(" ")[1]]] = max(
                ans[ref[color.split(" ")[1]]],
                int(color.split(" ")[0]))

    s += ans[0]*ans[1]*ans[2]


print(s)
