# HEAP

The concept of heap is embedded into the heap sort algorithm.

The binary heap data structure is an array object that we can view as a nearly complete binary tree. An array `A` which can represent a heap must have two attributes, `A.length` and `A.heap_size`.

- A.length: the size of the array, not all of the elements are arranged in heap
- A.heap_size: the size of the heap. A[0... heap_size-1] are sorted in a heap. The root of the tree is A[1].
- Since heap can be seen as a complete binary tree, given the index of a node `i`, we can easily calculate the parent `(i-1)//2`, left child `2i+1` and right child `2(i+1)` (need to check the boundary).

- two types: max heap, min heap

## Heap pop

1. pop out the first element
2. move the tail element to the top
3. shrink the heap size by 1
4. move top element down to an appropriate position, recursively
5. done

## Heap push

1. push the new element to the tail position
2. increase the heap size by 1
3. move tail element up to an appropriate position, recursively
4. done

## Heapify

1. initialize the array
2. starting from the parent of the last element, i = heapsize / 2.
3. move down to appropriate position, decrease i by 1 until i = 0.
