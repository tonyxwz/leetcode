class BinHeap:
    def __init__(self):
        # always occupy the first element so that the array starts from 1 for
        # easy division
        self.heaplist = [0]
        self.current_size = 0

    def top(self):
        return self.heaplist[1]

    def percUp(self, i):
        while i >> 1 > 0:
            if self.heaplist[i] < self.heaplist[i >> 1]:
                self.heaplist[i], self.heaplist[i >> 1] = (
                    self.heaplist[i >> 1],
                    self.heaplist[i],
                )
            i = i >> 1

    def insert(self, value):
        self.heaplist.append(value)
        self.current_size += 1
        self.percUp(self.current_size)

    def percDown(self, i):
        while i << 1 <= self.current_size:
            mc = self.minChild(i)
            if self.heaplist[mc] < self.heaplist[i]:
                print(self.heaplist[mc], self.heaplist[i])
                self.heaplist[mc], self.heaplist[i] = (
                    self.heaplist[i],
                    self.heaplist[mc],
                )
            i = mc

    def minChild(self, i):
        left = i << 1
        if left + 1 > self.current_size:
            return left
        else:
            if self.heaplist[left] > self.heaplist[left + 1]:
                return left + 1
            else:
                return left

    def delMin(self):
        self.heaplist[1] = self.heaplist[self.current_size]
        self.current_size -= 1
        self.heaplist.pop()
        self.percDown(1)

    def buildHeap(self, alist):
        self.current_size = len(alist)
        i = self.current_size >> 1
        self.heaplist = [0] + alist
        while i > 0:
            print(i)
            self.percDown(i)
            i = i - 1


if __name__ == "__main__":
    h = BinHeap()
    h.buildHeap([6, 2, 7, 8, 1, 9, 12])
    print(h.heaplist)
