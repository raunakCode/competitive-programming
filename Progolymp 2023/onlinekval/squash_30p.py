n, k = map(int, input().split())
s = input()
a = []

def maxNonIntersectSum(A, N):
    frontKadane = []
    backKadane = [0]*N
    sum1 = 0
    sum2 = 0
    result = 0

    frontKadane.append(0)
    backKadane.append(0)
    for i in range(N):
        sum1 += A[i]
        sum2 = max(sum1, sum2)
        sum1 = max(sum1, 0)
        frontKadane.append(sum2)

    sum1 = 0
    sum2 = 0
    for i in range(N-1, 0, -1):
        sum1 += A[i]
        sum2 = max(sum1, sum2)
        sum1 = max(sum1, 0)
        backKadane[i] = sum2
    for i in range(N+1):
        result = max(result, backKadane[i] + frontKadane[i])
    return result

for i in s:
    a.append(i)
if a.count('F') == len(a):
    print(0)
else:
    while a[len(a) - 1] == 'F':
            a.pop()
    a.reverse()
    while a[len(a) - 1] == 'F':
        a.pop()
    l = []
    for i in a:
        if i == 'V':
            l.append(1)
        else:
            l.append(-1)
    if k == 1:
        maxSub = l[0];
        curSum = 0
        for n in l:
            if curSum < 0:
                curSum = 0
            curSum += n
            maxSub = max(maxSub, curSum)
        print(maxSub)
    elif k == 2:
        print(maxNonIntersectSum(l, len(l)))
