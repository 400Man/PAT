class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Tree:
    def isBalanced(self, root):
        return (self.getHeight(root) >= 0)
    
    def getHeight(self, root):
        if root is None:
            return 0
        left_height, right_height = self.getHeight(root.left), self.getHeight(root.right)
        # if left_height < 0 or right_height < 0 or abs(left_height - right_height) > 1:
        #     return -1
        return max(left_height, right_height) + 1

    def invertTree(self,root):
        if(root):
            root.left, root.right = self.invertTree(root.right), self.invertTree(root.left)
        return root
        
    def pathSum(self, root, sum):
        return self.pathSumRecu([], [], root, sum)
    
    def pathSumRecu(self, result, cur, root, sum):
        if root is None:
            return result
        
        if root.left is None and root.right is None and root.val == sum:
            result.append(cur + [root.val])
            return result
        
        cur.append(root.val)
        self.pathSumRecu(result, cur, root.left, sum - root.val)
        self.pathSumRecu(result, cur, root.right, sum - root.val)
        cur.pop()
        return result
        
if __name__ == "__main__":
    node = [None]*8
    for i in range(8):
       node[i]=TreeNode(i)

    node[0].left=node[1]
    node[2].left=node[0]
    node[3].left=node[2]
    node[3].right=node[7]
    node[6].left=node[5]
    node[7].left=node[4]
    node[7].right=node[6]

    root = node[3]

    result = Tree().isBalanced(root)
    print(result)
    # print(node[6].left.val)

    print(Tree().getHeight(root))


    print(Tree().pathSum(root, 14))





