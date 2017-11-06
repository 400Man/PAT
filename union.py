class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0]*n
        self.size = n

    def find(self, v):
        if(v==self.parent[v]):
            return v
        else:
            return self.find(self.parent[v])
 
    def union(self, x, y):
        xRoot = self.find(x)
        yRoot = self.find(y)
        self.parent[xRoot] = yRoot

    def graph(self):
        myDict = {}
        for node in range(self.size):
            root = self.find(node)
            if not root in myDict:
                myDict[root] = set([node])
            else:
                myDict[root].add(node)
        return myDict

n=8
n+=1
inp = ['3: 2 7 10','1: 4','2: 5 3','1: 4','1: 3','1: 4','4: 6 8 1 5','1: 4']


if __name__ == '__main__':
    uf = UnionFind(11)
    for index,ele in enumerate(inp):
        ele = list(map(int,ele[3:].split()))
        print(ele)
        for e in ele:
            uf.union(index+1,e)

    #     uf.union()
    # uf.union(2,1)
    # uf.union(4,3)
    # uf.union(6,5)
    # uf.union(2,4)

    print(uf.graph())