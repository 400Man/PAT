n = 8
inp = ['3: 2 7 10','1: 4','2: 5 3','1: 4','1: 3','1: 4','4: 6 8 1 5','1: 4']
# n = int(input())
# inp = [input() for i in range(n)]
ans = []

for ele in inp:
	new = list(map(int,ele[3:].split()))
	find = 0
	for s in ans:
		if(find==1):
			break
		for num in new:
			if(num in s[0]):
				find = 1
				[s[0].add(n) for n in new]
				s[1]+=1
				break
	if(find==0):
		ans.append([set(),1])
		[ans[-1][0].add(n) for n in new]
print(ans)

# u = []
# for ele in ans:
# 	u.append(ele[1])
# print(len(u))
# print(*sorted(u,reverse=True))


