# n,l=7, 3
n,l = map(int,input().split())

# inp = ['3 2 3 4','0','2 5 6','2 3 1','2 3 4','1 4','1 5']
inp = [input() for i in range(n)]
n+=1
# que = list(map(int,'2 2 6'.split()))[1:]
que = list(map(int,input().split()))[1:]

graph = [[] for i in range(n)]

for index,ele in enumerate(inp):
	if(ele!='0'):
		ele = list(map(int,ele.split()))[1:]
		for e in ele:
			graph[e].append(index+1)

def bfs(root,level=0):
	global l,count
	if(level>l):
		return
	if(flag[root]==0):
		count+=1
		flag[root]=1
	for node in graph[root]:
		bfs(node,level+1)

ans=[]
for ele in que:
	count = 0
	flag = [0]*n
	bfs(ele)
	ans.append(count-1)
for ele in ans:
	print(ele)
# print(graph)