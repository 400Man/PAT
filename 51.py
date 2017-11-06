
# m,n,k=5, 7, 5
# inp = ['1 2 3 4 5 6 7','3 2 1 7 5 6 4','7 6 5 4 3 2 1','5 6 4 3 7 2 1','1 7 6 5 4 3 2']

m,n,k = map(int,input().split())
inp = [input() for i in range(k)]


lis = [list(map(int,ele.split())) for ele in inp]
ans = []

for l in lis:
	j = 0
	s = []
	for i in range(1,n+1):
		if(len(s)<m):
			s.append(i)
		while(len(s)!=0 and s[-1]==l[j]):
			u = s.pop()
			if(j<n-1):
				j += 1
	if(len(s)!=0):
		ans.append('NO')
	else:
		ans.append('YES')
for ele in ans:
	print(ele)
