#!/usr/bin/python -tt

''' Use 2 stacks to get min in stack in O(1) '''
class MinStack:

    def __init__(self):
        self.stk = []
        self.minVal = []

    def push(self, val):
        '''push a val to stack'''
        if len(self.stk) and self.stk[-1] > val:
            self.minVal.append(val)
        elif not self.minVal:
            self.minVal.append(val)
        self.stk.append(val)

    def pop(self):
        '''pop top element from stack'''
        if self.stk:
            if self.stk[-1] == self.minVal[-1]:
                self.minVal.pop()
            self.stk.pop()

    def top(self):
        '''peek at top element of stack'''
        return self.stk[-1]

    def minV(self):
        '''min value in the stack'''
        if self.minVal:
            return self.minVal[-1]
    
def main():
    ms = MinStack()
    ms.push(10)
    print  str(ms.minV())
    print "top: " + str(ms.top())
    ms.push(12)
    ms.push(11)
    ms.push(3)
    print "min: " + str(ms.minV())
    print "top: " + str(ms.top())
    ms.pop()
    print "min: " + str(ms.minV())
    print "top: " + str(ms.top())
    ms.pop()
    ms.pop()
    ms.pop()
    ms.pop()
    print "min: " + str(ms.minV())
if __name__ == "__main__":
    main()
