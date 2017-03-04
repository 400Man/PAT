class TreeNode:
	def __init__(self,x):
		self.val = x
		self.left = None
		self.right = None

lev_list = []
in_list = []

class Tree:
	def level(self,root):
		if(root):
			que = []
			que.append(root)
			while(que):
				node = que.pop(0)
				lev_list.append(node.val)
				if(node.left!=None):
					que.append(node.left)
				if(node.right!=None):
					que.append(node.right)
	def inOrder(self,root):
		if(root):
			self.inOrder(root.left)
			in_list.append(root.val)
			self.inOrder(root.right)
	def reverse(self,root):
		if(root):
			root.left,root.right = self.reverse(root.right),self.reverse(root.left)
		return root

n = int(input())
flag = [0]*n

node = [TreeNode(i) for i in range(n)]


for i in range(n):
	l,r = input().split()
	if(l!='-'):
		flag[int(l)]=1
		node[i].left=node[int(l)]
	if(r!='-'):
		flag[int(r)]=1
		node[i].right=node[int(r)]

root = node[flag.index(0)]
Tree().reverse(root)
Tree().level(root)
Tree().inOrder(root)
print(*lev_list)
print(*in_list)





