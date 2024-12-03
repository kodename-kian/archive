###
#  ICPC North America Qualifiers
#  10/5/24
#
#  Problem C - Call for Problems
#  AC
# 
#  @author Kian Chua
##

n = int(input())

ans = 0

for i in range(n):
    d = int(input())
    ans += d%2

print(ans)
    
