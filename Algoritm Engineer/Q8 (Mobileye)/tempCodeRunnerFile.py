class Node:
    def __init__(self, data, leftNode=None, rightNode=None):
        self.leftNode = leftNode
        self.rightNode = rightNode  
        self.data = data


n1 = Node(1)
n2 = Node(2)
n3 = Node(3,n1,n2)
print(n3.leftNode.data)




