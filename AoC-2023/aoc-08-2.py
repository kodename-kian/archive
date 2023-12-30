import copy

def isOk(ar):
    for i in ar:
        if i[2] != "Z":
            return False
    return True


s = [(k == "R") for k in input()]
l = len(s)

_ = input() #""

def gcd(a,b):
    if b == 0:
        return a
    elif a == b:
        return b
    else:
        return gcd(b, a%b)

def lcm(a,b):
    return a*b//gcd(a,b)


koda = dict()

q_track = []
a_track = []

data = input()
while data != "STAHP":
    dataS = data.split(" = ")
    koda[ dataS[0] ] = [ dataS[1][1:4], dataS[1][6:9] ]

    if dataS[0][2] == "A":
        q_track.append(dataS[0])

    data = input()

print(q_track)

for q in q_track:
    cnt = 0
    cur = q

    while cur[2] != "Z":
        cur = koda[cur][s[cnt%l]]
        cnt += 1

    a_track.append(cnt)


print(a_track)

ans = 1

for a in a_track:
    ans = lcm(ans, a)

print(ans)


#11567
#19637
#
#
#
#
