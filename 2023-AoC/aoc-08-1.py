
s = [(k == "R") for k in input()]
l = len(s)

_ = input() #""

koda = dict()

data = input()
while data != "STAHP":
    dataS = data.split(" = ")
    koda[ dataS[0] ] = [ dataS[1][1:4], dataS[1][6:9] ]

    data = input()

cur = "AAA"
cnt = 0

while cur != "ZZZ":
    cur = koda[cur][s[cnt%l]]
    cnt += 1

print(cnt)
