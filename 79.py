# inp = [[3 ,2 ,3 ,5],[1 ,9],[1 ,4],[1, 7],[0 ,7],[2, 6 ,1],[1, 8],[0, 9],[0, 4],[0, 3]]
# n,p,r = 10,1.8,1.0

n,p,r = map(float,input().split())
n=int(n)
inp = [list(map(int,input().split())) for i in range(n)]

ans = 0.0
class TreeNode:
	def __init__(self,x):
		self.val = x
		self.child = []

def dfs(index,depth):
	global ans
	if(len(node[index].child)==0):
		ans += node[index].val*pow(1+r*0.01,depth)
		return None
	for i in range(len(node[index].child)):
		dfs(node[index].child[i],depth+1)

node = [TreeNode(i) for i in range(n)]

for i in range(n):
	if(inp[i][0]==0):
		node[i].val = inp[i][1]
	else:
		node[i].child.extend(inp[i][1:])

dfs(0,0)

print("%.1f" % (ans*p))
