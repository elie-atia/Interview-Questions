'''Python3 program to print DFS traversal for complete graph'''
from collections import defaultdict
 
# this class represents a directed graph using adjacency list representation
 
 
class Graph:
    # Constructor
    def __init__(self):
        # default dictionary to store graph
        self.graph = defaultdict(list)
 
    # Function to add an edge to graph
    def addEdge(self, u, v):
        self.graph[u].append(v)
    # A function used by DFS
 
    def DFSUtil(self, v, visited):
        # Mark the current node as visited and print it
        visited.add(v)
        print(v, end=" ")
 
    # recur for all the vertices adjacent to this vertex
        for neighbour in self.graph[v]:
            if neighbour not in visited:
                self.DFSUtil(neighbour, visited)
    # The function to do DFS traversal. It uses recursive DFSUtil
 
    def DFS(self):
        # create a set to store all visited vertices
        visited = set()
    # call the recursive helper function to print DFS traversal starting from all
    # vertices one by one
        for vertex in list(self.graph.keys()):
            if vertex not in visited:
                self.DFSUtil(vertex, visited)
# Driver's code
# create a graph given in the above diagram
 
 
if __name__ == "__main__":
    print("Following is Depth First Traversal \n")
    g = Graph()
    g.addEdge(1, 2)
    g.addEdge(2, 3)
    g.addEdge(3, 6)
    g.addEdge(6, 9)
    g.addEdge(9, 8)
    g.addEdge(8, 7)
    g.addEdge(7, 4)
    g.addEdge(4, 1)
    g.addEdge(2, 5)
    g.addEdge(6, 5)
    g.addEdge(8, 5)
    g.addEdge(4, 5)
    
    
 
    # Function call
    g.DFS()
 
# This code is contributed by Priyank Namdeo