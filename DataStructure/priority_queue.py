"""a simple python implementation of priority queue and corresponding methods

Mocking the C++ stl api:

priority_queue:
    __init__(iterable)
    top() -> element_type
    empty() -> bool
    size() -> int

    push() -> None
    pop() -> None
    swap() ? maybe not now
"""
from .heap import BinHeap

class PriorityQueue(BinHeap):
    def __init__(self, iterable):
        pass

