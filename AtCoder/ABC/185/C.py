n = int(input())
ans = 1
for i in range(11):
    ans *= (n-1-i)
for i in range(11):
    ans //= i+1
print(ans)

