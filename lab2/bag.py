'''
Created on Mar 11, 2019

@author: Andrea
'''

class Bag:

    # creates a new, empty Bag
    def __init__(self):
        self.elements = []
        self.frequency = []

    # adds a new element to the Bag
    '''
    Complexity: O(n);  n = nr elem unice
    '''
    def add(self, e):
        if e in self.elements:
            for i in range(0, len(self.elements)):
                if(e == self.elements[i]):
                    self.frequency[i] += 1
                    return
        else:
            self.elements.append(e);
            self.frequency.append(1);

    # removes one occurrence of an element from a Bag
    # returns True if an element was actually removed (the Bag contained the element e), or False if nothing was removed
    """
    Complexity: O(n)
    """
    def remove(self, e):
        if e in self.elements:
            for i in range(0, len(self.elements)):
                if e == self.elements[i]:
                    if (self.frequency[i] != 1):
                        self.frequency[i] -= 1
                        return True
                    else:
                        self.elements.pop(i)
                        self.frequency.pop(i)
                        return True
        else:
            return False

    # searches for an element e in the Bag
    # returns True if the Bag contains the element, False otherwise
    """
    Complexity: O(n)
    """
    def search(self, e):
        if e in self.elements:
            for i in range(0, len(self.elements)):
                if e == self.elements[i]:
                    if self.frequency[i] > 0:
                        return True
        return False

    # counts and returns the number of times the element e appears in the bag
    '''
    Complexity: O(n)
    '''
    def nrOccurrences(self, e):
        if e in self.elements:
            for i in range(0, len(self.elements)):
                if e == self.elements[i]:
                    return self.frequency[i]
        return 0
    
    # returns the size of the Bag (the number of elements)
    '''
    Complexity: Theta(n)
    '''
    def size(self):
        count = 0;
        for i in range(0, len(self.elements)):
            count += self.frequency[i];
        return count

    # returns True if the Bag is empty, False otherwise
    """
    Complexity: theta(n)
    """
    def isEmpty(self):
        if self.size() == 0:
            return True
        return False

    # returns a BagIterator for the Bag
    """
    Complexity Thetha(1)
    """
    def iterator(self):
        return BagIterator(self)


class BagIterator:

    #creates an iterator for the Bag b, set to the first element of the bag, or invalid if the Bag is empty
    def __init__(self, b):
        self.__bag = b
        self.__current = 0
        self.__freq = 0
        
        
    # returns True if the iterator is valid
    def valid(self):
        if self.__current + 1 < len(self.__bag.elements):
            return True
    
    
    # returns the current element from the iterator.
    # throws ValueError if the iterator is not valid
    def getCurrent(self):
        return self.__bag.elements[self.__current]
    
    # moves the iterator to the next element
    #throws ValueError if the iterator is not valid
    def next(self):
        if self.__current == len(self.__bag.elements):
            raise ValueError
        else:
            if self.__freq == 1:
                self.__current += 1
                self.__freq = self.__bag.elements[self.__current]
            else:
                self.__freq -= 1
    
    # sets the iterator to the first element from the Bag
    def first(self):
        self.__current = 0
        self.__freq = 0