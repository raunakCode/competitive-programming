import sys
n = int(input())
adj = []
for i in range(n+1):
    adj.append([])
    adj[i].append(0)

for j in range(n-1):
    a,b = map(int,input().split())
    adj[a].append(b)
    adj[b].append(a)

def eagle(node, speed, oriNode):
    adj[node][0] += speed
    if len(adj[node]) - 1 >= 2:
        if (oriNode == -1):
            spreadValue = speed/(len(adj[node])-1)
        elif (oriNode != -1):
            spreadValue = speed / (len(adj[node]) - 2)
    else:
        spreadValue = speed
    for k in range(1,len(adj[node])):
        if (adj[node][k] != oriNode):
            eagle(adj[node][k], spreadValue, node)

if (len(adj[1]) == 2 and len(adj[len(adj)-1]) == 2):
    amount = 0
    for i in range(2,len(adj)-1):
        if ((adj[i][1] == i-1 and adj[i][2] == i+1) or (adj[i][1] == i+1 and adj[i][2] == i-1)) and len(adj[i]) == 3:
            amount += 1
    if amount == len(adj) - 3:
        p = int(input())
        for r in range(p):
            x, y = map(int, input().split())
            if (x != 1 and x != len(adj)-1):
                adj[x][0] += y
                for q in range(1,len(adj)):
                    if (q != x):
                        adj[q][0] += y/2
            elif (x == 1 or x == len(adj)-1):
                for q in range(1,len(adj)):
                    adj[q][0] += y
        for o in range(1, len(adj)):
            print(adj[o][0])
        sys.exit()
else:
    p = int(input())
    for r in range(p):
        x,y = map(int, input().split())
        eagle(x,y,-1)

    for q in range(1, len(adj)):
        print(adj[q][0])