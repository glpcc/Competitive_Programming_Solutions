import random
f = open('demo2.in','w')
for i in range(10):
    a = random.randint(1,100000)
    f.write(f'{a}\n')
    for i in range(a):
        b = random.randint(1,100000)
        c = random.randint(1,a)
        f.write(f'{b} {c}\n')
f.write('0')