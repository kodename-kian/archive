
s = 0
nums = ["0", "1", "2", "3",
        "4", "5", "6", "7",
        "8", "9" ]

line = input()

while line != "terminate":

    first = -1
    last = -1

    for c in line:
        if c in nums:
            if first == -1:
                first = c
                last = c
            else:
                last = c

    s += int( first+last )
    line = input()

print(s)
