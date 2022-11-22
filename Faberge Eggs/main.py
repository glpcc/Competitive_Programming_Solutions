from functools import cache

@cache
def height(n,m):
    if n*m == 0:
        return 0
    if m == 1:
        return 1
    if n == 1:
        return m
    if n == 2:
        return (m*(m+1))/2
    elif m<=n:
        return 2**m - 1
    else:
        return 1+height(n-1,m-1)+height(n,m-1)

# print(height(5,7))

test_dict = dict()
def test_height(n,m):
    if (n,m) in test_dict:
        test_dict[(n,m)] += 1
    else:
        test_dict[(n,m)] = 1
    if m*n != 0 and n > 2 and m > 1:
        test_height(n-1,m-1)
        test_height(n,m-1)

n = 5
m = 7
print(test_height(n,m))

test_list = []
result = 0
for x,y in test_dict:
    if y == 1 :
        # test_list.append(test_dict[(x,y)])
        print(x,y,':',test_dict[(x,y)],test_dict[(x,y)]/(2))
    

def combinatory(n,m):

def test2_height()