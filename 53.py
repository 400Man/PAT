# n,m,w=20, 9, 24
# weight = list(map(int,'10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2'.split()))
# inp = ['00 4 01 02 03 04','02 1 05','04 2 06 07','03 3 11 12 13','06 1 09','07 2 08 10','16 1 15','13 3 14 16 17','17 2 18 19']

n,m,w = map(int,input().split())
weight = list(map(int,input().split()))
inp=[input() for i in range(m)]

graph = [[] for i in range(n)]
ans=[]

for ele in inp:
	ele = list(map(int,ele.split()))
	graph[ele[0]].extend(ele[2:])

def dfs(root,weight_sum,route):
	for node in graph[root]:
		if(graph[node]):
			dfs(node,weight_sum+weight[node],route+[node])
		else:
			dfs(node,weight_sum,route)
	if(len(graph[root])==0):
		ans.append([route+[root],weight_sum+weight[root]])

dfs(0,weight[0],[0])
for i in range(len(ans)):
	ans[i][0] = list(map(lambda x:weight[x],ans[i][0]))

ans.sort(reverse = True)
for key,val in ans:
	if(val==w):
		print(*key)



