
n,m,k=map(int,input().split())
n+=1
graph = [[] for i in range(n)]

for i in range(m):
	a,b=map(int,input().split())
	graph[a].append(b)
	graph[b].append(a)

check = list(map(int,input().split()))

def bfs(node,current):
	if(node==current):
		return None
	flag[node]=1
	for ele in graph[node]:
		if(flag[ele]==0):
			bfs(ele,current)

for ele in check:
	block = 0
	flag = [0]*n
	for i in range(1,n):
		if(flag[i]==0 and i!=ele):
			bfs(i,ele)
			block+=1
	print(block-1)