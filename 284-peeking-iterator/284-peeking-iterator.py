class PeekingIterator:
    def __init__(self, iterator):
        """
        Initialize your data structure here.
        :type iterator: Iterator
        """
        self.iterator = iterator
        self.current = self.iterator.next() if self.iterator.hasNext() else None        

    def peek(self):
        """
        Returns the next element in the iteration without advancing the iterator.
        :rtype: int
        """
        return self.current
        

    def next(self):
        """
        :rtype: int
        """
        value = self.current
        self.current = self.iterator.next() if self.iterator.hasNext() else None       
        return value
            
    def hasNext(self):
        """
        :rtype: bool
        """
        return self.current != None
      