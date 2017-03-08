
class Node:
	def __init__(self,x):
		self.data = x
		self.left = None
		self.right = None

	def insert(self,data):
		if(self.data):
			if(data < self.data):
				if(self.left!=None):
					self.left.insert(data)
				else:
					self.left = Node(data)
			else:
				if(self.right!=None):
					self.right.insert(data)
				else:
					self.right = Node(data)
		else:
			self.data = data

	def preOrder(self):
		pre_order.append(self.data)
		if(self.left):
			self.left.preOrder()
		if(self.right):
			self.right.preOrder()
	def mi_preOrder(self):
		mi_pre_order.append(self.data)
		if(self.right):
			self.right.mi_preOrder()
		if(self.left):
			self.left.mi_preOrder()

	def postOrder(self):
		if(self.left):
			self.left.postOrder()
		if(self.right):
			self.right.postOrder()
		post_order.append(self.data)
	def mi_postOrder(self):
		if(self.right):
			self.right.mi_postOrder()
		if(self.left):
			self.left.mi_postOrder()
		mi_post_order.append(self.data)

# inp = list(map(int,'8 6 5 7 10 8 11'.split()))
_ = input()
inp = list(map(int,input().split()))

root = Node(inp[0])

for ele in inp[1:]:
	root.insert(ele)

pre_order = []
mi_pre_order = []
post_order = []
mi_post_order = []

root.preOrder()
root.postOrder()
root.mi_postOrder()
root.mi_preOrder()

if(pre_order==inp):
	print('YES')
	print(*post_order)
elif(inp==mi_pre_order):
	print('YES')
	print(*mi_post_order)
else:
	print('NO')


