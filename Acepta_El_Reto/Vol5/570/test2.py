a = [0,0,0,0]
while a[0] != 10:
    a[-1] += 1
    for i in range(1,len(a)):
        if a[-i] == 10:
            a[-i] = 0
            a[-i-1] += 1
    print(a)

 