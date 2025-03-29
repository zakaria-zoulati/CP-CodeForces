import sys; input = sys.stdin.readline
for i in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    s = 0
    mod = int(1e9 + 7)
    for i in range(n): s += a[i]
    s %= mod
    for i in range(n):
        s -= a[i]
        ans = (ans + a[i] * s) % mod
    ans = (ans * pow(n * (n - 1) // 2, mod - 2, mod)) % mod
    print(ans)