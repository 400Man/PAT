
class Node:
	def __init__(self):
		self.val = None
		self.left = None
		self.right = None

	def inOrder(self):
		if(self.left):
			self.left.inOrder()
		root.val=inp.pop(0)
		if(self.right):
			self.right.inOrder()

n = 9

tree = ['1 6',
'2 3',
'-1 -1',
'-1 4',
'5 -1',
'-1 -1',
'7 -1',
'-1 8',
'-1 -1']

inp1=[]

for ele in tree:
	inp1.append(list(map(int,ele.split())))

node = [Node() for i in range(n)]
for i in range(n):
	if(tree[i][0]!=-1):
		node[i].left = inp1[i][0]
	if(tree[i][1]!=-1):
		node[i].right = inp1[i][1]

inp = sorted(list(map(int,'73 45 11 58 82 25 67 38 42'.split())))

node[0].inOrder()
