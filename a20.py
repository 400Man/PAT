
class treeNode:
	def __init__(self,x):
		self.val = x
		self.left = None
		self.right = None

lis_lev = []

class Tree:
	def level(self,root):
		lev = []
		if(root):
			lev.append(root)
			while(len(lev)!=0):
				node = lev.pop(0)
				lis_lev.append(node.val)
				if(node.left!=None):
					lev.append(node.left)
				if(node.right!=None):
					lev.append(node.right)

	def leveldata(self,root):
		ans = []
		def bfs(root,level):
			if(root):
				if(len(ans)<level+1):
					ans.append([])
				ans[level].append(root.val)
				bfs(root.left,level+1)
				bfs(root.right,level+1)
		bfs(root,0)
		return ans

	def build(self,inOrder,postOrder):
		if(inOrder):
			k = inOrder.index(postOrder.pop())
			root = treeNode(inOrder[k])
			root.right = self.build(inOrder[k+1:],postOrder)
			root.left = self.build(inOrder[:k],postOrder)
			return root
	
	def reverse(self,root):
		if(root):
			root.left,root.right = self.reverse(root.right),self.reverse


_=input()
postOrder = list(map(int,input().split()))
inOrder= list(map(int,input().split()))
root = Tree().build(inOrder,postOrder)
Tree().level(root)
# print(*lis_lev)
Tree().reverse(root)
print(Tree().leveldata(root))