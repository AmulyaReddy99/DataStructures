n=int(input("Nodes? "))
connections,visited,temp=[],[],[]
for _ in range(n):
	connections.append([])

edges=int(input("Edges? \n"))
for _ in range(edges):
	x=list(map(int,input().split(' ')))
	connections[x[0]-1].append(x[1]-1)
	connections[x[1]-1].append(x[0]-1)

print(connections)

t=int(input("Starting node? "))-1
visited.append(t); 

for t in visited:
	for i in connections[t]: 
		visited.append(i)
	for i in visited:
		for each in connections: 
			if i in each: each.remove(i)

print(visited)