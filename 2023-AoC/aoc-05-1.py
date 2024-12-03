
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

    def convert(self, val):
        for entry in self.data:
            dr, sr, rl = entry
            if val >= sr and val <= sr+rl-1:
                return (val-sr)+dr
        return val


##k = almanac()
##k.report()
##print(k.convert(98))  #50
##print(k.convert(99))  #51
##print(k.convert(53))  #55
##print(k.convert(10))  #10
##

s = [int(x) for x in input().split(": ")[1].split() ]
space = input()

ab = almanac()
bc = almanac()
cd = almanac()
de = almanac()
ef = almanac()
fg = almanac()
gh = almanac()

ans = []

for a in s:
    ans.append( gh.convert(
        fg.convert(
            ef.convert(
                de.convert(
                    cd.convert(
                        bc.convert(
                            ab.convert(a)
                            )
                        )
                    )
                )
            )
        )
                )
print( min(ans) )
