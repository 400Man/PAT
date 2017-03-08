# n,p,r = 10,1.8,1.0
# s = ['3 2 3 5','1 9','1 4','1 7','0','2 6 1','1 8','0','0','0']

n,p,r = map(float,input().split())
n=int(n)
s = [input() for i in range(n)]

inp = [list(map(int,x.split())) for x in s]

node = [[] for i in range(n)]

for index,ele in enumerate(inp):
	node[index]+=ele[1:]

minDepth = n
count = 0

def dfs(root,depth=0):
	global minDepth,count
	if(len(node[root])==0):
		if(depth<minDepth):
			minDepth=depth
			count=1
		elif(depth==minDepth):
			count+=1
	for child in node[root]:
		dfs(child,depth+1)

dfs(0)
print("%.4f %d" % (p*pow(1+r*0.01,count),count))


from heapq import heappush, heappop
heap = []
data = [1, 3, 5, 7, 9, 2, 4, 6, 8, 0]
for item in data:
     heappush(heap, item)