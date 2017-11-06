# n,m = 7,12
# inp = ['5 7','1 2','1 3','2 3','2 4','3 4','5 2','7 6','6 3','4 5','6 4','5 6']

n,m = map(int,input().split())
inp = [input() for i in range(m)]

h = [0]*(n+1)
for ele in inp:
	a,b = map(int,ele.split())
	h[a]+=1
	h[b]+=1
ans = [0 if(ele%2==0) else 1 for ele in h ]
u=sum(ans)
print(*h[1:])
if(u==0):
	print('Eulerian')
elif(u==2):
	print('semi-Eulerian')
else:
	print('semi-Eulerian')

