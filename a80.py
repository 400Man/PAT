n,m,k = list(map(int,input().split()))
left = list(map(int,input().split()))
candidate = []
school = [[] for i in range(m)]
school_last_score = [[0,0] for i in range(m)]

for i in range(n):
	u = list(map(int,input().split()))
	u.append(i)
	candidate.append(u)

def candidate_sort(candidate):
	return (candidate[0]+candidate[1],candidate[0])

candidate.sort(key=candidate_sort,reverse=True)

for i in range(n):
	for j in range(k):
		sch = candidate[i][j+2]
		if(left[sch]>0):
			left[sch]-=1
			if(left[sch]==0):
				school_last_score[sch][0]=candidate[i][0]
				school_last_score[sch][1]=candidate[i][1]
			school[sch].append(candidate[i][k+2])
			break
		if(school_last_score[sch][0]==candidate[i][0] and school_last_score[sch][1]==candidate[i][1]):
			school[sch].append(candidate[i][k+2])

for ele in school:
	ele.sort()
	print(*ele)
