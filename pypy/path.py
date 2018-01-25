#! usr/bin/python -tt

import random
from collections import deque

class Vertex(object):
    '''Vertex is a node with a value and set of neighboring nodes'''
    def __init__(self, val):
        self.val = val
        self.neighbors = set()
        
#terminate search as soon as we see end node
def shortPath(start, end):
    backRefs = {start: None}
    q = deque()
    q.appendleft(start)
    endNotFound = True
    while(len(q) and endNotFound):
        curr = q.pop()
        if curr == end:
            break
        for n in curr.neighbors:
            print "in for: " + str(n.val)
            if n not in backRefs:
                backRefs[n] = curr
                if n == end:
                    print "end found: " + str(n.val)
                    endNotFound = False
                    break
                q.appendleft(n)
    # no path found
    if end not in backRefs:
        return []

    curr = end
    path = []
    while curr is not None:
        path.append(curr.val)
        curr = backRefs[curr]

    path.reverse()
    return path

if __name__ == '__main__':
    graph = []
    for n in range(1, 16):
        v = Vertex(n)
        graph.append(v)
        
    for v in graph:
        c = random.choice(range(1, 6))
        v.neighbors.update(random.sample(graph, c))        
    
#    for v in graph:
end = random.choice(graph)
path = shortPath(v, end)
print "Path from: " + str(v.val) + "-->" + str(end.val) \
    + " " + str(path)

    
    
