n = int(input())

def fact(n):
    if n == 1:
        return 1
    return n * fact(n - 1)

def comb(k, n):
    rs = 1
    for i in range(k):
        rs *= (n - i)
    rs /= fact(k)
    return rs  

rs = 0
for i in range(5, 8):
    rs += int(comb(i, n))

print(rs)
