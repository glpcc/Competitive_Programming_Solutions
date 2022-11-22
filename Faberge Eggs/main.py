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
    if m*n != 0 and n > 2 and m > 1 and m>n:
        test_height(n-1,m-1)
        test_height(n,m-1)

n = 2
m = 4
print(height(n,m))

# test_list = []
# result = 0
# for x,y in test_dict:
#     print(x,y,':',test_dict[(x,y)])

def test_height2(n,m):
    if n*m == 0:
        return 0
    if m == 1:
        return 1
    if n == 1:
        return m
    if n == 2:
        return (m*(m+1))/2
    if m<=n:
        return 2**m - 1
    pascal_tree_dict = {(n,m):1}
    result = 1
    for i in range(1,m-2):
        new_pascal_tree = dict()
        new_m = m-i
        min_range = i-(n-2)
        min_range = min_range*(min_range > 0)
        max_range = i-(m-n)
        max_range = (i+1) - max_range*(max_range > 0)
        for j in range(min_range,max_range):
            new_n = (n-i) + j
            pascal_value = pascal_tree_dict.get((new_n+1,new_m+1),0) + pascal_tree_dict.get((new_n,new_m+1),0)
            if new_n == 2:
                result += int(pascal_value*((new_m*(new_m+1))//2))
            elif new_n == new_m:
                result += int(pascal_value*int(2**(new_m)-1))
            else:
                result += pascal_value
                new_pascal_tree[(new_n,new_m)] = int(pascal_value)
        if len(new_pascal_tree) == 0:
            return result
        pascal_tree_dict = new_pascal_tree
    return result

print(test_height2(n,m))



