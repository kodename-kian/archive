
s = 0

nums = ["0", "1", "2", "3",
        "4", "5", "6", "7",
        "8", "9" ]
words = ["zero", "one", "two", "three", "four", "five",
         "six", "seven", "eight", "nine" ]

字典 = dict()
for i in range(10):
    字典[words[i]] = nums[i]

line = input()

while line != "terminate":

    l = len(line)
    line += "___________________"

    i = 0

    first = -1
    last = -1

    while i < l:
        if line[i] in nums:
            if first == -1:
                first = line[i]
                last = line[i]
            else:
                last = line[i]
            
        else:
            
            for j in words:
                if line[i: i+len(j)] == j:
                    if first == -1:
                        first = 字典[j]
                        last = 字典[j]
                    else:
                        last = 字典[j]
                    break

        i += 1
            
    #print(first+last)
    s += int( first+last )
    line = input()

print(s)
