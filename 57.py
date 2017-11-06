
# n = 17
# inp = ['Pop','PeekMedian','Push 3','PeekMedian','Push 2','PeekMedian','Push 1','PeekMedian','Pop','Pop','Push 5','Push 4','PeekMedian','Pop','Pop','Pop','Pop']

n = int(input())
inp = [input() for i in range(n)]

stack = []
ans = []

for ele in inp:
	lenth = len(stack)
	if(ele[1]=='o'):
		if(lenth!=0):
			ans.append(stack.pop())
		else:
			ans.append('Invalid')
	elif(ele[1]=='e'):
		if(lenth!=0):
			lis = sorted(stack)
			if(lenth%2==0):
				ans.append(lis[max(0,int(lenth/2)-1)])
			else:
				ans.append(lis[int(lenth/2)])
		else:
			ans.append('Invalid')
	else:
		stack.append(int(ele.split()[1]))

for ele in ans:
	print(ele)
	