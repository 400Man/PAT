
# n,k = 5, 6
# inp1 = ['310101 98 85 88','310102 70 95 88','310103 82 87 94','310104 91 91 91','310105 85 90 90']
# req = ['310101','310102','310103','310104','310105','999999']

n,k = map(int,input().split())
inp1 = [input() for i in range(n)]
req = [input() for i in range(k)]

dic = {}
score = [[] for i in range(4)]
for ele in inp1:
	ele = list(map(int,ele.split()))
	s = [sum(ele[1:]),ele[1],ele[2],ele[3]]
	dic[ele[0]] = s
	for index in range(4):
		score[index].append(s[index])
for index in range(4):
	score[index].sort(reverse = True)

ans=[]
for stu in req:
	MIN = pow(10,9)
	sub = 0
	if(dic.get(int(stu))):
		for subject in range(4):
			num = score[subject].index(dic[int(stu)][subject])
			if(num<MIN):
				MIN = num
				sub = subject
		ans.append([MIN+1,'ACME'[sub]])
	else:
		ans.append('N/A')

for ele in ans:
	if(ele =='N/A'):
		print('N/A')
	else:
		print(*ele)

