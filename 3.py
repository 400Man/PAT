MAXV = 510
INF = pow(10,10)

def Dijkstra(s):
	dis[s],w[s],num[s] = 0,weight[s],1

	for i in range(n):
		for index,ele in enumerate(dis):
			MIN,u = INF, -1
			if(vis[index]==False and dis[index]<MIN):
				MIN = dis[index]
				u = index
			if(u==-1): 
				return

			vis[u] = True
			for v in range(n):
				if(vis[v]==False and G[u][v]!=INF):
					if(dis[u]+G[u][v]<dis[v]):
						dis[v]=dis[u]+G[u][v]
						w[v]=w[u]+weight[v]
						num[v]=num[u]
					elif(dis[u]+G[u][v]==dis[v]):
						if(w[u]+weight[v]>w[v]):
							w[v]=w[u]+weight[v]
					num[v] += num[u]

G = [[INF]*MAXV for i in range(MAXV)]
vis = [False]*MAXV
dis = [INF]*MAXV
num,w = [[None]*MAXV]*2

n,m,st,ed = 5,6,0,2
weight = 1, 2, 1, 5, 3
inp = ['0 1 1','0 2 2','0 3 1','1 2 1','2 4 1','3 4 1']
for ele in inp:
	a,b,c = map(int,ele.split())
	G[a][b],G[b][a] = c,c

Dijkstra(st)
print(num[ed],w[ed])