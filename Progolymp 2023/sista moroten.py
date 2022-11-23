import sys
sys.setrecursionlimit(10000000)
n = int(input("Tärningar? "))
m = int(input("sidor M? "))
k = int(input("Utfall k? "))

dp = [[-1 for _ in range(10000)] for _ in range(100)]
def NoofWays(face, throws, sum):
    if (sum == 0 and throws == 0):
        return 1
    if (sum < 0 or throws == 0):
        return 0
    if (dp[throws][sum] != -1):
        return dp[throws][sum]
    ans = 0
    for i in range(1, face+1):
        ans += NoofWays(face, throws-1, sum-i)
    dp[throws][sum] = ans
    return ans

values = []
for i in range(3, m*n+1):
    values.append(NoofWays(m, n, i)/(m**n))
values.sort(reverse=True)
ans = 0
for i in range(k):
    ans += values[i]
print(ans)
n = int(input("Answered"))