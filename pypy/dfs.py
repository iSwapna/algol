#! usr/bin/python -tt
import random
from collections import deque

class Vertex(object):
    '''Vertex is a node with a value and set of neighboring nodes'''
    def __init__(self, val):
        self.val = val
        self.neighbors = set()

visited = set()
def dfs(v):
    if v in visited:
        return
    print "visiting: " + str(v.val) + "with " \
                  + str(len(v.neighbors)) + " neighbors"
    visited.add(v)
    for neighbor in v.neighbors:
        dfs(neighbor)


def bfs(v):
    seen = set()
    q = deque()
    q.appendleft(v)
    
    while len(q):
        curr = q.pop()
        if curr in seen:
            continue
        print "bfs visit of node: " + str(curr.val)
        seen.add(curr)
        for n in curr.neighbors:
            print " -- neighbors: " + str(n.val)
            q.appendleft(n)
            

if __name__ == '__main__':
    graph = []
    for n in range(1, 11):
        v = Vertex(n)
        graph.append(v)
        
    for v in graph:
        c = random.choice(range(1, 4))
        v.neighbors.update(random.sample(graph, c))        
    
    for n in range(len(graph)):
        print "DFS starting at node: " + str(n+1)
        dfs(graph[n])
        print 

    for n in range(len(graph)):
        print " BFS from node: " + str(n+1)
        bfs(graph[n])
        print

                          
        
    
    
