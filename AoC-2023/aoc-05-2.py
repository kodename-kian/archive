
#let's over-engineer this with oop
#cuz i haven't practiced oop in a while

class almanac():
    def __init__(self):
        self.name = input()
        
        self.data = []
        line = input()
        while line != "":
            self.data.append([int(k) for k in line.split()]) 
            line = input()

    def report(self):
        for i in self.data:
            print(i)

    def convert(self, val): #val is array of ranges [start, length]
        
        response = []
        
        for item in val: #item is [start, length]

            STR, LEN = item
            END = STR + LEN -1
                
            filled_gap = []
            
            for entry in self.data: #entry is [dst, src, lgt]
                
                dst, src, lgt = entry
                end = src + lgt - 1
                
                if END < src or end < STR: #entirely outside
                    pass
                else:
                    opening = max(STR, src)
                    ending = min(END, end)
                    assert( opening <= ending )

                    response.append([
                        dst + (opening-src),
                        ending-opening+1 ])

                    filled_gap.append([
                        opening,
                        ending-opening+1 ])

            dagdag = []

            filled_gap.sort()

            COUNTER = STR
            #COUNTER still needs to be placed in

            for thing in filled_gap:

                if thing[0] > COUNTER:
                    dagdag.append([COUNTER, thing[0]-COUNTER])
                    COUNTER = max(COUNTER, thing[0]+thing[1])
                else:
                    COUNTER = max(COUNTER, thing[0]+thing[1])

            if COUNTER <= END:
                dagdag.append([COUNTER, END-COUNTER+1])

            response += dagdag

            
                
        #print(self.name + ": ", response )
        return response


s = [int(x) for x in input().split(": ")[1].split() ]
l = len(s)
space = input()

ab = almanac()
bc = almanac()
cd = almanac()
de = almanac()
ef = almanac()
fg = almanac()
gh = almanac()

data = []
for i in range(0, l, 2):
    data.append( [s[i], s[i+1]] )


response = gh.convert(
    fg.convert(
        ef.convert(
            de.convert(
                cd.convert(
                    bc.convert(
                        ab.convert( data )
                        )
                    )
                )
            )
        )
    )

k = response[0][0]

for i in response:
    k = min(k, i[0])

print(k)

##bc.convert( ab.convert( data ) )
