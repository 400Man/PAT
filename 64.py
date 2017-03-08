# n = int(input())
# inp = list(map(int,input().split()))

n = 10
inp = list(map(int,'1 2 3 4 5 6 7 8 9 0'.split()))


inp.sort()

ans =[None]*(n+1)

def inOrder(index=1):
	global n
	if(index>n):
		return None
	inOrder(index*2)
	ans[index]=inp.pop(0)
	inOrder(index*2+1)

inOrder()

print(*ans[1:])


