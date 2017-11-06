
# n=8
# inorder = list(map(int,'12 11 20 17 1 15 8 5'.split()))
# postorder = list(map(int,'12 20 17 11 15 8 5 1'.split()))

n=int(input())
inorder = list(map(int,input().split()))
postorder = list(map(int,input().split()))


l = [[] for i in range(n)]

class Node:
	def __init__(self,x):
		self.val = x
		self.left = None
		self.right = None

	def level(self,depth=0):
		l[depth].append(self.val)
		if(self.left):
			self.left.level(depth+1)
		if(self.right):
			self.right.level(depth+1)



def build(inorder,postorder):
	if(inorder):
		k = inorder.index(postorder.pop())
		root=Node(inorder[k])
		root.right = build(inorder[k+1:],postorder)
		root.left = build(inorder[:k],postorder)
		return root

root = build(inorder,postorder)
root.level()
ans = []
for index,ele in enumerate(l):
	if(index%2==0):
		ans.extend(ele[::-1])
	else:
		ans.extend(ele)
print(*ans)


