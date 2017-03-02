
n = int(input())
inOrder = list(map(int,input().split()))
postOrder = list(map(int,input().split()))

class TreeNode:
	def __init__(self,x):
		self.evl = x
		self.left = None
		self.right = None



def buildTree(preOrder,inOrder):
	root = TreeNode(preOrder[0])
	pos = inOrder.index(preOrder[0])



for i in range(postOrder):

