n=int(input("Nodes? "))
connections,visited=[],[]
for _ in range(n):
	connections.append([])

edges=int(input("Edges? \n"))
for _ in range(edges):
	x=list(map(int,input().split(' ')))
	connections[x[0]-1].append(x[1]-1)
	connections[x[1]-1].append(x[0]-1)

print(connections)

t=int(input("Starting node? "))
visited.append(t)
for each in connections: 
	if t in each: each.remove(t)
for i in range(n-1):
	t=connections[t].pop()
	for each in connections: 
		if t in each: each.remove(t)
	visited.append(t)

print(visited)