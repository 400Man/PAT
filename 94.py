s = ['21 1 23','01 4 03 02 04 05','03 3 06 07 08','06 2 12 13','13 1 21','08 2 15 16','02 2 09 10','11 2 19 20','17 1 22','05 1 11','07 1 14','09 1 17','10 1 18']
n,m = 23,13

# n,m = map(int,input().split())
# s = [input() for i in range(m)]

inp = [list(map(int,x.split())) for x in s]

num = 0
n+=1
node = [[] for i in range(n)]
level = [0]*n

for i in range(m):
	node[inp[i][0]].extend(inp[i][2:])
	num += sum(inp[i][2:])

def dfs(root,depth=1):
	level[depth]+=1
	if(len(node[root])!=0):
		for child in node[root]:
			dfs(child,depth+1)

root = sum(range(n))-num
dfs(root)
print(max(level),level.index(max(level)))

print(level)