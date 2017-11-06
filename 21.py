
n = int(input())

# inp1 = ['1 2','1 3','1 4','2 5']
inp1 = [input() for i in range(n-1)]
n+=1
inp = []
graph = [[] for i in range(n)]
for ele in inp1:
	a,b = map(int,ele.split())
	graph[a].append(b)
	graph[b].append(a)

def getHight(root,hight=0):
	global maxHight
	if(len(graph[root])==0):
		return 0
	if(flag[root]==1):
		return None
	flag[root]=1
	if(hight>maxHight):
		maxHight = hight
	for ele in graph[root]:
		getHight(ele,hight+1)
	return maxHight

def graphCheck():
	def bfs(root):
		if(flag[root]==1):
			return
		flag[root]=1
		for ele in graph[root]:
			bfs(ele)
	k = 0
	flag = n*[0]
	for i in range(1,n):
		if(flag[i]==0):
			bfs(i)
			k+=1
	return k

ans = []
for i in range(1,n):
	flag = n*[0]
	maxHight=0
	ans.append(getHight(i))

k=graphCheck()
if(k!=1):
	print('Error: %d components'%(k))
else:
	maxAns = max(ans)
	maxAns_li = []
	for index,ele in enumerate(ans):
		if(ele==maxAns):
			print(index+1)


