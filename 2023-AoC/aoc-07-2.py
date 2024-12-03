

n = 1000

card = dict()
card["J"] = -9
card["2"] = 0
card["3"] = 1
card["4"] = 2
card["5"] = 3
card["6"] = 4
card["7"] = 5
card["8"] = 6
card["9"] = 7
card["T"] = 8
card["Q"] = 10
card["K"] = 11
card["A"] = 12

def rank( hand ):
    count = dict()

    Jay = 0
    
    for card in hand:
        if card == "J":
            Jay += 1
            continue
        
        if card not in count:
            count[card] = 0
        count[card] += 1

    mxC = -1
    mx = "."
    for entry in count:
        if count[entry] > mxC:
            mx = entry
            mxC = count[entry]
    if mx == ".":
        count["L"] = 5
    else:
        count[mx] += Jay

    if len(count) == 1:
        return 7
    elif len(count) == 2:
        for entry in count:
            if count[entry] == 4:
                return 6
        return 5
    elif len(count) == 3:
        for entry in count:
            if count[entry]  == 3:
                return 4
        return 3
    elif len(count) == 4:
        return 2
    elif len(count) == 5:
        return 1
            

def shouldSwap( A, B ):

    if rank(A) > rank(B):
        return True
    elif rank(A) < rank(B):
        return False
    else:
        for i in range(5):
            if card[A[i]] > card[B[i]]:
                return True
            elif card[A[i]] < card[B[i]]:
                return False
            #equal: keep going
        return False #should never trigger


deck = []

for i in range(n):
    deck.append( input().split() )

passThru = True

while passThru:
    passThru = False
    for ind in range(0, n-1):
        if shouldSwap( deck[ind][0], deck[ind+1][0] ):
            passThru = True
            deck[ind], deck[ind+1] = deck[ind+1], deck[ind]

ans = 0



for i in range(0, n):
    ans += int(deck[i][1]) * (i+1)

print(ans)
            
