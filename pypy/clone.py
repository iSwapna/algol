#! usr/bin/python -tt
import random
from collections import deque

class Vertex(object):
    '''Vertex is a node with a value and set of neighboring nodes'''
    def __init__(self, val):
        self.val = val
        self.neighbors = set()

#clone an entire graph
#follow neighbors to clone other connected nodes using DFS
#clone only if not found in map - for O(1) lookup
def cloneGraph(g):
    cl = {}
    for v in g:
        clone(v, cl)
    return list(cl.values())

def clone(v, cl):
    if v.val in cl:
        return cl[v.val]

    cln = Vertex(v.val)
    cl[v.val] = cln
    for n in v.neighbors:
        cln.neighbors.add(clone(n, cl))
    return cln
        
    
        
if __name__ == '__main__':
    graph = []
    for n in range(1, 5):
        v = Vertex(n)
        graph.append(v)
        
    for v in graph:
        c = random.choice(range(1, 5))
        v.neighbors.update(random.sample(graph, c))        

def pprint(gr):
    print "Graph: "
    for v in gr:
        print "Node: " + str(v.val) + "-->",
        print "[",
        for n in v.neighbors:
            print str(n.val) + ",",
            
        print "]"
    
newG = cloneGraph(graph)
print "Old: " ,
pprint(graph)
print "New: " ,
pprint(newG)
    
