
def dis():
	global current,currentDistance
	while True:
		for neighbour,distance in distances[current].items():
			if neighbour in visited:
				continue
			newDistance = currentDistance + distance
			if unvisited[neighbour] is None or unvisited[neighbour]>newDistance:
				unvisited[neighbour]=newDistance

			visited[current] = currentDistance
			del unvisited[current]
			if not unvisited:
				break

			candidates = [node for node in unvisited if node[1]!=None]
			current,currentDistance=sorted(candidates,key = lambda x:x[1])[0]

for node in nodes:
	unvisited = {node: None for node in nodes}
	visited = {}
	current = node
	currentDistance = 0
	unvisited[current]= currentDistance
	dis()
	print(visited)