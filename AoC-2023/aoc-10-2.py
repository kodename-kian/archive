import sys
sys.setrecursionlimit(1000000)
#boooo grids

guide = dict()
guide["|"] = [ 0, 0]
guide["-"] = [ 0, 0]
guide["L"] = [-1, 1]
guide["J"] = [-1,-1]
guide["7"] = [ 1,-1]
guide["F"] = [ 1, 1]

griddy =[]
s = input()
while s != "STAHP":
    griddy.append(s)
    s = input()

n = len(griddy)
m = len(griddy[0])

loopID = []
ansID = []
for i in range(n):
    tool = []
    toolDos = []
    for j in range(m):
        tool.append(0)
        toolDos.append(0)
    loopID.append(tool)
    ansID.append(toolDos)

cur = []

for i in range(0,n):
    for j in range(0,m):
        if griddy[i][j] == "S":
            cur = [i,j]
            break
    if cur != []:
        break


loopID[cur[0]][cur[1]] = 1

### grrr iterative
cnt = 0
cur = [cur[0], cur[1]+1]
pre = [0, 1]
#cur = [cur[0]+1, cur[1]]
#pre = [1,0]

while griddy[cur[0]][cur[1]] != "S":
    cnt += 1

    x,y = cur
    px, py = pre

    loopID[x][y] = 1

    dx, dy = guide[ griddy[x][y] ]

    dx += px
    dy += py

    nx = x + dx
    ny = y + dy

    cur = [nx, ny]
    pre = [dx, dy]

print(cnt)
print( (cnt+1)//2 )


## decided to get help w this one
# | : +2
# - : +0
# F, J : +1
# 7, L : +3

ans = 0
for i in range(n):
    cnt = 0
    for j in range(0,m):
        if loopID[i][j]: #part of the loop
            if griddy[i][j] == "|":
                cnt += 2
            elif griddy[i][j] in ["F", "J"]:
                cnt += 1
            elif griddy[i][j] in ["7", "L"]:
                cnt += 3
        else:
            if cnt%4 == 2:
                ans += 1
print(ans)

###go horizontally
##for i in range(n):
##    inside = False
##    active = False
##    for j in range(0,m):
##        if loopID[i][j] == 1: #inside
##            active = True
##        else:
##            if active:
##                active = False
##                inside = not inside
##            if inside:
##                ansID[i][j] += 1
##
###vertically
##for j in range(m):
##    inside = False
##    active = False
##    for i in range(0,n):
##        if loopID[i][j] == 1:
##            active = True
##        else:
##            if active:
##                active = False
##                inside = not inside
##            if inside:
##                ansID[i][j] += 1
##
##cnt = 0
##for i in loopID:
##    for j in i:
##        cnt += (j==0)

##def corrupt(i,j):
##    loopID[i][j] = 2
##
##    if j > 0:
##        if loopID[i][j-1] == 0:
##            corrupt(i, j-1)
##    if j < m-1:
##        if loopID[i][j+1] == 0:
##            corrupt(i, j+1)
##    #if i > 0:
##        #if loopID[i-1][j] == 0:
##            corrupt(i-1, j)
##    if i < n-1:
##        if loopID[i+1][j] == 0:
##            corrupt(i+1, j)
##
##corrupt(0,0)
##corrupt(0,m-1)
##corrupt(n-34, m-1)
##
##cnt = 0
##for i in loopID:
##    for j in i:
##        cnt += (j==0)
##
##print(cnt)

##for i in loopID:
##    for j in i:
##        if j == 0:
##            print(".", end="")
##        elif j == 2:
##            print("#", end="")
##        else:
##            print(j, end="")
##    print("")
##
##print("==========")
##
##for i in ansID:
##    print(i)
