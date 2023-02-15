import cProfile
import pstats


def calculate1(pascal_val,m):
    return pascal_val*(((m-1)*m*(m+1))//6 + m)

def calculate2(pascal_val,m):
    return pascal_val*int(2**(m)-1)  

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
    pascal_tree_dict = {(n,m):1}
    num_ops = 0
    result = 1
    for i in range(1,m-2):
        new_pascal_tree = dict()
        new_m = m-i
        min_range = i-n+3
        min_range = min_range*(min_range > 0)
        max_range = i-m+n
        max_range = (i+1) - max_range*(max_range > 0)
        for j in range(min_range,max_range):
            num_ops += 1
            new_n = (n-i) + j
            pascal_value = pascal_tree_dict.get((new_n+1,new_m+1),0) + pascal_tree_dict.get((new_n,new_m+1),0)
            if new_n == 3:
                result += calculate1(pascal_value,new_m)
            elif new_n == new_m:
                result += calculate2(pascal_value,new_m)  
            else:
                result += pascal_value
                new_pascal_tree[(new_n,new_m)] = int(pascal_value)
        if len(new_pascal_tree) == 0:
            # print(num_ops)
            return result
        pascal_tree_dict = new_pascal_tree
    # print(num_ops)
    return result

n= 19000
m = 20000
with cProfile.Profile() as p:
    test_height3(n,m)

stats = pstats.Stats(p)
stats.sort_stats(pstats.SortKey.TIME)
stats.print_stats(20)