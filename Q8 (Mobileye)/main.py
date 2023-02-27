class Node:
    def __init__(self, data=None):
        self.leftNode = None
        self.rightNode = None  
        self.data = data


        # Insert Node
    def insert(self,data):
            if(self.data):
                if(data < self.data):
                    if(self.leftNode is None):
                        self.leftNode = Node(data)
                    else:
                        self.leftNode.insert(data)
                else:
                    if(self.rightNode is None):
                        self.rightNode = Node(data)
                    else:
                        self.rightNode.insert(data)
            else:
                self.data = data


    def printTree(self):
            if(self.leftNode):
                self.leftNode.printTree()
            print(self.data)
            if(self.rightNode):
                self.rightNode.printTree()



n1 = Node()
n1.insert(4)
n1.insert(3)
n1.insert(5)
n1.insert(2)
n1.insert(1)

n1.printTree()




