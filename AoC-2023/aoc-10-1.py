
import sys
sys.setrecursionlimit(20000)

done = dict()
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

cur = []

for i in range(0,n):
    for j in range(0,m):
        if griddy[i][j] == "S":
            cur = [i,j]
            break
    if cur != []:
        break

print(n*m)
print(cur)

##def explore( cor, pre ):
##
##    #print(cor)
##    
##    x,y = cor
##    px, py = pre
##
##    if griddy[x][y] == "S":
##        #special handling: custom from test input
##        return explore( [x,y+1], [0, 1] )
##        
##    else:
##        dx, dy = guide[ griddy[x][y] ]
##        
##        dx += px
##        dy += py
##
##        nx = x + dx
##        ny = y + dy
##
##        if griddy[nx][ny] == "S":
##            return 1 #just the current spot
##        else:
##            return 1 + explore( [nx, ny], [dx, dy] )

### grrr iterative
cnt = 0
cur = [cur[0], cur[1]+1]
pre = [0, 1]

while griddy[cur[0]][cur[1]] != "S":
    cnt += 1

    x,y = cur
    px, py = pre

    dx, dy = guide[ griddy[x][y] ]

    dx += px
    dy += py

    nx = x + dx
    ny = y + dy

    cur = [nx, ny]
    pre = [dx, dy]

print(cnt)
print( (cnt+1)//2 )

    

##k = explore(cur, [0,0]) 

##print( k )
##print( (k+1)//2 )
