def height(n, m): #the answer is c(m ,1) + c(m, 2) + ... + c(m, n).
    combs = [1]
    for i in range(n): combs.append(combs[-1]*(m-i)//(i+1)) #calculating all the combinations needed.
    return sum(combs[1:])

print(height(3,2))