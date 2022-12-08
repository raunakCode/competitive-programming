import sys
sys.setrecursionlimit(10000000)

def dfs1(node, length):
    vis1[node] = 1
    if len(graph[node]) == 1:
        return length+1
    for i in graph[node]:
        if vis1[i] == 0:
            return dfs1(i, length+1)

def solve1():
    vis1[0] = 1
    for node in graph[0]:
        ans1.append(dfs1(node, 0))
    cur = 1
    ans1.sort(reverse=True)
    for x in ans1:
        for i in range(x):
            print(cur, end=' ')
        cur += 1

n = int(input())
graph = [[] for i in range(n)]
for _ in range(n-1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
vis1 = [0 for i in range(100005)]
ans1 = []
solve1()