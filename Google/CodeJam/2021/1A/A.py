import math
def solve(prob):
    n = int(input())
    X = list(map(int, input().split()))
    ans = 0
    for i in range(n):
        if i == 0:
            continue
        if X[i] > X[i-1]:
            continue
        prev = X[i-1]+1
        d1 = int(math.log10(prev)+1)
        d2 = int(math.log10(X[i])+1)
        pw = 1
        for j in range(d1-d2):
            prev //= 10
            pw *= 10
        if prev < X[i]:
            X[i] *= pw
            ans += d1-d2
        elif prev == X[i]:
            X[i] = X[i-1]+1
            ans += d1-d2
        else:
            X[i] *= pw * 10
            ans += d1-d2+1
    print("Case #{}: {}".format(prob+1, ans))

t = int(input())
for i in range(t):
    solve(i)
