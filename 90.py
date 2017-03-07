n,p,r = 9,1.8,1.00
inp = list(map(int,'1 5 4 4 -1 4 5 3 6'.split()))

# n,p,r = map(float,input().split())
# n = int(n)
# inp = list(map(int,input().split()))

maxDepth = 0
count = 0

root = inp.index(-1)
node = [[] for i in range(n)]

for index,ele in enumerate(inp):
	if(ele!=-1):
		node[ele].append(index)

def dfs(index,depth = 0):
	global maxDepth,count
	if(len(node[index])==0):
		if(depth>maxDepth):
			maxDepth = depth
			count=1
		elif(depth==maxDepth):
			count+=1
	for child in node[index]:
		dfs(child,depth+1)

dfs(root)
print("%.2f %d" % (p*pow(r*0.01+1,maxDepth),count))