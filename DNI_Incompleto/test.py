test_dni = 0
test2 = '?87?54??'

vals = []
interger_pos = []
for j,i in enumerate(test2):
    print(test_dni)
    if i == '?':
        test_dni *= 10
        vals.append(0)
        interger_pos.append(len(test2)-(j+1))
    else:
        test_dni += int(i)
        test_dni *= 10
test_dni = test_dni // 10
print(test_dni)
print(vals)
print(interger_pos)
count = 0
test_int = 0
while vals[0] < 10:
    temp = test_dni
    for i,v in enumerate(vals):
        temp += v*(10**interger_pos[len(interger_pos)-i-1])
    #print(temp)
    if temp % 23 == 20:
        count += 1
        print(temp-test_dni)
    test_int += 1
    vals[-1] += 1
    for i in range(1,len(vals)):
        if vals[-i] == 10:
            vals[-i-1] += 1
            vals[-i] = 0

print(count)
print(test_int)