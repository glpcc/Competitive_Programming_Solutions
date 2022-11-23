from functools import cache
import sys
sys.setrecursionlimit(1500)


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

# n = 19477
# m = 20000
# n = 7
# m = 20
# print(height(n,m))

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
    num_ops = 0
    for i in range(1,m-2):
        new_pascal_tree = dict()
        new_m = m-i
        min_range = i-(n-2)
        min_range = min_range*(min_range > 0)
        max_range = i-(m-n)
        max_range = (i+1) - max_range*(max_range > 0)
        for j in range(min_range,max_range):
            num_ops += 1
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
            # print(num_ops)
            return result
        pascal_tree_dict = new_pascal_tree
    # print(num_ops)
    return result

def test_height4(n,m):
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
    num_ops = 0
    result = 1
    for i in range(1,m-2):
        new_pascal_tree = dict()
        new_m = m-i
        min_range = i-n+3
        min_range = min_range*(min_range > 0)
        max_range = i-m+n+2
        max_range = (i+1) - max_range*(max_range > 0)
        for j in range(min_range,max_range):
            num_ops += 1
            new_n = (n-i) + j   
            pascal_value = pascal_tree_dict.get((new_n+1,new_m+1),0) + pascal_tree_dict.get((new_n,new_m+1),0)
            if new_n == 3:
                result += pascal_value*(((new_m-1)*new_m*(new_m+1))//6 + new_m)
            elif new_m - new_n == 2:
                result += pascal_value*int(2**(new_m)-4 - new_n)    
            else:
                result += pascal_value
                new_pascal_tree[(new_n,new_m)] = pascal_value
        if len(new_pascal_tree) == 0:
            # print(num_ops)
            return result
        pascal_tree_dict = new_pascal_tree
    # print(num_ops)
    return result

def test_height3(n,m):
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
    pascal_tree_dict = [1]
    num_ops = 0
    result = 1
    for i in range(1,m-2):
        new_pascal_tree = []
        new_m = m-i
        min_range = i-n+3
        min_range = min_range*(min_range > 0)
        max_range = i-m+n+2
        max_range = (i+1) - max_range*(max_range > 0)
        for j in range(min_range,max_range):
            num_ops += 1
            new_n = (n-i) + j
            indx = j - min_range
            pascal_value = 0
            if indx - 1 >= 0:
                pascal_value += pascal_tree_dict[indx - 1]
            if j != max_range - 1:
                pascal_value += pascal_tree_dict[indx]
            if new_n == 3:
                result += pascal_value*(((new_m-1)*new_m*(new_m+1))//6 + new_m)
            elif new_m - new_n == 2:
                result += pascal_value*int(2**(new_m)-4 - new_n)    
            else:
                result += pascal_value
                new_pascal_tree.append(pascal_value)

        if len(new_pascal_tree) == 0:
            # print(num_ops)
            return result
        pascal_tree_dict = new_pascal_tree
    # print(num_ops)
    return result

from time import time
def time_function(func,n,m,times = 1):
    average = 0
    for i in range(times):
        a = time()
        func(n,m)
        b = time()
        average += (b-a)/times
    return average
n = 1000
m = 10000
n_times = 1
# print(test_height2(n,m))
# print()
# print(test_height3(n,m))
result = test_height3(n,m)
print(type(result))
assert test_height2(n,m) == result
print(time_function(test_height4,n,m,n_times))
print(time_function(test_height3,n,m,n_times))
# print(time_function(height,n,m))


