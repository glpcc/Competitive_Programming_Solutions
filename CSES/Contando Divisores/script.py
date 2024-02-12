max_n = int(1e6)

nums = [0] * ( max_n + 1)
for i in range(2, max_n//2 + 10):
    for j in range(i, max_n+1, i):
        nums[j] += 1
result = ''
cases = int(input())
for i in range(cases):
    n = int(input())
    if n >= max_n//2 + 10:
        print(nums[n]+ 2)
    else:
        print(nums[n]+ 1)