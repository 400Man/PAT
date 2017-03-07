# s = ['21 1 23','01 4 03 02 04 05','03 3 06 07 08','06 2 12 13','13 1 21','08 2 15 16','02 2 09 10','11 2 19 20','17 1 22','05 1 11','07 1 14','09 1 17','10 1 18']
# n,m = 23,13

n,m = map(int,input().split())
s = [input() for i in range(m)]

n+=1
inp = [list(map(int,x.split())) for x in s]
node = [[] for i in range(n)]

for index,ele in enumerate(inp):
	node[ele[0]].extend(ele[2:])

leaves = [0]*n
maxDepth=0

def dfs(root,depth = 0):
	global leaves,maxDepth
	if(len(node[root])==0):
		if(depth>maxDepth):
			maxDepth=depth
		leaves[depth]+=1
	for child in node[root]:
		dfs(child,depth+1)

dfs(1)

print(*leaves[:maxDepth+1])

